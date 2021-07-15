/*鞠璇 1851846 数强*/
/********************************************

RBTree

函数模板：	Key		基本变量类型
			Value	set中就是Key，在map中是pair
			Compare	比较函数

包含变量：	root			根节点
			key_compare		比较所使用的类
			node_count		追踪节点的个数

包含函数：	构造析构
			begin、end等
			容量相关	empty、size、max_size
			插入删除
			destory、search等等

*********************************************/

#pragma once

#include <iostream>
#include "tj_RBTree_Iterator.h"
using namespace std;

template <class Key, class Value, class Compare>
class RBTree {
public:
	// 根结点
	tj_RBTree_Node<Value>* root;

	//比较所用的类
	Compare key_compare;

	//用于追踪结点个数
	size_t node_count;

	//迭代器
	typedef tj_RBTree_Iterator<Value, Value&, Value*>  iterator;
	typedef tj_RBTree_Iterator<Value, const Value&, const Value*>  const_iterator;

	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	//构造和析构函数
	RBTree();
	~RBTree();

	//迭代器函数
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

	//容量
	bool empty()const;
	size_t size()const;
	size_t max_size() const;

	//修改
	bool rb_insert(Value key);//插入
	void rb_insertFixUp(tj_RBTree_Node<Value>* node);// 插入修正函数
	bool rb_erase(Value key);//删除
	void rb_eraseFixUp(tj_RBTree_Node<Value>* node, tj_RBTree_Node<Value>* parent);//删除修正函数
	void leftRotate(tj_RBTree_Node<Value>* x);
	void rightRotate(tj_RBTree_Node<Value>* y);

	//其他函数
	void destroy();
	void destroy(tj_RBTree_Node<Value>*& tree);
	tj_RBTree_Node<Value>* search(const Value key);
	tj_RBTree_Node<Value>* minimum(tj_RBTree_Node<Value>* tree)const;
	tj_RBTree_Node<Value>* maximum(tj_RBTree_Node<Value>* tree)const;
	size_t count(const Key& key);

};


//构造函数
template <class Key, class Value, class Compare>
RBTree<Key, Value, Compare>::RBTree()
{
	root = NULL;
	node_count = 0;
}

//析构函数
template <class Key, class Value, class Compare>
RBTree<Key, Value, Compare>::~RBTree()
{
	destroy();
}

//begin(返回iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::iterator RBTree<Key, Value, Compare>::begin() noexcept
{

	return iterator(minimum(root), root);
}

//begin(返回const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::begin() const  noexcept
{
	return const_iterator(minimum(root), root);
}

//end(返回iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::iterator RBTree<Key, Value, Compare>::end()  noexcept
{
	return iterator(NULL, root);
}

//end(返回const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::end() const  noexcept
{
	return const_iterator(NULL, root);
}

//rbegin(返回reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::reverse_iterator RBTree<Key, Value, Compare>::rbegin()  noexcept
{
	return reverse_iterator(end());
}

//rbegin(返回const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::rbegin() const noexcept
{
	return const_reverse_iterator(end());
}

//rend(返回reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::reverse_iterator RBTree<Key, Value, Compare>::rend() noexcept
{
	return reverse_iterator(begin());
}

//rend(返回const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::rend() const noexcept
{
	return const_reverse_iterator(begin());
}

//cbegin(返回const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::cbegin() const noexcept
{
	return (begin());
}

//cend(返回const_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_iterator RBTree<Key, Value, Compare>::cend() const noexcept
{
	return end();
}

//crbegin(返回const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::crbegin() const noexcept
{
	return rbegin();
}

//crend(返回const_reverse_iterator)
template <class Key, class Value, class Compare>
typename RBTree<Key, Value, Compare>::const_reverse_iterator RBTree<Key, Value, Compare>::crend() const  noexcept
{
	return rend();
}

//是否为空
template <class Key, class Value, class Compare>
bool RBTree<Key, Value, Compare>::empty()const
{
	return node_count == 0;
}

//大小
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

//插入节点
template <class Key, class Value, class Compare>
bool RBTree<Key, Value, Compare>::rb_insert(Value value)
{
	//新建结点（红色）
	tj_RBTree_Node<Value>* new_node = NULL;
	//如果可以找到结点或新建结点失败则返回
	if (search(value) || (new_node = new tj_RBTree_Node<Value>(value, RED, NULL, NULL, NULL)) == NULL)
		return false;

	tj_RBTree_Node<Value>* x = root;
	tj_RBTree_Node<Value>* y = NULL;

	//查找结点应插入的位置
	while (x != NULL) {//从根结点开始
		y = x;
		//根据key_compare判断是向左还是向右
		if (key_compare(new_node->value_field, x->value_field))
			x = x->left;
		else
			x = x->right;
	}
	//新节点的父节点为y
	new_node->parent = y;
	if (y != NULL) {
		if (key_compare(new_node->value_field, y->value_field))
			y->left = new_node;
		else
			y->right = new_node;
	}
	else//整个树只有new_node一个结点的情况
		root = new_node;

	//进行修正
	rb_insertFixUp(new_node);
	node_count++;

	return true;
}

//插入后的修正
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::rb_insertFixUp(tj_RBTree_Node<Value>* node)
{
	tj_RBTree_Node<Value>* parent, * gparent, * uncle;

	// 若父节点和祖父节点存在，且父节点为红色
	while ((parent = node->parent) && (gparent = parent->parent) && parent->color == RED)
	{

		//若父节点是祖父节点的左孩子
		if (parent == gparent->left)
		{
			uncle = gparent->right;//叔叔
			// 如果叔叔节点存在且是红色
			if (uncle && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			// 如果叔叔结点是黑色（或不存在）
			else {
				//如果当前结点是右孩子
				if (parent->right == node) {
					leftRotate(parent);//左旋
					tj_RBTree_Node<Value>* tmp;
					tmp = parent;//交换node和parent
					parent = node;
					node = tmp;
				}
				//变色和右旋
				parent->color = BLACK;
				gparent->color = RED;
				rightRotate(gparent);
			}
		}
		//若父节点是祖父节点的右孩子
		else {
			uncle = gparent->left;
			// 如果叔叔节点是红色
			if (uncle && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
			}
			// 如果叔叔结点是黑色（或不存在）
			else {
				//当前节点是左孩子
				if (parent->left == node) {
					rightRotate(parent);//右旋
					tj_RBTree_Node<Value>* tmp;//交换parent和node
					tmp = parent;
					parent = node;
					node = tmp;
				}
				//变色和左旋
				parent->color = BLACK;
				gparent->color = RED;
				leftRotate(gparent);

			}

		}
	}
	// 将根节点设为黑色
	root->color = BLACK;
}


//删除结点
template <class Key, class Value, class Compare>
bool RBTree<Key, Value, Compare>::rb_erase(Value key)
{
	tj_RBTree_Node<Value>* delete_node;

	//找到结点则删除，否则返回false
	if ((delete_node = search(key)) != NULL) {

		tj_RBTree_Node<Value>* child, * parent;
		tj_RBTree_Color color;

		// 被删除节点的左右孩子都不为空的情况。
		if ((delete_node->left != NULL) && (delete_node->right != NULL))
		{
			//找到后继结点(replace)取代delete_node
			tj_RBTree_Node<Value>* replace = delete_node;

			// 获取后继节点
			replace = replace->right;
			while (replace->left != NULL)
				replace = replace->left;

			//如果要删除的不是根节点（有父节点）
			if (delete_node->parent) {
				if (delete_node->parent->left == delete_node)
					delete_node->parent->left = replace;
				else
					delete_node->parent->right = replace;
			}
			//如果要删除的是根节点，则更新根节点
			else
				root = replace;

			// child为replace的右孩子，parent为replace的左孩子
			child = replace->right;
			parent = replace->parent;
			// 保存replace的颜色
			color = replace->color;

			// 被删除节点是它的后继节点的父节点
			if (parent == delete_node)
				parent = replace;
			else {
				// child不为空
				if (child)
					child->parent = parent;
				parent->left = child;

				replace->right = delete_node->right;
				delete_node->right->parent = replace;
			}
			//删除delete_node
			replace->parent = delete_node->parent;
			replace->color = delete_node->color;
			replace->left = delete_node->left;
			delete_node->left->parent = replace;

			//如果replace的颜色为黑色，则进行调整
			if (color == BLACK)
				rb_eraseFixUp(child, parent);

			delete delete_node;
			return true;
		}

		//被删除结点左右孩子中有一个为空或都为空
		//被删除结点的左孩子不为空
		if (delete_node->left != NULL)
			child = delete_node->left;
		else//被删除结点的右孩子不为空或被删除结点左右孩子都为空
			child = delete_node->right;

		parent = delete_node->parent;
		// 保存取代节点的颜色
		color = delete_node->color;

		if (child)
			child->parent = parent;

		// 被删除结点不是根节点
		if (parent) {
			if (parent->left == delete_node)
				parent->left = child;
			else
				parent->right = child;
		}
		//否则更新根节点
		else
			root = child;

		//如果颜色为黑则进行调整
		if (color == BLACK)
			rb_eraseFixUp(child, parent);
		delete delete_node;
		node_count--;

		return true;
	}
	return false;
}

//删除后的修正
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::rb_eraseFixUp(tj_RBTree_Node<Value>* node, tj_RBTree_Node<Value>* parent)
{
	tj_RBTree_Node<Value>* uncle;

	//当结点不存在或颜色为黑且结点不是根节点
	while ((!node || node->color == BLACK) && node != root) {
		if (parent->left == node) {//如果结点是左孩子
			uncle = parent->right;
			if (uncle->color == RED) {//如果叔叔是红色
				uncle->color = BLACK;
				parent->color = RED;
				leftRotate(parent);
				uncle = parent->right;
			}
			//如果叔叔的两个孩子是黑色（或不存在）
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

//进行左旋
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::leftRotate(tj_RBTree_Node<Value>* x)
{
	// 设置x的右孩子为y
	tj_RBTree_Node<Value>* y = x->right;

	//将y的左孩子设为x的右孩子
	//如果y的左孩子非空，将x设为y的左孩子的父亲
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	//将x的父亲设为y的父亲
	y->parent = x->parent;

	if (x->parent == NULL)
		root = y;            //如果x的父亲是空节点，则将y设为根节点
	else {
		if (x->parent->left == x)
			x->parent->left = y;    // 如果x是它父节点的左孩子，则将y设为x的父节点的左孩子
		else
			x->parent->right = y;    // 如果x是它父节点的左孩子，则将y设为x的父节点的左孩子
	}

	//将x设为y的左孩子
	y->left = x;
	//将x的父节点设为y
	x->parent = y;
}

//进行右旋
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::rightRotate(tj_RBTree_Node<Value>* y)
{
	// 设置x是当前节点的左孩子。
	tj_RBTree_Node<Value>* x = y->left;

	// 将x的右孩子设为y的左孩子
	y->left = x->right;
	// 如果x的右孩子不为空的话，将y设为x的右孩子的父亲
	if (x->right != NULL)
		x->right->parent = y;

	// 将y的父亲设为x的父亲
	x->parent = y->parent;

	if (y->parent == NULL)
		root = x;            // 如果y的父亲是空节点，则将x设为根节点
	else {
		if (y == y->parent->right)
			y->parent->right = x;    //如果y是它父节点的右孩子，则将x设为y的父节点的右孩子
		else
			y->parent->left = x;    //y是它父节点的左孩子将x设为x的父节点的左孩子
	}

	// 将y设为x的右孩子
	x->right = y;

	// 将y的父节点设为x
	y->parent = x;
}

//递归销毁
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

//销毁
template <class Key, class Value, class Compare>
void RBTree<Key, Value, Compare>::destroy()
{
	destroy(root);
}

//寻找元素
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

//查找以tree为根的最小结点
template <class Key, class Value, class Compare>
tj_RBTree_Node<Value>* RBTree<Key, Value, Compare>::minimum(tj_RBTree_Node<Value>* tree)const
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

//查找以tree为根的最大结点
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
