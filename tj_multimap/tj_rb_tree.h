//1852024 数强 李兵磊
#pragma once
#include<iostream>
using namespace std;
const bool __rb_tree_red__ = false;
const bool __rb_tree_black__ = true;

//红黑树节点定义
template<class T>
struct node
{
	bool color;		//节点颜色，非红即黑
	node* parent;	//父结点
	node* left;		//左子结点
	node* right;	//右子结点
	T value;		//节点值
};

//一些类外函数声明
template<class T>
void _swap(T& a, T& b);
template<class T>
node<T>* minimum(node<T>* x);
template<class T>
node<T>* maximum(node<T>* x);

//红黑树定义
template<class T, class Compare>
class tj_rb_tree {
public:
	size_t __node_num__;//追踪记录树的大小
	node<T>* header;//头节点
	Compare key_compare;//节点间的键值大小比较准则，是个function object
	class iterator//正向迭代器
	{
	private:
		void increment() {
			if (ptr->right != NULL) {//如果有右节点
				ptr = ptr->right;//就向右走
				while (ptr->left != NULL)//然后一直往左子树走到底
					ptr = ptr->left;//即是解答
			}
			else {
				//没有右子树
				node<T>* y = ptr->parent;//找出父结点
				while (ptr == y->right) {//现行节点本身是右子节点
					ptr = y;//一直上溯，直到不为右子节点为止
					y = y->parent;
				}
				if (ptr->right != y)//若此时的右子节点不等于此时的父结点
					ptr = y;//此时的父结点即为解答
				//否则此时的ptr为解答
			}
		}
		void decrement() {
			if (ptr->color == __rb_tree_red__ &&	// 如果是红节点，且
				ptr->parent->parent == ptr)		// 父节点的父节点等于自己
				ptr = ptr->right;
			//以上情况发生于ptr为header时(亦即ptr为end())
			//header之右节点为mostright，指向整棵树的max结点
			else if (ptr->left != NULL) {//如果有左子节点
				node<T>* y = ptr->left;//令y指向左子节点
				while (y->right != NULL)//当y有右子节点时
					y = y->right;//一直往右子节点走到底
				ptr = y;//最后即为答案
			}
			else {//既非根节点，亦无左子节点
				node<T>* y = ptr->parent;//找出父结点
				while (ptr == y->left) {//现行节点本身是左子节点
					ptr = y;//一直上溯，直到不为左子节点为止
					y = y->parent;
				}
				ptr = y;//此时的父结点即为解答
			}
		}
	public:
		node<T>* ptr;
		iterator() {};
		iterator(node<T>* x) { 
			ptr = x; 
		}
		iterator(const iterator& it) { 
			ptr = it.ptr; 
		}
		T& operator*() { 
			return ptr->value; 
		}
		T* operator->() { 
			return &(operator*()); 
		}
		iterator operator++() { 
			increment(); 
			return *this; 
		}
		iterator operator++(int) {
			iterator tmp = *this;
			increment();
			return tmp;
		}
		iterator operator--() { 
			decrement(); 
			return *this; 
		}
		iterator operator--(int) {
			iterator tmp = *this;
			decrement();
			return tmp;
		}
		bool operator!=(const iterator& iter) { 
			return iter.ptr != this->ptr; 
		}
		bool operator==(const iterator& iter) { 
			return iter.ptr == this->ptr; 
		}
	};
	class reverse_iterator//反向迭代器
	{
	private:
		void increment() {
			if (ptr->left != NULL) {//如果有左子节点
				node<T>* y = ptr->left;//令y指向左子节点
				while (y->right != NULL)//当y有右子节点时
					y = y->right;//一直往右子节点走到底
				ptr = y;//最后即为答案
			}
			else {//既非根节点，亦无左子节点
				node<T>* y = ptr->parent;//找出父结点
				while (ptr == y->left) {//现行节点本身是左子节点
					ptr = y;//一直上溯，直到不为左子节点为止
					y = y->parent;
				}
				if (ptr->left != y)//若此时的左子节点不等于此时的父结点
					ptr = y;//此时的父结点即为解答
				//否则此时的ptr为解答
			}
		}
		void decrement() {
			if (ptr->color == __rb_tree_red__ &&	// 如果是红节点，且
				ptr->parent->parent == ptr)		// 父节点的父节点等于自己
				ptr = ptr->left;
			//以上情况发生于ptr为header时(亦即ptr为begin())
			//header之左节点为mostleft，指向整棵树的min结点
			else if (ptr->right != NULL) {//如果有右子节点
				ptr = ptr->right;//就向右走
				while (ptr->left != NULL)//然后一直往左子树走到底
					ptr = ptr->left;//即是解答
			}
			else {//没有右子树
				node<T>* y = ptr->parent;//找出父结点
				while (ptr == y->right) {//现行节点本身是右子节点
					ptr = y;//一直上溯，直到不为右子节点为止
					y = y->parent;
				}
				ptr = y;//此时的父结点即为解答
			}
		}
	public:
		node<T>* ptr;
		reverse_iterator() {};
		reverse_iterator(node<T>* x) { 
			ptr = x; 
		}
		reverse_iterator(const reverse_iterator& it) { 
			ptr = it.ptr; 
		}
		T& operator*() { 
			return ptr->value; 
		}
		T* operator->() { 
			return &(operator*()); 
		}
		reverse_iterator operator++() { 
			increment(); 
			return *this; 
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			increment();
			return tmp;
		}
		reverse_iterator operator--() { 
			decrement(); 
			return *this; 
		}
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			decrement();
			return tmp;
		}
		bool operator!=(const reverse_iterator& iter) { 
			return iter.ptr != this->ptr; 
		};
		bool operator==(const reverse_iterator& iter) { 
			return iter.ptr == this->ptr; 
		}
	};
	typedef const iterator const_iterator;
	typedef const reverse_iterator const_reverse_iterator;

protected:
	node<T>* get_node() { 
		return new node<T>; 
	}
	void put_node(node<T>* p) { 
		delete p; 
	}
	node<T>* create_node(const T& x) {
		node<T>* tmp = get_node();			// 配置空间
		tmp->value = x;
		return tmp;
	}
	node<T>* clone_node(node<T>* x) {	// 复制一个节点（值和颜色）
		node<T>* tmp = create_node(x->value);
		tmp->color = x->color;
		tmp->left = NULL;
		tmp->right = NULL;
		return tmp;
	}
	void destroy_node(node<T>* p) {
		put_node(p);
	}
private:
	void init() {
		header = get_node();	// 产生一个节点空间，令header指向它
		header->color = __rb_tree_red__; // 令 header 为红色，用来区分 header 和 root（在 iterator.operator++ 中）
		header->parent = NULL;
		header->left = header->right = header;	// 令 header 的左、右孩子为自己。
	}
	iterator __insert(node<T>* x, node<T>* y, const T& v);
	node<T>* __copy(node<T>* x, node<T>* p) {
		// x 和 p 必须非空
		node<T>* top = clone_node(x);
		top->parent = p;

		if (x->right)
			top->right = __copy(x->right, top);
		p = top;
		x = x->left;

		while (x != 0) {
			node<T>* y = clone_node(x);
			p->left = y;
			y->parent = p;
			if (x->right)
				y->right = __copy(x->right, y);
			p = y;
			x = x->left;
		}
		return top;
	}
	void __erase(node<T>* x) {
		while (x != NULL) {
			__erase(x->right);
			node<T>* y = x->left;
			destroy_node(x);
			x = y;
		}
	}
	void distance(iterator first, iterator last, size_t& n);
public:
	//默认构造函数
	tj_rb_tree(const Compare& comp = Compare()) :__node_num__(0), key_compare(comp) { 
		init(); 
	}
	//复制构造函数
	tj_rb_tree(const tj_rb_tree<T, Compare>& x)
		: __node_num__(0), key_compare(x.key_compare) {
		header = get_node();
		header->color = __rb_tree_red__;
		if (x.header->parent == NULL) {	//如果x空树
			header->parent = NULL;
			header->left = header->right = header;	// 令 header 的左、右孩子为自己。
		}
		else {	//x 不是空树
			header->parent = __copy((x.header)->parent, header);		// 拷贝红黑树x 
			header->left = minimum(header->parent);	// 令 header 的左孩子为最小节点
			header->right = maximum(header->parent);	// 令 header 的右孩子为最大节点
		}
		__node_num__ = x.__node_num__;
	}
	//重载赋值运算符
	tj_rb_tree<T, Compare>& operator = (const tj_rb_tree<T, Compare>& x) {
		if (this != &x) {//防止自身赋值
			header = get_node();
			header->color = __rb_tree_red__;
			if (x.header->parent == NULL) {	//如果x空树
				header->parent = NULL;
				header->left = header->right = header;	// 令 header 的左、右孩子为自己。
			}
			else {	//x 不是空树
				header->parent = __copy((x.header)->parent, header);		// 拷贝红黑树x 
				header->left = minimum(header->parent);	// 令 header 的左孩子为最小节点
				header->right = maximum(header->parent);	// 令 header 的右孩子为最大节点
			}
			key_compare = x.key_compare;
			__node_num__ = x.__node_num__;
		}
		return *this;
	}
	//析构函数
	~tj_rb_tree() {
		clear();
		put_node(header);
	}
	void clear() {
		if (__node_num__ != 0) {
			__erase(header->parent);
			header->left = header->right = header;
			header->parent = NULL;
			__node_num__ = 0;
		}
	}

	//交换函数
	void swap(tj_rb_tree<T, Compare>& x) {
		_swap(__node_num__, x.__node_num__);
		_swap(header, x.header);
		_swap(key_compare, x.key_compare);
	}
	//比较函数
	Compare key_comp() { 
		return key_compare;
	}
	//迭代器函数
	iterator begin() const { return iterator(header->left); }
	iterator end() const { return iterator(header); }
	reverse_iterator rbegin() { return reverse_iterator(header->right); }
	reverse_iterator rend() { return reverse_iterator(header); }

	//大小函数
	bool empty() { return __node_num__ == 0; }
	size_t size() const { return __node_num__; }
	size_t max_size() { return size_t(-1) / sizeof(node<T>); }

	//计数函数
	size_t count(const T& x) {
		size_t n = 0;
		pair<iterator, iterator> p = equal_range(x);
		distance(p.first, p.second, n);
		return n;
	}
	iterator lower_bound(const T& k);
	iterator upper_bound(const T& k);
	pair<iterator, iterator> equal_range(const T& x);

	//插入函数（保持节点值独一无二）
	pair<iterator, bool> insert_unique(const T& x);
	//插入函数（允许重复节点）
	iterator insert_equal(const T& x);
	//查找函数
	iterator find(const T& v);
	//删除函数
	iterator erase(iterator position);
	void erase(iterator first, iterator last);
	size_t erase(const T& v);

	//重载比较运算符
	bool operator == (const tj_rb_tree<T, Compare>& x);
	bool operator != (const tj_rb_tree<T, Compare>& x);
	bool operator < (const tj_rb_tree<T, Compare>& x);
	bool operator <= (const tj_rb_tree<T, Compare>& x);
	bool operator > (const tj_rb_tree<T, Compare>& x);
	bool operator >= (const tj_rb_tree<T, Compare>& x);

	//打印红黑树
	void show(int depth, node<T>* root);

	//检验红黑树
	bool tj__rb_verify();
};
