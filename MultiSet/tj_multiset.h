//1853790 ��ǿ ׯ��

#include<iostream>
using namespace std;
const bool _red = false;
const bool _black = true;

//������ڵ㶨��
template<class T>
struct node 
{
	bool color;//�ڵ���ɫ���Ǻ켴��
	node* parent;//�����
	node* left;//���ӽ��
	node* right;//���ӽ��
	T value;//�ڵ�ֵ
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
	size_t node_count;//׷�ټ�¼���Ĵ�С
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
			else {//û��������
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
			if (ptr->color == _red &&	// ����Ǻ�ڵ㣬��
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
		iterator(node<T>* x) { ptr = x; };
		iterator(const iterator& it) { ptr = it.ptr; };
		T& operator*() { return ptr->value; };
		T* operator->() { return &(operator*()); }
		iterator operator++() { increment(); return *this; };
		iterator operator++(int) {
			iterator tmp = *this;
			increment();
			return tmp;
		};
		iterator operator--() { decrement(); return *this; };
		iterator operator--(int) {
			iterator tmp = *this;
			decrement();
			return tmp;
		};
		bool operator!=(const iterator& iter) { return iter.ptr != this->ptr; };
		bool operator==(const iterator& iter) { return iter.ptr == this->ptr; };
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
			if (ptr->color == _red &&	// ����Ǻ�ڵ㣬��
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
		reverse_iterator(node<T>* x) { ptr = x; };
		reverse_iterator(const reverse_iterator& it) { ptr = it.ptr; };
		T& operator*() { return ptr->value; };
		T* operator->() { return &(operator*()); }
		reverse_iterator operator++() { increment(); return *this; };
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			increment();
			return tmp;
		};
		reverse_iterator operator--() { decrement(); return *this; };
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			decrement();
			return tmp;
		};
		bool operator!=(const reverse_iterator& iter) { return iter.ptr != this->ptr; };
		bool operator==(const reverse_iterator& iter) { return iter.ptr == this->ptr; };
	};
protected:
	node<T>* get_node() { return new node<T>; }
	void put_node(node<T>* p) { delete p; }
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
		header->color = _red; // �� header Ϊ��ɫ���������� header �� root���� iterator.operator++ �У�
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
	tj_rb_tree(const Compare& comp = Compare()) :node_count(0), key_compare(comp) { init(); }
	//���ƹ��캯��
	tj_rb_tree(const tj_rb_tree<T, Compare>& x)
		: node_count(0), key_compare(x.key_compare) {
		header = get_node();
		header->color = _red;
		if (x.header->parent == NULL) {	//���x����
			header->parent = NULL;
			header->left = header->right = header;	// �� header �����Һ���Ϊ�Լ���
		}
		else {	//x ���ǿ���
			header->parent = __copy((x.header)->parent, header);		// ���������x 
			header->left = minimum(header->parent);	// �� header ������Ϊ��С�ڵ�
			header->right = maximum(header->parent);	// �� header ���Һ���Ϊ���ڵ�
		}
		node_count = x.node_count;
	}
	//���ظ�ֵ�����
	tj_rb_tree<T, Compare>& operator = (const tj_rb_tree<T, Compare>& x) {
		if (this != &x) {//��ֹ����ֵ
			header = get_node();
			header->color = _red;
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
			node_count = x.node_count;
		}
		return *this;
	}
	//��������
	~tj_rb_tree() {
		clear();
		put_node(header);
	}
	void clear() {
		if (node_count != 0) {
			__erase(header->parent);
			header->left = header->right = header;
			header->parent = NULL;
			node_count = 0;
		}
	}

	//��������
	void swap(tj_rb_tree<T, Compare>& x) {
		_swap(node_count, x.node_count);
		_swap(header, x.header);
		_swap(key_compare, x.key_compare);
	}
	//�ȽϺ���
	Compare key_comp() { return key_compare; }

	//����������
	iterator begin() const { return iterator(header->left); }
	iterator end() const { return iterator(header); }
	reverse_iterator rbegin() { return reverse_iterator(header->right); }
	reverse_iterator rend() { return reverse_iterator(header); }

	//��С����
	bool empty() { return node_count == 0; }
	size_t size() const { return node_count; }
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
	void show(int depth, node<T>* root) {
		if (depth == 1)
			cout << "|---";
		if (root != NULL)
			cout << root->value << " " << root->color << endl;

		if (root->left != NULL) {
			depth++;
			for (int i = 1; i < depth; i++)
				cout << "|   ";
			cout << "|---";
			show(depth, root->left);
			depth--;
		}

		if (root->right != NULL) {
			depth++;
			for (int i = 1; i < depth; i++)
				cout << "|   ";
			cout << "|---";
			show(depth, root->right);
		}
	}
	//��������
	bool tj__rb_verify();
};

//tj_multiset����
template<class T, class Compare = less<T>>
class tj_multiset
{
private:
	tj_rb_tree<T, Compare> t;//���ú������ʾmultiset
public:
	//�޲ι��캯��
	tj_multiset() : t(Compare()) {}
	//initializer_list ���캯��
	tj_multiset(const initializer_list<T>& init) : t(Compare()) {
		for (auto it = init.begin(); it != init.end(); it++)
			t.insert_equal(*it);
	}
	//���������캯��
	tj_multiset(typename tj_rb_tree<T, Compare>::iterator first, typename tj_rb_tree<T, Compare>::iterator last) : t(Compare()) {
		for (auto it = first; it != last; it++)
			t.insert_equal(*it);
	}
	//���ƹ��캯��
	tj_multiset(const tj_multiset<T, Compare>& x) : t(x.t) {}
	//���ظ�ֵ�����
	tj_multiset<T, Compare>& operator = (const tj_multiset<T, Compare>& x) {
		t = x.t;
		return *this;
	}
	//���ظ�ֵ�����
	tj_multiset<T, Compare>& operator = (const initializer_list<T>& init) {
		for (auto it = init.begin(); it != init.end(); it++)
			t.insert_equal(*it);
		return *this;
	}
	//��������
	~tj_multiset() {}

	//����������
	typename tj_rb_tree<T, Compare>::iterator begin() { return t.begin(); }
	typename tj_rb_tree<T, Compare>::iterator cbegin() { return t.begin(); }
	typename tj_rb_tree<T, Compare>::iterator end() { return t.end(); }
	typename tj_rb_tree<T, Compare>::iterator cend() { return t.end(); }
	typename tj_rb_tree<T, Compare>::reverse_iterator rbegin() { return t.rbegin(); }
	typename tj_rb_tree<T, Compare>::reverse_iterator crbegin() { return t.rbegin(); }
	typename tj_rb_tree<T, Compare>::reverse_iterator rend() { return t.rend(); }
	typename tj_rb_tree<T, Compare>::reverse_iterator crend() { return t.rend(); }

	//��������
	void swap(tj_multiset<T, Compare>& x) { t.swap(x.t); }
	//��С����
	size_t size() { return t.size(); }
	size_t max_size() { return t.max_size(); }
	bool empty() { return t.empty(); }
	void clear() { t.clear(); }
	//�ȽϺ���
	Compare key_comp() { return t.key_comp(); }
	Compare value_comp() { return t.key_comp(); }
	//���뺯��
	typename tj_rb_tree<T, Compare>::iterator emplace(const T& x) { return t.insert_equal(x); }
	typename tj_rb_tree<T, Compare>::iterator insert(const T& x) { return t.insert_equal(x); }
	void insert(typename tj_rb_tree<T, Compare>::iterator first, typename tj_rb_tree<T, Compare>::iterator last) {
		for (auto it = first; it != last; it++)
			t.insert_equal(*it);
	}
	void insert(const initializer_list<T>& init) {
		for (auto it = init.begin(); it != init.end(); it++)
			t.insert_equal(*it);
	}
	//���Һ���
	typename tj_rb_tree<T, Compare>::iterator find(const T& x) { return t.find(x); }
	//ɾ������
	size_t erase(const T& x) { return t.erase(x); }
	typename tj_rb_tree<T, Compare>::iterator erase(typename tj_rb_tree<T, Compare>::iterator iter) { return t.erase(iter); }
	void erase(typename tj_rb_tree<T, Compare>::iterator first, typename tj_rb_tree<T, Compare>::iterator last) { t.erase(first, last); }
	//��������
	size_t count(const T& x) { return t.count(x); };
	pair<typename tj_rb_tree<T, Compare>::iterator, typename tj_rb_tree<T, Compare>::iterator> equal_range(const T& x) { return t.equal_range(x); }
	typename tj_rb_tree<T, Compare>::iterator lower_bound(const T& x) { return t.lower_bound(x); }
	typename tj_rb_tree<T, Compare>::iterator upper_bound(const T& x) { return t.upper_bound(x); }
	//���رȽ������
	bool operator == (const tj_multiset<T, Compare>& x) { return t == x.t; }
	bool operator != (const tj_multiset<T, Compare>& x) { return t != x.t; }
	bool operator < (const tj_multiset<T, Compare>& x) { return t < x.t; }
	bool operator <= (const tj_multiset<T, Compare>& x) { return t <= x.t; }
	bool operator > (const tj_multiset<T, Compare>& x) { return t > x.t; }
	bool operator >= (const tj_multiset<T, Compare>& x) { return t >= x.t; }
};