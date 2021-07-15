/*¾Ïè¯ 1851846 ÊýÇ¿*/
#include "tj_student.h"
#include<string.h>

student::student(const int n, const char* nam, const char se, const float s, const char* a)
{
	num = n;
	memcpy(name, nam, sizeof(char) * 10);
	sex = se;
	score = s;
	memcpy(addr, a, sizeof(char) * 30);
}
student::student(const student& a)
{
	num = a.num;
	memcpy(name, a.name, sizeof(char) * 10);
	sex = a.sex;
	score = a.score;
	memcpy(addr, a.addr, sizeof(char) * 30);
}
ostream& operator<< (ostream& out, const student& a)
{
	out << a.num << " " << a.name << " " << a.sex << " " << a.score << " " << a.addr << endl;
	return out;
}
bool operator==(const student& stu1, const student& stu2)
{
	if (stu1.num == stu2.num)
		return true;
	else
		return false;
}
bool operator!=(const student& stu1, const student& stu2)
{
	if (stu1.num != stu2.num)
		return true;
	else
		return false;
}
bool operator<(const student& stu1, const student& stu2)
{
	if (stu1.score < stu2.score)
		return true;
	else
		return false;
}
void student::set(const int n, const char* nam, const char se, const float s, const char* a)
{
	num = n;
	memcpy(name, nam, sizeof(char) * 10);
	sex = se;
	score = s;
	memcpy(addr, a, sizeof(char) * 30);
}
istream& operator>> (istream& in, student& a)
{
	in >> a.num >> a.name >> a.sex >> a.score >> a.addr;
	return in;
}
