/*��� 1851846 ��ǿ*/
/********************************************

RBTree�ĵ�����

����ģ�壺	Value����ֵ������
			Ref����ֵ������
			Ptr����ֵ��ָ��

����������	root(����tj_RBTree�ĸ����)(������++��--��NULLʱ�Ĳ���)��
			node(������ָ��Ľ��ָ��)

����������	���캯������Ĭ�ϡ����ơ�����
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
	//Ϊ��ʹ��reverse_iterator���е�typedef
	typedef Value value_type;
	typedef Ref reference;
	typedef Ptr pointer;
	typedef bidirectional_iterator_tag iterator_category;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;


	//Node rbtree�Ľ������
	typedef tj_RBTree_Node<Value> Node;

	//����������Ҫ���������
	Node* node;
	Node* root;

	//iterator&const_iterator
	typedef tj_RBTree_Iterator<Value, Value&, Value*> iterator;
	typedef tj_RBTree_Iterator<Value, const Value&, const Value*> const_iterator;

	//self ������溯���������͵ı�д
	typedef tj_RBTree_Iterator<Value, Ref, Ptr> self;//!!!!ע�� ����������ʹ�õ���Ҫ��typname ��ֹ���������Ʋ���һ�����͡��ı���

	//*************************����****************************

	//����
	tj_RBTree_Iterator();//Ĭ��
	tj_RBTree_Iterator(const iterator& x);//����
	tj_RBTree_Iterator(Node* n, Node* r);//����

	//*��->
	Ref operator*();
	Ptr operator->();

	//++��--
	self& operator++();
	self operator++(int);
	self& operator--();
	self operator--(int);

	//==��!=
	bool operator==(const self& s)const;
	bool operator!=(const self& s)const;

};

//Ĭ�Ϲ��캯��
template<class Value, class Ref, class Ptr>
tj_RBTree_Iterator<Value, Ref, Ptr>::tj_RBTree_Iterator()
{
	//ʲôҲ����Ҫ��
}

//���ι��캯��
template<class Value, class Ref, class Ptr>
tj_RBTree_Iterator<Value, Ref, Ptr>::tj_RBTree_Iterator(Node* n, Node* r)
{
	node = n;
	root = r;
}

//���ƹ��캯��
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

//->��������ǳ���Դ�� ����֪��Ҫ��ô�� ����дд�������ܾ�֪���˰ȣ�
template<class Value, class Ref, class Ptr>
Ptr tj_RBTree_Iterator<Value, Ref, Ptr>::operator->()
{
	return &(operator*());
}

//x++
template<class Value, class Ref, class Ptr>
typename tj_RBTree_Iterator<Value, Ref, Ptr>::self& tj_RBTree_Iterator<Value, Ref, Ptr>::operator++()
{
	if (!node) {//���֮ǰ������NULL�����ҵ���һ��Ԫ��
		node = root;
		while (node->left)
			node = node->left;
		return *this;
	}
	if (node->right) {//������ҽ�㣬��������һ·����
		node = node->right;//����
		while (node->left)//һ·����
			node = node->left;
	}
	else {//���û���ҽ��
		Node* y = node->parent;//�ҵ����ڵ�
		while (y && node == y->right) {//���y��ΪNULL�ҵ�ǰ�����y���Һ��ӣ���������
			node = y;
			y = y->parent;
		}
		node = y;//��ʱyΪNULL����
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
	if (!node) {//���֮ǰ�ӵ���NULL�����ҵ����һ��Ԫ��
		node = root;
		while (node->right)
			node = node->right;
		return *this;
	}
	if (node->left) {//��������㣬��������һ·����
		node = node->left;//����
		while (node->right)//һ·����
			node = node->right;
	}
	else {//���û������
		Node* y = node->parent;//�ҵ����ڵ�
		while (y && node == y->left) {//���y��ΪNULL�ҵ�ǰ�����y�����ӣ���������
			node = y;
			y = y->parent;
		}
		node = y;//��ʱyΪNULL��ǰ��
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