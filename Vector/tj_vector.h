// 1852024 数强 李兵磊
#pragma once
#include<memory>
#include<iostream>
#include <string.h>
#include<stdexcept>
#include<initializer_list>
#include<exception>
using namespace std;

#define InitialSize	4
#define IncreaseTime 2
/*********************************************************** 迭代器 ************************************************************/
template<class T>
class tj_iterator {
public:
	T * ptr;
public:
	tj_iterator() {
		ptr = nullptr;
	}
	tj_iterator(T*p) {
		ptr = p;
	}
	tj_iterator(const tj_iterator & iter) {
		ptr = iter.ptr;
	}
	tj_iterator& operator++() {
		ptr = ptr+1;
		return *this;
	}
	tj_iterator operator++(int) {
		tj_iterator temp(*this);
		ptr = ptr+1;
		return temp;
	}
	tj_iterator& operator--() {
		ptr = ptr-1;
		return *this;
	}
	tj_iterator operator--(int) {
		tj_iterator temp(*this);
		ptr = ptr-1;
		return temp;
	}
	tj_iterator<T>& operator=(const tj_iterator & iter) {
		ptr = iter.ptr;
		return *this;
	}
	bool operator==(const tj_iterator & other) const {
		return (ptr == other.ptr) ? true : false;
	}
	bool operator!=(const tj_iterator & other) const {
		return (ptr != other.ptr) ? true : false;
	}
	bool operator<(const tj_iterator & other) const {
		return (ptr < other.ptr) ? true : false;
	}
	bool operator>(const tj_iterator & other) const {
		return (ptr > other.ptr) ? true : false;
	}
	tj_iterator<T>& operator+(int n) {
		ptr = ptr + n;
		return *this;
	}
	tj_iterator<T>& operator-(int n){
		ptr = ptr - n;
		return *this;
	}
	int operator-(const tj_iterator<T>& iter) {
		return ptr-iter.ptr;
	}
	T& operator*() {
		return (*ptr);
	}
	T* next() {
		return *(ptr+1);
	}
	T* pre() {
		return *(ptr-1);
	}
};

template<class T>
class tj_reverse_iterator {
public:
	T *ptr;
public:
	tj_reverse_iterator() {
		ptr = nullptr;
	}
	tj_reverse_iterator(T*p) {
		ptr = p;
	}
	tj_reverse_iterator(const tj_reverse_iterator & iter) {
		ptr = iter.ptr;
	}
	tj_reverse_iterator& operator++() {
		ptr = ptr-1;
		return *this;
	}
	tj_reverse_iterator operator++(int) {
		tj_reverse_iterator temp(*this);
		ptr = ptr-1;
		return temp;
	}
	tj_reverse_iterator& operator--() {
		ptr = ptr+1;
		return *this;
	}
	tj_reverse_iterator operator--(int) {
		tj_reverse_iterator temp(*this);
		ptr = ptr+1;
		return temp;
	}
	tj_iterator<T>& operator=(const tj_iterator<T> & iter) {
		ptr = iter.ptr;
		return *this;
	}
	bool operator==(const tj_reverse_iterator & other) const {
		return (ptr == other.ptr) ? true : false;
	}
	bool operator!=(const tj_reverse_iterator & other) const {
		return (ptr != other.ptr) ? true : false;
	}
	bool operator<(const tj_reverse_iterator & other) const {
		return (ptr < other.ptr) ? true : false;
	}
	bool operator>(const tj_reverse_iterator & other) const {
		return (ptr > other.ptr) ? true : false;
	}
	tj_reverse_iterator<T>& operator+(int n) const {
		ptr = ptr - n;
		return *this;
	}
	tj_reverse_iterator<T>& operator-(int n) const {
		ptr = ptr + n;
		return *this;
	}
	int operator-(const tj_reverse_iterator<T>& iter) {
		return ptr - iter.ptr;
	}
	T& operator*() {
		return *ptr;
	}
	T* next() {
		return *(ptr+1);
	}
	T* pre() {
		return *(ptr-1);
	}
};

template<class T>
using tj_const_reverse_iterator = const tj_reverse_iterator<T>;

template<class T>
using tj_const_iterator = const tj_iterator<T>;


/******************************************************* tj_vector定义 ************************************************************/
template<class T>
class tj_vector:public tj_iterator<T> {	// 通用适配模板
private:
	size_t len;			//该vector已经使用的个数
	size_t max_len;		//为该vector已经分配的空间个数
	allocator<T> Alloc;
public:
	T *head;			//所有线性元素的头指针.
public:

	using iterator = tj_iterator<T>;
	using reverse_iterator = tj_reverse_iterator<T>;
	using const_iterator = tj_const_iterator<T>;
	using const_reverse_iterator = tj_const_reverse_iterator<T>;

	explicit tj_vector();
	explicit tj_vector(size_t n);
	explicit tj_vector(size_t n, const T & value);
	tj_vector(const tj_vector<T>& a);
	tj_vector(initializer_list<T> L);
	~tj_vector();


	tj_vector<T>& operator=(const tj_vector<T>& a) {
		assign(a);
		return *this;
	}
	tj_vector<T>& operator= (initializer_list<T> L) {
		assign(L);
		return *this;
	}

	void assign(size_t n, const T & value);
	void assign(const tj_iterator<T> & first, const tj_iterator<T> & last);
	void assign(const tj_vector<T>& _Other);
	void assign(initializer_list<T> L);

	/********************迭代器相关********************/
	tj_iterator<T> begin() noexcept {
		return tj_iterator<T>(len ? head : nullptr);
	}
	tj_iterator<T> end() noexcept {
		return tj_iterator<T>(len ? head+len: nullptr);
	}
	tj_const_iterator<T> cbegin() noexcept {
		return tj_const_iterator<T>(len ? head : nullptr);
	}
	tj_const_iterator<T> cend() noexcept {
		return tj_const_iterator<T>(len ? head+len : nullptr);
	}
	tj_reverse_iterator<T> rbegin() noexcept {
		return tj_reverse_iterator<T>(len ? head+len-1 : nullptr);
	}
	tj_reverse_iterator<T> rend() noexcept {
		return tj_reverse_iterator<T>(len ? head-1 : nullptr);
	}
	tj_const_reverse_iterator<T> crbegin() noexcept {
		return tj_const_reverse_iterator<T>(len ? head+len-1 : nullptr);
	}
	tj_const_reverse_iterator<T> crend() noexcept {
		return tj_const_reverse_iterator<T>(len ? head-1 : nullptr);
	}


	T& back() {
		return *(head+len-1);
	}
	T& front() {
		return *head;
	}
	T& operator [](size_t n);
	T& at(size_t n);
	T* data() {
		return head;
	}


	void pop_back();
	void push_back(const T & value);


	bool empty() noexcept {
		return len == 0 ? true : false;
	}
	size_t size() noexcept {
		return len;
	}
	size_t capacity() noexcept {
		return max_len;
	}
	size_t max_size() noexcept {
		return Alloc.max_size();
	}
	void resize(size_t n);
	void resize(size_t n, const  T& _Value);
	void reserve(size_t);
	void shrink_to_fit();

	void clear();
	tj_iterator<T> erase(tj_iterator<T> position);
	tj_iterator<T> erase(tj_iterator<T> first, tj_iterator<T> last);
	tj_iterator<T> insert(tj_iterator<T> position, const T & _Value);
	tj_iterator<T> insert(tj_iterator<T> position, size_t n, const T & _Value);
	tj_iterator<T> insert(tj_iterator<T> position, tj_iterator<T> first, tj_iterator<T> last);

	template <class ... Args> void emplace_back(Args && ... args);
	template <class ... Args> tj_iterator<T> emplace(tj_iterator<T>, Args && ...);
	void swap(tj_vector<T>& Other);

	bool operator == (const tj_vector<T>& a) const;
	bool operator != (const tj_vector<T>& a) const;
	bool operator < (const tj_vector<T>& a) const;
	bool operator <= (const tj_vector<T>& a) const;
	bool operator > (const tj_vector<T>& a) const;
	bool operator >= (const tj_vector<T>& a) const;
};


