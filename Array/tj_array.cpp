// 1852024 ��ǿ �����
#include <iostream>
#include "tj_array.h"

//��ʼ�������ƹ���ĳ�Ա����ʵ��
template<typename T, size_t N>
tj_array<T, N>::tj_array() {
	//�չ��캯����ɶҲ������
}
template<typename T, size_t N>
tj_array<T, N>::tj_array(const initializer_list<T> &list) {
	if (N) {
		int i = 0;
		for (auto p = list.begin(); p != list.end(); ++p, ++i) {
			content[i] = *p;
		}
	}
}
template<typename T, size_t N>
tj_array<T, N>::tj_array(const tj_array<T, N> &self) {
	if (N) {
		memcpy(content, self.content, N * sizeof(T));
	}
}
template<typename T, size_t N>
tj_array<T, N>& tj_array<T, N>::operator=(const tj_array<T, N> self) {
	if (self.content)
		memcpy(content, self.content, sizeof(T)*N);
	return *this;
}


//at,fill,swap�ĳ�Ա����ʵ��
template<typename T, size_t N>
T& tj_array<T, N>::at(int i){
	if(i<0||i>=N)
		throw(out_of_range("array::at"));
	else
		return *(content + i);
}
template<typename T, size_t N>
void tj_array<T, N>::fill(T self){
	int i;
	for (i = 0; i < N; i++)
		content[i] = self;
}
template<typename T, size_t N>
void tj_array<T, N>::swap(tj_array<T, N> &a){
	int i;
	T temp;
	for (i = 0; i < N; i++) {
		temp = a.content[i];
		a.content[i] = content[i];
		content[i] = temp;
	}
}



//�Ƚ�������ĳ�Ա����ʵ��
template<typename T, size_t N>
bool tj_array<T, N>::operator!=(const tj_array<T, N> &a) {
	int i;
	for (i = 0; i < N; i++) {
		if (content[i] != a.content[i])
			return true;
	}
	return false;
}
template<typename T, size_t N>
bool tj_array<T, N>::operator==(const tj_array<T, N> &a)
{
	int i;
	for (i = 0; i < N; i++) {
		if (content[i] != a.content[i])
			return false;
	}
	return true;
}
template<typename T, size_t N>
bool tj_array<T, N>::operator>(const tj_array<T, N> &a)
{
	int i;
	for (i = 0; i < N; i++) {
		if (content[i] > a.content[i])
			return true;
		else if (content[i] < a.content[i])
			return false;
	}
	return false;
}
template<typename T, size_t N>
bool tj_array<T, N>::operator<(const tj_array<T, N> &a){
	int i;
	for (i = 0; i < N; i++) {
		if (content[i] < a.content[i])
			return true;
		else if (content[i] > a.content[i])
			return false;
	}
	return false;
}
template<typename T, size_t N>
bool tj_array<T, N>::operator<=(const tj_array<T, N> &a)
{
	int i;
	for (i = 0; i < N; i++) {
		if (content[i] < a.content[i])
			return true;
		else if (content[i] > a.content[i])
			return false;
	}
	return true;

}
template<typename T, size_t N>
bool tj_array<T, N>::operator>=(const tj_array<T, N> &a)
{
	int i;
	for (i = 0; i < N; i++) {
		if (content[i] > a.content[i])
			return true;
		else if (content[i] < a.content[i])
			return false;
	}
	return true;
}



//get����������ʵ��
template<size_t n, typename T, size_t N>
const T& get(const tj_array<T, N> &a){
	return a.content[n];
}

template<size_t n, typename T, size_t N>
T& get(tj_array<T, N> &a){
	return a.content[n];
}