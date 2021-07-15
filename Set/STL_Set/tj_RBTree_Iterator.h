/*鞠璇 1851846 数强*/
/********************************************

RBTree的迭代器

函数模板：	Value——值的类型
			Ref——值的引用
			Ptr——值的指针

包含变量：	root(放入tj_RBTree的根结点)(方便在++或--到NULL时的操作)、
			node(迭代器指向的结点指针)

包含函数：	构造函数——默认、复制、带参
			*
			->
			++
			--
			==
			!=

*********************************************/

#pragma once
#include <iostream>
#include "tj_RBTree_node.h"
using namespace std;

template<class Value, class Ref, class Ptr>
struct tj_RBTree_Iterator
{
	//为了使用reverse_iterator进行的typedef
	typedef Value value_type;
	typedef Ref reference;
	typedef Ptr pointer;
	typedef bidirectional_iterator_tag iterator_category;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;


	//Node rbtree的结点类型
	typedef tj_RBTree_Node<Value> Node;

	//迭代器所需要的两个结点
	Node* node;
	Node* root;

	//iterator&const_iterator
	typedef tj_RBTree_Iterator<Value, Value&, Value*> iterator;
	typedef tj_RBTree_Iterator<Value, const Value&, const Value*> const_iterator;

	//self 方便后面函数返回类型的编写
	typedef tj_RBTree_Iterator<Value, Ref, Ptr> self;//!!!!注意 后面在类外使用到需要加typname 防止“依赖名称不是一个类型”的报错

	//*************************函数****************************

	//构造
	tj_RBTree_Iterator();//默认
	tj_RBTree_Iterator(const iterator& x);//复制
	tj_RBTree_Iterator(Node* n, Node* r);//带参

	//*和->
	Ref operator*();
	Ptr operator->();

	//++和--
	self& operator++();
	self operator++(int);
	self& operator--();
	self operator--(int);

	//==和!=
	bool operator==(const self& s)const;
	bool operator!=(const self& s)const;

};

//默认构造函数
template<class Value, class Ref, class Ptr>
tj_RBTree_Iterator<Value, Ref, Ptr>::tj_RBTree_Iterator()
{
	//什么也不需要做
}

//带参构造函数
template<class Value, class Ref, class Ptr>
tj_RBTree_Iterator<Value, Ref, Ptr>::tj_RBTree_Iterator(Node* n, Node* r)
{
	node = n;
	root = r;
}

//复制构造函数
template<class Value, class Ref, class Ptr>
tj_RBTree_Iterator<Value, Ref, Ptr>::tj_RBTree_Iterator(const iterator& x)
{
	root = x.root;
	node = x.node;
}

//*
template<class Value, class Ref, class Ptr>
Ref tj_RBTree_Iterator<Value, Ref, Ptr>::operator*()
{
	return node->value_field;
}

//->（唔这个是抄的源码 并不知道要怎么用 往后写写康康可能就知道了叭）
template<class Value, class Ref, class Ptr>
Ptr tj_RBTree_Iterator<Value, Ref, Ptr>::operator->()
{
	return &(operator*());
}

//x++
template<class Value, class Ref, class Ptr>
typename tj_RBTree_Iterator<Value, Ref, Ptr>::self& tj_RBTree_Iterator<Value, Ref, Ptr>::operator++()
{
	if (!node) {//如果之前减到了NULL，则找到第一个元素
		node = root;
		while (node->left)
			node = node->left;
		return *this;
	}
	if (node->right) {//如果有右结点，先向右再一路向左
		node = node->right;//向右
		while (node->left)//一路向左
			node = node->left;
	}
	else {//如果没有右结点
		Node* y = node->parent;//找到父节点
		while (y && node == y->right) {//如果y不为NULL且当前结点是y的右孩子，继续向上
			node = y;
			y = y->parent;
		}
		node = y;//此时y为NULL或后继
	}
	return *this;
}

//++x
template<class Value, class Ref, class Ptr>
typename tj_RBTree_Iterator<Value, Ref, Ptr>::self tj_RBTree_Iterator<Value, Ref, Ptr>::operator++(int)
{
	self tmp(*this);
	++(*this);
	return tmp;
}

//x--
template<class Value, class Ref, class Ptr>
typename tj_RBTree_Iterator<Value, Ref, Ptr>::self& tj_RBTree_Iterator<Value, Ref, Ptr>::operator--()
{
	if (!node) {//如果之前加到了NULL，则找到最后一个元素
		node = root;
		while (node->right)
			node = node->right;
		return *this;
	}
	if (node->left) {//如果有左结点，先向左再一路向右
		node = node->left;//向左
		while (node->right)//一路向右
			node = node->right;
	}
	else {//如果没有左结点
		Node* y = node->parent;//找到父节点
		while (y && node == y->left) {//如果y不为NULL且当前结点是y的左孩子，继续向上
			node = y;
			y = y->parent;
		}
		node = y;//此时y为NULL或前继
	}
	return *this;
}

//x--
template<class Value, class Ref, class Ptr>
typename tj_RBTree_Iterator<Value, Ref, Ptr>::self tj_RBTree_Iterator<Value, Ref, Ptr>::operator--(int)
{
	self tmp(*this);
	--(*this);
	return tmp;
}

//==
template<class Value, class Ref, class Ptr>
bool tj_RBTree_Iterator<Value, Ref, Ptr>::operator==(const self& s)const
{
	return node == s.node;
}

//!=
template<class Value, class Ref, class Ptr>
bool tj_RBTree_Iterator<Value, Ref, Ptr>::operator!=(const self& s)const
{
	return node != s.node;
}