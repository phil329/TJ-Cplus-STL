// 1852024 数强 李兵磊
#include<memory>
#include<iostream>
#include<stdexcept>
#include<initializer_list>
#include<exception>
using namespace std;

/* 双向链表结点定义 */
template<class T>
struct Node {
	T      value;
	Node * pre;
	Node * next;
};

/*********************************************************** 迭代器 ************************************************************/
template<class T>
class tj_iterator {
public:
	Node<T> * ptr;
public:
	tj_iterator() {
		ptr = nullptr;
	}
	tj_iterator(Node<T>*p) {
		ptr = p;
	}
	tj_iterator(const tj_iterator & iter) {
		ptr = iter.ptr;
	}
	tj_iterator& operator++() {
		ptr = ptr->next;
		return *this;
	}
	tj_iterator operator++(int) {
		tj_iterator temp(*this);
		ptr = ptr->next;
		return temp;
	}
	tj_iterator& operator--() {
		ptr = ptr->pre;
		return *this;
	}
	tj_iterator operator--(int) {
		tj_iterator temp(*this);
		ptr = ptr->pre;
		return temp;
	}
	bool operator==(const tj_iterator & other) const {
		return (ptr == other.ptr) ? true : false;
	}
	bool operator!=(const tj_iterator & other) const {
		return (ptr != other.ptr) ? true : false;
	}
	T& operator*() {
		return ptr->value;
	}
	Node<T>* next() {
		return ptr->next;
	}
	Node<T>* pre() {
		return ptr->pre;
	}
};

template<class T>
class tj_reverse_iterator {
public:
	Node<T> *ptr;
public:
	tj_reverse_iterator() {
		ptr = nullptr;
	}
	tj_reverse_iterator(Node<T>*p) {
		ptr = p;
	}
	tj_reverse_iterator(const tj_reverse_iterator & iter) {
		ptr = iter.ptr;
	}
	tj_reverse_iterator& operator++() {
		ptr = ptr->pre;
		return *this;
	}
	tj_reverse_iterator operator++(int) {
		tj_reverse_iterator temp(*this);
		ptr = ptr->pre;
		return temp;
	}
	tj_reverse_iterator& operator--() {
		ptr = ptr->next;
		return *this;
	}
	tj_reverse_iterator operator--(int) {
		tj_reverse_iterator temp(*this);
		ptr = ptr->next;
		return temp;
	}
	bool operator==(const tj_reverse_iterator & other) const {
		return (ptr == other.ptr) ? true : false;
	}
	bool operator!=(const tj_reverse_iterator & other) const {
		return (ptr != other.ptr) ? true : false;
	}
	T& operator*() {
		return ptr->value;
	}
	Node<T>* next() {
		return ptr->next;
	}
	Node<T>* pre() {
		return ptr->pre;
	}
};

template<class T>
using tj_const_reverse_iterator = const tj_reverse_iterator<T>;

template<class T>
using tj_const_iterator = const tj_iterator<T>;


/******************************************************* tj_list定义 ************************************************************/
template<class T, class Alloc = allocator<Node<T>>>
class tj_list{
public:
	Node<T> *head;
	Node<T> *tail;
	size_t len;
	Alloc alloc;

public:

	explicit tj_list();
	explicit tj_list(size_t n);
	explicit tj_list(size_t n, const T & value);
	tj_list(const tj_list<T, Alloc> & a);
	tj_list(initializer_list<T> L);
	~tj_list();


	tj_list<T, Alloc> & operator=(const tj_list<T, Alloc> & a) {
		assign(a);
		return *this;
	}
	tj_list<T, Alloc> & operator= (initializer_list<T> L) {
		assign(L);
		return *this;
	}

	void assign(size_t n, const T & value);
	void assign(const tj_iterator<T> & first, const tj_iterator<T> & last);
	void assign(const tj_list<T, Alloc> & _Other);
	void assign(initializer_list<T> L);


	tj_iterator<T> begin() noexcept {
		return tj_iterator<T>(len?head->next:nullptr);
	}
	tj_iterator<T> end() noexcept {
		return tj_iterator<T>(len ? tail : nullptr);
	}
	tj_const_iterator<T> cbegin() noexcept {
		return tj_const_iterator<T>(len ? head->next : nullptr);
	}
	tj_const_iterator<T> cend() noexcept {
		return tj_const_iterator<T>(len ? tail : nullptr);
	}
	tj_reverse_iterator<T> rbegin() noexcept {
		return tj_reverse_iterator<T>(len?tail->pre:nullptr);
	}
	tj_reverse_iterator<T> rend() noexcept {
		return tj_reverse_iterator<T>(len?head:nullptr);
	}
	tj_const_reverse_iterator<T> crbegin() noexcept {
		return tj_const_reverse_iterator<T>(len ? tail->pre : nullptr);
	}
	tj_const_reverse_iterator<T> crend() noexcept {
		return tj_const_reverse_iterator<T>(len ? head : nullptr);
	}


	T& back() {
		return tail->pre->value;
	}
	T& front() {
		return head->next->value;
	}
	void pop_back();
	void pop_front();
	void push_back(const T & value);
	void push_front(const T & value);


	bool empty() noexcept {
		return len == 0 ? true : false;
	}
	size_t size() noexcept {
		return len;
	}
	size_t max_size() noexcept {
		return alloc.max_size();
	}


	void clear();
	tj_iterator<T> erase(tj_iterator<T> position);
	tj_iterator<T> erase(tj_iterator<T> first, tj_iterator<T> last);
	tj_iterator<T> insert(tj_iterator<T> position, const T & _Value);
	tj_iterator<T> insert(tj_iterator<T> position, size_t n, const T & _Value);
	tj_iterator<T> insert(tj_iterator<T> position, tj_iterator<T> first, tj_iterator<T> last);
	void remove(const T & _Value);
	void remove_if(bool remove_pred_int(T data));


	void reverse();
	void resize(size_t n);
	void resize(size_t n, const  T& _Value);
	void sort();
	void sort(bool compare(T data1, T data2));
	void swap(tj_list<T, Alloc> & Other);
	void unique();
	void unique(bool pred(T data1, T data2));
	void splice(tj_iterator<T> position, tj_list<T, Alloc> & Other);
	void splice(tj_iterator<T> position, tj_list<T, Alloc> & Other, tj_iterator<T> i);
	void splice(tj_iterator<T> position, tj_list<T, Alloc> & Other, tj_iterator<T> first, tj_iterator<T> last);
	void merge(tj_list<T, Alloc> & a);
	void merge(tj_list<T, Alloc> & a, bool compare(T data1, T data2));

};



