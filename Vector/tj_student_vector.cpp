// 1852024 ??? ?????
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "tj_student_vector.h"

student::student(const student &a) {
	num=a.num;
	strcpy(name,a.name);
	sex=a.sex;
	score=a.score;
	strcpy(addr, a.addr);
}
student::student(int nu , const char *na , char se , float sc , const char*add) {
	num = nu;
	strcpy(name, na);
	sex = se;
	score = sc;
	strcpy(addr, add);
}
void student::set(int nu, const char *na, char se, float sc, const char *add) {
	num = nu;
	strcpy(name, na);
	sex = se;
	score = sc;
	strcpy(addr, add);
}

bool operator ==(const student &a, const student &b) {
	return a.num == b.num ? true : false;
}
bool operator !=(const student &a, const student &b) {
	return a.num != b.num ? true : false;
}
ostream &operator<<(ostream &out, const student &a) {
	out << "????" << a.num << "??????" << a.name << " ???" << a.sex << " ??????" << a.score << " ?????" << a.addr << endl;
	return out;
}
istream &operator>>(istream &in, student& a) {
	in >> a.num >> a.name >> a.sex >> a.score >> a.addr;
	return in;
}
