
#include <iostream>
#include <string>
#include <map>
#include "tj_student.h"
#include "tj_multimap.h"
using namespace std;

/* ���궨��ע�͵�������ϵͳarray�Ĳ��ԣ�
   �򿪺궨�壬������Լ��� tj_array */
#define	multimap	tj_multimap


void press_key(int num, const char* prompt)
{
	int i;
	cout << endl << prompt << "�������������...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}

string tmp = "test";
int main()
{
	//int
	if (1) {
		press_key(1, "\n key=int,value=int���ԣ�\n");
		int test_int[] = { 1,1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		// ��1����� 
		if (test_int[0]) {
			press_key(1, "��1����ԣ�\n size()��empty()����");
			cout << "������multimap" << endl;
			multimap<int, int>m1;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;
			cout << "max_size()����: " << endl;
			cout << "Ӧ�����178956970" << endl;
			cout << "ʵ���ǣ�" << m1.max_size() << endl;
		}
		if (test_int[1]) {
			press_key(1, "��2����ԣ�\n �������뷽ʽ");
			multimap<int, int>m1;
			cout << "multimap�и�ֵ" << endl;
			pair<int, int> temp_pair(1, 100);
			m1.insert(temp_pair);
			cout << "insert(   pair   )��ʽ����ɹ�" << endl;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;

			m1.emplace(2, 200);
			cout << "emplace��ʽ����ɹ�" << endl;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����2" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;

			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << endl;
			}

			cout << endl << "����" << endl;
			cout << "Ӧ�����key=1   value=100        key=2   value=200" << endl;
			cout << "ʵ���ǣ�";
			multimap<int, int>m2 = m1;
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}

			cout << endl << "��ֵ" << endl;
			multimap<int, int>m3;
			m3 = m1;
			cout << "Ӧ�����key=1   value=100        key=2   value=200" << endl;
			cout << "ʵ���ǣ�";
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}
			cout << endl;
		}
		// ��2����� 
		if (test_int[2]) {
			press_key(1, "��3����ԣ�\n begin/end/��rbegin/rend/����");

			multimap<int, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			cout << "����(����): " << endl;
			cout << "Ӧ�����1-100 2-200 3-300 4-400 5-500" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = m1.begin(); it != m1.end(); it++) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;




			cout << "����(����): " << endl;
			cout << "Ӧ�����5-500 4-400 3-300 2-200 1-100" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;

			multimap<int, int>m2;
			cout << "���Ե�multimap��СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (m2.begin() == m2.end()) << endl;

			cout << endl;

			cout << "���Ե�multimap��СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (m2.rbegin() == m2.rend());

			cout << endl << endl;
		}

		// ��4����� 
		if (test_int[3]) {
			press_key(1, "��4����ԣ�\n erase��insert");
			cout << "insert�Ĳ���";
			multimap<int, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			multimap<int, int>m2;
			for (int i = 5; i <= 10; i++)
				m2.insert(make_pair(i, i * 100));
			auto q = m2.begin();
			q++; q++;
			m1.insert(m2.begin(), q);
			cout << "���Ӧ����:\n1-100 2-200 3-300 4-400 5-500 5-500 6-600 " << endl << "ʵ����: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			cout << "����insert�ķ���ֵ �����Ӧ���� 1,  " << "ʵ����: ";
			q = m1.insert(make_pair(0, 5000));
			cout << (q == m1.begin()) << endl;

			cout << "erase�Ĳ���";
			q = m1.end();
			q = m1.erase(--q);
			cout << "����erase�ķ���ֵ �����Ӧ���� 1,  " << "ʵ����: ";
			cout << (q == m1.end()) << endl;
			cout << "ɾ��һ��Ԫ��" << endl;
			cout << "���Ӧ����:\n 0-5000 1-100 2-200 3-300 4-400 5-500 5-500 " << endl << "ʵ����: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			q = m1.begin();
			q++;
			auto q_e = m1.end();
			m1.erase(q, q_e);
			cout << "ɾ�����Ԫ��" << endl;
			cout << "���Ӧ����: 0-5000" << endl << "ʵ����: ";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}

		// ��5����� 
		if (test_int[4]) {
			press_key(1, "��5����ԣ�\n find()/lower_bound()/upper_bound()/count()");
			multimap<int, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			for (int i = 1; i <= 3; i++)
				m1.emplace(2, i + 100);
			auto n1 = m1.find(2);
			cout << "find()�Ĳ���,Ӧ����2-200��ʵ����";
			cout << (*n1).first << "-" << (*n1).second << endl;
			auto n2 = m1.lower_bound(2);
			cout << "lower_bound()�Ĳ���,Ӧ����2-200��ʵ����";
			cout << (*n2).first << " -" << (*n2).second << endl;
			n2 = m1.upper_bound(2);
			cout << "upper_bound()�Ĳ���,Ӧ����3-300��ʵ����";
			cout << (*n2).first << " -" << (*n2).second << endl;

			cout << "-----" << endl;
			cout << "equal_range()�Ĳ���,Ӧ����2-200 2-101 2-102 2-103��ʵ����";
			auto q = m1.equal_range(2);
			for (auto p = q.first; p != q.second; p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << "count()�Ĳ���,Ӧ����4��ʵ����";
			cout << m1.count(2) << endl;

			cout << endl << "findʧ�ܵ����" << endl;

			auto p1 = m1.find(100);
			cout << "find()�Ҳ����ڵ�ֵ�Ĳ���,Ӧ��1��ʵ����  ";
			cout << (p1 == m1.end()) << endl;
			auto p2 = m1.lower_bound(100);
			cout << "lower_bound()�Ҳ����ڵ�ֵ�Ĳ���,Ӧ��1��ʵ����  ";
			cout << (p2 == m1.end()) << endl;
			auto p3 = m1.upper_bound(100);
			cout << "upper_bound()�Ҳ����ڵ�ֵ�Ĳ���,Ӧ��1��ʵ����  ";
			cout << (p3 == m1.end()) << endl;
		}

		// ��6����� 
		if (test_int[5]) {
			press_key(1, "��6����ԣ�\n key_comp");
			multimap<int, int>m1;
			bool r;
			r = m1.key_comp()(3, 5);
			cout << "key_comp()�Ĳ��ԣ����Ӧ���ǣ�1��ʵ����";
			cout << r << endl;
			r = m1.key_comp()(3, 3);
			cout << "key_comp()�Ĳ��ԣ����Ӧ���ǣ�0��ʵ����";
			cout << r << endl;
			r = m1.key_comp()(5, 3);
			cout << "key_comp()�Ĳ��ԣ����Ӧ���ǣ�0��ʵ����";
			cout << r << endl;
		}

		// ��7����� 
		if (test_int[6]) {

			press_key(1, "��7����ԣ�\n swap()  ");
			multimap<int, int>m1;
			multimap<int, int>m2;
			for (int i = 1; i <= 3; i++)
				m1.emplace(i, i * 100);
			for (int i = 8; i <= 9; i++)
				m2.emplace(i, i * 100);

			cout << "swap()�Ĳ���" << endl;
			m1.swap(m2);
			cout << "m1 Ӧ���� 8-800 9-900��ʵ����";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 Ӧ����1-100 2-200 3-300��ʵ����";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "�ٴν����Ĳ���" << endl;
			m1.swap(m2);
			cout << "m1 Ӧ����1-100 2-200 3-300��ʵ����";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 Ӧ����8-800 9-900��ʵ����";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}
		// ��8����� 
		if (test_int[7]) {

			press_key(1, "��8����ԣ����ز���,clear���� ");
			multimap<int, int>m1;
			multimap<int, int>m2;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			for (int i = 1; i <= 3; i++)
				m2.emplace(i, i * 100);
			for (int i = 8; i <= 12; i++)
				m2.emplace(i, i * 100);
			cout << "<�Ų���" << "Ӧ���  1��ʵ�����" << (m1 < m2) << endl;
			cout << ">�Ų���" << "Ӧ���  0��ʵ�����" << (m1 > m2) << endl;
			cout << "=�Ų���" << "Ӧ���  0��ʵ�����" << (m1 == m2) << endl;

			m1.clear();
			m2.clear();
			cout << "clear m1,Ӧ��� 1��ʵ�����" << m1.empty() << endl;
			cout << "clear m2,Ӧ��� 1��ʵ�����" << m2.empty() << endl;
			cout << "<�Ų���" << "Ӧ���  0��ʵ�����" << (m1 < m2) << endl;
			cout << ">�Ų���" << "Ӧ���  0��ʵ�����" << (m1 > m2) << endl;
			cout << "=�Ų���" << "Ӧ���  1��ʵ�����" << (m1 == m2) << endl;
		}
	}
	//string int
	if (1) {
		press_key(1, "\n key=string,value=int���ԣ�\n");
		int test_int[] = { 1,1,1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		// ��1����� 
		if (test_int[0]) {
			press_key(1, "��1����ԣ�\n size()��empty()����");
			cout << "������multimap" << endl;
			multimap<string, int>m1;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;
			cout << "max_size()����: " << endl;
			cout << "Ӧ�����89478485" << endl;
			cout << "ʵ���ǣ�" << m1.max_size() << endl;
		}
		if (test_int[1]) {
			press_key(1, "��2����ԣ�\n �������뷽ʽ");
			multimap<string, int>m1;
			cout << "multimap�и�ֵ" << endl;
			pair<string, int> temp_pair("test1", 100);
			m1.insert(temp_pair);
			cout << "insert(   pair   )��ʽ����ɹ�" << endl;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;

			m1.emplace("test2", 200);
			cout << "emplace��ʽ����ɹ�" << endl;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����2" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;

			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << endl;
			}

			cout << endl << "����" << endl;
			cout << "Ӧ�����key=test1   value=100        key=test2   value=200" << endl;
			cout << "ʵ���ǣ�";
			multimap<string, int>m2 = m1;
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}

			cout << endl << "��ֵ" << endl;
			multimap<string, int>m3;
			m3 = m1;
			cout << "Ӧ�����key=test1   value=100        key=test2   value=200" << endl;
			cout << "ʵ���ǣ�";
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}
			cout << endl;
		}
		// ��2����� 
		if (test_int[2]) {
			press_key(1, "��3����ԣ�\n begin/end/��rbegin/rend/����");
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			cout << "����(����): " << endl;
			cout << "Ӧ�����test1-100 test2-200 test3-300 test4-400 test5-500" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = m1.begin(); it != m1.end(); it++) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;




			cout << "����(����): " << endl;
			cout << "Ӧ�����test5-500 test4-400 test3-300 test2-200 test1-100" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;

			multimap<int, int>m2;
			cout << "���Ե�multimap��СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (m2.begin() == m2.end()) << endl;

			cout << endl;

			cout << "���Ե�multimap��СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (m2.rbegin() == m2.rend());

			cout << endl << endl;
		}

		// ��4����� 
		if (test_int[3]) {
			press_key(1, "��4����ԣ�\n erase��insert");
			cout << "insert�Ĳ���";
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			multimap<string, int>m2;
			for (int i = 5; i <= 10; i++)
				m2.insert(make_pair(tmp + char('0' + i), i * 100));
			auto q = m2.begin();
			q++; q++;
			m1.insert(m2.begin(), q);
			cout << "���Ӧ����:\ntest1-100 test2-200 test3-300 test4-400 test5-500 test5-500 test6-600 " << endl << "ʵ����: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			cout << "����insert�ķ���ֵ �����Ӧ���� 1,  " << "ʵ����: ";
			q = m1.insert(make_pair("test0", 5000));
			cout << (q == m1.begin()) << endl;

			cout << "erase�Ĳ���";
			q = m1.end();
			q = m1.erase(--q);
			cout << "����erase�ķ���ֵ �����Ӧ���� 1,  " << "ʵ����: ";
			cout << (q == m1.end()) << endl;
			cout << "ɾ��һ��Ԫ��" << endl;
			cout << "���Ӧ����:\n test0-5000 test1-100 test2-200 test3-300 test4-400 test5-500 test5-500 " << endl << "ʵ����: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			q = m1.begin();
			q++;
			auto q_e = m1.end();
			m1.erase(q, q_e);
			cout << "ɾ�����Ԫ��" << endl;
			cout << "���Ӧ����: test0-5000" << endl << "ʵ����: ";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}

		// ��5����� 
		if (test_int[4]) {
			press_key(1, "��5����ԣ�\n find()/lower_bound()/upper_bound()/count()");
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			for (int i = 1; i <= 3; i++)
				m1.emplace("test2", i + 100);
			auto n1 = m1.find("test2");
			cout << "find()�Ĳ���,Ӧ����test2-200��ʵ����";
			cout << (*n1).first << "-" << (*n1).second << endl;
			auto n2 = m1.lower_bound("test2");
			cout << "lower_bound()�Ĳ���,Ӧ����test2-200��ʵ����";
			cout << (*n2).first << " -" << (*n2).second << endl;
			n2 = m1.upper_bound("test2");
			cout << "upper_bound()�Ĳ���,Ӧ����test3-300��ʵ����";
			cout << (*n2).first << " -" << (*n2).second << endl;

			cout << "-----" << endl;
			cout << "equal_range()�Ĳ���,Ӧ����test2-200 test2-101 test2-102 test2-103��ʵ����";
			auto q = m1.equal_range("test2");
			for (auto p = q.first; p != q.second; p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << "count()�Ĳ���,Ӧ����4��ʵ����";
			cout << m1.count("test2") << endl;

			cout << endl << "findʧ�ܵ����" << endl;

			auto p1 = m1.find("test200");
			cout << "find()�Ҳ����ڵ�ֵ�Ĳ���,Ӧ��1��ʵ����  ";
			cout << (p1 == m1.end()) << endl;
			auto p2 = m1.lower_bound("test200");
			cout << "lower_bound()�Ҳ����ڵ�ֵ�Ĳ���,Ӧ��0��ʵ����  ";
			cout << (p2 == m1.end()) << endl;
			auto p3 = m1.upper_bound("test200");
			cout << "upper_bound()�Ҳ����ڵ�ֵ�Ĳ���,Ӧ��0��ʵ����  ";
			cout << (p3 == m1.end()) << endl;
		}

		// ��6����� 
		if (test_int[5]) {
			press_key(1, "��6����ԣ�\n key_comp");
			multimap<string, int>m1;
			bool r;
			r = m1.key_comp()("test200", "test300");
			cout << "key_comp()�Ĳ��ԣ����Ӧ���ǣ�1��ʵ����";
			cout << r << endl;
			r = m1.key_comp()("test300", "test300");
			cout << "key_comp()�Ĳ��ԣ����Ӧ���ǣ�0��ʵ����";
			cout << r << endl;
			r = m1.key_comp()("test300", "test200");
			cout << "key_comp()�Ĳ��ԣ����Ӧ���ǣ�0��ʵ����";
			cout << r << endl;
		}

		// ��7����� 
		if (test_int[6]) {

			press_key(1, "��7����ԣ�\n swap()  ");
			multimap<string, int>m1;
			multimap<string, int>m2;
			for (int i = 1; i <= 3; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			for (int i = 8; i <= 9; i++)
				m2.emplace(tmp + char('0' + i), i * 100);

			cout << "swap()�Ĳ���" << endl;
			m1.swap(m2);
			cout << "m1 Ӧ���� test8-800 test9-900��ʵ����";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 Ӧ����test1-100 test2-200 test3-300��ʵ����";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "�ٴν����Ĳ���" << endl;
			m1.swap(m2);
			cout << "m1 Ӧ����test1-100 test2-200 test3-300��ʵ����";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 Ӧ����test8-800 test9-900��ʵ����";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}
		// ��8����� 
		if (test_int[7]) {

			press_key(1, "��8����ԣ����ز���,clear���� ");
			multimap<string, int>m1;
			multimap<string, int>m2;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			for (int i = 1; i <= 3; i++)
				m2.emplace(tmp + char('0' + i), i * 100);
			for (int i = 8; i <= 9; i++)
				m2.emplace(tmp + char('0' + i), i * 100);
			cout << "<�Ų���" << "Ӧ���  1��ʵ�����" << (m1 < m2) << endl;
			cout << ">�Ų���" << "Ӧ���  0��ʵ�����" << (m1 > m2) << endl;
			cout << "=�Ų���" << "Ӧ���  0��ʵ�����" << (m1 == m2) << endl;

			m1.clear();
			m2.clear();
			cout << "clear m1,Ӧ��� 1��ʵ�����" << m1.empty() << endl;
			cout << "clear m2,Ӧ��� 1��ʵ�����" << m2.empty() << endl;
			cout << "<�Ų���" << "Ӧ���  0��ʵ�����" << (m1 < m2) << endl;
			cout << ">�Ų���" << "Ӧ���  0��ʵ�����" << (m1 > m2) << endl;
			cout << "=�Ų���" << "Ӧ���  1��ʵ�����" << (m1 == m2) << endl;
		}

		// ��9����� 
		if (test_int[9])
		{
			press_key(1, "��5����ԣ���ͬ���Ĳ��� ");
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('1'), i);
			cout << "Ӧ�����" << endl;
			cout << "test1 - 1" << endl;
			cout << "test1 - 2" << endl;
			cout << "test1 - 3" << endl;
			cout << "test1 - 4" << endl;
			cout << "test1 - 5" << endl;
			cout << "ʵ���ǣ�" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;
		}
	}
	//string student
	if (1) {
		press_key(1, "\n key=string,value=student���ԣ�\n");
		int test_int[] = { 1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		student t[4] = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
								{1003,"t3",'M',83,"test3" } ,{1004,"t4",'F',84,"test4" } };

		// ��1����� 
		if (test_int[0]) {
			press_key(1, "��1����ԣ�\n size()��empty()����");
			cout << "������multimap" << endl;
			multimap<string, student>m1;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;
			cout << "max_size()����: " << endl;
			cout << "Ӧ�����44739242" << endl;
			cout << "ʵ���ǣ�" << m1.max_size() << endl;
		}
		if (test_int[1]) {
			press_key(1, "��2����ԣ�\n �������뷽ʽ");
			multimap<string, student>m1;
			cout << "multimap�и�ֵ" << endl;
			pair<string, student> temp_pair("test1", t[0]);
			m1.insert(temp_pair);
			cout << "insert(   pair   )��ʽ����ɹ�" << endl;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;

			m1.emplace("test2", t[1]);
			cout << "emplace��ʽ����ɹ�" << endl;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << m1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����2" << endl;
			cout << "ʵ���ǣ�" << m1.size() << endl;

			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << endl;
			}

			cout << endl << "����" << endl;
			cout << "Ӧ�����key=test1   value=1001 t1 M 81 test1        key=test2   value=1002 t2 F 82 test2" << endl;
			cout << "ʵ���ǣ�";
			multimap<string, student>m2 = m1;
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}

			cout << endl << "��ֵ" << endl;
			multimap<string, student>m3;
			m3 = m1;
			cout << "Ӧ�����key=test1   value=1001 t1 M 81 test1        key=test2   value=1002 t2 F 82 test2" << endl;
			cout << "ʵ���ǣ�";
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}
			cout << endl;
		}
		// ��2����� 
		if (test_int[2]) {
			press_key(1, "��3����ԣ�\n begin/end/��rbegin/rend/����");
			multimap<string, student>m1;
			for (int i = 0; i <= 2; i++)
				m1.emplace(tmp + char('0' + i), t[i]);
			cout << "����(����): " << endl;
			cout << "Ӧ�����\n" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test2 - 1003 t3 M 83 test3" << endl;
			cout << "ʵ���ǣ�\n";
			for (auto it = m1.begin(); it != m1.end(); it++) {
				cout << (*it).first << " - " << (*it).second << endl;
			}
			cout << endl;

			cout << endl;

			cout << "����(����): " << endl;
			cout << "Ӧ�����\n" << endl;
			cout << "test2 - 1003 t3 M 83 test3" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;

			cout << "ʵ���ǣ�\n";
			for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
				cout << (*it).first << " - " << (*it).second << endl;
			}
			cout << endl;

			cout << endl;

			multimap<int, student>m2;
			cout << "���Ե�multimap��СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (m2.begin() == m2.end()) << endl;

			cout << endl;

			cout << "���Ե�multimap��СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (m2.rbegin() == m2.rend());

			cout << endl << endl;
		}

		// ��4����� 
		if (test_int[3]) {
			press_key(1, "��4����ԣ�\n erase��insert");
			cout << "insert�Ĳ���";
			multimap<string, student>m1;
			for (int i = 0; i <= 1; i++)
				m1.emplace(tmp + char('0' + i), t[i]);
			multimap<string, student>m2;
			for (int i = 0; i <= 3; i++)
				m2.insert(make_pair(tmp + char('0' + i), t[i]));
			auto q = m2.begin();
			q++; q++;
			m1.insert(m2.begin(), q);
			cout << "Ӧ�����" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;

			cout << "ʵ���ǣ�" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;
			cout << "����insert�ķ���ֵ �����Ӧ���� 1,  " << "ʵ����: ";
			q = m1.insert(make_pair("test", t[3]));
			cout << (q == m1.begin()) << endl;

			cout << "erase�Ĳ���";
			q = m1.end();
			q = m1.erase(--q);
			cout << "����erase�ķ���ֵ �����Ӧ���� 1,  " << "ʵ����: ";
			cout << (q == m1.end()) << endl;
			cout << "ɾ��һ��Ԫ��" << endl;
			cout << "Ӧ�����" << endl;
			cout << "test - 1004 t4 F 84 test4" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "ʵ���ǣ�" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;
		}

		// ��5����� 
		if (test_int[4]) {

			press_key(1, "��5����ԣ���ͬ���Ĳ��� ");
			multimap<string, student>m1;
			for (int i = 0; i <= 3; i++)
				m1.emplace(tmp + char('1'), t[i]);
			cout << "Ӧ�����" << endl;
			cout << "test1 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test1 - 1003 t3 M 83 test3" << endl;
			cout << "test1 - 1004 t4 F 84 test4" << endl;
			cout << "ʵ���ǣ�" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;

		}
	}

	return 0;
}
