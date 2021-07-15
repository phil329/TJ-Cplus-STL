/*��� 1851846 ��ǿ*/
/********************************************

RBTree��һ�����

����ģ�壺	Value����ֵ������

����������	value_field(ֵ)��
			color(��ɫ)��
			parent(���ڵ�)��
			left\right(���Һ��ӽ��)

����������	���ι��캯��

*********************************************/
#pragma once
#include <iostream>
using namespace std;

enum  tj_RBTree_Color { RED, BLACK };

template <class Value>
class tj_RBTree_Node {
public:
	Value value_field;	//���ļ�ֵ
	tj_RBTree_Color color;	//������ɫ
	tj_RBTree_Node* parent;	//���ڵ�
	tj_RBTree_Node* left;	//����
	tj_RBTree_Node* right;	//�Һ���

	//���캯��
	tj_RBTree_Node(Value value, tj_RBTree_Color c, tj_RBTree_Node* p, tj_RBTree_Node* l, tj_RBTree_Node* r);

};
template <class Value>
tj_RBTree_Node<Value>::tj_RBTree_Node(Value value, tj_RBTree_Color c, tj_RBTree_Node* p, tj_RBTree_Node* l, tj_RBTree_Node* r)
{
	value_field = value;
	color = c;
	parent = p;
	left = l;
	right = r;
}
