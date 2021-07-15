/*��� 1851846 ��ǿ*/
/********************************************

set

����ģ�壺	Value����ֵ������
			Compare�����Ƚ���

����������	�̳�RBTree
			value_compare�ṹ��

����������	���캯����4����
			��������
			=
			insert��6����
			erase��3����
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
			�Ƚ�ʹ�õ��Ѻ���

*********************************************/
#pragma once
#include "tj_RBTree.h"
#include <initializer_list>
#include <utility>


template<class Value, class Compare = less<Value>>
class tj_set :public RBTree<Value, Value, Compare>//�̳�RBTree
{
public:
	//value_type��value_compare
	typedef   Value value_type;
	/*typedef struct {
		bool operator() (const value_type& a, const value_type& b) const
		{
			return Compare()(a, b);
		}

	}value_compare;*///��ôд��C++20��׼�²�����
	struct value_compare {
		bool operator() (const value_type& a, const value_type& b) const
		{
			return Compare()(a, b);
		}

	};
	typedef   tj_RBTree_Node<value_type> Node;//���
	//������
	typedef   tj_RBTree_Iterator<value_type, value_type&, value_type*>  iterator;
	typedef   tj_RBTree_Iterator<value_type, const value_type&, const value_type*>  const_iterator;
	typedef   std::reverse_iterator<iterator> reverse_iterator;
	typedef   std::reverse_iterator<const_iterator> const_reverse_iterator;

	//*********************����**********************

	//���캯��
	tj_set() :RBTree<value_type, value_type, Compare>() {}
	tj_set(const tj_set& s);
	template <class Iterator>
	tj_set(Iterator begin, Iterator end);
	tj_set(std::initializer_list<value_type> list);

	//����������ֱ��ʹ��rbtree�ģ�
	~tj_set() {}

	//=
	tj_set& operator=(const tj_set& s);

	//begin\end\rbegin\rend\cbegin\cend\crbegin\crend

	//empty\size\max_size

	//insert
	pair<iterator, bool> insert(const Value& value);
	pair<iterator, bool> insert(Value&& value);//&&Ϊ��ֵ����
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
	template <class... Args>//�����ɱ亯��ģ��
	pair<iterator, bool> emplace(Args&&... args);

	//emplace_hint
	template <class... Args>//�����ɱ亯��ģ��
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


	//������ģ����Ѻ�������Ҫ����<>.����������֪��Ϊɶ��������������û����
	//linux����ĵط������в����ˡ��������ĳ����ÿ������С�����Ϊɶ��
	//����set�Ƿ���� ==
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

	//�����ֵ���Ƚ�����set <
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

	//�����ֵ���Ƚ�����set >
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

	//�����ֵ���Ƚ�����set !=
	friend bool operator!= (const tj_set& x, const tj_set& y)
	{
		return !(x == y);
	}

	//�����ֵ���Ƚ�����set >=
	friend bool operator>= (const tj_set& x, const tj_set& y)
	{
		return !(x < y);
	}

	//�����ֵ���Ƚ�����set <=
	friend bool operator<= (const tj_set& x, const tj_set& y)
	{
		return !(x > y);
	}

};

//���ƹ���
template<class Value, class Compare>
tj_set<Value, Compare>::tj_set(const tj_set& s)
{
	insert(s.begin(), s.end());
}

//ͨ������������
template<class Value, class Compare>
template <class Iterator>
tj_set<Value, Compare>::tj_set(Iterator begin, Iterator end)
{
	insert(begin, end);
}

//ͨ��initializer_list���죨�����ţ�
template<class Value, class Compare>
tj_set<Value, Compare>::tj_set(std::initializer_list<Value> list)
{
	insert(list.begin(), list.end());
};

//=
template<class Value, class Compare>
tj_set<Value, Compare>& tj_set<Value, Compare>::operator=(const tj_set& s)
{
	//����ǰ�Ĳ�Ϊsʱ
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
template <class... Args>//�����ɱ亯��ģ��
pair<typename tj_set<Value, Compare>::iterator, bool> tj_set<Value, Compare>::emplace(Args&&... args)
{
	return insert(value_type(args...));
}

//emplace_hint
template<class Value, class Compare>
template <class... Args>//�����ɱ亯��ģ��
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
	//���value������
	else {
		Node* y = NULL;
		Node* x = this->root;
		//Ѱ��value����һ��Ԫ��
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
//����set�Ƿ���� ==
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

//�����ֵ���Ƚ�����set <
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

//�����ֵ���Ƚ�����set >
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

//�����ֵ���Ƚ�����set !=
template<class Value, class Compare>
bool operator!= (const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	return !(x == y);
}

//�����ֵ���Ƚ�����set >=
template<class Value, class Compare>
bool operator>= (const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	return !(x < y);
}

//�����ֵ���Ƚ�����set <=
template<class Value, class Compare>
bool operator<= <>(const tj_set<Value, Compare>& x, const tj_set<Value, Compare>& y)
{
	return !(x > y);
}
*/