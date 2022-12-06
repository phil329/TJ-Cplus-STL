// 1852024 数强 李兵磊
#pragma once
#include<iostream>
#include <initializer_list>
#include "tj_student_array.h"
#include<string.h>
#include<exception>
#include <stdexcept> // std::out_of_range
using namespace std;

template<typename T, size_t N>
class tj_array{
public:
	T content[N ? N : 1];
	typedef T* tj_iterator;
	typedef const T* tj_const_iterator;
	typedef std::reverse_iterator<tj_iterator>  tj_reverse_iterator;
	typedef std::reverse_iterator<tj_const_iterator>   tj_const_reverse_iterator;
	//这种利用迭代器的方法是鞠璇给出的解决案例。

public:
	//构造及析构函数
	tj_array();
	tj_array(const initializer_list<T> &c);
	tj_array(const tj_array &self);
	int size() {
		return N;
	}
	int max_size() {
		return N;
	}
	bool empty() {
		return N ? false : true;
	}
	tj_array& operator=(const tj_array a);
	tj_iterator begin(){
		return (tj_iterator)(content);
	}
	tj_iterator end(){
		return (tj_iterator)(content + N);
	}
	tj_const_iterator cbegin() const{
		return(tj_const_iterator)(content);
	}
	tj_const_iterator cend() const {
		return(tj_const_iterator)(content + N);
	}
	tj_reverse_iterator rbegin(){
		return(tj_reverse_iterator)(content + N);
	}
	tj_reverse_iterator rend(){
		return(tj_reverse_iterator)(content);
	}
	tj_const_reverse_iterator crend() const{
		return(tj_const_reverse_iterator)(content);
	}
	tj_const_reverse_iterator crbegin() const{
		return(tj_const_reverse_iterator)(content + N);

	}
	T& operator[](int i) {
		return *(content + i);
	}
	T& front() noexcept{
		return *content;
	}
	T& back() noexcept {
		return *(content+N-1);
	}
	T* data() noexcept {
		return content;
	}
	T& at(int i);
	void fill(T c);
	void swap(tj_array &a);

	bool operator!=(const tj_array<T, N> &a);

	bool operator==(const tj_array<T, N>& a);

	bool operator>(const tj_array<T, N>& a);

	bool operator<(const tj_array<T, N>& a);

	bool operator<=(const tj_array<T, N>& a);

	bool operator>=(const tj_array<T, N>& a);

};