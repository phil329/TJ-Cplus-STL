/* 1851846 ��ǿ ��� */
#include <iostream>
#include <set>
#include <string>
#include "tj_student.h"
#include "tj_set.h"

using namespace std;


/* ���궨��ע�͵�������ϵͳset�Ĳ��ԣ�
   �򿪺궨�壬������Լ��� tj_set */
#define set tj_set

void press_key(int num, const char* prompt)
{
	int i;
	cout << endl << prompt << "�������������...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}

/*���ڲ����Զ����������*/

struct intcmp {
	bool operator () (const int& a, const int& b)const {
		return a > b;
	}
};


struct strComp {
	bool operator() (const string& str1, const string& str2) const {
		return str1 > str2;
	}
};

struct studentComp {
	bool operator() (const student& str1, const student& str2) const {
		return str1.score > str2.score;
	}
};

int main()
{
	//int
	if (1) {
		int test_int[] = { 1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		/* ��0����� */
		if (test_int[0]) {
			press_key(1, "��0����ԣ�\n begin(),end(),rbegin(),rend()������set�����Ĵ���");

			int a[5] = { 1, 2, 3, 4, 5 };

			set <int> set1(a, a + 5);

			cout << "set��������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "set��������(����): " << endl;
			cout << "Ӧ�����5 4 3 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = set1.rbegin(); it != set1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;


			set<int> set2;
			cout << "���Ե�������СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (set2.begin() == set2.end()) << endl;

			cout << endl;

			cout << "���Ե�������СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (set2.rbegin() == set2.rend());

			cout << endl << endl;

			set<int> set3(set1);
			cout << "���������ĸ��ƹ���" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert(6);
			set3.insert(7);
			set3.insert(8);

			cout << "����insert()����" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5 6 7 8" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert(6);
			cout << "����set������Ԫ�ز�����ͬ" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5 6 7 8" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "���Բ����Ԫ���Ƿ�ɹ�" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set3.insert(6).second << endl;
			cout << "���������е�Ԫ�صĵ�������Ӧλ�õ�ֵΪ��" << endl;
			cout << "Ӧ�����6" << endl;
			cout << "ʵ�������" << *set3.insert(6).first << endl;

			set<int> set4(set1.begin(), set1.end());

			cout << "���������ĵ��������乹��" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set4.begin(); it != set4.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set<int> set5;

			set5.insert(a, a + 5);

			cout << "�����������������乹��" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set5.begin(); it != set5.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;
		}

		/* ��1����� */
		if (test_int[1]) {
			press_key(1, "��1����ԣ�\n size()��max_size()��count()��empty()����");

			int a[5] = { 1, 2, 3, 4, 5 };

			set <int> set1(a, a + 5);
			set<int> set2;

			cout << "size()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << set1.size() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set2.size() << endl;

			cout << endl;

			cout << "max_size()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ����� 214748364" << endl;
			cout << "ʵ���ǣ�" << set1.max_size() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����214748364" << endl;
			cout << "ʵ���ǣ�" << set2.max_size() << endl;

			cout << endl;

			cout << "empty()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set1.empty() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << set2.empty() << endl;

			cout << endl;

			//��Ȼset��count()��������ֵֻ��0/1���ֿ��ܣ������ǲ�һ����~
			cout << "count()����: " << endl;
			cout << "set1��1�ĸ���:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << set1.count(1) << endl;
			cout << "set1��0�ĸ���:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set1.count(0) << endl;
			cout << endl << endl;
		}

		/* ��2����� */
		if (test_int[2]) {
			press_key(1, "��2����ԣ�\n find(),erase(),clear()����");

			int a[5] = { 1,2,3,4,5 };
			set<int> set1(a, a + 5);
			set<int> set2(set1);

			auto it = set1.find(1);
			cout << "����find()����(���ҵ�)�� " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�";
			cout << *it << endl;

			cout << endl;

			cout << endl;

			it = set1.find(6);
			cout << "����find()����(�����ҵ�)�� " << endl;
			cout << "Ӧ�����6�����ҵ�" << endl;
			cout << "ʵ���ǣ�";
			if (it != set1.end())
				cout << "6���ҵ�" << endl;
			else
				cout << "6�����ҵ�" << endl;

			cout << endl;

			cout << endl;
			set1.erase(3);
			cout << "erase()����ΪԪ��ֵ�Ĳ���,��������(����): " << endl;
			cout << "Ӧ�����1 2 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			it = set1.find(1);
			set1.erase(it);
			cout << "erase()����Ϊ�������Ĳ���,��������(����): " << endl;
			cout << "Ӧ�����2 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set1.erase(set1.begin(), set1.end());
			cout << "erase()����Ϊ����������Ĳ��ԣ��жϴ�ʱ������С�Ƿ�Ϊ0: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�";
			cout << set1.size() << endl;

			cout << endl;

			cout << endl;

			set2.clear();
			cout << "clear()����������ԣ��жϴ�ʱ������С�Ƿ�Ϊ0: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�";
			cout << set1.empty() << endl;

			cout << endl;

			cout << endl;
		}

		/* ��3����� */
		if (test_int[3]) {
			press_key(1, "��3����ԣ�\n lower_bound()������upper_bound()������equal_range()����");

			set<int> set1;
			set1.insert(1);
			set1.insert(2);
			set1.insert(5);

			cout << "�ҵõ�Ԫ�ص������" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "��һ�����ڻ����3��Ԫ��: " << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << *set1.lower_bound(3) << endl;
			cout << "��һ�����ڻ����2��Ԫ��: " << endl;
			cout << "Ӧ�����2" << endl;
			cout << "ʵ���ǣ�" << *set1.lower_bound(2) << endl;
			cout << "��һ������2��Ԫ��: " << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << *set1.upper_bound(2) << endl;

			cout << endl;
			cout << endl;

			cout << "�Ҳ���Ԫ�ص������" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "��һ�����ڻ����6��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.lower_bound(6) == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.lower_bound(6) << endl;

			cout << "��һ������5��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.upper_bound(5) == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.upper_bound(5) << endl;

			cout << endl << endl;

			cout << "�ҵõ�Ԫ�ص������" << endl;

			cout << "equal_range test:" << endl;
			cout << "��һ�����ڻ����2��Ԫ��: " << endl;
			cout << "Ӧ�����2" << endl;
			cout << "ʵ���ǣ�" << *set1.equal_range(2).first << endl;
			cout << "��һ������2��Ԫ��: " << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << *set1.equal_range(2).second << endl;
			cout << endl;
			cout << endl;

			cout << "�Ҳ���Ԫ�ص������" << endl;
			cout << "equal_range test:" << endl;
			cout << "��һ�����ڻ����6��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.equal_range(6).first == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.lower_bound(6) << endl;

			cout << "��һ������5��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.equal_range(6).second == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.equal_range(6).second << endl;
			cout << endl;
			cout << endl;

		}

		/* ��4����� */
		if (test_int[4]) {
			press_key(1, "��4����ԣ�\n swap()����");

			set<int> set1, set2;
			set1.insert(100);
			set2.insert(200);
			cout << "swap()����: " << endl;
			cout << "set1�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << "���н���" << endl;

			set1.swap(set2);
			cout << "set1�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << endl;
		}

		/* ��5����� */
		if (test_int[5]) {
			press_key(1, "��5����ԣ�\n ����> == < >= <= !=��˳�������set�������бȽ�");
			int a[5] = { 1,2,3,4,5 };
			int b[4] = { 1,2,3,4 };
			int c[6] = { 1,2,3,4,5,6 };
			set<int> set1(a, a + 5);
			set<int> set2(set1);
			set<int> set3(b, b + 4);
			set<int> set4(c, c + 6);

			cout << "set1��set2�Ƚ�: " << endl;
			cout << "Ӧ�����0 1 0 1 1 0" << endl;
			cout << "ʵ���ǣ�" << ((set1 > set2) ? 1 : 0) << " ";
			cout << ((set1 == set2) ? 1 : 0) << " ";
			cout << ((set1 < set2) ? 1 : 0) << " ";
			cout << ((set1 >= set2) ? 1 : 0) << " ";
			cout << ((set1 <= set2) ? 1 : 0) << " ";
			cout << ((set1 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "set2��set3�Ƚ�: " << endl;
			cout << "Ӧ�����1 0 0 1 0 1" << endl;
			cout << "ʵ���ǣ�" << ((set2 > set3) ? 1 : 0) << " ";
			cout << ((set2 == set3) ? 1 : 0) << " ";
			cout << ((set2 < set3) ? 1 : 0) << " ";
			cout << ((set2 >= set3) ? 1 : 0) << " ";
			cout << ((set2 <= set3) ? 1 : 0) << " ";
			cout << ((set2 != set3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "set4��set2�Ƚ�: " << endl;
			cout << "Ӧ�����1 0 0 1 0 1" << endl;
			cout << "ʵ���ǣ�" << ((set4 > set2) ? 1 : 0) << " ";
			cout << ((set4 == set2) ? 1 : 0) << " ";
			cout << ((set4 < set2) ? 1 : 0) << " ";
			cout << ((set4 >= set2) ? 1 : 0) << " ";
			cout << ((set4 <= set2) ? 1 : 0) << " ";
			cout << ((set4 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		/* ��6����� */
		if (test_int[6]) {

			press_key(1, "��6����ԣ�\n �Զ�������������");
			set<int, intcmp>s;
			s.insert(1);
			s.insert(2);
			s.insert(6);
			cout << "Test output :" << endl;
			cout << "Ӧ�����6 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = s.begin(); it != s.end(); it++)
				cout << *it << " ";
			cout << endl;
			cout << endl;
		}
	}
#if 1
	//string
	if (1) {
		int test_string[] = { 1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����

	/* ��0����� */
		if (test_string[0]) {
			press_key(1, "��0����ԣ�\n begin(),end(),rbegin(),rend()������set�����Ĵ���");

			string a[5] = { "ab","cd" ,"ef", "gh", "ij" };

			set<string> set1(a, a + 5);
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ij gh ef cd ab" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = set1.rbegin(); it != set1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;


			set<string> set2;
			cout << "���Ե�������СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (set2.begin() == set2.end()) << endl;

			cout << endl;

			cout << "���Ե�������СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (set2.rbegin() == set2.rend());

			cout << endl << endl;

			set<string> set3(set1);
			cout << "���������ĸ��ƹ���" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert("kl");
			set3.insert("mn");
			set3.insert("op");

			cout << "����insert()����" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij kl mn op" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert("ab");
			cout << "����set������Ԫ�ز�����ͬ" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij kl mn op" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "���Բ����Ԫ���Ƿ�ɹ�" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set3.insert("cd").second << endl;
			cout << "���������е�Ԫ�صĵ�������Ӧλ�õ�ֵΪ��" << endl;
			cout << "Ӧ�����cd" << endl;
			cout << "ʵ���ǣ�" << *set3.insert("cd").first << endl;

			set<string> set4(set1.begin(), set1.end());

			cout << "���������ĵ��������乹��" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set4.begin(); it != set4.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set<string> set5;

			set5.insert(a, a + 5);

			cout << "�����������������乹��" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set5.begin(); it != set5.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

		}

		/* ��1����� */
		if (test_string[1]) {
			press_key(1, "��1����ԣ�\n size()��max_size()��count()��empty()����");

			string a[5] = { "ab","cd" ,"ef", "gh", "ij" };

			set <string> set1(a, a + 5);
			set<string> set2;

			cout << "size()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << set1.size() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set2.size() << endl;

			cout << endl;

			cout << "max_size()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����97612893" << endl;
			cout << "ʵ���ǣ�" << set1.max_size() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����97612893" << endl;
			cout << "ʵ���ǣ�" << set2.max_size() << endl;

			cout << endl;

			cout << "empty()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set1.empty() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << set2.empty() << endl;

			cout << endl;

			//��Ȼset��count()��������ֵֻ��0/1���ֿ��ܣ������ǲ�һ����~
			cout << "count()����: " << endl;
			cout << "set1��ab�ĸ���:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << set1.count("ab") << endl;
			cout << "set1��ac�ĸ���:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set1.count("ac") << endl;
			cout << endl << endl;
		}

		/* ��2����� */
		if (test_string[2]) {
			press_key(1, "��2����ԣ�\n find(),erase(),clear()����");

			string a[5] = { "ab","cd" ,"ef", "gh", "ij" };
			set<string> set1(a, a + 5);
			set<string> set2(set1);

			auto it = set1.find("ab");
			cout << "����find()����(���ҵ�)�� " << endl;
			cout << "Ӧ�����ab" << endl;
			cout << "ʵ���ǣ�";
			cout << *it << endl;

			cout << endl;

			cout << endl;

			it = set1.find("ac");
			cout << "����find()����(�����ҵ�)�� " << endl;
			cout << "Ӧ�����ac�����ҵ�" << endl;
			cout << "ʵ���ǣ�";
			if (it != set1.end())
				cout << "ac���ҵ�" << endl;
			else
				cout << "ac�����ҵ�" << endl;

			cout << endl;

			cout << endl;
			set1.erase("ab");
			cout << "erase()����ΪԪ��ֵ�Ĳ���,��������(����): " << endl;
			cout << "Ӧ�����cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			it = set1.find("ef");
			set1.erase(it);
			cout << "erase()����Ϊ�������Ĳ���,��������(����): " << endl;
			cout << "Ӧ�����cd gh ij" << endl;
			cout << "ʵ���ǣ�";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set1.erase(set1.begin(), set1.end());
			cout << "erase()����Ϊ����������Ĳ��ԣ��жϴ�ʱ������С�Ƿ�Ϊ0: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�";
			cout << set1.size() << endl;

			cout << endl;

			cout << endl;

			set2.clear();
			cout << "clear()����������ԣ��жϴ�ʱ������С�Ƿ�Ϊ0: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�";
			cout << set1.empty() << endl;

			cout << endl;

			cout << endl;

		}

		/* ��3����� */
		if (test_string[3]) {
			press_key(1, "��3����ԣ�\n lower_bound()������upper_bound()������equal_range()����");

			set<string> set1;
			set1.insert("ab");
			set1.insert("abc");
			set1.insert("cd");

			cout << "�ҵõ�Ԫ�ص������" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "��һ�����ڻ����ab��Ԫ��: " << endl;
			cout << "Ӧ�����ab" << endl;
			cout << "ʵ���ǣ�" << *set1.lower_bound("ab") << endl;
			cout << "��һ�����ڻ����a��Ԫ��: " << endl;
			cout << "Ӧ�����ab" << endl;
			cout << "ʵ���ǣ�" << *set1.lower_bound("a") << endl;
			cout << "��һ������ab��Ԫ��: " << endl;
			cout << "Ӧ�����abc" << endl;
			cout << "ʵ���ǣ�" << *set1.upper_bound("ab") << endl;

			cout << endl;
			cout << endl;

			cout << "�Ҳ���Ԫ�ص������" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "��һ�����ڻ����cde��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.lower_bound("cde") == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.lower_bound("cde") << endl;

			cout << "��һ������cd��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.upper_bound("cd") == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.upper_bound("cd") << endl;

			cout << endl << endl;

			cout << "�ҵõ�Ԫ�ص������" << endl;

			cout << "equal_range test:" << endl;
			cout << "��һ�����ڻ����ab��Ԫ��: " << endl;
			cout << "Ӧ�����ab" << endl;
			cout << "ʵ���ǣ�" << *set1.equal_range("ab").first << endl;
			cout << "��һ������ab��Ԫ��: " << endl;
			cout << "Ӧ�����abc" << endl;
			cout << "ʵ���ǣ�" << *set1.equal_range("ab").second << endl;
			cout << endl;
			cout << endl;

			cout << "�Ҳ���Ԫ�ص������" << endl;
			cout << "equal_range test:" << endl;
			cout << "��һ�����ڻ����cde��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.equal_range("cde").first == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.lower_bound("cde") << endl;

			cout << "��һ������cd��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.equal_range("cd").second == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.equal_range("cd").second << endl;
			cout << endl;
			cout << endl;
		}

		/* ��4����� */
		if (test_string[4]) {
			press_key(1, "��4����ԣ�\n swap()����");

			set<string> set1, set2;
			set1.insert("ab");
			set1.insert("cd");
			set1.insert("efgh");
			set2.insert("hijk");
			set2.insert("lmn");
			cout << "swap()����: " << endl;
			cout << "set1�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << "���н���" << endl;

			set1.swap(set2);
			cout << "set1�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << endl;
		}

		/* ��5����� */
		if (test_string[5]) {
			press_key(1, "��5����ԣ�\n ����> == < >= <= !=��˳�������set�������бȽ�");

			string a[5] = { "abc", "def", "ghi","jkl", "mno" };
			string b[5] = { "mno", "jkl", "ghi", "def", "abc" };
			string c[5] = { "abc", "def", "ghi","jkl" };
			string d[5] = { "abc", "def", "ghi","jkl", "mnop" };

			set<string> set1(a, a + 5);
			set<string> set2(b, b + 5);
			set<string> set3(c, c + 4);
			set<string> set4(d, d + 5);

			cout << "set1��set2�Ƚ�: " << endl;
			cout << "Ӧ�����0 1 0 1 1 0" << endl;
			cout << "ʵ���ǣ�" << ((set1 > set2) ? 1 : 0) << " ";
			cout << ((set1 == set2) ? 1 : 0) << " ";
			cout << ((set1 < set2) ? 1 : 0) << " ";
			cout << ((set1 >= set2) ? 1 : 0) << " ";
			cout << ((set1 <= set2) ? 1 : 0) << " ";
			cout << ((set1 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "set2��set3�Ƚ�: " << endl;
			cout << "Ӧ�����1 0 0 1 0 1" << endl;
			cout << "ʵ���ǣ�" << ((set2 > set3) ? 1 : 0) << " ";
			cout << ((set2 == set3) ? 1 : 0) << " ";
			cout << ((set2 < set3) ? 1 : 0) << " ";
			cout << ((set2 >= set3) ? 1 : 0) << " ";
			cout << ((set2 <= set3) ? 1 : 0) << " ";
			cout << ((set2 != set3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "set4��set2�Ƚ�: " << endl;
			cout << "Ӧ�����1 0 0 1 0 1" << endl;
			cout << "ʵ���ǣ�" << ((set4 > set2) ? 1 : 0) << " ";
			cout << ((set4 == set2) ? 1 : 0) << " ";
			cout << ((set4 < set2) ? 1 : 0) << " ";
			cout << ((set4 >= set2) ? 1 : 0) << " ";
			cout << ((set4 <= set2) ? 1 : 0) << " ";
			cout << ((set4 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		/* ��6����� */
		if (test_string[6]) {
			press_key(1, "��6����ԣ�\n �Զ�������������");
			set<string, strComp>s;
			s.insert("ab");
			s.insert("cd");
			s.insert("ef");
			cout << "Test output :" << endl;
			cout << "Ӧ�����ef cd ab" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = s.begin(); it != s.end(); it++)
				cout << *it << " ";
			cout << endl;
			cout << endl;
		}


	}

	//student
	if (1) {
		int test_student[] = { 1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		const student mother[4] = { {1851846,"���",'f',(float)(92.2),"�ӱ�"},
		{1851801,"������",'f',(float)(94.2),"�ӱ�"},
		{1854205,"֣���",'f',(float)(93.5),"����"},
		{1854167,"��˼��",'f',(float)(91.7),"����"} };


		/* ��0����� */
		if (test_student[0]) {
			press_key(1, "��0����ԣ�\n  begin(),end(),rbegin(),rend()������set�����Ĵ���");

			set<student> set1(mother, mother + 4);
			student a[3] = { {1853790,"ׯ��",'f',(float)(92.7),"ɽ��"},
					{1852024,"�����",'f',(float)(90.9),"����"},
					{1851909,"��Ң",'f',(float)(92.8),"�ӱ�"},
			};
			cout << "set��������(����): " << endl;
			cout << "Ӧ�������˼������诣�֣�����������������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;


			cout << "set��������(����): " << endl;
			cout << "Ӧ����������ƣ�֣�������诣���˼��������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = set1.rbegin(); it != set1.rend(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;



			set<student> set2;
			cout << "���Ե�������СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (set2.begin() == set2.end()) << endl;

			cout << endl;

			cout << "���Ե�������СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (set2.rbegin() == set2.rend());

			cout << endl << endl;

			set<student> set3(set1);
			cout << "���������ĸ��ƹ���" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����˼������诣�֣�����������������Ϣ " << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set3.insert(a[0]);
			set3.insert(a[1]);
			set3.insert(a[2]);

			cout << "����insert()����" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�������ڣ���˼������诣�ׯ�񻪣���Ң��֣�����������������Ϣ " << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set3.insert(a[0]);
			cout << "����set������Ԫ�ز�����ͬ" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�������ڣ���˼������诣�ׯ�񻪣���Ң��֣�����������������Ϣ" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			cout << "���Բ����Ԫ���Ƿ�ɹ�" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set3.insert(a[1]).second << endl;
			cout << "���������е�Ԫ�صĵ�������Ӧλ�õ�ֵΪ��" << endl;
			cout << "Ӧ�������ڵ���Ϣ" << endl;
			cout << "ʵ���ǣ�" << *set3.insert(a[1]).first << endl;

			set<student> set4(set1.begin(), set1.end());

			cout << "���������ĵ��������乹��" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����˼������诣�֣�����������������Ϣ" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set4.begin(); it != set4.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set<student> set5;

			set5.insert(mother, mother + 4);

			cout << "�����������������乹��" << endl;
			cout << "set��������(����): " << endl;
			cout << "Ӧ�����˼������诣�֣�����������������Ϣ" << endl;
			cout << "ʵ���ǣ�";

			for (auto it = set5.begin(); it != set5.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

		}

		/* ��1����� */
		if (test_student[1]) {
			press_key(1, "��1����ԣ�\n size()��max_size()��count()��empty()����");

			set<student> set1(mother, mother + 4);
			set<student> set2;
			student a[3] = { {1853790,"ׯ��",'f',(float)(92.7),"ɽ��"},
					{1852024,"�����",'f',(float)(90.9),"����"},
					{1851909,"��Ң",'f',(float)(92.8),"�ӱ�"},
			};


			cout << "size()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����4" << endl;
			cout << "ʵ���ǣ�" << set1.size() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set2.size() << endl;

			cout << endl;

			cout << "max_size()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����63161283" << endl;
			cout << "ʵ���ǣ�" << set1.max_size() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����63161283" << endl;
			cout << "ʵ���ǣ�" << set2.max_size() << endl;

			cout << endl;

			cout << "empty()����: " << endl;
			cout << "set1:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set1.empty() << endl;
			cout << "set2:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << set2.empty() << endl;

			cout << endl;

			//��Ȼset��count()��������ֵֻ��0/1���ֿ��ܣ������ǲ�һ����~
			cout << "count()����: " << endl;
			cout << "set1����˼����Ϣ�ĸ���:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << set1.count(mother[3]) << endl;
			cout << "set1��ׯ�񻪵ĸ���:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << set1.count(a[0]) << endl;
			cout << endl << endl;

		}

		/* ��2����� */
		if (test_student[2]) {

			press_key(1, "��2����ԣ�\n find(),erase(),clear()����");

			set<student> set1(mother, mother + 4);
			set<student> set2(set1);
			student a[3] = { {1853790,"ׯ��",'f',(float)(92.7),"ɽ��"},
				{1852024,"�����",'f',(float)(90.9),"����"},
				{1851909,"��Ң",'f',(float)(92.8),"�ӱ�"},
			};

			auto it = set1.find(mother[0]);
			cout << "����find()����(���ҵ�)�� " << endl;
			cout << "Ӧ�����诵ĸ�����Ϣ" << endl;
			cout << "ʵ���ǣ�";
			cout << *it << endl;

			cout << endl;

			cout << endl;

			it = set1.find(a[0]);
			cout << "����find()����(�����ҵ�)�� " << endl;
			cout << "Ӧ�����ׯ�񻪵ĸ�����Ϣ�����ҵ�" << endl;
			cout << "ʵ���ǣ�";
			if (it != set1.end())
				cout << "ׯ�񻪵ĸ�����Ϣ���ҵ�" << endl;
			else
				cout << "ׯ�񻪵ĸ�����Ϣ�����ҵ�" << endl;

			cout << endl;

			cout << endl;
			set1.erase(mother[0]);
			cout << "erase()����ΪԪ��ֵ�Ĳ���,��������(����): " << endl;
			cout << "Ӧ�����˼����֣�����������������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			it = set1.find(mother[3]);
			set1.erase(it);
			cout << "erase()����Ϊ�������Ĳ���,��������(����): " << endl;
			cout << "Ӧ���֣�����������������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set1.erase(set1.begin(), set1.end());
			cout << "erase()����Ϊ����������Ĳ��ԣ��жϴ�ʱ������С�Ƿ�Ϊ0: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�";
			cout << set1.size() << endl;

			cout << endl;

			cout << endl;

			set2.clear();
			cout << "clear()����������ԣ��жϴ�ʱ������С�Ƿ�Ϊ0: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�";
			cout << set1.empty() << endl;

			cout << endl;

			cout << endl;
		}

		/* ��3����� */
		if (test_student[3]) {
			press_key(1, "��3����ԣ�\n lower_bound()������upper_bound()������equal_range()����");

			set<student> set1(mother, mother + 4);
			student a[3] = { {1853790,"ׯ��",'f',(float)(92.7),"ɽ��"},
					{1852024,"�����",'f',(float)(90.9),"����"},
					{1851909,"��Ң",'f',(float)(95.8),"�ӱ�"},
			};
			cout << "�ҵõ�Ԫ�ص������" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "��һ�����ڻ���ھ�诵�Ԫ��: " << endl;
			cout << "Ӧ�����诵ĸ�����Ϣ" << endl;
			cout << "ʵ���ǣ�" << *set1.lower_bound(mother[0]) << endl;
			cout << "��һ�����ڻ������˼����Ԫ��: " << endl;
			cout << "Ӧ�����˼���ĸ�����Ϣ" << endl;
			cout << "ʵ���ǣ�" << *set1.lower_bound(mother[3]) << endl;
			cout << "��һ�����ھ�诵�Ԫ��: " << endl;
			cout << "Ӧ���֣����ĸ�����Ϣ" << endl;
			cout << "ʵ���ǣ�" << *set1.upper_bound(mother[0]) << endl;

			cout << endl;
			cout << endl;

			cout << "�Ҳ���Ԫ�ص������" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "��һ�����ڻ������Ң��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.lower_bound(a[2]) == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.lower_bound(a[2]) << endl;

			cout << "��һ�����������Ƶ�Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.upper_bound(mother[1]) == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.upper_bound(mother[1]) << endl;

			cout << endl << endl;

			cout << "�ҵõ�Ԫ�ص������" << endl;

			cout << "equal_range test:" << endl;
			cout << "��һ�����ڻ���ھ�诵�Ԫ��: " << endl;
			cout << "Ӧ�����诵ĸ�����Ϣ" << endl;
			cout << "ʵ���ǣ�" << *set1.equal_range(mother[0]).first << endl;
			cout << "��һ�����ھ�诵�Ԫ��: " << endl;
			cout << "Ӧ���֣����ĸ�����Ϣ" << endl;
			cout << "ʵ���ǣ�" << *set1.equal_range(mother[0]).second << endl;
			cout << endl;
			cout << endl;

			cout << "�Ҳ���Ԫ�ص������" << endl;
			cout << "equal_range test:" << endl;
			cout << "��һ�����ڻ������Ң��Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.equal_range(a[2]).first == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.lower_bound(a[2]) << endl;

			cout << "��һ�����������Ƶ�Ԫ��: " << endl;
			cout << "Ӧ������Ҳ�������Ҫ���Ԫ��" << endl;
			cout << "ʵ���ǣ�";
			if (set1.equal_range(mother[1]).second == set1.end())
				cout << "�Ҳ�������Ҫ���Ԫ��" << endl;
			else
				cout << "��Ԫ��Ϊ" << *set1.equal_range(mother[1]).second << endl;
			cout << endl;
			cout << endl;
		}

		/* ��4����� */
		if (test_student[4]) {
			press_key(1, "��4����ԣ�\n swap()����");
			student a[3] = { {1853790,"ׯ��",'f',(float)(92.7),"ɽ��"},
									{1852024,"�����",'f',(float)(90.9),"����"},
									{1851909,"��Ң",'f',(float)(95.8),"�ӱ�"},
			};
			set<student> set1, set2;
			set1.insert(mother, mother + 4);
			set2.insert(a, a + 3);
			cout << "swap()����: " << endl;
			cout << "set1�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << "set2�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << "���н���" << endl;

			set1.swap(set2);
			cout << "set1�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << "set2�е�Ԫ�ر��������򣩣�" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << endl;
		}

		/* ��5����� */
		if (test_student[5]) {
			press_key(1, "��5����ԣ�\n ���� == !=��˳�������set�������бȽϣ��Ƚ�ѧ�ţ����������в��ԣ�");

			set<student> set1(mother, mother + 4);
			set<student> set2;
			set2.insert(mother[0]);
			set2.insert(mother[1]);
			set2.insert(mother[2]);
			set2.insert(mother[3]);
			set<student> set3;
			set2.insert(mother[0]);
			set2.insert(mother[1]);
			set2.insert(mother[3]);


			cout << "set1��set2�Ƚ�: " << endl;
			cout << "Ӧ�����1 0" << endl;
			cout << "ʵ���ǣ�";
			cout << ((set1 == set2) ? 1 : 0) << " ";
			cout << ((set1 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "set1��set3�Ƚ�: " << endl;
			cout << "Ӧ�����0 1" << endl;
			cout << "ʵ���ǣ�";
			cout << ((set1 == set3) ? 1 : 0) << " ";
			cout << ((set1 != set3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		/* ��6����� */
		if (test_student[6]) {
			press_key(1, "��6����ԣ�\n �Զ�������������");
			set<student, studentComp> s;
			s.insert(mother, mother + 4);
			cout << "Test output :" << endl;
			cout << "Ӧ��������ƣ�֣�������诣���˼��������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = s.begin(); it != s.end(); it++)
				cout << *it << endl;
			cout << endl;
			cout << endl;
		}
	}
#endif
	return 0;
}
