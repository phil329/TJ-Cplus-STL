// 1852024 数强 李兵磊
#include "tj_list.h"
using namespace std;

/*****************************************************************构造和析构**********************************************************/
template<class T, class Alloc>
tj_list<T, Alloc>::tj_list(){
	head = alloc.allocate(1);
	alloc.construct(head);
	tail = alloc.allocate(1);
	alloc.construct(tail);
	head->pre = nullptr;
	head->next = tail;
	tail->pre = head;
	tail->next = nullptr;
	len = 0;
}

template<class T, class Alloc>
tj_list<T, Alloc>::tj_list(size_t n){
	head = alloc.allocate(1);
	alloc.construct(head);
	tail = alloc.allocate(1);
	alloc.construct(tail);
	head->pre = nullptr;
	tail->next = nullptr;
	Node<T> *p, *q;
	size_t i;
	q = head;
	for (i = 0; i < n; i++){
		p = alloc.allocate(1);
		alloc.construct(p);	
		q->next = p;
		p->pre = q;
		q = p;
	}
	q->next = tail;
	tail->pre = q;
	len = n;
}

template<class T, class Alloc>
tj_list<T, Alloc>::tj_list(size_t n, const T & value){
	head = alloc.allocate(1);
	alloc.construct(head);
	tail = alloc.allocate(1);
	alloc.construct(tail);
	head->pre = nullptr;
	tail->next = nullptr;
	Node<T> *p, *q;
	size_t i;
	q = head;
	for (i = 0; i < n; i++){
		p = alloc.allocate(1);
		alloc.construct(p);	
		p->value = value;
		q->next = p;
		p->pre = q;
		q = p;
	}
	q->next = tail;	
	tail->pre = q;
	len = n;
}

template<class T, class Alloc>
tj_list<T, Alloc>::tj_list(const tj_list<T, Alloc> & a){
	head = alloc.allocate(1);
	alloc.construct(head);
	tail = alloc.allocate(1);
	alloc.construct(tail);
	head->pre = nullptr;
	tail->next = nullptr;
	Node<T> *p, *q, *r;
	size_t i;
	r = a.head;
	q = head;
	for (i = 0; i < a.len; i++){
		p = alloc.allocate(1);
		alloc.construct(p);	
		r = r->next;
		p->value = r->value;
		q->next = p;
		p->pre = q;
		q = p;
	}
	q->next = tail;	
	tail->pre = q;
	len = a.len;
}

template<class T, class Alloc>
tj_list<T, Alloc>::tj_list(initializer_list<T> L)
{
	auto iter = L.begin();
	head = alloc.allocate(1);		//头结点
	alloc.construct(head);
	tail = alloc.allocate(1);		//尾结点
	alloc.construct(tail);
	head->pre = nullptr;			//调整指针
	tail->next = nullptr;
	Node<T> *p, *q;
	size_t i;
	q = head;						//上一个结点
	for (i = 0; i < L.size(); i++)
	{
		p = alloc.allocate(1);		//申请一个结点
		alloc.construct(p);			//构造
		p->value = *iter;			//赋值
		iter++;
		q->next = p;				//调整指针
		p->pre = q;
		q = p;
	}
	q->next = tail;					//调整指针
	tail->pre = q;
	len = L.size();					//预置长度
}

template<class T, class Alloc>
tj_list<T, Alloc>::~tj_list(){
	Node<T> *p=nullptr , *q;
	q = head;
	while (q != tail){
		p = q->next;
		alloc.destroy(q);
		alloc.deallocate(q, 1);
		q = p;
	}
	alloc.destroy(p);
	alloc.deallocate(p, 1);
}

/******************************************************************* assign赋值 ***********************************************/
template<class T, class Alloc>
void tj_list<T, Alloc>::assign(size_t n, const T & value){
	clear();
	Node<T> *p, *q;
	size_t i;
	q = head;
	for (i = 0; i < n; i++)
	{
		p = alloc.allocate(1);
		alloc.construct(p);	
		p->value = value;
		q->next = p;
		p->pre = q;
		q = p;
	}
	q->next = tail;	
	tail->pre = q;
	len = n;
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::assign(const tj_iterator<T> & from, const tj_iterator<T> & to){
	clear();
	Node<T> *p, *q;
	size_t i = 0;
	q = head;						//上一个结点
	for (auto iter = from; iter != to; iter++, i++)
	{
		p = alloc.allocate(1);		//申请一个结点
		alloc.construct(p);			//构造
		p->value = *iter;			//赋值
		q->next = p;				//调整指针
		p->pre = q;
		q = p;
	}
	q->next = tail;					//调整指针
	tail->pre = q;
	len = i;						//预置长度
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::assign(const tj_list<T, Alloc> & _a)
{
	clear();
	Node<T> *p, *q, *r;
	size_t i;
	r = _a.head;
	q = head;						//上一个结点
	for (i = 0; i < _a.len; i++)
	{
		p = alloc.allocate(1);		//申请一个结点
		alloc.construct(p);			//构造
		r = r->next;				//赋值
		p->value = r->value;
		q->next = p;				//调整指针
		p->pre = q;
		q = p;
	}
	q->next = tail;					//调整指针
	tail->pre = q;
	len = _a.len;				//预置长度
}

template<class T, class Alloc>
void tj_list<T, Alloc>::assign(initializer_list<T> L){
	clear();
	auto iter = L.begin();
	Node<T> *p, *q;
	size_t i;
	q = head;						//上一个结点
	for (i = 0; i < L.size(); i++)
	{
		p = alloc.allocate(1);		//申请一个结点
		alloc.construct(p);			//构造
		p->value = *iter;			//赋值
		iter++;
		q->next = p;				//调整指针
		p->pre = q;
		q = p;
	}
	q->next = tail;					//调整指针
	tail->pre = q;
	len = L.size();					//预置长度
	return;
}



/***************************************************************** 元素的增减 *************************************************/

template<class T, class Alloc>
void tj_list<T, Alloc>::clear(){
	Node<T> *p, *q;
	q = head->next;
	while (q != tail){
		p = q->next;				//抓住下一个
		alloc.destroy(q);
		alloc.deallocate(q, 1);
		q = p;
	}
	head->next = tail;
	tail->pre = head;
	len = 0;
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::pop_back() {
	if (len > 0) {
		Node<T> *p = tail->pre;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		alloc.destroy(p);
		alloc.deallocate(p, 1);
		len--;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::pop_front() {
	if (len > 0) {
		Node<T> *p = head->next;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		alloc.destroy(p);
		alloc.deallocate(p, 1);
		len--;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::push_back(const T & value) {
	Node<T> *p;
	p = alloc.allocate(1);
	alloc.construct(p);
	p->value = value;
	p->next = tail;
	p->pre = tail->pre;
	tail->pre = p;
	p->pre->next = p;
	len++;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::push_front(const T & value) {
	Node<T> *p;
	p = alloc.allocate(1);
	alloc.construct(p);
	p->value = value;
	p->pre = head;
	p->next = head->next;
	head->next = p;
	p->next->pre = p;
	len++;
}

template<class T, class Alloc>
tj_iterator<T> tj_list<T, Alloc>::erase(tj_iterator<T> pos){
	tj_iterator<T> t;
	Node<T> *p = pos.ptr;
	t.ptr = p->next;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	alloc.destroy(p);
	alloc.deallocate(p, 1);
	len--;
	return t;
}

template<class T, class Alloc>
tj_iterator<T> tj_list<T, Alloc>::erase(tj_iterator<T> from, tj_iterator<T> to){
	tj_iterator<T> t;
	Node<T> *p, *q;
	size_t count = 0;
	q = from.ptr;
	p = to.ptr;
	t.ptr = p;
	q->pre->next = p;
	p->pre = q->pre;
	p = nullptr;
	while (q != to.ptr){
		p = q->next;
		alloc.destroy(q);
		alloc.deallocate(q, 1);
		q = p;
		count++;
	}
	len = len - count;
	return t;
}

template<class T, class Alloc>
tj_iterator<T> tj_list<T, Alloc>::insert(tj_iterator<T> pos, const T & value){
	tj_iterator<T> t;
	Node<T> *p;
	p = alloc.allocate(1);
	alloc.construct(p);
	p->value = value;
	p->next = pos.ptr;
	p->pre = pos.ptr->pre;
	pos.ptr->pre = p;
	p->pre->next = p;
	len++;
	t.ptr = p;
	return t;
}

template<class T, class Alloc>
tj_iterator<T> tj_list<T, Alloc>::insert(tj_iterator<T> pos, size_t n, const T & value){
	tj_iterator<T> t;
	t.ptr = pos.ptr;
	Node<T> *p, *q;
	size_t i;
	q = pos.ptr->pre;
	for (i = 0; i < n; i++){
		p = alloc.allocate(1);
		alloc.construct(p);
		p->value =value;
		q->next = p;
		p->pre = q;
		q = p;
	}
	q->next = pos.ptr;
	pos.ptr->pre = q;
	len = len + n;
	return t;
}

template<class T, class Alloc>
tj_iterator<T> tj_list<T, Alloc>::insert(tj_iterator<T> pos, tj_iterator<T> from, tj_iterator<T> to){
	tj_iterator<T> ret;
	ret.ptr = pos.ptr;
	Node<T> *p, *q;
	int i = 0;
	tj_iterator<T> iter = from;
	q = pos.ptr->pre;
	for (; iter != to; iter++, i++){
		p = alloc.allocate(1);
		alloc.construct(p);
		p->value = (*iter);
		q->next = p;
		p->pre = q;
		q = p;
	}
	q->next = pos.ptr;
	pos.ptr->pre = q;
	len = len + i;
	return ret;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::remove(const T & value){
	Node<T> *p = head->next;
	while (p != tail){
		if (p->value == value){
			Node<T> *q = p->next;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			alloc.destroy(p);
			alloc.deallocate(p, 1);
			len--;
			p = q;
		}
		else
			p = p->next;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::remove_if(bool condition(T data)) {
	Node<T> *p = head->next;
	while (p != tail) {
		if (condition(p->value)) {
			Node<T> *q = p->next;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			alloc.destroy(p);
			alloc.deallocate(p, 1);
			len--;
			p = q;
		}
		else
			p = p->next;
	}
	return;
}



/***************************************************************** 其余功能 *****************************************************/
template<class T, class Alloc>
void tj_list<T, Alloc>::reverse(){
	Node<T> *p = head;
	head = tail;
	tail = p;
	for (p = tail; p != nullptr; p = p->pre){
		Node<T> *r = p->next;
		p->next = p->pre;
		p->pre = r;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::resize(size_t n){
	Node<T> *p = head->next;
	size_t i = 0;
	for (; i < n && p != tail; i++)
		p = p->next;
	while (p != tail){
		Node<T> *q = p->next;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		alloc.destroy(p);
		alloc.deallocate(p, 1);
		p = q;
	}
	for (; i < n; i++){
		p = alloc.allocate(1);
		alloc.construct(p);
		p->next = tail;
		p->pre = tail->pre;
		tail->pre = p;
		p->pre->next = p;
	}
	len = n;
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::resize(size_t n, const T & value){
	Node<T> *p = head->next;
	size_t i = 0;
	for (; i < n && p != tail; i++)
		p = p->next;
	while (p != tail){
		Node<T> *q = p->next;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		alloc.destroy(p);
		alloc.deallocate(p, 1);
		p = q;
	}
	for (; i < n; i++){
		p = alloc.allocate(1);
		alloc.construct(p);
		p->value = value;
		p->next = tail;
		p->pre = tail->pre;
		tail->pre = p;
		p->pre->next = p;
	}
	len = n;
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::sort(){
	size_t i;
	for (i = 0; i < len; i++){
		Node<T> *p;
		for (p = head->next; p != tail; p = p->next)
			if (p->value < p->pre->value && p != head->next){
				T temp = p->value;
				p->value = p->pre->value;
				p->pre->value = temp;
			}
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::sort(bool compare(T data1, T data2)){
	size_t i;
	for (i = 0; i < len; i++){
		Node<T> *p;
		for (p = head->next; p != tail; p = p->next)
			if (compare(p->value, p->pre->value) && p != head->next){
				T temp = p->value;
				p->value = p->pre->value;
				p->pre->value = temp;
			}
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::swap(tj_list<T, Alloc> & a){
	if (len == 0 && a.len == 0)
		;
	else if (len > 0 && a.len == 0){
		a.head->next = head->next;
		a.tail->pre = tail->pre;
		a.head->next->pre = a.head;
		a.tail->pre->next = a.tail;
		head->next = a.tail;
		tail->pre = a.head;
	}
	else if (len == 0 && a.len > 0) {
		head->next = a.head->next;
		tail->pre = a.tail->pre;
		head->next->pre = head;
		tail->pre->next = tail;
		a.head->next = tail;
		a.tail->pre = head;
	}
	else{
		Node<T> *p = head->next, *q = tail->pre;
		head->next = a.head->next;
		tail->pre = a.tail->pre;
		head->next->pre = head;
		tail->pre->next = tail;
		p->pre = a.head;
		q->next = a.tail;
		a.head->next = p;
		a.tail->pre = q;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::unique(){
	if (len < 2)
		return;	//仅有一个元素不用直接返回
	Node<T> *p = head->next->next,*q;
	while (p != tail) {
		if (p->value ==p->pre->value) {
			q = p->next;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			alloc.destroy(p);
			alloc.deallocate(p, 1);
			len--;
			p = q;
		}
		else
			p = p->next;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::unique(bool pred(T data1, T data2)){
	if (len < 2)
		return;	//仅有一个元素不用直接返回
	Node<T> *p = head->next->next, *q;
	while (p != tail) {
		if (pred(p->pre->value, p->value)) {
			q = p->next;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			alloc.destroy(p);
			alloc.deallocate(p, 1);
			len--;
			p = q;
		}
		else
			p = p->next;
	}
	return;
}


template<class T, class Alloc>
void tj_list<T, Alloc>::splice(tj_iterator<T> position, tj_list<T, Alloc> & a){
	if (len > 0 && a.len > 0){
		Node<T> *p = a.head->next, *q = a.tail->pre;
		Node<T> *t = position.ptr;
		p->pre = t->pre;
		q->next = t;
		t->pre = q;
		p->pre->next = p;
		len = len + a.len;
		a.len = 0;
		a.head->next = a.tail;
		a.tail->pre = a.head;
	}
	else if (len == 0 && a.len > 0){
		head->next = a.head->next;
		tail->pre = a.tail->pre;
		a.head->next->pre = head;
		a.tail->pre->next = tail;
		a.len = 0;
		a.head->next = a.tail;
		a.tail->pre = a.head;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::splice(tj_iterator<T> position, tj_list<T, Alloc> & a, tj_iterator<T> i){
	if (len > 0){
		Node<T> *p = position.ptr, *q = i.ptr;
		q->pre->next = q->next;
		q->next->pre = q->pre;
		a.len--;
		p->pre->next = q;
		q->next = p;
		p->pre = q;
		q->pre = p->pre;
		len++;
	}
	else{
		Node<T> *q = i.ptr;
		q->pre->next = q->next;
		q->next->pre = q->pre;
		a.len--;
		head->next = q;
		tail->pre = q;
		q->pre = head;
		q->next = tail;
		len++;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::splice(tj_iterator<T> position, tj_list<T, Alloc> & a, tj_iterator<T> from, tj_iterator<T> to){
	if (len > 0 && a.len > 0){
		Node<T> *pos = position.ptr, *r = from.ptr, *s = to.ptr->pre, *c;
		r->pre->next = s->next;
		s->next->pre = r->pre;
		pos->pre->next = r;
		s->next = pos;
		r->pre = pos->pre;
		pos->pre = s;
		size_t count = 1;
		for (c = r; c != s; c = c->next)
			count++;
		len += count;
		a.len -= count;
	}
	else if (len == 0 && a.len > 0){
		Node<T> *r = from.ptr, *s = to.ptr->pre, *c;
		r->pre->next = s->next;
		s->next->pre = r->pre;
		head->next = r;
		tail->pre = s;
		r->pre = head;
		s->next = tail;
		size_t count = 1;
		for (c = r; c != s; c = c->next)
			count++;
		len += count;
		a.len -= count;
	}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::merge(tj_list<T, Alloc> & a){
	//Node<T> *p1, *p2, *p;
	//p1 = (head->next);
	//p2 = (a.head->next);
	//while (p1 != tail && p2 != tail) {
	//	if (p2->value<= p1->value) {
	//		p = p2->next;
	//		splice((tj_iterator<T>)(p1), a, (tj_iterator<T>)p2);
	//		p2 = p;
	//	}
	//	else
	//		p1 = p1->next;
	//}
	//while (p2 != tail) {
	//	p = p2->next;
	//	splice((tj_iterator<T>)p1, a, (tj_iterator<T>)p2);
	//	p2 = p;
	//}
	return;
}

template<class T, class Alloc>
void tj_list<T, Alloc>::merge(tj_list<T, Alloc> & a, bool compare(T data1, T data2)) {
	//Node<T> *p1 = head->next, *p2 = a.head->next, *p;
	//while (p1 != tail && p2 != tail) {
	//	if (compare(p2->value, p1->value)) {
	//		p = p2->next;
	//		splice((tj_iterator<T>)(p1), a, (tj_iterator<T>)p2);
	//		p2 = p;
	//	}
	//	else
	//		p1 = p1->next;
	//}
	//while (p2 != tail) {
	//	p = p2->next;
	//	splice((tj_iterator<T>)p1, a, (tj_iterator<T>)p2);
	//	p2 = p;
	//}
	return;
}