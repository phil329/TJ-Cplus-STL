// 1852024 数强 李兵磊
#pragma once
#include<iostream>
using namespace std;
class student {
public:
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
public:
	student(int n = 0, const char *nam = "", char se = 'M', float s = 0, const char*a = "");
	student(const student& a);
	friend bool operator ==(const student&a, const student &b);
	friend bool operator !=(const student&a, const student &b);
	void set(int n = 0, const char *nam = "", char se = 'M', float s = 0, const char*a = "");
	friend ostream &operator<< (ostream &out, const student &a);
	friend istream &operator>> (istream &in, student &a);
};
