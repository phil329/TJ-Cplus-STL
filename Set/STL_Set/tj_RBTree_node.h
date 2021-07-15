/*鞠璇 1851846 数强*/
/********************************************

RBTree的一个结点

函数模板：	Value——值的类型

包含变量：	value_field(值)、
			color(颜色)、
			parent(父节点)、
			left\right(左右孩子结点)

包含函数：	带参构造函数

*********************************************/
#pragma once
#include <iostream>
using namespace std;

enum  tj_RBTree_Color { RED, BLACK };

template <class Value>
class tj_RBTree_Node {
public:
	Value value_field;	//结点的键值
	tj_RBTree_Color color;	//结点的颜色
	tj_RBTree_Node* parent;	//父节点
	tj_RBTree_Node* left;	//左孩子
	tj_RBTree_Node* right;	//右孩子

	//构造函数
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
