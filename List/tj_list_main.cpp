
#include <iostream>
#include <string>
#include <list>
//#include"tj_list.cpp"
#include"tj_student_list.h"

using namespace std;

//测试了最大填充，记得push_back中设置抛出异常
/* 这句宏定义注释掉，就是系统array的测试，
   打开宏定义，则测试自己的 tj_array */
//#define	list	tj_list


void press_key(int num, const char *prompt)
{
	int i;
	cout << endl << prompt << "，按任意键继续...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}


int main()
{
	//int
	if (1) {
		press_key(1, "\n int测试：\n");
		int test_int[] = { 1,1,1,1,1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			press_key(1, "第1组测试：\n size()和empty()函数");

			cout << "创建空list" << endl;
			list<int> t1;
			cout << "empty()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << t1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << t1.size() << endl;

			cout << "创建5个元素的list" << endl;
			list<int> t2(5);
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << t2.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << t2.size() << endl;

			cout << "用5个元素的list  t2初始化" << endl;
			list<int> t3(t2);
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << t3.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << t3.size() << endl;

			cout << "用空的list  t1初始化" << endl;
			list<int> t4(t1);
			cout << "empty()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << t4.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << t4.size() << endl;

		}

		// 第2组测试 
		if (test_int[1]) {
			press_key(1, "第2组测试：\n begin/end/cbegin/cend()及rbegin/rend/crbegin/crend()函数");

			list<int> t1 = { 1, 2, 3, 4, 5 };

			cout << "遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";
			for (auto it = t1.cbegin(); it != t1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "数组遍历(反向): " << endl;
			cout << "应输出：5 4 3 2 1" << endl;
			cout << "实际是：";
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：5 4 3 2 1" << endl;
			cout << "实际是：";
			for (auto it = t1.crbegin(); it != t1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			list<int> t2;
			cout << "测试当list大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (t2.begin() == t2.end()) << endl;

			cout << endl;

			cout << "测试当list大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (t2.rbegin() == t2.rend());

			cout << endl << endl;
		}

		// 第3组测试 
		if (test_int[2]) {
			press_key(1, "第3组测试：\n push_back() push_front() pop_back() pop_front() 函数");
			list<int> t1 = { 1,2,3,4,5 };
			t1.pop_back();
			cout << "pop_back()的测试";
			cout << "结果应该是:1 2 3 4       " << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_back(6);
			cout << "push_back()的测试";
			cout << "结果应该是:1 2 3 4 6     " << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.pop_front();
			cout << "pop_front()的测试";
			cout << "结果应该是:2 3 4 6       " << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_front(7);
			cout << "push_front()的测试";
			cout << "结果应该是:7 2 3 4 6    " << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// 第4组测试 
		if (test_int[3]) {
			press_key(1, "第4组测试：\n erase和insert");
			cout << "insert的测试";
			list<int> t1 = { 1,2,3,4,5 };
			auto q = t1.insert(t1.begin(), 9);
			cout << "插入一个元素" << endl;
			cout << "结果应该是:9 1 2 3 4 5" << endl << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "测试insert的返回值 ，结果应该是 1" << endl << "实际是: ";
			cout << (q == t1.begin()) << endl;
			t1.insert(t1.begin(), 3, -1);
			cout << "插入多个元素" << endl;
			cout << "结果应该是:-1 -1 -1 9 1 2 3 4 5" << endl << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;

			cout << "erase的测试";
			q = t1.end();
			q = t1.erase(--q);
			cout << "测试erase的返回值 ，结果应该是 1" << endl << "实际是: ";
			cout << (q == t1.end()) << endl;
			cout << "删除一个元素" << endl;
			cout << "结果应该是:-1 -1 -1 9 1 2 3 4" << endl << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.erase(--q);
			cout << "删除一个元素" << endl;
			cout << "结果应该是:-1 -1 -1 9 1 2 3" << endl << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.erase(t1.begin());
			cout << "删除一个元素" << endl;
			cout << "结果应该是:-1 -1 9 1 2 3" << endl << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			auto p = t1.begin();
			auto t = t1.begin();
			t++;
			t++;
			t1.erase(p, t);
			cout << "删除多个元素" << endl;
			cout << "结果应该是: 9 1 2 3" << endl << "实际是: ";
			for (auto k = t1.begin(); k != t1.end(); k++)
				cout << *k << " ";
			cout << endl;
		}

		// 第5组测试 
		if (test_int[5]) {
			press_key(1, "第5组测试：\n Back()/front()/swap()");
			list<int> t1 = { 1, 2, 3, 4, 5 };
			list<int> t2 = { -5,-4,-3,-2 };

			cout << "front()的测试,应该是 1，实际是";
			cout << t1.front() << endl;
			cout << "front()结果++的测试,应该是 2，实际是";
			cout << ++t1.front() << endl;
			cout << "back()的测试,应该是 5，实际是";
			cout << t1.back() << endl;
			cout << "back()结果++的测试,应该是 6，实际是";
			cout << ++t1.back() << endl;

			cout << "swap()的测试" << endl;
			t1.swap(t2);
			cout << "t1 应该是 -5 -4 -3 -2，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 应该是 2 2 3 4 6，实际是";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "再次交换的测试" << endl;
			t1.swap(t2);
			cout << "t1 应该是 2 2 3 4 6，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 应该是 -5 -4 -3 -2，实际是";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// 第6组测试 
		if (test_int[5]) {
			press_key(1, "第6组测试：\n sort和unique");
			list<int> t1 = { 3,2,2,1,7,2,5 };
			t1.unique();
			cout << "unique()的测试，结果应该是：3 2 1 7 2 5，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.sort();
			cout << "unique()的测试，结果应该是：1 2 2 3 5 7，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.unique();
			cout << "unique()的测试，结果应该是：1 2 3 5 7，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
		}

		// 第7组测试 
		if (test_int[6]) {

			press_key(1, "第7组测试：\n splice() reverse() ");
			list<int> t1 = { 1,2,3,4,5 };
			list<int> t2 = { 6,7,8 };

			t1.splice(t1.begin(), t2);
			cout << "splice()的测试，结果应该是：6 7 8 1 2 3 4 5，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.reverse();
			cout << "reverse()的测试，结果应该是：5 4 3 2 1 8 7 6，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}
		// 第8组测试 
		if (test_int[7]) {

			press_key(1, "第8组测试：\n 最大填充测试,需要等待一段时间，建议在linux下测试，VS用时较多 ");
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
		press_key(1, "\n string测试：\n");
		int test_int[] = { 1,1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			press_key(1, "第1组测试：\n begin/end  rbegin/rend函数");

			list<string> t1 = { "test1", "test2", "test3", "test4", "test5" };

			cout << "遍历(正向): " << endl;
			cout << "应输出：test1 test2 test3 test4 test5" << endl;
			cout << "实际是：";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "数组遍历(反向): " << endl;
			cout << "应输出：test5 test4 test3 test2 test1" << endl;
			cout << "实际是：";
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;
		}

		// 第2组测试 
		if (test_int[1]) {
			press_key(1, "第2组测试：\n push_back() push_front() pop_back() pop_front() 函数");
			list<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			t1.pop_back();
			cout << "pop_back()的测试";
			cout << "应输出：test1 test2 test3 test4" << endl;
			cout << "实际是：";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_back("test6");
			cout << "push_back()的测试";
			cout << "结果应该是:test1 test2 test3 test4 test6    " << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.pop_front();
			cout << "pop_front()的测试";
			cout << "结果应该是:test2 test3 test4 test6       " << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_front("test7");
			cout << "push_front()的测试";
			cout << "结果应该是:test7 test2 test3 test4 test6     " << "实际是: ";
				for (auto p = t1.begin(); p != t1.end(); p++)
					cout << *p << " ";
			cout << endl;
		}

		// 第3组测试 
		if (test_int[2]) {
			press_key(1, "第5组测试：\n swap()");
			list<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			list<string> t2 = { "test-1", "test-2", "test-3", "test-4" };
			cout << "swap()的测试" << endl;
			t1.swap(t2);
			cout << "t1 应该是 test-1 test-2 test-3 test-4，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 应该是 test1 test2 test3 test4 test5，实际是";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "再次交换的测试" << endl;
			t1.swap(t2);
			cout << "t1 应该是 test1 test2 test3 test4 test5，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 应该是 test-1 test-2 test-3 test-4，实际是";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// 第4组测试 
		if (test_int[3]) {
			press_key(1, "第4组测试：\n sort和unique");
			list<string> t1 = { "test3","test2","test2","test1","test7","test2","test5" };
			t1.unique();
			cout << "unique()的测试，结果应该是：test3 test2 test1 test7 test2 test5，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.sort();
			cout << "unique()的测试，结果应该是：test1 test2 test2 test3 test5 test7，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.unique();
			cout << "unique()的测试，结果应该是：test1 test2 test3 test5 test7，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
		}

		// 第5组测试 
		if (test_int[4]) {

			press_key(1, "第5组测试：\n splice() reverse() ");
			list<string> t1 = { "t1","t2","t3","t4","t5" };
			list<string> t2 = { "t6","t7","t8" };

			t1.splice(t1.begin(), t2);
			cout << "splice()的测试，结果应该是：t6 t7 t8 t1 t2 t3 t4 t5，实际是" << endl;;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.reverse();
			cout << "reverse()的测试，结果应该是：t5 t4 t3 t2 t1 t8 t7 t6，实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

	}
	//student
	if (1)
	{
		press_key(1, "\n student测试：\n");
		int test_int[] = { 1,1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			press_key(1, "第1组测试：\n begin/end  rbegin/rend函数");

			list<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
								{1003,"t3",'M',83,"test3" } };

			cout << "遍历(正向): " << endl;
			cout << "应输出：1001 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1003 t3 M 83 test1 " << endl;
			cout << "实际是：";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			cout << "数组遍历(反向): " << endl;
			cout << "应输出：1003 t3 M 83 test1" << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1001 t1 M 81 test1 " << endl;
			cout << "实际是：" << endl;
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;
		}

		// 第2组测试 
		if (test_int[1]) {
			press_key(1, "第2组测试：\n push_back() push_front() pop_back() pop_front() 函数");
			list<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1003,"t3",'M',83,"test3" } };
			t1.pop_back();
			cout << "pop_back()的测试";
			cout << "应输出：1001 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "实际是：" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p <<endl;
			cout << endl;
			t1.push_back({ 1004,"t4",'M',84,"test4" });
			cout << "push_back()的测试";
			cout << "应输出：1001 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1004 t4 M 84 test4 " << endl;
			cout<< "实际是: " << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.pop_front();
			cout << "pop_front()的测试";
			cout << "结果应该是   1002 t2 F 82 test2"<< endl;
			cout << "             1004 t4 M 84 test4 " << endl;
			cout<< "实际是: " << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.push_front({ 1005,"t5",'M',85,"test5" });
			cout << "push_front()的测试";
			cout << "结果应该是:  1005 t5 M 85 test5" << endl;
			cout << "             1002 t2 F 82 test2 " << endl;
			cout << "             1004 t4 M 84 test4 " << endl;
			cout<< "实际是: " << endl;
				for (auto p = t1.begin(); p != t1.end(); p++)
					cout << *p << endl;
			cout << endl;
		}


		// 第3组测试 
		if (test_int[2]) {
			press_key(1, "第3组测试：\n sort和unique(可能因为重载比较的定义不同，有不同)");
			list<student> t1 = { {1003,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1002,"t2",'F',82,"test2" } };
			t1.unique();
			cout << "unique()测试" << endl;
			cout << "应输出：1003 t1 M 81 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "实际是" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.sort();
			cout << "sort()的测试" << endl;
			cout << "应输出：1002 t2 F 82 test2 " << endl;
			cout << "        1003 t1 M 81 test1 " << endl;
			cout << "实际是" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
		}

		// 第4组测试 
		if (test_int[3]) {

			press_key(1, "第4组测试：\n  reverse() ");
			list<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1003,"t3",'M',83,"test3" } };

			t1.reverse();
			cout << "reverse()的测试，结果应该是" << endl;
			cout << "        1003 t3 M 83 test1 " << endl;
			cout << "        1002 t2 F 82 test2 " << endl;
			cout << "        1001 t1 M 81 test1 " << endl;
			cout << "实际是" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
		}
		// 第5组测试 
		if (test_int[4]) {

			press_key(1, "第5组测试：\n 最大填充测试,需要等待一段时间，建议在linux下测试，VS用时较多 ");
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
