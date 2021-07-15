// 1852024 数强 李兵磊
#include "tj_vector.h"
using namespace std;

/*****************************************************************构造和析构**********************************************************/
template<class T>
tj_vector<T>::tj_vector() {
	head = new T[InitialSize];
	len = 0;
	max_len = InitialSize;
}

template<class T>
tj_vector<T>::tj_vector(size_t n) {
	if (n < InitialSize) {
		head = new T[InitialSize];
		len = n;
		max_len = InitialSize;
	}
	else {
		head = new T[n*IncreaseTime];
		len = n;
		max_len = n * IncreaseTime;
	}
	size_t i;
	for (i = 0; i < n; i++) {
		head[i] = T();
	}
}

template<class T>
tj_vector<T>::tj_vector(size_t n, const T & value) {
	if (n < InitialSize) {
		head = new T[InitialSize];
		len = n;
		max_len = InitialSize;
	}
	else {
		head = new T[n*IncreaseTime];
		len = n;
		max_len = n * IncreaseTime;
	}
	size_t i;
	for (i = 0; i < n; i++) {
		head[i] = value;
	}
}

template<class T>
tj_vector<T>::tj_vector(const tj_vector<T> & a) {
	size_t n = a.len, i;
	if (n < InitialSize) {
		head = new T[InitialSize];
		len = n;
		max_len = InitialSize;
	}
	else {
		head = new T[n*IncreaseTime];
		len = n;
		max_len = n * IncreaseTime;
	}
	for (i = 0; i < n; i++) {
		head[i] = a.head[i];
	}
}

template<class T>
tj_vector<T>::tj_vector(initializer_list<T> L) {
	auto iter = L.begin();
	size_t n = L.size(), i;
	if (n < InitialSize) {
		head = new T[InitialSize];
		len = n;
		max_len = InitialSize;
	}
	else {
		head = new T[n*IncreaseTime];
		len = n;
		max_len = n * IncreaseTime;
	}
	for (i = 0; i < n; i++) {
		head[i] = *iter;
		iter++;
	}
}

template<class T>
tj_vector<T>::~tj_vector() {
	//delete[]head;
	len = 0;
	max_len = 0;
}

/******************************************************************* assign赋值 ***********************************************/
template<class T>
void tj_vector<T>::assign(size_t n, const T & value) {
	clear();
	if (n < max_len) {
		len = n;
		max_len = InitialSize;
	}//内存够使
	else {
		//delete[]head;
		head = new T[n*IncreaseTime];
		len = n;
		max_len = n * IncreaseTime;
	}
	size_t i;
	for (i = 0; i < n; i++) {
		head[i] = value;
	}
	return;
}

template<class T>
void tj_vector<T>::assign(const tj_iterator<T> & from, const tj_iterator<T> & to) {
	clear();
	auto iter = from;
	while (1) {
		push_back(*iter);
		iter++;
		if (iter == to)
			return;
	}
}

template<class T>
void tj_vector<T>::assign(const tj_vector<T> & _a) {
	if (_a.len <= max_len) {	//可以直接赋值，不用操作空间
		memcpy(head, _a.head, sizeof(T)*_a.len);
		len = _a.len;
	}
	else {
		//delete[]head;
		head = new T[_a.len*IncreaseTime];
		len = _a.len;
		max_len = _a.len * IncreaseTime;
		memcpy(head, _a.head, sizeof(T)*_a.len);
	}
}

template<class T>
void tj_vector<T>::assign(initializer_list<T> L) {
	auto iter = L.begin();
	size_t i;
	if (L.size() > max_len) {
		//delete[]head;
		head = new T[L.size()*IncreaseTime];
		max_len = L.size() * IncreaseTime;
	}
	for (i = 0; i < L.size(); i++) {
		head[i] = *iter;
		iter++;
	}
	len = L.size();
	return;
}



/***************************************************************** 元素的增减 *************************************************/

template<class T>
void tj_vector<T>::clear() {
	len = 0;
	return;
}


template<class T>
T & tj_vector<T>::operator[](size_t n){
	return head[n];
}

template<class T>
T & tj_vector<T>::at(size_t n){
	if (n < len&&n>=0)
		return head[n];
	else
		throw std::out_of_range("vector::_M_range_check");
}

template<class T>
void tj_vector<T>::pop_back() {
	if (len > 0) {
		len--;
	}
	return;
}

template<class T>
void tj_vector<T>::push_back(const T & value) {
	if (len >= max_len) {
		T* tmp = new T[len*IncreaseTime];
		memcpy(tmp, head, len * sizeof(T));
		//delete[]head;
		head =tmp;
		max_len = len * IncreaseTime;
	}
	head[len] = value;
	len++;
}

template<class T>
tj_iterator<T> tj_vector<T>::erase(tj_iterator<T> pos) {

	size_t num= size_t(end() - pos)-1;
	memmove(pos.ptr, pos.ptr + 1, num * sizeof(T));
	len--;
	return pos;
}

template<class T>
tj_iterator<T> tj_vector<T>::erase(tj_iterator<T> from, tj_iterator<T> to) {
	size_t gap = to - from,num= size_t(end() - to);
	memmove(from.ptr, to.ptr, num * sizeof(T));
	len -= gap;
	return from;
}

template<class T>
tj_iterator<T> tj_vector<T>::insert(tj_iterator<T> pos, const T & value) {
	if (len >= max_len) {
		T* tmp = new T[(len) * IncreaseTime];
		memcpy(tmp, head, len * sizeof(T));
		//delete[]head;
		head = tmp;
		max_len = (len) * IncreaseTime;
	}
	//到此为止能够保证足够的空间，都可以做了。
	size_t num= size_t(end() - pos);
	memmove(pos.ptr+1, pos.ptr, num * sizeof(T));
	*pos = value;
	len++;
	return pos;
}

template<class T>
tj_iterator<T> tj_vector<T>::insert(tj_iterator<T> pos, size_t n, const T & value) {
	if (len + n >= max_len) {
		T* tmp = new T[(len + n) * IncreaseTime];
		memcpy(tmp, head, len * sizeof(T));
//		delete[]head;
		head = tmp;
		max_len = (len + n) * IncreaseTime;
	}
	//到此为止能够保证足够的空间，都可以做了。
	size_t i, num = size_t(end() - pos);
	memmove(pos.ptr+n, pos.ptr, num * sizeof(T));
	for (i = 0; i < n; i++) {
		*(pos + i) = value;
	}
	len += n;
	return pos;
}

template<class T>
tj_iterator<T> tj_vector<T>::insert(tj_iterator<T> pos, tj_iterator<T> from, tj_iterator<T> to) {
	if (len + (from-to)+1 >= max_len) {
		T* tmp = new T[(len + (from - to) + 1) * IncreaseTime];
		memcpy(tmp, head, len * sizeof(T));
		//		delete[]head;
		head = tmp;
		max_len = (len + (from - to) + 1) * IncreaseTime;
	}
	//到此为止能够保证足够的空间，都可以做了。

	size_t i,n= (to-from), num = size_t(end() - pos);
	for (i = 0; i <num; i++) {
		head[len - i + n - 1] = head[len - i - 1];
	}
	for (i = 0; i < n; i++) {
		*(pos + i) = *(from+i);
	}
	len += n;
	return pos;
}




/***************************************************************** 其余功能 *****************************************************/
template<class T>
void tj_vector<T>::resize(size_t n) {
	size_t i;
	if (n < max_len) {
		if (n > len)
			for (i = len; i < n; i++)
				head[i] = T();
		len = n;
		return;
	}
	else {
		T* tmp = new T[n * IncreaseTime];
		memcpy(tmp, head, len * sizeof(T));
		//delete[]head;
		head = tmp;
		for (i = len; i < n; i++)
			head[i] = T();
		len = n;
		max_len = n * IncreaseTime;
	}

	return;
}

template<class T>
void tj_vector<T>::resize(size_t n, const T & value) {
	size_t i;
	if (n >= max_len) {
		T* tmp= new T[n * IncreaseTime];
		memcpy(tmp, head, len * sizeof(T));
		//delete[]head;
		head = tmp;
		max_len = n * IncreaseTime;
	}
	for (i = len; i < n; i++)
		head[i] = value;
	len = n;
	return;
}

template<class T>
void tj_vector<T>::reserve(size_t n){
	if (n > max_len) {
		max_len = n;
		T *tmp=new T[max_len];
		memcpy(tmp, head, len * sizeof(T));
		//delete[] head;
		head=tmp;
	}
}

template<class T>
void tj_vector<T>::shrink_to_fit() {
	T* tmp = new T[len];
	memcpy(tmp, head, len * sizeof(T));
//	delete[]head;
	head = tmp;
	max_len = len;
}

template<class T>
void tj_vector<T>::swap(tj_vector<T> & a) {
	size_t tmplen=a.len, tmpmax_len=a.max_len;
	T *tmphead=a.head;
	a.len = len;
	a.max_len = max_len;
	a.head = head;
	len = tmplen;
	max_len = tmpmax_len;
	head = tmphead;
	return;
}

template<class T>
bool tj_vector<T>::operator==(const tj_vector<T>& a) const{
	if (len != a.len) 
		return false;
	size_t i;
	for (i = 0; i < len; ++i)
		if (head[i] != a.head[i])
			return false;
	return true;
}

template<class T>
bool tj_vector<T>::operator!=(const tj_vector<T>& a) const{
	if (len != a.len)
		return true;
	size_t i;
	for (i = 0; i < len; ++i)
		if (head[i] != a.head[i])
			return true;
	return false;
}

template<class T>
bool tj_vector<T>::operator<(const tj_vector<T>& a) const{
	size_t i, ub = len < a.len ? len :a.len;
	for (i = 0; i < ub; ++i)
		if (head[i] != a.head[i])
			return head[i] < a.head[i];
	return len < a.len;
}

template<class T>
bool tj_vector<T>::operator<=(const tj_vector<T>& a) const{
	size_t i, ub = len < a.len ? len : a.len;
	for (i = 0; i < ub; ++i)
		if (head[i] != a.head[i])
			return head[i] < a.head[i];
	return len <= a.len;
}

template<class T>
bool tj_vector<T>::operator>(const tj_vector<T>& a) const{
	size_t i, ub = len < a.len ? len : a.len;
	for (i = 0; i < ub; ++i)
		if (head[i] != a.head[i])
			return head[i] > a.head[i];
	return len > a.len;
}

template<class T>
bool tj_vector<T>::operator>=(const tj_vector<T>& a) const{
	size_t i, ub = len < a.len ? len : a.len;
	for (i = 0; i < ub; ++i)
		if (head[i] != a.head[i])
			return head[i] > a.head[i];
	return len >= a.len;
}

template<class T>
template<class ...Args>
void tj_vector<T>::emplace_back(Args && ...args) {
	if (len == max_len) {
		T *tmp = new T[len * IncreaseTime];
		memcpy(tmp, head, len*IncreaseTime);
		delete[]head;
		head = tmp;
		max_len = len * IncreaseTime;
	}
	new (&head[len]) T(std::forward<Args>(args) ...);
	++len;

}

template<class T>
template<class ...Args>
tj_iterator<T> tj_vector<T>::emplace(tj_iterator<T> it, Args && ...args) {
	tj_iterator<T> iit = &head[it - head];
	if (len == max_len) {
		T * tmp = new T[len * IncreaseTime];
		memcpy(tmp, head, len*IncreaseTime);
		delete[]head;
		head = tmp;
		max_len = len * IncreaseTime;
	}
	memmove(iit.ptr + 1, iit.ptr, (len - (it - head)) * sizeof(T));
	new (&head[it - head]) T(std::forward<Args>(args) ...);
//	(*iit) = std::move(T(std::forward<Args>(args) ...));
	len++;
	return iit;
}

