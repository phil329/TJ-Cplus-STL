
#include <iostream>
#include <string>
#include <list>
//#include"tj_list.cpp"
#include"tj_student_list.h"

using namespace std;

//�����������䣬�ǵ�push_back�������׳��쳣
/* ���궨��ע�͵�������ϵͳarray�Ĳ��ԣ�
   �򿪺궨�壬������Լ��� tj_array */
//#define	list	tj_list


void press_key(int num, const char *prompt)
{
	int i;
	cout << endl << prompt << "�������������...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}


int main()
{
	//int
	if (1) {
		press_key(1, "\n int���ԣ�\n");
		int test_int[] = { 1,1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		// ��1����� 
		if (test_int[0]) {
			press_key(1, "��1����ԣ�\n size()��empty()����");

			cout << "������list" << endl;
			list<int> t1;
			cout << "empty()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << t1.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << t1.size() << endl;

			cout << "����5��Ԫ�ص�list" << endl;
			list<int> t2(5);
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << t2.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << t2.size() << endl;

			cout << "��5��Ԫ�ص�list  t2��ʼ��" << endl;
			list<int> t3(t2);
			cout << "empty()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << t3.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << t3.size() << endl;

			cout << "�ÿյ�list  t1��ʼ��" << endl;
			list<int> t4(t1);
			cout << "empty()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << t4.empty() << endl;
			cout << "size()����: " << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << t4.size() << endl;

		}

		// ��2����� 
		if (test_int[1]) {
			press_key(1, "��2����ԣ�\n begin/end/cbegin/cend()��rbegin/rend/crbegin/crend()����");

			list<int> t1 = { 1, 2, 3, 4, 5 };

			cout << "����(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.cbegin(); it != t1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "�������(����): " << endl;
			cout << "Ӧ�����5 4 3 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�����5 4 3 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.crbegin(); it != t1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			list<int> t2;
			cout << "���Ե�list��СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (t2.begin() == t2.end()) << endl;

			cout << endl;

			cout << "���Ե�list��СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (t2.rbegin() == t2.rend());

			cout << endl << endl;
		}

		// ��3����� 
		if (test_int[2]) {
			press_key(1, "��3����ԣ�\n push_back() push_front() pop_back() pop_front() ����");
			list<int> t1 = { 1,2,3,4,5 };
			t1.pop_back();
			cout << "pop_back()�Ĳ���";
			cout << "���Ӧ����:1 2 3 4       " << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_back(6);
			cout << "push_back()�Ĳ���";
			cout << "���Ӧ����:1 2 3 4 6     " << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.pop_front();
			cout << "pop_front()�Ĳ���";
			cout << "���Ӧ����:2 3 4 6       " << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_front(7);
			cout << "push_front()�Ĳ���";
			cout << "���Ӧ����:7 2 3 4 6    " << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// ��4����� 
		if (test_int[3]) {
			press_key(1, "��4����ԣ�\n erase��insert");
			cout << "insert�Ĳ���";
			list<int> t1 = { 1,2,3,4,5 };
			auto q = t1.insert(t1.begin(), 9);
			cout << "����һ��Ԫ��" << endl;
			cout << "���Ӧ����:9 1 2 3 4 5" << endl << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "����insert�ķ���ֵ �����Ӧ���� 1" << endl << "ʵ����: ";
			cout << (q == t1.begin()) << endl;
			t1.insert(t1.begin(), 3, -1);
			cout << "������Ԫ��" << endl;
			cout << "���Ӧ����:-1 -1 -1 9 1 2 3 4 5" << endl << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;

			cout << "erase�Ĳ���";
			q = t1.end();
			q = t1.erase(--q);
			cout << "����erase�ķ���ֵ �����Ӧ���� 1" << endl << "ʵ����: ";
			cout << (q == t1.end()) << endl;
			cout << "ɾ��һ��Ԫ��" << endl;
			cout << "���Ӧ����:-1 -1 -1 9 1 2 3 4" << endl << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.erase(--q);
			cout << "ɾ��һ��Ԫ��" << endl;
			cout << "���Ӧ����:-1 -1 -1 9 1 2 3" << endl << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.erase(t1.begin());
			cout << "ɾ��һ��Ԫ��" << endl;
			cout << "���Ӧ����:-1 -1 9 1 2 3" << endl << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			auto p = t1.begin();
			auto t = t1.begin();
			t++;
			t++;
			t1.erase(p, t);
			cout << "ɾ�����Ԫ��" << endl;
			cout << "���Ӧ����: 9 1 2 3" << endl << "ʵ����: ";
			for (auto k = t1.begin(); k != t1.end(); k++)
				cout << *k << " ";
			cout << endl;
		}

		// ��5����� 
		if (test_int[5]) {
			press_key(1, "��5����ԣ�\n Back()/front()/swap()");
			list<int> t1 = { 1, 2, 3, 4, 5 };
			list<int> t2 = { -5,-4,-3,-2 };

			cout << "front()�Ĳ���,Ӧ���� 1��ʵ����";
			cout << t1.front() << endl;
			cout << "front()���++�Ĳ���,Ӧ���� 2��ʵ����";
			cout << ++t1.front() << endl;
			cout << "back()�Ĳ���,Ӧ���� 5��ʵ����";
			cout << t1.back() << endl;
			cout << "back()���++�Ĳ���,Ӧ���� 6��ʵ����";
			cout << ++t1.back() << endl;

			cout << "swap()�Ĳ���" << endl;
			t1.swap(t2);
			cout << "t1 Ӧ���� -5 -4 -3 -2��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 Ӧ���� 2 2 3 4 6��ʵ����";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "�ٴν����Ĳ���" << endl;
			t1.swap(t2);
			cout << "t1 Ӧ���� 2 2 3 4 6��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 Ӧ���� -5 -4 -3 -2��ʵ����";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// ��6����� 
		if (test_int[5]) {
			press_key(1, "��6����ԣ�\n sort��unique");
			list<int> t1 = { 3,2,2,1,7,2,5 };
			t1.unique();
			cout << "unique()�Ĳ��ԣ����Ӧ���ǣ�3 2 1 7 2 5��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.sort();
			cout << "unique()�Ĳ��ԣ����Ӧ���ǣ�1 2 2 3 5 7��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.unique();
			cout << "unique()�Ĳ��ԣ����Ӧ���ǣ�1 2 3 5 7��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
		}

		// ��7����� 
		if (test_int[6]) {

			press_key(1, "��7����ԣ�\n splice() reverse() ");
			list<int> t1 = { 1,2,3,4,5 };
			list<int> t2 = { 6,7,8 };

			t1.splice(t1.begin(), t2);
			cout << "splice()�Ĳ��ԣ����Ӧ���ǣ�6 7 8 1 2 3 4 5��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.reverse();
			cout << "reverse()�Ĳ��ԣ����Ӧ���ǣ�5 4 3 2 1 8 7 6��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}
		// ��8����� 
		if (test_int[7]) {

			press_key(1, "��8����ԣ�\n ���������,��Ҫ�ȴ�һ��ʱ�䣬������linux�²��ԣ�VS��ʱ�϶� ");
			list<int>a;
			for (int i = 1; ; i++)
			{
				try
				{
					a.push_back(1);
				}
				catch (...)
				{
					cout << i;
					break;
				}
			}
		}
	}
	//string
	if (1)
	{
		press_key(1, "\n string���ԣ�\n");
		int test_int[] = { 1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		// ��1����� 
		if (test_int[0]) {
			press_key(1, "��1����ԣ�\n begin/end  rbegin/rend����");

			list<string> t1 = { "test1", "test2", "test3", "test4", "test5" };

			cout << "����(����): " << endl;
			cout << "Ӧ�����test1 test2 test3 test4 test5" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "�������(����): " << endl;
			cout << "Ӧ�����test5 test4 test3 test2 test1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;
		}

		// ��2����� 
		if (test_int[1]) {
			press_key(1, "��2����ԣ�\n push_back() push_front() pop_back() pop_front() ����");
			list<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			t1.pop_back();
			cout << "pop_back()�Ĳ���";
			cout << "Ӧ�����test1 test2 test3 test4" << endl;
			cout << "ʵ���ǣ�";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_back("test6");
			cout << "push_back()�Ĳ���";
			cout << "���Ӧ����:test1 test2 test3 test4 test6    " << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.pop_front();
			cout << "pop_front()�Ĳ���";
			cout << "���Ӧ����:test2 test3 test4 test6       " << "ʵ����: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_front("test7");
			cout << "push_front()�Ĳ���";
			cout << "���Ӧ����:test7 test2 test3 test4 test6     " << "ʵ����: ";
				for (auto p = t1.begin(); p != t1.end(); p++)
					cout << *p << " ";
			cout << endl;
		}

		// ��3����� 
		if (test_int[2]) {
			press_key(1, "��5����ԣ�\n swap()");
			list<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			list<string> t2 = { "test-1", "test-2", "test-3", "test-4" };
			cout << "swap()�Ĳ���" << endl;
			t1.swap(t2);
			cout << "t1 Ӧ���� test-1 test-2 test-3 test-4��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 Ӧ���� test1 test2 test3 test4 test5��ʵ����";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "�ٴν����Ĳ���" << endl;
			t1.swap(t2);
			cout << "t1 Ӧ���� test1 test2 test3 test4 test5��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 Ӧ���� test-1 test-2 test-3 test-4��ʵ����";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// ��4����� 
		if (test_int[3]) {
			press_key(1, "��4����ԣ�\n sort��unique");
			list<string> t1 = { "test3","test2","test2","test1","test7","test2","test5" };
			t1.unique();
			cout << "unique()�Ĳ��ԣ����Ӧ���ǣ�test3 test2 test1 test7 test2 test5��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.sort();
			cout << "unique()�Ĳ��ԣ����Ӧ���ǣ�test1 test2 test2 test3 test5 test7��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.unique();
			cout << "unique()�Ĳ��ԣ����Ӧ���ǣ�test1 test2 test3 test5 test7��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
		}

		// ��5����� 
		if (test_int[4]) {

			press_key(1, "��5����ԣ�\n splice() reverse() ");
			list<string> t1 = { "t1","t2","t3","t4","t5" };
			list<string> t2 = { "t6","t7","t8" };

			t1.splice(t1.begin(), t2);
			cout << "splice()�Ĳ��ԣ����Ӧ���ǣ�t6 t7 t8 t1 t2 t3 t4 t5��ʵ����" << endl;;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.reverse();
			cout << "reverse()�Ĳ��ԣ����Ӧ���ǣ�t5 t4 t3 t2 t1 t8 t7 t6��ʵ����";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

	}
	//student
	if (1)
	{
		press_key(1, "\n student���ԣ�\n");
		int test_int[] = { 1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		// ��1����� 
		if (test_int[0]) {
			press_key(1, "��1����ԣ�\n begin/end  rbegin/rend����");

			list<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
								{1003,"t3",'M',83,"test3" } };

			cout << "����(����): " << endl;
			cout << "Ӧ�����1001 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1003 t3 M 83 test1 " << endl;
			cout << "ʵ���ǣ�";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			cout << "�������(����): " << endl;
			cout << "Ӧ�����1003 t3 M 83 test1" << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1001 t1 M 81 test1 " << endl;
			cout << "ʵ���ǣ�" << endl;
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;
		}

		// ��2����� 
		if (test_int[1]) {
			press_key(1, "��2����ԣ�\n push_back() push_front() pop_back() pop_front() ����");
			list<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1003,"t3",'M',83,"test3" } };
			t1.pop_back();
			cout << "pop_back()�Ĳ���";
			cout << "Ӧ�����1001 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "ʵ���ǣ�" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p <<endl;
			cout << endl;
			t1.push_back({ 1004,"t4",'M',84,"test4" });
			cout << "push_back()�Ĳ���";
			cout << "Ӧ�����1001 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1004 t4 M 84 test4 " << endl;
			cout<< "ʵ����: " << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.pop_front();
			cout << "pop_front()�Ĳ���";
			cout << "���Ӧ����   1002 t2 F 82 test2"<< endl;
			cout << "             1004 t4 M 84 test4 " << endl;
			cout<< "ʵ����: " << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.push_front({ 1005,"t5",'M',85,"test5" });
			cout << "push_front()�Ĳ���";
			cout << "���Ӧ����:  1005 t5 M 85 test5" << endl;
			cout << "             1002 t2 F 82 test2 " << endl;
			cout << "             1004 t4 M 84 test4 " << endl;
			cout<< "ʵ����: " << endl;
				for (auto p = t1.begin(); p != t1.end(); p++)
					cout << *p << endl;
			cout << endl;
		}


		// ��3����� 
		if (test_int[2]) {
			press_key(1, "��3����ԣ�\n sort��unique(������Ϊ���رȽϵĶ��岻ͬ���в�ͬ)");
			list<student> t1 = { {1003,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1002,"t2",'F',82,"test2" } };
			t1.unique();
			cout << "unique()����" << endl;
			cout << "Ӧ�����1003 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "ʵ����" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.sort();
			cout << "sort()�Ĳ���" << endl;
			cout << "Ӧ�����1002 t2 F 82 test2 " << endl;
			cout << "        1003 t1 M 81 test1 " << endl;
			cout << "ʵ����" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
		}

		// ��4����� 
		if (test_int[3]) {

			press_key(1, "��4����ԣ�\n  reverse() ");
			list<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1003,"t3",'M',83,"test3" } };

			t1.reverse();
			cout << "reverse()�Ĳ��ԣ����Ӧ����" << endl;
			cout << "        1003 t3 M 83 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1001 t1 M 81 test1 " << endl;
			cout << "ʵ����" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
		}
		// ��5����� 
		if (test_int[4]) {

			press_key(1, "��5����ԣ�\n ���������,��Ҫ�ȴ�һ��ʱ�䣬������linux�²��ԣ�VS��ʱ�϶� ");
			list<student>a;
			for (int i = 1; ; i++)
			{
				try
				{
					a.push_back({ 1003,"t1",'M',81,"test1" });
				}
				catch (...)
				{
					cout << i;
					break;
				}
			}
		}

	}
	return 0;
}
