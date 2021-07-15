//1852024 ��ǿ �����
#pragma once
#include<iostream>
using namespace std;
const bool __rb_tree_red__ = false;
const bool __rb_tree_black__ = true;

//������ڵ㶨��
template<class T>
struct node
{
	bool color;		//�ڵ���ɫ���Ǻ켴��
	node* parent;	//�����
	node* left;		//���ӽ��
	node* right;	//���ӽ��
	T value;		//�ڵ�ֵ
};

//һЩ���⺯������
template<class T>
void _swap(T& a, T& b);
template<class T>
node<T>* minimum(node<T>* x);
template<class T>
node<T>* maximum(node<T>* x);

//���������
template<class T, class Compare>
class tj_rb_tree {
public:
	size_t __node_num__;//׷�ټ�¼���Ĵ�С
	node<T>* header;//ͷ�ڵ�
	Compare key_compare;//�ڵ��ļ�ֵ��С�Ƚ�׼���Ǹ�function object
	class iterator//���������
	{
	private:
		void increment() {
			if (ptr->right != NULL) {//������ҽڵ�
				ptr = ptr->right;//��������
				while (ptr->left != NULL)//Ȼ��һֱ���������ߵ���
					ptr = ptr->left;//���ǽ��
			}
			else {
				//û��������
				node<T>* y = ptr->parent;//�ҳ������
				while (ptr == y->right) {//���нڵ㱾�������ӽڵ�
					ptr = y;//һֱ���ݣ�ֱ����Ϊ���ӽڵ�Ϊֹ
					y = y->parent;
				}
				if (ptr->right != y)//����ʱ�����ӽڵ㲻���ڴ�ʱ�ĸ����
					ptr = y;//��ʱ�ĸ���㼴Ϊ���
				//�����ʱ��ptrΪ���
			}
		}
		void decrement() {
			if (ptr->color == __rb_tree_red__ &&	// ����Ǻ�ڵ㣬��
				ptr->parent->parent == ptr)		// ���ڵ�ĸ��ڵ�����Լ�
				ptr = ptr->right;
			//�������������ptrΪheaderʱ(�༴ptrΪend())
			//header֮�ҽڵ�Ϊmostright��ָ����������max���
			else if (ptr->left != NULL) {//��������ӽڵ�
				node<T>* y = ptr->left;//��yָ�����ӽڵ�
				while (y->right != NULL)//��y�����ӽڵ�ʱ
					y = y->right;//һֱ�����ӽڵ��ߵ���
				ptr = y;//���Ϊ��
			}
			else {//�ȷǸ��ڵ㣬�������ӽڵ�
				node<T>* y = ptr->parent;//�ҳ������
				while (ptr == y->left) {//���нڵ㱾�������ӽڵ�
					ptr = y;//һֱ���ݣ�ֱ����Ϊ���ӽڵ�Ϊֹ
					y = y->parent;
				}
				ptr = y;//��ʱ�ĸ���㼴Ϊ���
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
	class reverse_iterator//���������
	{
	private:
		void increment() {
			if (ptr->left != NULL) {//��������ӽڵ�
				node<T>* y = ptr->left;//��yָ�����ӽڵ�
				while (y->right != NULL)//��y�����ӽڵ�ʱ
					y = y->right;//һֱ�����ӽڵ��ߵ���
				ptr = y;//���Ϊ��
			}
			else {//�ȷǸ��ڵ㣬�������ӽڵ�
				node<T>* y = ptr->parent;//�ҳ������
				while (ptr == y->left) {//���нڵ㱾�������ӽڵ�
					ptr = y;//һֱ���ݣ�ֱ����Ϊ���ӽڵ�Ϊֹ
					y = y->parent;
				}
				if (ptr->left != y)//����ʱ�����ӽڵ㲻���ڴ�ʱ�ĸ����
					ptr = y;//��ʱ�ĸ���㼴Ϊ���
				//�����ʱ��ptrΪ���
			}
		}
		void decrement() {
			if (ptr->color == __rb_tree_red__ &&	// ����Ǻ�ڵ㣬��
				ptr->parent->parent == ptr)		// ���ڵ�ĸ��ڵ�����Լ�
				ptr = ptr->left;
			//�������������ptrΪheaderʱ(�༴ptrΪbegin())
			//header֮��ڵ�Ϊmostleft��ָ����������min���
			else if (ptr->right != NULL) {//��������ӽڵ�
				ptr = ptr->right;//��������
				while (ptr->left != NULL)//Ȼ��һֱ���������ߵ���
					ptr = ptr->left;//���ǽ��
			}
			else {//û��������
				node<T>* y = ptr->parent;//�ҳ������
				while (ptr == y->right) {//���нڵ㱾�������ӽڵ�
					ptr = y;//һֱ���ݣ�ֱ����Ϊ���ӽڵ�Ϊֹ
					y = y->parent;
				}
				ptr = y;//��ʱ�ĸ���㼴Ϊ���
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
		node<T>* tmp = get_node();			// ���ÿռ�
		tmp->value = x;
		return tmp;
	}
	node<T>* clone_node(node<T>* x) {	// ����һ���ڵ㣨ֵ����ɫ��
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
		header = get_node();	// ����һ���ڵ�ռ䣬��headerָ����
		header->color = __rb_tree_red__; // �� header Ϊ��ɫ���������� header �� root���� iterator.operator++ �У�
		header->parent = NULL;
		header->left = header->right = header;	// �� header �����Һ���Ϊ�Լ���
	}
	iterator __insert(node<T>* x, node<T>* y, const T& v);
	node<T>* __copy(node<T>* x, node<T>* p) {
		// x �� p ����ǿ�
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
	//Ĭ�Ϲ��캯��
	tj_rb_tree(const Compare& comp = Compare()) :__node_num__(0), key_compare(comp) { 
		init(); 
	}
	//���ƹ��캯��
	tj_rb_tree(const tj_rb_tree<T, Compare>& x)
		: __node_num__(0), key_compare(x.key_compare) {
		header = get_node();
		header->color = __rb_tree_red__;
		if (x.header->parent == NULL) {	//���x����
			header->parent = NULL;
			header->left = header->right = header;	// �� header �����Һ���Ϊ�Լ���
		}
		else {	//x ���ǿ���
			header->parent = __copy((x.header)->parent, header);		// ���������x 
			header->left = minimum(header->parent);	// �� header ������Ϊ��С�ڵ�
			header->right = maximum(header->parent);	// �� header ���Һ���Ϊ���ڵ�
		}
		__node_num__ = x.__node_num__;
	}
	//���ظ�ֵ�����
	tj_rb_tree<T, Compare>& operator = (const tj_rb_tree<T, Compare>& x) {
		if (this != &x) {//��ֹ����ֵ
			header = get_node();
			header->color = __rb_tree_red__;
			if (x.header->parent == NULL) {	//���x����
				header->parent = NULL;
				header->left = header->right = header;	// �� header �����Һ���Ϊ�Լ���
			}
			else {	//x ���ǿ���
				header->parent = __copy((x.header)->parent, header);		// ���������x 
				header->left = minimum(header->parent);	// �� header ������Ϊ��С�ڵ�
				header->right = maximum(header->parent);	// �� header ���Һ���Ϊ���ڵ�
			}
			key_compare = x.key_compare;
			__node_num__ = x.__node_num__;
		}
		return *this;
	}
	//��������
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

	//��������
	void swap(tj_rb_tree<T, Compare>& x) {
		_swap(__node_num__, x.__node_num__);
		_swap(header, x.header);
		_swap(key_compare, x.key_compare);
	}
	//�ȽϺ���
	Compare key_comp() { 
		return key_compare;
	}
	//����������
	iterator begin() const { return iterator(header->left); }
	iterator end() const { return iterator(header); }
	reverse_iterator rbegin() { return reverse_iterator(header->right); }
	reverse_iterator rend() { return reverse_iterator(header); }

	//��С����
	bool empty() { return __node_num__ == 0; }
	size_t size() const { return __node_num__; }
	size_t max_size() { return size_t(-1) / sizeof(node<T>); }

	//��������
	size_t count(const T& x) {
		size_t n = 0;
		pair<iterator, iterator> p = equal_range(x);
		distance(p.first, p.second, n);
		return n;
	}
	iterator lower_bound(const T& k);
	iterator upper_bound(const T& k);
	pair<iterator, iterator> equal_range(const T& x);

	//���뺯�������ֽڵ�ֵ��һ�޶���
	pair<iterator, bool> insert_unique(const T& x);
	//���뺯���������ظ��ڵ㣩
	iterator insert_equal(const T& x);
	//���Һ���
	iterator find(const T& v);
	//ɾ������
	iterator erase(iterator position);
	void erase(iterator first, iterator last);
	size_t erase(const T& v);

	//���رȽ������
	bool operator == (const tj_rb_tree<T, Compare>& x);
	bool operator != (const tj_rb_tree<T, Compare>& x);
	bool operator < (const tj_rb_tree<T, Compare>& x);
	bool operator <= (const tj_rb_tree<T, Compare>& x);
	bool operator > (const tj_rb_tree<T, Compare>& x);
	bool operator >= (const tj_rb_tree<T, Compare>& x);

	//��ӡ�����
	void show(int depth, node<T>* root);

	//��������
	bool tj__rb_verify();
};
