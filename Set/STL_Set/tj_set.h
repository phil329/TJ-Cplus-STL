/*鞠璇 1851846 数强*/
/********************************************

set

函数模板：	Value——值的类型
			Compare——比较类

包含变量：	继承RBTree
			value_compare结构体

包含函数：	构造函数（4个）
			析构函数
			=
			insert（6个）
			erase（3个）
			swap
			clear
			emplace
			emplace_hint
			key_compare
			value_compare
			find
			lower_bound
			upper_bound
			equal_range
			比较使用的友函数

*********************************************/
#pragma once
#include "tj_RBTree.h"
#include <initializer_list>
#include <utility>


template<class Value, class Compare = less<Value>>
class tj_set :public RBTree<Value, Value, Compare>//继承RBTree
{
public:
	//value_type和value_compare
	typedef   Value value_type;
	/*typedef struct {
		bool operator() (const value_type& a, const value_type& b) const
		{
			return Compare()(a, b);
		}

	}value_compare;*///这么写在C++20标准下不对了
	struct value_compare {
		bool operator() (const value_type& a, const value_type& b) const
		{
			return Compare()(a, b);
		}

	};
	typedef   tj_RBTree_Node<value_type> Node;//结点
	//迭代器
	typedef   tj_RBTree_Iterator<value_type, value_type&, value_type*>  iterator;
	typedef   tj_RBTree_Iterator<value_type, const value_type&, const value_type*>  const_iterator;
	typedef   std::reverse_iterator<iterator> reverse_iterator;
	typedef   std::reverse_iterator<const_iterator> const_reverse_iterator;

	//*********************函数**********************

	//构造函数
	tj_set() :RBTree<value_type, value_type, Compare>() {}
	tj_set(const tj_set& s);
	template <class Iterator>
	tj_set(Iterator begin, Iterator end);
	tj_set(std::initializer_list<value_type> list);

	//析构函数（直接使用rbtree的）
	~tj_set() {}

	//=
	tj_set& operator=(const tj_set& s);

	//begin\end\rbegin\rend\cbegin\cend\crbegin\crend

	//empty\size\max_size

	//insert
	pair<iterator, bool> insert(const Value& value);
	pair<iterator, bool> insert(Value&& value);//&&为右值引用
	iterator insert(const_iterator position, const Value& value);
	iterator insert(const_iterator position, Value&& value);
	template <class Iterator>
	void insert(Iterator first, Iterator last);
	void insert(std::initializer_list<value_type> list);

	//erase
	iterator  erase(const_iterator position);
	size_t erase(const Value& val);
	iterator  erase(const_iterator first, const_iterator last);

	//swap
	void swap(tj_set& x);

	//clear
	void clear();

	//emplace
	template <class... Args>//参数可变函数模板
	pair<iterator, bool> emplace(Args&&... args);

	//emplace_hint
	template <class... Args>//参数可变函数模板
	iterator emplace_hint(const_iterator position, Args&&... args);

	//key_comp
	Compare key_comp() const;

	//value_comp
	value_compare value_comp() const;

	//find
	iterator find(const Value& value);

	//lower_bound
	iterator lower_bound(const Value& value);

	//upper_bound
	iterator upper_bound(const Value& value);

	//equal_range
	pair<iterator, iterator> equal_range(const Value& value);


	//带函数模板的友函数声明要加上<>.。。。它不知道为啥报错。。。但运行没问题
	//linux报错的地方就运行不了了。。。。改成内置可以运行。。。为啥呢
	//两个set是否相等 ==
	friend bool operator==(const tj_set& x, const tj_set& y)
	{
		auto f1 = x.begin(), f2 = y.begin();
		auto e1 = x.end(), e2 = y.end();
		for (; f1 != e1 && f2 != e2; f1++, f2++) {
			if (*f1 != *f2)
				return false;
		}
		return (f1 == e1 && f2 == e2);

	}

	//按照字典序比较两个set <
	friend bool operator< (const tj_set& x, const tj_set& y)
	{
		auto f1 = x.begin(), f2 = y.begin();
		auto e1 = x.end(), e2 = y.end();
		for (; f1 != e1 && f2 != e2; f1++, f2++) {
			if (*f1 != *f2)
				return *f1 < *f2;
		}
		if (f2 == e2)
			return false;
		return true;
	}

	//按照字典序比较两个set >
	friend bool operator> (const tj_set& x, const tj_set& y)
	{
		auto f1 = x.begin(), f2 = y.begin();
		auto e1 = x.end(), e2 = y.end();
		for (; f1 != e1 && f2 != e2; f1++, f2++) {
			if (*f1 != *f2)
				return *f1 > * f2;
		}
		if (f1 == e1)
			return false;
		return true;
	}

	//按照字典序比较两个set !=
	friend bool operator!= (const tj_set& x, const tj_set& y)
	{
		return !(x == y);
	}

	//按照字典序比较两个set >=
	friend bool operator>= (const tj_set& x, const tj_set& y)
	{
		return !(x < y);
	}

	//按照字典序比较两个set <=
	friend bool operator<= (const tj_set& x, const tj_set& y)
	{
		return !(x > y);
	}

};

//复制构造
template<class Value, class Compare>
tj_set<Value, Compare>::tj_set(const tj_set& s)
{
	insert(s.begin(), s.end());
}

//通过迭代器构造
template<class Value, class Compare>
template <class Iterator>
tj_set<Value, Compare>::tj_set(Iterator begin, Iterator end)
{
	insert(begin, end);
}

//通过initializer_list构造（花括号）
template<class Value, class Compare>
tj_set<Value, Compare>::tj_set(std::initializer_list<Value> list)
{
	insert(list.begin(), list.end());
};

//=
template<class Value, class Compare>
tj_set<Value, Compare>& tj_set<Value, Compare>::operator=(const tj_set& s)
{
	//当当前的不为s时
	if (this != &s) {
		this->destroy();
		insert(s.begin(), s.end());
	}
	return *this;
}

//insert 1-1
template<class Value, class Compare>
pair<typename tj_set<Value, Compare>::iterator, bool> tj_set<Value, Compare>::insert(const Value& value)
{
	bool r = this->rb_insert(value);
	return pair<iterator, bool>(find(value), r);
}

//insert 1-2
template<class Value, class Compare>
pair<typename tj_set<Value, Compare>::iterator, bool> tj_set<Value, Compare>::insert(Value&& value)
{
	bool r = this->rb_insert(value);
	return pair<iterator, bool>(find(value), r);
}

//insert 2-1
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator tj_set<Value, Compare>::insert(const_iterator position, const Value& value)
{
	bool r = this->rb_insert(value);
	return find(value);
}

//insert 2-2
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator tj_set<Value, Compare>::insert(const_iterator position, Value&& value)
{
	bool r = this->rb_insert(value);
	return find(value);
}

//insert 3
template<class Value, class Compare>
template <class Iterator>
void tj_set<Value, Compare>::insert(Iterator first, Iterator last)
{
	while (first != last) {
		this->rb_insert(*first);
		first++;
	}
}

//insert 4
template<class Value, class Compare>
void tj_set<Value, Compare>::insert(std::initializer_list<Value> list)
{
	insert(list.begin(), list.end());
}

//erase 1
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator  tj_set<Value, Compare>::erase(const_iterator position)
{
	iterator tmp(position.node, position.root);
	tmp = tmp++;
	this->rb_erase(*position);

	return tmp;
}

//erase 2
template<class Value, class Compare>
size_t tj_set<Value, Compare>::erase(const Value& value)
{
	Node* tmp = this->search(value);
	if (!tmp)
		return 0;
	this->rb_erase(tmp->value_field);
	return 1;
}

//erase 3
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator  tj_set<Value, Compare>::erase(const_iterator first, const_iterator last)
{
	iterator f = iterator(first.node, first.root);
	while (f.node != last.node) {
		iterator tmp = f;
		f++;
		this->rb_erase(*tmp);
	}
	return f;
}

//swap
template<class Value, class Compare>
void tj_set<Value, Compare>::swap(tj_set& x)
{
	auto tmp = this->root;
	this->root = x.root;
	x.root = tmp;
}

//clear
template<class Value, class Compare>
void tj_set<Value, Compare>::clear()
{
	this->destroy();
}

//emplace
template<class Value, class Compare>
template <class... Args>//参数可变函数模板
pair<typename tj_set<Value, Compare>::iterator, bool> tj_set<Value, Compare>::emplace(Args&&... args)
{
	return insert(value_type(args...));
}

//emplace_hint
template<class Value, class Compare>
template <class... Args>//参数可变函数模板
typename tj_set<Value, Compare>::iterator tj_set<Value, Compare>::emplace_hint(const_iterator position, Args&&... args)
{
	return insert(position, value_type(args...));

}

//key_comp
template<class Value, class Compare>
Compare tj_set<Value, Compare>::key_comp() const
{
	return Compare();
}

//value_comp
template<class Value, class Compare>
typename tj_set<Value, Compare>::value_compare tj_set<Value, Compare>::value_comp() const
{
	return value_compare();
}

//find
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator tj_set<Value, Compare>::find(const Value& value)
{
	return iterator(this->search(value), this->root);
}

//lower_bound
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator tj_set<Value, Compare>::lower_bound(const Value& value) {
	auto tmp = equal_range(value);
	return tmp.first;
}

//upper_bound
template<class Value, class Compare>
typename tj_set<Value, Compare>::iterator tj_set<Value, Compare>::upper_bound(const Value& value) {
	auto tmp = equal_range(value);
	return tmp.second;
}

//equal_range
template<class Value, class Compare>
pair<typename tj_set<Value, Compare>::iterator, typename  tj_set<Value, Compare>::iterator> tj_set<Value, Compare>::equal_range(const Value& value) {
	Node* first = this->search(value);

	if (first) {
		iterator f(first, this->root);
		auto tmp = f;
		return pair<iterator, iterator>(tmp, ++f);
	}
	//如果value不存在
	else {
		Node* y = NULL;
		Node* x = this->root;
		//寻找value的下一个元素
		while (x != NULL)
		{
			y = x;
			if (Compare()(value, x->value_field))
				x = x->left;
			else
				x = x->right;
		}
		iterator result(y, this->root);
		if (Compare()(value, y->value_field))
			return pair<iterator, iterator>(result, result);
		else {
			++result;
			return pair<iterator, iterator>(result, result);

		}
	}

}
/*
//两个set是否相等 ==
template<class Value, class Compare>
bool operator== (const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	auto f1 = x.begin(), f2 = y.begin();
	auto e1 = x.end(), e2 = y.end();
	for (; f1 != e1 && f2 != e2; f1++, f2++) {
		if (*f1 != *f2)
			return false;
	}
	return (f1 == e1 && f2 == e2);
}

//按照字典序比较两个set <
template<class Value, class Compare>
bool operator< <>(const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	auto f1 = x.begin(), f2 = y.begin();
	auto e1 = x.end(), e2 = y.end();
	for (; f1 != e1 && f2 != e2; f1++, f2++) {
		if (*f1 != *f2)
			return *f1 < *f2;
	}
	if (f2 == e2)
		return false;
	return true;
}

//按照字典序比较两个set >
template<class Value, class Compare>
bool operator> (const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	auto f1 = x.begin(), f2 = y.begin();
	auto e1 = x.end(), e2 = y.end();
	for (; f1 != e1 && f2 != e2; f1++, f2++) {
		if (*f1 != *f2)
			return *f1 > * f2;
	}
	if (f1 == e1)
		return false;
	return true;
}

//按照字典序比较两个set !=
template<class Value, class Compare>
bool operator!= (const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	return !(x == y);
}

//按照字典序比较两个set >=
template<class Value, class Compare>
bool operator>= (const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	return !(x < y);
}

//按照字典序比较两个set <=
template<class Value, class Compare>
bool operator<= <>(const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	return !(x > y);
}
*/