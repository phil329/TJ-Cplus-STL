/*��� 1851846 ��ǿ*/
/********************************************

RBTree

����ģ�壺	Key		������������
			Value	set�о���Key����map����pair
			Compare	�ȽϺ���

����������	root			���ڵ�
			key_compare		�Ƚ���ʹ�õ���
			node_count		׷�ٽڵ�ĸ���

����������	��������
			begin��end��
			�������	empty��size��max_size
			����ɾ��
			destory��search�ȵ�

*********************************************/

#pragma once

#include <iostream>
#include "tj_RBTree_Iterator.h"
using namespace std;

template <class Key, class Value, class Compare>
class RBTree {
public:
	// �����
	tj_RBTree_Node<Value>* root;

	//�Ƚ����õ���
	Compare key_compare;

	//����׷�ٽ�����
	size_t node_count;

	//������
	typedef tj_RBTree_Iterator<Value, Value&, Value*>  iterator;
	typedef tj_RBTree_Iterator<Value, const Value&, const Value*>  const_iterator;

	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	//�������������
	RBTree();
	~RBTree();

	//����������
	iterator begin() noexcept;
	const_iterator begin() const noexcept;
	iterator end() noexcept;
	const_iterator end() const noexcept;
	reverse_iterator rbegin() noexcept;
	const_reverse_iterator rbegin() const noexcept;
	reverse_iterator rend() noexcept;
	const_reverse_iterator rend() const noexcept;
	const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;
	const_reverse_iterator crbegin() const noexcept;
	const_reverse_iterator crend() const noexcept;

	//����
	bool empty()const;
	size_t size()const;
	size_t max_size() const;

	//�޸�
	bool rb_insert(Value key);//����
	void rb_insertFixUp(tj_RBTree_Node<Value>* node);// ������������
	bool rb_erase(Value key);//ɾ��
	void rb_eraseFixUp(tj_RBTree_Node<Value>* node, tj_RBTree_Node<Value>* parent);//ɾ����������
	void leftRotate(tj_RBTree_Node<Value>* x);
	void rightRotate(tj_RBTree_Node<Value>* y);

	//��������
	void destroy();
	void destroy(tj_RBTree_Node<Value>*& tree);
	tj_RBTree_Node<Value>* search(const Value key);
	tj_RBTree_Node<Value>* minimum(tj_RBTree_Node<Value>* tree)const;
	tj_RBTree_Node<Value>* maximum(tj_RBTree_Node<Value>* tree)const;
	size_t count(const Key& key);

};


//���캯��
template <class Key, class Value, class Compare>
RBTree<Key, Value, Compare>::RBTree()
{
	root = NULL;
	node_count = 0;
}

//��������
template <class Key, class Value, class Compare>
RBTree<Key, Value, Compare>::~RBTree()
{
	destroy();
}

//begin(����iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::iterator RBTree<Key, Value, Compare>::begin() noexcept
{

	return iterator(minimum(root), root);
}

//begin(����const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::begin() const  noexcept
{
	return const_iterator(minimum(root), root);
}

//end(����iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::iterator RBTree<Key, Value, Compare>::end()  noexcept
{
	return iterator(NULL, root);
}

//end(����const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::end() const  noexcept
{
	return const_iterator(NULL, root);
}

//rbegin(����reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::reverse_iterator RBTree<Key, Value, Compare>::rbegin()  noexcept
{
	return reverse_iterator(end());
}

//rbegin(����const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::rbegin() const noexcept
{
	return const_reverse_iterator(end());
}

//rend(����reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::reverse_iterator RBTree<Key, Value, Compare>::rend() noexcept
{
	return reverse_iterator(begin());
}

//rend(����const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::rend() const noexcept
{
	return const_reverse_iterator(begin());
}

//cbegin(����const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::cbegin() const noexcept
{
	return (begin());
}

//cend(����const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::cend() const noexcept
{
	return end();
}

//crbegin(����const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::crbegin() const noexcept
{
	return rbegin();
}

//crend(����const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::crend() const  noexcept
{
	return rend();
}

//�Ƿ�Ϊ��
template <class Key, class Value, class Compare>
bool RBTree<Key, Value, Compare>::empty()const
{
	return node_count == 0;
}

//��С
template <class Key, class Value, class Compare>
size_t RBTree<Key, Value, Compare>::size() const
{
	return node_count;
};

//max_size
template <class Key, class Value, class Compare>
size_t RBTree<Key, Value, Compare>::max_size() const
{
	return size_t(-1) / sizeof(tj_RBTree_Node<Key>);
}

//����ڵ�
template <class Key, class Value, class Compare>
bool RBTree<Key, Value, Compare>::rb_insert(Value value)
{
	//�½���㣨��ɫ��
	tj_RBTree_Node<Value>* new_node = NULL;
	//��������ҵ������½����ʧ���򷵻�
	if (search(value) || (new_node = new tj_RBTree_Node<Value>(value, RED, NULL, NULL, NULL)) == NULL)
		return false;

	tj_RBTree_Node<Value>* x = root;
	tj_RBTree_Node<Value>* y = NULL;

	//���ҽ��Ӧ�����λ��
	while (x != NULL) {//�Ӹ���㿪ʼ
		y = x;
		//����key_compare�ж�������������
		if (key_compare(new_node->value_field, x->value_field))
			x = x->left;
		else
			x = x->right;
	}
	//�½ڵ�ĸ��ڵ�Ϊy
	new_node->parent = y;
	if (y != NULL) {
		if (key_compare(new_node->value_field, y->value_field))
			y->left = new_node;
		else
			y->right = new_node;
	}
	else//������ֻ��new_nodeһ���������
		root = new_node;

	//��������
	rb_insertFixUp(new_node);
	node_count++;

	return true;
}

//����������
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::rb_insertFixUp(tj_RBTree_Node<Value>* node)
{
	tj_RBTree_Node<Value>* parent, * gparent, * uncle;

	// �����ڵ���游�ڵ���ڣ��Ҹ��ڵ�Ϊ��ɫ
	while ((parent = node->parent) && (gparent = parent->parent) && parent->color == RED)
	{

		//�����ڵ����游�ڵ������
		if (parent == gparent->left)
		{
			uncle = gparent->right;//����
			// �������ڵ�������Ǻ�ɫ
			if (uncle && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			// ����������Ǻ�ɫ���򲻴��ڣ�
			else {
				//�����ǰ������Һ���
				if (parent->right == node) {
					leftRotate(parent);//����
					tj_RBTree_Node<Value>* tmp;
					tmp = parent;//����node��parent
					parent = node;
					node = tmp;
				}
				//��ɫ������
				parent->color = BLACK;
				gparent->color = RED;
				rightRotate(gparent);
			}
		}
		//�����ڵ����游�ڵ���Һ���
		else {
			uncle = gparent->left;
			// �������ڵ��Ǻ�ɫ
			if (uncle && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			// ����������Ǻ�ɫ���򲻴��ڣ�
			else {
				//��ǰ�ڵ�������
				if (parent->left == node) {
					rightRotate(parent);//����
					tj_RBTree_Node<Value>* tmp;//����parent��node
					tmp = parent;
					parent = node;
					node = tmp;
				}
				//��ɫ������
				parent->color = BLACK;
				gparent->color = RED;
				leftRotate(gparent);

			}

		}
	}
	// �����ڵ���Ϊ��ɫ
	root->color = BLACK;
}


//ɾ�����
template <class Key, class Value, class Compare>
bool RBTree<Key, Value, Compare>::rb_erase(Value key)
{
	tj_RBTree_Node<Value>* delete_node;

	//�ҵ������ɾ�������򷵻�false
	if ((delete_node = search(key)) != NULL) {

		tj_RBTree_Node<Value>* child, * parent;
		tj_RBTree_Color color;

		// ��ɾ���ڵ�����Һ��Ӷ���Ϊ�յ������
		if ((delete_node->left != NULL) && (delete_node->right != NULL))
		{
			//�ҵ���̽��(replace)ȡ��delete_node
			tj_RBTree_Node<Value>* replace = delete_node;

			// ��ȡ��̽ڵ�
			replace = replace->right;
			while (replace->left != NULL)
				replace = replace->left;

			//���Ҫɾ���Ĳ��Ǹ��ڵ㣨�и��ڵ㣩
			if (delete_node->parent) {
				if (delete_node->parent->left == delete_node)
					delete_node->parent->left = replace;
				else
					delete_node->parent->right = replace;
			}
			//���Ҫɾ�����Ǹ��ڵ㣬����¸��ڵ�
			else
				root = replace;

			// childΪreplace���Һ��ӣ�parentΪreplace������
			child = replace->right;
			parent = replace->parent;
			// ����replace����ɫ
			color = replace->color;

			// ��ɾ���ڵ������ĺ�̽ڵ�ĸ��ڵ�
			if (parent == delete_node)
				parent = replace;
			else {
				// child��Ϊ��
				if (child)
					child->parent = parent;
				parent->left = child;

				replace->right = delete_node->right;
				delete_node->right->parent = replace;
			}
			//ɾ��delete_node
			replace->parent = delete_node->parent;
			replace->color = delete_node->color;
			replace->left = delete_node->left;
			delete_node->left->parent = replace;

			//���replace����ɫΪ��ɫ������е���
			if (color == BLACK)
				rb_eraseFixUp(child, parent);

			delete delete_node;
			return true;
		}

		//��ɾ��������Һ�������һ��Ϊ�ջ�Ϊ��
		//��ɾ���������Ӳ�Ϊ��
		if (delete_node->left != NULL)
			child = delete_node->left;
		else//��ɾ�������Һ��Ӳ�Ϊ�ջ�ɾ��������Һ��Ӷ�Ϊ��
			child = delete_node->right;

		parent = delete_node->parent;
		// ����ȡ���ڵ����ɫ
		color = delete_node->color;

		if (child)
			child->parent = parent;

		// ��ɾ����㲻�Ǹ��ڵ�
		if (parent) {
			if (parent->left == delete_node)
				parent->left = child;
			else
				parent->right = child;
		}
		//������¸��ڵ�
		else
			root = child;

		//�����ɫΪ������е���
		if (color == BLACK)
			rb_eraseFixUp(child, parent);
		delete delete_node;
		node_count--;

		return true;
	}
	return false;
}

//ɾ���������
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::rb_eraseFixUp(tj_RBTree_Node<Value>* node, tj_RBTree_Node<Value>* parent)
{
	tj_RBTree_Node<Value>* uncle;

	//����㲻���ڻ���ɫΪ���ҽ�㲻�Ǹ��ڵ�
	while ((!node || node->color == BLACK) && node != root) {
		if (parent->left == node) {//������������
			uncle = parent->right;
			if (uncle->color == RED) {//��������Ǻ�ɫ
				uncle->color = BLACK;
				parent->color = RED;
				leftRotate(parent);
				uncle = parent->right;
			}
			//�����������������Ǻ�ɫ���򲻴��ڣ�
			if ((!uncle->left || uncle->left->color == BLACK) &&
				(!uncle->right || uncle->right->color == BLACK)) {
				uncle->color = RED;
				node = parent;
				parent = node->parent;
			}
			else {
				if (!uncle->right || uncle->right->color == BLACK) {
					uncle->left->color = BLACK;
					uncle->color = RED;
					rightRotate(uncle);
					uncle = parent->right;
				}
				uncle->color = parent->color;
				parent->color = BLACK;
				uncle->right->color = BLACK;
				leftRotate(parent);
				node = root;
			}
		}
		else {
			uncle = parent->left;
			if (uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = RED;
				rightRotate(parent);
				uncle = parent->left;
			}
			if ((!uncle->left || uncle->left->color == BLACK) &&
				(!uncle->right || uncle->right->color == BLACK)) {
				uncle->color = RED;
				node = parent;
				parent = node->parent;
			}
			else {
				if (!uncle->left || uncle->left->color == BLACK) {
					uncle->right->color = BLACK;
					uncle->color = RED;
					leftRotate(uncle);
					uncle = parent->left;
				}
				uncle->color = parent->color;
				parent->color = BLACK;
				uncle->left->color = BLACK;
				rightRotate(parent);
				node = root;
			}
		}
	}
	if (node)
		node->color = BLACK;
}

//��������
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::leftRotate(tj_RBTree_Node<Value>* x)
{
	// ����x���Һ���Ϊy
	tj_RBTree_Node<Value>* y = x->right;

	//��y��������Ϊx���Һ���
	//���y�����ӷǿգ���x��Ϊy�����ӵĸ���
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	//��x�ĸ�����Ϊy�ĸ���
	y->parent = x->parent;

	if (x->parent == NULL)
		root = y;            //���x�ĸ����ǿսڵ㣬��y��Ϊ���ڵ�
	else {
		if (x->parent->left == x)
			x->parent->left = y;    // ���x�������ڵ�����ӣ���y��Ϊx�ĸ��ڵ������
		else
			x->parent->right = y;    // ���x�������ڵ�����ӣ���y��Ϊx�ĸ��ڵ������
	}

	//��x��Ϊy������
	y->left = x;
	//��x�ĸ��ڵ���Ϊy
	x->parent = y;
}

//��������
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::rightRotate(tj_RBTree_Node<Value>* y)
{
	// ����x�ǵ�ǰ�ڵ�����ӡ�
	tj_RBTree_Node<Value>* x = y->left;

	// ��x���Һ�����Ϊy������
	y->left = x->right;
	// ���x���Һ��Ӳ�Ϊ�յĻ�����y��Ϊx���Һ��ӵĸ���
	if (x->right != NULL)
		x->right->parent = y;

	// ��y�ĸ�����Ϊx�ĸ���
	x->parent = y->parent;

	if (y->parent == NULL)
		root = x;            // ���y�ĸ����ǿսڵ㣬��x��Ϊ���ڵ�
	else {
		if (y == y->parent->right)
			y->parent->right = x;    //���y�������ڵ���Һ��ӣ���x��Ϊy�ĸ��ڵ���Һ���
		else
			y->parent->left = x;    //y�������ڵ�����ӽ�x��Ϊx�ĸ��ڵ������
	}

	// ��y��Ϊx���Һ���
	x->right = y;

	// ��y�ĸ��ڵ���Ϊx
	y->parent = x;
}

//�ݹ�����
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::destroy(tj_RBTree_Node<Value>*& tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		destroy(tree->left);
	if (tree->right != NULL)
		destroy(tree->right);

	delete tree;
	tree = NULL;
}

//����
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::destroy()
{
	destroy(root);
}

//Ѱ��Ԫ��
template <class Key, class Value, class Compare>
tj_RBTree_Node<Value>* RBTree<Key, Value, Compare>::search(Value key)
{
	tj_RBTree_Node<Value>* x = root;
	while ((x != NULL) && (x->value_field != key)) {
		if (key < x->value_field)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

//������treeΪ������С���
template <class Key, class Value, class Compare>
tj_RBTree_Node<Value>* RBTree<Key, Value, Compare>::minimum(tj_RBTree_Node<Value>* tree)const
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

//������treeΪ���������
template <class Key, class Value, class Compare>
tj_RBTree_Node<Value>* RBTree<Key, Value, Compare>::maximum(tj_RBTree_Node<Value>* tree)const
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

//count
template <class Key, class Value, class Compare>
size_t RBTree<Key, Value, Compare>::count(const Key& key)
{
	if (search(key))
		return 1;
	return 0;

}
