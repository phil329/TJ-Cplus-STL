
#include <iostream>
#include <string>
#include <map>
#include "tj_student.h"
#include "tj_multimap.h"
using namespace std;

/* 这句宏定义注释掉，就是系统array的测试，
   打开宏定义，则测试自己的 tj_array */
#define	multimap	tj_multimap


void press_key(int num, const char* prompt)
{
	int i;
	cout << endl << prompt << "，按任意键继续...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}

string tmp = "test";
int main()
{
	//int
	if (1) {
		press_key(1, "\n key=int,value=int测试：\n");
		int test_int[] = { 1,1,1,1,1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			press_key(1, "第1组测试：\n size()和empty()函数");
			cout << "创建空multimap" << endl;
			multimap<int, int>m1;
			cout << "empty()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.size() << endl;
			cout << "max_size()函数: " << endl;
			cout << "应输出：178956970" << endl;
			cout << "实际是：" << m1.max_size() << endl;
		}
		if (test_int[1]) {
			press_key(1, "第2组测试：\n 几种输入方式");
			multimap<int, int>m1;
			cout << "multimap中赋值" << endl;
			pair<int, int> temp_pair(1, 100);
			m1.insert(temp_pair);
			cout << "insert(   pair   )方式插入成功" << endl;
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << m1.size() << endl;

			m1.emplace(2, 200);
			cout << "emplace方式插入成功" << endl;
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：2" << endl;
			cout << "实际是：" << m1.size() << endl;

			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << endl;
			}

			cout << endl << "复制" << endl;
			cout << "应输出：key=1   value=100        key=2   value=200" << endl;
			cout << "实际是：";
			multimap<int, int>m2 = m1;
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}

			cout << endl << "赋值" << endl;
			multimap<int, int>m3;
			m3 = m1;
			cout << "应输出：key=1   value=100        key=2   value=200" << endl;
			cout << "实际是：";
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}
			cout << endl;
		}
		// 第2组测试 
		if (test_int[2]) {
			press_key(1, "第3组测试：\n begin/end/及rbegin/rend/函数");

			multimap<int, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			cout << "遍历(正向): " << endl;
			cout << "应输出：1-100 2-200 3-300 4-400 5-500" << endl;
			cout << "实际是：";
			for (auto it = m1.begin(); it != m1.end(); it++) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;




			cout << "遍历(反向): " << endl;
			cout << "应输出：5-500 4-400 3-300 2-200 1-100" << endl;
			cout << "实际是：";
			for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;

			multimap<int, int>m2;
			cout << "测试当multimap大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (m2.begin() == m2.end()) << endl;

			cout << endl;

			cout << "测试当multimap大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (m2.rbegin() == m2.rend());

			cout << endl << endl;
		}

		// 第4组测试 
		if (test_int[3]) {
			press_key(1, "第4组测试：\n erase和insert");
			cout << "insert的测试";
			multimap<int, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			multimap<int, int>m2;
			for (int i = 5; i <= 10; i++)
				m2.insert(make_pair(i, i * 100));
			auto q = m2.begin();
			q++; q++;
			m1.insert(m2.begin(), q);
			cout << "结果应该是:\n1-100 2-200 3-300 4-400 5-500 5-500 6-600 " << endl << "实际是: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			cout << "测试insert的返回值 ，结果应该是 1,  " << "实际是: ";
			q = m1.insert(make_pair(0, 5000));
			cout << (q == m1.begin()) << endl;

			cout << "erase的测试";
			q = m1.end();
			q = m1.erase(--q);
			cout << "测试erase的返回值 ，结果应该是 1,  " << "实际是: ";
			cout << (q == m1.end()) << endl;
			cout << "删除一个元素" << endl;
			cout << "结果应该是:\n 0-5000 1-100 2-200 3-300 4-400 5-500 5-500 " << endl << "实际是: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			q = m1.begin();
			q++;
			auto q_e = m1.end();
			m1.erase(q, q_e);
			cout << "删除多个元素" << endl;
			cout << "结果应该是: 0-5000" << endl << "实际是: ";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}

		// 第5组测试 
		if (test_int[4]) {
			press_key(1, "第5组测试：\n find()/lower_bound()/upper_bound()/count()");
			multimap<int, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			for (int i = 1; i <= 3; i++)
				m1.emplace(2, i + 100);
			auto n1 = m1.find(2);
			cout << "find()的测试,应该是2-200，实际是";
			cout << (*n1).first << "-" << (*n1).second << endl;
			auto n2 = m1.lower_bound(2);
			cout << "lower_bound()的测试,应该是2-200，实际是";
			cout << (*n2).first << " -" << (*n2).second << endl;
			n2 = m1.upper_bound(2);
			cout << "upper_bound()的测试,应该是3-300，实际是";
			cout << (*n2).first << " -" << (*n2).second << endl;

			cout << "-----" << endl;
			cout << "equal_range()的测试,应该是2-200 2-101 2-102 2-103，实际是";
			auto q = m1.equal_range(2);
			for (auto p = q.first; p != q.second; p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << "count()的测试,应该是4，实际是";
			cout << m1.count(2) << endl;

			cout << endl << "find失败的情况" << endl;

			auto p1 = m1.find(100);
			cout << "find()找不存在的值的测试,应该1，实际是  ";
			cout << (p1 == m1.end()) << endl;
			auto p2 = m1.lower_bound(100);
			cout << "lower_bound()找不存在的值的测试,应该1，实际是  ";
			cout << (p2 == m1.end()) << endl;
			auto p3 = m1.upper_bound(100);
			cout << "upper_bound()找不存在的值的测试,应该1，实际是  ";
			cout << (p3 == m1.end()) << endl;
		}

		// 第6组测试 
		if (test_int[5]) {
			press_key(1, "第6组测试：\n key_comp");
			multimap<int, int>m1;
			bool r;
			r = m1.key_comp()(3, 5);
			cout << "key_comp()的测试，结果应该是：1，实际是";
			cout << r << endl;
			r = m1.key_comp()(3, 3);
			cout << "key_comp()的测试，结果应该是：0，实际是";
			cout << r << endl;
			r = m1.key_comp()(5, 3);
			cout << "key_comp()的测试，结果应该是：0，实际是";
			cout << r << endl;
		}

		// 第7组测试 
		if (test_int[6]) {

			press_key(1, "第7组测试：\n swap()  ");
			multimap<int, int>m1;
			multimap<int, int>m2;
			for (int i = 1; i <= 3; i++)
				m1.emplace(i, i * 100);
			for (int i = 8; i <= 9; i++)
				m2.emplace(i, i * 100);

			cout << "swap()的测试" << endl;
			m1.swap(m2);
			cout << "m1 应该是 8-800 9-900，实际是";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 应该是1-100 2-200 3-300，实际是";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "再次交换的测试" << endl;
			m1.swap(m2);
			cout << "m1 应该是1-100 2-200 3-300，实际是";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 应该是8-800 9-900，实际是";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}
		// 第8组测试 
		if (test_int[7]) {

			press_key(1, "第8组测试：重载测试,clear测试 ");
			multimap<int, int>m1;
			multimap<int, int>m2;
			for (int i = 1; i <= 5; i++)
				m1.emplace(i, i * 100);
			for (int i = 1; i <= 3; i++)
				m2.emplace(i, i * 100);
			for (int i = 8; i <= 12; i++)
				m2.emplace(i, i * 100);
			cout << "<号测试" << "应输出  1，实际输出" << (m1 < m2) << endl;
			cout << ">号测试" << "应输出  0，实际输出" << (m1 > m2) << endl;
			cout << "=号测试" << "应输出  0，实际输出" << (m1 == m2) << endl;

			m1.clear();
			m2.clear();
			cout << "clear m1,应输出 1，实际输出" << m1.empty() << endl;
			cout << "clear m2,应输出 1，实际输出" << m2.empty() << endl;
			cout << "<号测试" << "应输出  0，实际输出" << (m1 < m2) << endl;
			cout << ">号测试" << "应输出  0，实际输出" << (m1 > m2) << endl;
			cout << "=号测试" << "应输出  1，实际输出" << (m1 == m2) << endl;
		}
	}
	//string int
	if (1) {
		press_key(1, "\n key=string,value=int测试：\n");
		int test_int[] = { 1,1,1,1,1,1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			press_key(1, "第1组测试：\n size()和empty()函数");
			cout << "创建空multimap" << endl;
			multimap<string, int>m1;
			cout << "empty()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.size() << endl;
			cout << "max_size()函数: " << endl;
			cout << "应输出：89478485" << endl;
			cout << "实际是：" << m1.max_size() << endl;
		}
		if (test_int[1]) {
			press_key(1, "第2组测试：\n 几种输入方式");
			multimap<string, int>m1;
			cout << "multimap中赋值" << endl;
			pair<string, int> temp_pair("test1", 100);
			m1.insert(temp_pair);
			cout << "insert(   pair   )方式插入成功" << endl;
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << m1.size() << endl;

			m1.emplace("test2", 200);
			cout << "emplace方式插入成功" << endl;
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：2" << endl;
			cout << "实际是：" << m1.size() << endl;

			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << endl;
			}

			cout << endl << "复制" << endl;
			cout << "应输出：key=test1   value=100        key=test2   value=200" << endl;
			cout << "实际是：";
			multimap<string, int>m2 = m1;
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}

			cout << endl << "赋值" << endl;
			multimap<string, int>m3;
			m3 = m1;
			cout << "应输出：key=test1   value=100        key=test2   value=200" << endl;
			cout << "实际是：";
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}
			cout << endl;
		}
		// 第2组测试 
		if (test_int[2]) {
			press_key(1, "第3组测试：\n begin/end/及rbegin/rend/函数");
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			cout << "遍历(正向): " << endl;
			cout << "应输出：test1-100 test2-200 test3-300 test4-400 test5-500" << endl;
			cout << "实际是：";
			for (auto it = m1.begin(); it != m1.end(); it++) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;




			cout << "遍历(反向): " << endl;
			cout << "应输出：test5-500 test4-400 test3-300 test2-200 test1-100" << endl;
			cout << "实际是：";
			for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
				cout << (*it).first << "-" << (*it).second << " ";
			}
			cout << endl;

			cout << endl;

			multimap<int, int>m2;
			cout << "测试当multimap大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (m2.begin() == m2.end()) << endl;

			cout << endl;

			cout << "测试当multimap大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (m2.rbegin() == m2.rend());

			cout << endl << endl;
		}

		// 第4组测试 
		if (test_int[3]) {
			press_key(1, "第4组测试：\n erase和insert");
			cout << "insert的测试";
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			multimap<string, int>m2;
			for (int i = 5; i <= 10; i++)
				m2.insert(make_pair(tmp + char('0' + i), i * 100));
			auto q = m2.begin();
			q++; q++;
			m1.insert(m2.begin(), q);
			cout << "结果应该是:\ntest1-100 test2-200 test3-300 test4-400 test5-500 test5-500 test6-600 " << endl << "实际是: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			cout << "测试insert的返回值 ，结果应该是 1,  " << "实际是: ";
			q = m1.insert(make_pair("test0", 5000));
			cout << (q == m1.begin()) << endl;

			cout << "erase的测试";
			q = m1.end();
			q = m1.erase(--q);
			cout << "测试erase的返回值 ，结果应该是 1,  " << "实际是: ";
			cout << (q == m1.end()) << endl;
			cout << "删除一个元素" << endl;
			cout << "结果应该是:\n test0-5000 test1-100 test2-200 test3-300 test4-400 test5-500 test5-500 " << endl << "实际是: \n";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << endl;
			q = m1.begin();
			q++;
			auto q_e = m1.end();
			m1.erase(q, q_e);
			cout << "删除多个元素" << endl;
			cout << "结果应该是: test0-5000" << endl << "实际是: ";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}

		// 第5组测试 
		if (test_int[4]) {
			press_key(1, "第5组测试：\n find()/lower_bound()/upper_bound()/count()");
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			for (int i = 1; i <= 3; i++)
				m1.emplace("test2", i + 100);
			auto n1 = m1.find("test2");
			cout << "find()的测试,应该是test2-200，实际是";
			cout << (*n1).first << "-" << (*n1).second << endl;
			auto n2 = m1.lower_bound("test2");
			cout << "lower_bound()的测试,应该是test2-200，实际是";
			cout << (*n2).first << " -" << (*n2).second << endl;
			n2 = m1.upper_bound("test2");
			cout << "upper_bound()的测试,应该是test3-300，实际是";
			cout << (*n2).first << " -" << (*n2).second << endl;

			cout << "-----" << endl;
			cout << "equal_range()的测试,应该是test2-200 test2-101 test2-102 test2-103，实际是";
			auto q = m1.equal_range("test2");
			for (auto p = q.first; p != q.second; p++)
				cout << (*p).first << "-" << (*p).second << " ";
			cout << endl;
			cout << "count()的测试,应该是4，实际是";
			cout << m1.count("test2") << endl;

			cout << endl << "find失败的情况" << endl;

			auto p1 = m1.find("test200");
			cout << "find()找不存在的值的测试,应该1，实际是  ";
			cout << (p1 == m1.end()) << endl;
			auto p2 = m1.lower_bound("test200");
			cout << "lower_bound()找不存在的值的测试,应该0，实际是  ";
			cout << (p2 == m1.end()) << endl;
			auto p3 = m1.upper_bound("test200");
			cout << "upper_bound()找不存在的值的测试,应该0，实际是  ";
			cout << (p3 == m1.end()) << endl;
		}

		// 第6组测试 
		if (test_int[5]) {
			press_key(1, "第6组测试：\n key_comp");
			multimap<string, int>m1;
			bool r;
			r = m1.key_comp()("test200", "test300");
			cout << "key_comp()的测试，结果应该是：1，实际是";
			cout << r << endl;
			r = m1.key_comp()("test300", "test300");
			cout << "key_comp()的测试，结果应该是：0，实际是";
			cout << r << endl;
			r = m1.key_comp()("test300", "test200");
			cout << "key_comp()的测试，结果应该是：0，实际是";
			cout << r << endl;
		}

		// 第7组测试 
		if (test_int[6]) {

			press_key(1, "第7组测试：\n swap()  ");
			multimap<string, int>m1;
			multimap<string, int>m2;
			for (int i = 1; i <= 3; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			for (int i = 8; i <= 9; i++)
				m2.emplace(tmp + char('0' + i), i * 100);

			cout << "swap()的测试" << endl;
			m1.swap(m2);
			cout << "m1 应该是 test8-800 test9-900，实际是";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 应该是test1-100 test2-200 test3-300，实际是";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "再次交换的测试" << endl;
			m1.swap(m2);
			cout << "m1 应该是test1-100 test2-200 test3-300，实际是";
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
			cout << "m2 应该是test8-800 test9-900，实际是";
			for (auto p = m2.begin(); p != m2.end(); p++)
				cout << (*p).first << "-" << (*p).second << "  ";
			cout << endl;
		}
		// 第8组测试 
		if (test_int[7]) {

			press_key(1, "第8组测试：重载测试,clear测试 ");
			multimap<string, int>m1;
			multimap<string, int>m2;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('0' + i), i * 100);
			for (int i = 1; i <= 3; i++)
				m2.emplace(tmp + char('0' + i), i * 100);
			for (int i = 8; i <= 9; i++)
				m2.emplace(tmp + char('0' + i), i * 100);
			cout << "<号测试" << "应输出  1，实际输出" << (m1 < m2) << endl;
			cout << ">号测试" << "应输出  0，实际输出" << (m1 > m2) << endl;
			cout << "=号测试" << "应输出  0，实际输出" << (m1 == m2) << endl;

			m1.clear();
			m2.clear();
			cout << "clear m1,应输出 1，实际输出" << m1.empty() << endl;
			cout << "clear m2,应输出 1，实际输出" << m2.empty() << endl;
			cout << "<号测试" << "应输出  0，实际输出" << (m1 < m2) << endl;
			cout << ">号测试" << "应输出  0，实际输出" << (m1 > m2) << endl;
			cout << "=号测试" << "应输出  1，实际输出" << (m1 == m2) << endl;
		}

		// 第9组测试 
		if (test_int[9])
		{
			press_key(1, "第5组测试：相同键的测试 ");
			multimap<string, int>m1;
			for (int i = 1; i <= 5; i++)
				m1.emplace(tmp + char('1'), i);
			cout << "应输出：" << endl;
			cout << "test1 - 1" << endl;
			cout << "test1 - 2" << endl;
			cout << "test1 - 3" << endl;
			cout << "test1 - 4" << endl;
			cout << "test1 - 5" << endl;
			cout << "实际是：" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;
		}
	}
	//string student
	if (1) {
		press_key(1, "\n key=string,value=student测试：\n");
		int test_int[] = { 1,1,1,1,1 }; //每个1对应1组if测试
		student t[4] = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
								{1003,"t3",'M',83,"test3" } ,{1004,"t4",'F',84,"test4" } };

		// 第1组测试 
		if (test_int[0]) {
			press_key(1, "第1组测试：\n size()和empty()函数");
			cout << "创建空multimap" << endl;
			multimap<string, student>m1;
			cout << "empty()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.size() << endl;
			cout << "max_size()函数: " << endl;
			cout << "应输出：44739242" << endl;
			cout << "实际是：" << m1.max_size() << endl;
		}
		if (test_int[1]) {
			press_key(1, "第2组测试：\n 几种输入方式");
			multimap<string, student>m1;
			cout << "multimap中赋值" << endl;
			pair<string, student> temp_pair("test1", t[0]);
			m1.insert(temp_pair);
			cout << "insert(   pair   )方式插入成功" << endl;
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << m1.size() << endl;

			m1.emplace("test2", t[1]);
			cout << "emplace方式插入成功" << endl;
			cout << "empty()函数: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << m1.empty() << endl;
			cout << "size()函数: " << endl;
			cout << "应输出：2" << endl;
			cout << "实际是：" << m1.size() << endl;

			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << endl;
			}

			cout << endl << "复制" << endl;
			cout << "应输出：key=test1   value=1001 t1 M 81 test1        key=test2   value=1002 t2 F 82 test2" << endl;
			cout << "实际是：";
			multimap<string, student>m2 = m1;
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}

			cout << endl << "赋值" << endl;
			multimap<string, student>m3;
			m3 = m1;
			cout << "应输出：key=test1   value=1001 t1 M 81 test1        key=test2   value=1002 t2 F 82 test2" << endl;
			cout << "实际是：";
			for (auto p = m1.begin(); p != m1.end(); p++) {
				cout << "key=" << (*p).first << "   value=" << (*p).second << "        ";
			}
			cout << endl;
		}
		// 第2组测试 
		if (test_int[2]) {
			press_key(1, "第3组测试：\n begin/end/及rbegin/rend/函数");
			multimap<string, student>m1;
			for (int i = 0; i <= 2; i++)
				m1.emplace(tmp + char('0' + i), t[i]);
			cout << "遍历(正向): " << endl;
			cout << "应输出：\n" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test2 - 1003 t3 M 83 test3" << endl;
			cout << "实际是：\n";
			for (auto it = m1.begin(); it != m1.end(); it++) {
				cout << (*it).first << " - " << (*it).second << endl;
			}
			cout << endl;

			cout << endl;

			cout << "遍历(反向): " << endl;
			cout << "应输出：\n" << endl;
			cout << "test2 - 1003 t3 M 83 test3" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;

			cout << "实际是：\n";
			for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
				cout << (*it).first << " - " << (*it).second << endl;
			}
			cout << endl;

			cout << endl;

			multimap<int, student>m2;
			cout << "测试当multimap大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (m2.begin() == m2.end()) << endl;

			cout << endl;

			cout << "测试当multimap大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (m2.rbegin() == m2.rend());

			cout << endl << endl;
		}

		// 第4组测试 
		if (test_int[3]) {
			press_key(1, "第4组测试：\n erase和insert");
			cout << "insert的测试";
			multimap<string, student>m1;
			for (int i = 0; i <= 1; i++)
				m1.emplace(tmp + char('0' + i), t[i]);
			multimap<string, student>m2;
			for (int i = 0; i <= 3; i++)
				m2.insert(make_pair(tmp + char('0' + i), t[i]));
			auto q = m2.begin();
			q++; q++;
			m1.insert(m2.begin(), q);
			cout << "应输出：" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;

			cout << "实际是：" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;
			cout << "测试insert的返回值 ，结果应该是 1,  " << "实际是: ";
			q = m1.insert(make_pair("test", t[3]));
			cout << (q == m1.begin()) << endl;

			cout << "erase的测试";
			q = m1.end();
			q = m1.erase(--q);
			cout << "测试erase的返回值 ，结果应该是 1,  " << "实际是: ";
			cout << (q == m1.end()) << endl;
			cout << "删除一个元素" << endl;
			cout << "应输出：" << endl;
			cout << "test - 1004 t4 F 84 test4" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test0 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "实际是：" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;
		}

		// 第5组测试 
		if (test_int[4]) {

			press_key(1, "第5组测试：相同键的测试 ");
			multimap<string, student>m1;
			for (int i = 0; i <= 3; i++)
				m1.emplace(tmp + char('1'), t[i]);
			cout << "应输出：" << endl;
			cout << "test1 - 1001 t1 M 81 test1" << endl;
			cout << "test1 - 1002 t2 F 82 test2" << endl;
			cout << "test1 - 1003 t3 M 83 test3" << endl;
			cout << "test1 - 1004 t4 F 84 test4" << endl;
			cout << "实际是：" << endl;
			for (auto p = m1.begin(); p != m1.end(); p++)
				cout << (*p).first << " - " << (*p).second << endl;
			cout << endl;
			cout << endl;

		}
	}

	return 0;
}
