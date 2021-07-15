//1852024 ��ǿ �����
#include "tj_rb_tree.h"

//��������
template<class T>
void _swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

//��������������һֱ�����ߣ��ҵ���С��ֵ
template<class T>
node<T>* minimum(node<T>* x) {
	while (x->left != NULL) x = x->left;
	return x;
}

//������������һֱ�����ߣ�������ֵ
template<class T>
node<T>* maximum(node<T>* x) {
	while (x->right != NULL) x = x->right;
	return x;
}
//����
template<class T>
void rotate_left(node<T>* x, node<T>*& root) {
	//xΪ��ת��
	node<T>* y = x->right;//��yΪ��ת������ӽڵ�
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	//��y��ȫ����x�ĵ�λ
	if (x == root)//xΪ���ڵ�
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

//����
template<class T>
void rotate_right(node<T>* x, node<T>*& root) {
	//xΪ��ת��
	node<T>* y = x->left;//��yΪ��ת������ӽڵ�
	x->left = y->right;
	if (y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	//��y��ȫ����x�ĵ�λ
	if (x == root)//xΪ���ڵ�
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->right = x;
	x->parent = y;
}

//__insert : �ڲ�����
template<class T, class Compare>
typename tj_rb_tree<T, Compare>::iterator tj_rb_tree<T, Compare>::__insert(node<T>* x_, node<T>* y_, const T& v) {
	//����x_Ϊ��ֵ����㣬����y_Ϊ�����֮���ڵ㣬����v Ϊ��ֵ
	node<T>* x = x_;
	node<T>* y = y_;
	node<T>* z;
	//key_compare�Ǽ�ֵ�ñȽ�׼���Ǹ���������ָ��
	if (y == header || x != NULL || key_compare(v.first, (y->value).first)) {
		z = create_node(v);  // ����һ���½ڵ�
		y->left = z;          // ��ʹ�õ�yΪheaderʱ��leftmost()=z
		if (y == header) {
			header->parent = z;
			header->right = z;
		}
		else if (y == header->left)	// ���yΪ����ڵ�
			header->left = z;           	// ά��leftmost()��ʹ����Զָ������ڵ�
	}
	else {
		z = create_node(v);
		y->right = z;				// ���½ڵ��Ϊ�����֮���ڵ�y���Һ���
		if (y == header->right)
			header->right = z;          	// ά��rightmost()��ʹ����Զָ�����ҽڵ�
	}
	z->parent = y;		// �趨�½ڵ�ĸ��ڵ�
	z->left = NULL;		// �趨�º��ӽڵ������
	z->right = NULL; 		// �趨�º��ӽڵ���Һ���
							// �½ڵ����ɫ���� __rb_tree_rebalance() �趨������
	tj__rb_tree_rebalance(z, header->parent);	// ����һΪ�����ڵ㣬������Ϊroot
	++__node_num__;		// �ڵ�������
	return iterator(z);	// ���ص�������ָ�������ڵ�
}


//�����������rb_treeƽ�⣨�ı���ɫ����ת������xΪ�����ڵ㣬������Ϊroot�ڵ�
template<class T>
inline void tj__rb_tree_rebalance(node<T>* x, node<T>*& root) {
	x->color = __rb_tree_red__;		// �½ڵ��Ϊ��ɫ
	while (x != root && x->parent->color == __rb_tree_red__) { // ���ڵ�Ϊ��ɫ
		if (x->parent == x->parent->parent->left) { // ���ڵ�Ϊ�游�ڵ������
			node<T>* y = x->parent->parent->right;	// ��y Ϊ�����ڵ�
			if (y && y->color == __rb_tree_red__) { 		// �����ڵ���ڣ���Ϊ��ɫ
				x->parent->color = __rb_tree_black__;  		// ���ĸ��ڵ�Ϊ��ɫ
				y->color = __rb_tree_black__;				// ���Ĳ����ڵ�Ϊ��ɫ
				x->parent->parent->color = __rb_tree_red__; 	// �����游�ڵ�Ϊ��ɫ
				x = x->parent->parent;
			}
			else {	// �޲����ڵ�򲮸��ڵ�Ϊ��ɫ��NULL���Ǻ�ɫ��
				if (x == x->parent->right) { // �����ڵ�Ϊ���ڵ���Һ���
					x = x->parent;
					rotate_left(x, root); // ��һ������Ϊ����ת��
				}
				x->parent->color = __rb_tree_black__;	// �ı���ɫ�����ڵ�Ϊ��ɫ
				x->parent->parent->color = __rb_tree_red__;
				rotate_right(x->parent->parent, root); // ��һ����Ϊ����ת��
			}
		}
		else {	// ���ڵ�Ϊ�游�ڵ���Һ���
			node<T>* y = x->parent->parent->left; // yΪ�����ڵ�
			if (y && y->color == __rb_tree_red__) {		// �в����ڵ���Ϊ��ɫ
				x->parent->color = __rb_tree_black__;		// ���ĸ��ڵ�Ϊ��ɫ
				y->color = __rb_tree_black__; 				// ���Ĳ����ڵ�Ϊ��ɫ
				x->parent->parent->color = __rb_tree_red__; 	// �����游�ڵ�Ϊ��ɫ
				x = x->parent->parent;	// ׼���������ϲ��顭��
			}
			else {	// �޲����ڵ�򲮸��ڵ�Ϊ��ɫ��NULL���Ǻ�ɫ��
				if (x == x->parent->left) {	// �½ڵ�Ϊ���ڵ������
					x = x->parent;
					rotate_right(x, root); 	// ��һ����������ת
				}
				x->parent->color = __rb_tree_black__;	// �ı���ɫ�����ڵ�Ϊ��ɫ
				x->parent->parent->color = __rb_tree_red__;
				rotate_left(x->parent->parent, root); // ��һ����������ת
			}
		}
	}	// while �Y��
	root->color = __rb_tree_black__;	// ���ڵ���ԶΪ��ɫ
}

//ɾ����������rb_treeƽ��
template<class T>
inline node<T>* tj__rb_tree_rebalance_for_erase(node<T>* z, node<T>*& root,
	node<T>*& leftmost, node<T>*& rightmost)
{
	node<T>* y = z;
	node<T>* x = NULL;
	node<T>* x_parent = NULL;
	if (y->left == NULL)             // z has at most one non-null child. y == z.
		x = y->right;               // x might be null.
	else {
		if (y->right == NULL)          // z has exactly one non-null child.  y == z.
			x = y->left;              // x is not null.
		else {                      // z has two non-null children.  Set y to
			y = y->right;             //   z's successor.  x might be null.
			while (y->left != NULL)
				y = y->left;
			x = y->right;
		}
	}
	if (y != z) {                 // relink y in place of z.  y is z's successor
		z->left->parent = y;
		y->left = z->left;
		if (y != z->right) {
			x_parent = y->parent;
			if (x)
				x->parent = y->parent;
			y->parent->left = x;      // y must be a left child
			y->right = z->right;
			z->right->parent = y;
		}
		else
			x_parent = y;
		if (root == z)
			root = y;
		else if (z->parent->left == z)
			z->parent->left = y;
		else
			z->parent->right = y;
		y->parent = z->parent;
		_swap(y->color, z->color);
		y = z;
		// y now points to node to be actually deleted
	}
	else {                        // y == z
		x_parent = y->parent;
		if (x)
			x->parent = y->parent;
		if (root == z)
			root = x;
		else
			if (z->parent->left == z)
				z->parent->left = x;
			else
				z->parent->right = x;
		if (leftmost == z)
			if (z->right == NULL)        // z->left must be null also
				leftmost = z->parent;
		// makes leftmost == header if z == root
			else
				leftmost = minimum(x);
		if (rightmost == z)
			if (z->left == NULL)         // z->right must be null also
				rightmost = z->parent;
		// makes rightmost == header if z == root
			else                      // x == z->left
				rightmost = maximum(x);
	}
	if (y->color != __rb_tree_red__) {
		while (x != root && (x == NULL || x->color == __rb_tree_black__))
			if (x == x_parent->left) {
				node<T>* w = x_parent->right;
				if (w->color == __rb_tree_red__) {
					w->color = __rb_tree_black__;
					x_parent->color = __rb_tree_red__;
					rotate_left(x_parent, root);
					w = x_parent->right;
				}
				if ((w->left == NULL || w->left->color == __rb_tree_black__) &&
					(w->right == NULL || w->right->color == __rb_tree_black__)) {
					w->color = __rb_tree_red__;
					x = x_parent;
					x_parent = x_parent->parent;
				}
				else {
					if (w->right == NULL || w->right->color == __rb_tree_black__) {
						if (w->left) w->left->color = __rb_tree_black__;
						w->color = __rb_tree_red__;
						rotate_right(w, root);
						w = x_parent->right;
					}
					w->color = x_parent->color;
					x_parent->color = __rb_tree_black__;
					if (w->right) w->right->color = __rb_tree_black__;
					rotate_left(x_parent, root);
					break;
				}
			}
			else {                  // same as above, with right <-> left.
				node<T>* w = x_parent->left;
				if (w->color == __rb_tree_red__) {
					w->color = __rb_tree_black__;
					x_parent->color = __rb_tree_red__;
					rotate_right(x_parent, root);
					w = x_parent->left;
				}
				if ((w->right == NULL || w->right->color == __rb_tree_black__) &&
					(w->left == NULL || w->left->color == __rb_tree_black__)) {
					w->color = __rb_tree_red__;
					x = x_parent;
					x_parent = x_parent->parent;
				}
				else {
					if (w->left == NULL || w->left->color == __rb_tree_black__) {
						if (w->right) w->right->color = __rb_tree_black__;
						w->color = __rb_tree_red__;
						rotate_left(w, root);
						w = x_parent->left;
					}
					w->color = x_parent->color;
					x_parent->color = __rb_tree_black__;
					if (w->left) w->left->color = __rb_tree_black__;
					rotate_right(x_parent, root);
					break;
				}
			}
		if (x) x->color = __rb_tree_black__;
	}
	return y;
}

//���Һ���
template<class T, class Compare>
typename tj_rb_tree<T, Compare>::iterator tj_rb_tree<T, Compare>::find(const T& k) {
	node<T>* y = header;        // Last node which is not less than k. 
	node<T>* x = header->parent;        // Current node. 

	while (x != NULL)
		// key_compare �� function object��
		if (!key_compare((x->value).first, k.first))
			// ���е������ʾx��ֵ����k��������ֵ�������ߡ�
			y = x, x = x->left;	// ע���﷨!���ű��ʽ
		else
			// ���е������ʾx��ֵС��k������Сֵ�������ߡ�
			x = x->right;

	iterator j = iterator(y);
	return (j == end() || key_compare(k.first, ((j.ptr)->value).first)) ? end() : j;
}

//���뺯�� �����ֵ�ظ��������²���ڵ�ĵ�����
template <class T, class Compare>
typename tj_rb_tree<T, Compare>::iterator tj_rb_tree<T, Compare>::insert_equal(const T& v)
{
	node<T>* y = header;
	node<T>* x = header->parent;
	while (x != NULL) {		// �Ӹ��ڵ㿪ʼ������Ѱ���ʵ�����λ��
		y = x;
		x = key_compare(v.first, (x->value).first) ? x->left : x->right;
	}
	return __insert(x, y, v);
}

//���뺯�� �������ֵ�ظ������򰲲���Ч������ֵ�Ǹ�pair����һ��Ԫ���Ǹ�RB-tree��������ָ�������ڵ㡣�ڶ���Ԫ�ر�ʾ�����Ƿ�ɹ���
template <class T, class Compare>
pair<typename tj_rb_tree<T, Compare>::iterator, bool>
tj_rb_tree<T, Compare>::insert_unique(const T& v)
{
	node<T>* y = header;
	node<T>* x = header->parent;  //�Ӹ��ڵ㿪ʼ
	bool comp = true;
	while (x != NULL) { 		// �Ӹ��ڵ㿪ʼ����Ѱ���ʵ�����λ��
		y = x;
		comp = key_compare(v, x->value); // v ��ֵС��Ŀǰ�ڵ�ļ�ֵ��
		x = comp ? x->left : x->right;	// ��������������С�ڻ���ڡ�����
	}
	//�뿪whileѭ��֮��y��ָ��Ϊ�����ĸ��ڵ㣬x��ΪҶ�ӽڵ�

	iterator j = iterator(y);   // �������jָ�򰲲��֮���ڵ� y
	if (comp)	//����뿪whileѭ��ʱcompΪ�棬��ʾ ���ڵ��ֵ>v �������������Ӵ�
		if (j == begin())   // ���j������ڵ�
			return pair<iterator, bool>(__insert(x, y, v), true);
	// ���ϣ�x Ϊ����㣬y Ϊ�����֮���ڵ㣬v Ϊ��ֵ��
		else	// ���򣨰����֮���ڵ㲻������ڵ㣩
			--j;	// ���� j����ͷ׼������...
	if (key_compare(j.ptr->value, v))
		// С����ֵ����ʾ����С�������������Ҳࣩ
		return pair<iterator, bool>(__insert(x, y, v), true);

	//�����е������ʾ��ֵ���ظ�����Ӧ�ò���
	return pair<iterator, bool>(j, false);
}

//ɾ������
template <class T, class Compare>
typename tj_rb_tree<T, Compare>::iterator tj_rb_tree<T, Compare>::erase(iterator position) {
	iterator origin = position++;
	node<T>* y = tj__rb_tree_rebalance_for_erase(origin.ptr,
		header->parent,
		header->left,
		header->right);
	destroy_node(y);
	--__node_num__;
	return position;
}

//ɾ������
template <class T, class Compare>
size_t tj_rb_tree<T, Compare>::erase(const T& x) {
	size_t n = 0;
	pair<iterator, iterator> p = equal_range(x);
	distance(p.first, p.second, n);
	erase(p.first, p.second);
	return n;
}

//ɾ������
template <class T, class Compare>
inline void tj_rb_tree<T, Compare>::erase(iterator first, iterator last) {
	if (first == begin() && last == end())
		clear();
	else
		while (first != last)
			erase(first++);
}

//���뺯��
template <class T, class Compare>
inline void tj_rb_tree<T, Compare>::distance(iterator first, iterator last, size_t& n) {
	n = 0;
	while (first != last) {
		first++;
		n++;
	}
}

//���ҵ�һ������kС�Ľڵ�
template <class T, class Compare>
typename tj_rb_tree<T, Compare>::iterator
tj_rb_tree<T, Compare>::lower_bound(const T& k) {
	node<T>* y = header; //��һ������kС�Ľڵ�
	node<T>* x = header->parent;//��ǰ�ڵ�

	while (x != NULL)
		if (!key_compare((x->value).first, k.first))
			y = x, x = x->left;
		else
			x = x->right;
	return iterator(y);
}

//���ҵ�һ����k��Ľڵ�
template <class T, class Compare>
typename tj_rb_tree<T, Compare>::iterator
tj_rb_tree<T, Compare>::upper_bound(const T& k) {
	node<T>* y = header;//��һ����k��Ľڵ�
	node<T>* x = header->parent;//��ǰ�ڵ�

	while (x != NULL)
		if (key_compare(k.first, (x->value).first))
			y = x, x = x->left;
		else
			x = x->right;
	return iterator(y);
}

//�������Ԫ�صķ�Χ
template <class T, class Compare>
pair<typename tj_rb_tree<T, Compare>::iterator, typename tj_rb_tree<T, Compare>::iterator>
tj_rb_tree<T, Compare>::equal_range(const T& k) {
	return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
}


//���� == �����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::operator == (const tj_rb_tree<T, Compare>& x)
{
	if (size() != x.size())
		return false;
	auto it1 = begin();
	auto it2 = x.begin();
	for (;it1 != end() && it2 != x.end();it1++, it2++)
		if (*it1 != *it2)
			return false;
	return true;
}

//���� != �����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::operator != (const tj_rb_tree<T, Compare>& x)
{
	return !(*this == x);
}

//���� < �����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::operator < (const tj_rb_tree<T, Compare>& x)
{
	auto it1 = begin();
	auto it2 = x.begin();
	for (; it1 != end() && it2 != x.end(); it1++, it2++)
		if (*it1 != *it2)
			return *it1 < *it2;
	return size() < x.size();
}

//���� <= �����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::operator <= (const tj_rb_tree<T, Compare>& x)
{
	auto it1 = begin();
	auto it2 = x.begin();
	for (; it1 != end() && it2 != x.end(); it1++, it2++)
		if (*it1 != *it2)
			return *it1 < *it2;
	return size() <= x.size();
}

//���� > �����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::operator > (const tj_rb_tree<T, Compare>& x)
{
	auto it1 = begin();
	auto it2 = x.begin();
	for (; it1 != end() && it2 != x.end(); it1++, it2++)
		if (*it1 != *it2)
			return *it1 > * it2;
	return size() > x.size();
}

//���� >= �����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::operator >= (const tj_rb_tree<T, Compare>& x)
{
	auto it1 = begin();
	auto it2 = x.begin();
	for (; it1 != end() && it2 != x.end(); it1++, it2++)
		if (*it1 != *it2)
			return *it1 > * it2;
	return size() >= x.size();
}


template <class T, class Compare>
void tj_rb_tree<T, Compare>::show(int depth, node<T>* root) {
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

//�����Ƿ��Ǻ����
template <class T, class Compare>
bool tj_rb_tree<T, Compare>::tj__rb_verify() {
	// ����������RB����׼
	if (__node_num__ == 0 || begin() == end())
		return __node_num__ == 0 && begin() == end() && header->left == header && header->right == header;

	//����Ҷ���ڵ��� root ·���ĺڽڵ����
	int len = tj___rb_tree_black___count(header->left, header->parent);
	//һ���߷�����RB�������ÿ���ڵ㣨����С����󣩡���
	for (iterator it = begin(); it != end(); ++it) {
		node<T>* x = it.ptr; // __rb_tree_base_iterator::node
		node<T>* L = x->left;		// �������ӽڵ�
		node<T>* R = x->right; 	// �������ӽڵ�

		if (x->color == __rb_tree_red__)
			if ((L && L->color == __rb_tree_red__) ||
				(R && R->color == __rb_tree_red__))
				return false;	// ���ӽڵ�ͬΪ��ɫ�����Ϸ�RB��Ҫ��

		if (L && key_compare(x->value, L->value)) // ��ǰ�ڵ�ļ�ֵС�����ӽڵ�ļ�ֵ
			return false;         	// �����϶����������Ҫ��
		if (R && key_compare(R->value, x->value)) // ��ǰ�ڵ�ļ�ֵ�����Һ��ӽڵ�ļ�ֵ
			return false;		// �����϶����������Ҫ��

		  //[Ҷ�ӽ�㵽root]·���ڵĺ�ɫ�ڵ�������[����ڵ���root]·���ڵĺ�ɫ�ڵ㲻ͬ��������RB��Ҫ��
		if (!L && !R && tj___rb_tree_black___count(x, header->parent) != len)
			return false;
	}

	if (header->left != minimum(header->parent))
		return false;	// ����ڵ㲻Ϊ��С�ڵ㣬�����϶����������Ҫ��
	if (header->right != maximum(header->parent))
		return false;	// ���ҽڵ㲻Ϊ���ڵ㣬���������϶����������Ҫ��
	return true;
}