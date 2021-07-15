//1852024 数强 李兵磊
#pragma once
#include "tj_rb_tree.cpp"


template <
	class Key,                              // multimap::key_type
	class T,                                       // multimap::mapped_type
	class Compare = less<const Key>,                     // multimap::key_compare
	class Alloc = allocator<pair<const Key, T> >   // multimap::allocator_type
>
class tj_multimap {
private:
	typedef pair<Key, T> value_type;
	typedef pair<const Key, T> cvalue_type;
	tj_rb_tree<value_type, Compare> tree;

public:
	//无参构造函数
	tj_multimap() : tree(Compare()) {}

	//initializer_list 构造函数
	tj_multimap(const initializer_list<value_type>& init) : tree(Compare()) {
		for (auto it = init.begin(); it != init.end(); it++)
			tree.insert_equal(*it);
	}
	tj_multimap(const initializer_list<cvalue_type>& init) : tree(Compare()) {
		for (auto it = init.begin(); it != init.end(); it++)
			tree.insert_equal(*it);
	}
	//迭代器构造函数
	tj_multimap(typename tj_rb_tree<value_type, Compare>::iterator first, typename tj_rb_tree<value_type, Compare>::iterator last) : tree(Compare()) {
		for (auto it = first; it != last; it++)
			tree.insert_equal(*it);
	}

	//复制构造函数
	tj_multimap(const tj_multimap<value_type, Compare>& x) : tree(x.tree) {}

	//重载赋值运算符
	tj_multimap<Key, T, Compare, Alloc>& operator = (const tj_multimap<Key, T, Compare, Alloc>& x) {
		tree = x.tree;
		return *this;
	}

	//重载赋值运算符
	tj_multimap<Key, T, Compare, Alloc>& operator = (const initializer_list<value_type>& init) {
		for (auto it = init.begin(); it != init.end(); it++)
			tree.insert_equal(*it);
		return *this;
	}
	//析构函数
	~tj_multimap() {
		tree.clear();
	}

	//迭代器函数
	typename tj_rb_tree<value_type, Compare>::iterator begin() { return tree.begin(); }
	typename tj_rb_tree<value_type, Compare>::iterator cbegin() { return tree.begin(); }
	typename tj_rb_tree<value_type, Compare>::iterator end() { return tree.end(); }
	typename tj_rb_tree<value_type, Compare>::iterator cend() { return tree.end(); }
	typename tj_rb_tree<value_type, Compare>::reverse_iterator rbegin() { return tree.rbegin(); }
	typename tj_rb_tree<value_type, Compare>::reverse_iterator crbegin() { return tree.rbegin(); }
	typename tj_rb_tree<value_type, Compare>::reverse_iterator rend() { return tree.rend(); }
	typename tj_rb_tree<value_type, Compare>::reverse_iterator crend() { return tree.rend(); }


	//交换函数
	void swap(tj_multimap<Key, T, Compare, Alloc>& x) { tree.swap(x.tree); }

	//大小函数
	size_t size() { return tree.size(); }
	size_t max_size() { return tree.max_size(); }
	bool empty() { return tree.empty(); }
	void clear() { tree.clear(); }

	//比较函数
	Compare key_comp() { return tree.key_comp(); }
	less<cvalue_type> value_comp() {
		less<cvalue_type> value_compare;
		return value_compare;
	//	return tree.key_comp(); 
	}

	//插入函数
	typename tj_rb_tree<value_type, Compare>::iterator emplace(const value_type& x) { return tree.insert_equal(x); }
	typename tj_rb_tree<value_type, Compare>::iterator emplace(const Key& key, const T& value) {
		return tree.insert_equal(make_pair(key, value));
	}
	typename tj_rb_tree<value_type, Compare>::iterator emplace_hint(typename tj_rb_tree<value_type, Compare>::iterator pos,const value_type& x) { return tree.insert_equal(x); }
	typename tj_rb_tree<value_type, Compare>::iterator emplace_hint(typename tj_rb_tree<value_type, Compare>::iterator pos, const Key& key, const T& value) {
		return tree.insert_equal(make_pair(key, value));
	}
	typename tj_rb_tree<value_type, Compare>::iterator insert(const value_type& x) { return tree.insert_equal(x); }
	void insert(typename tj_rb_tree<value_type, Compare>::iterator first, typename tj_rb_tree<value_type, Compare>::iterator last) {
		for (auto it = first; it != last; it++)
			tree.insert_equal(*it);
	}
	void insert(const initializer_list<value_type>& init) {
		for (auto it = init.begin(); it != init.end(); it++)
			tree.insert_equal(*it);
	}

	//查找函数
	typename tj_rb_tree<value_type, Compare>::iterator find(const value_type& x) { return tree.find(x); }
	typename tj_rb_tree<value_type, Compare>::iterator find(const Key& x) { return tree.find(make_pair(x, 0)); }

	//删除函数
	size_t erase(const value_type& x) { return tree.erase(x); }
	size_t erase(const Key& x) { return tree.erase(make_pair(x,0)); }
	typename tj_rb_tree<value_type, Compare>::iterator erase(typename tj_rb_tree<value_type, Compare>::iterator iter) { return tree.erase(iter); }
	void erase(typename tj_rb_tree<value_type, Compare>::iterator first, typename tj_rb_tree<value_type, Compare>::iterator last) { tree.erase(first, last); }

	//计数函数
	size_t count(const Key& x) { return tree.count(make_pair(x, 0)); };
	pair<typename tj_rb_tree<value_type, Compare>::iterator, typename tj_rb_tree<value_type, Compare>::iterator> equal_range(const value_type& x) { return tree.equal_range(x); }
	pair<typename tj_rb_tree<value_type, Compare>::iterator, typename tj_rb_tree<value_type, Compare>::iterator> equal_range(const Key& x) { return tree.equal_range(make_pair(x, 0)); }
	typename tj_rb_tree<value_type, Compare>::iterator lower_bound(const value_type& x) { return tree.lower_bound(x); }
	typename tj_rb_tree<value_type, Compare>::iterator upper_bound(const value_type& x) { return tree.upper_bound(x); }
	typename tj_rb_tree<value_type, Compare>::iterator lower_bound(const Key& x) {
		return tree.lower_bound(make_pair(x, 0));
	}
	typename tj_rb_tree<value_type, Compare>::iterator upper_bound(const Key& x) {
		return tree.upper_bound(make_pair(x, 0));
	}

	//重载比较运算符
	bool operator == (const tj_multimap<Key, T, Compare, Alloc>& x) { return tree == x.tree; }
	bool operator != (const tj_multimap<Key, T, Compare, Alloc>& x) { return tree != x.tree; }
	bool operator < (const tj_multimap<Key, T, Compare, Alloc>& x) { return tree < x.tree; }
	bool operator <= (const tj_multimap<Key, T, Compare, Alloc>& x) { return tree <= x.tree; }
	bool operator > (const tj_multimap<Key, T, Compare, Alloc>& x) { return tree > x.tree; }
	bool operator >= (const tj_multimap<Key, T, Compare, Alloc>& x) { return tree >= x.tree; }
};
