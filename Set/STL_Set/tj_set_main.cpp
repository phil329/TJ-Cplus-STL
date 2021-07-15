/* 1851846 数强 鞠璇 */
#include <iostream>
#include <set>
#include <string>
#include "tj_student.h"
#include "tj_set.h"

using namespace std;


/* 这句宏定义注释掉，就是系统set的测试，
   打开宏定义，则测试自己的 tj_set */
#define set tj_set

void press_key(int num, const char* prompt)
{
	int i;
	cout << endl << prompt << "，按任意键继续...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}

/*用于测试自定义的排序函数*/

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
		int test_int[] = { 1,1,1,1,1,1,1 }; //每个1对应1组if测试
		/* 第0组测试 */
		if (test_int[0]) {
			press_key(1, "第0组测试：\n begin(),end(),rbegin(),rend()函数和set容器的创建");

			int a[5] = { 1, 2, 3, 4, 5 };

			set <int> set1(a, a + 5);

			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";

			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "set容器遍历(反向): " << endl;
			cout << "应输出：5 4 3 2 1" << endl;
			cout << "实际是：";
			for (auto it = set1.rbegin(); it != set1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;


			set<int> set2;
			cout << "测试当容器大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (set2.begin() == set2.end()) << endl;

			cout << endl;

			cout << "测试当容器大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (set2.rbegin() == set2.rend());

			cout << endl << endl;

			set<int> set3(set1);
			cout << "测试容器的复制构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert(6);
			set3.insert(7);
			set3.insert(8);

			cout << "测试insert()函数" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5 6 7 8" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert(6);
			cout << "测试set容器内元素不能相同" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5 6 7 8" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "测试插入的元素是否成功" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set3.insert(6).second << endl;
			cout << "容器中已有的元素的迭代器对应位置的值为：" << endl;
			cout << "应输出：6" << endl;
			cout << "实际输出：" << *set3.insert(6).first << endl;

			set<int> set4(set1.begin(), set1.end());

			cout << "测试容器的迭代器区间构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";

			for (auto it = set4.begin(); it != set4.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set<int> set5;

			set5.insert(a, a + 5);

			cout << "测试容器的数组区间构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";

			for (auto it = set5.begin(); it != set5.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;
		}

		/* 第1组测试 */
		if (test_int[1]) {
			press_key(1, "第1组测试：\n size()、max_size()、count()和empty()函数");

			int a[5] = { 1, 2, 3, 4, 5 };

			set <int> set1(a, a + 5);
			set<int> set2;

			cout << "size()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << set1.size() << endl;
			cout << "set2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set2.size() << endl;

			cout << endl;

			cout << "max_size()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出： 214748364" << endl;
			cout << "实际是：" << set1.max_size() << endl;
			cout << "set2:" << endl;
			cout << "应输出：214748364" << endl;
			cout << "实际是：" << set2.max_size() << endl;

			cout << endl;

			cout << "empty()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set1.empty() << endl;
			cout << "set2:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << set2.empty() << endl;

			cout << endl;

			//虽然set的count()函数返回值只有0/1两种可能，但还是测一下呗~
			cout << "count()函数: " << endl;
			cout << "set1中1的个数:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << set1.count(1) << endl;
			cout << "set1中0的个数:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set1.count(0) << endl;
			cout << endl << endl;
		}

		/* 第2组测试 */
		if (test_int[2]) {
			press_key(1, "第2组测试：\n find(),erase(),clear()函数");

			int a[5] = { 1,2,3,4,5 };
			set<int> set1(a, a + 5);
			set<int> set2(set1);

			auto it = set1.find(1);
			cout << "测试find()函数(能找到)： " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：";
			cout << *it << endl;

			cout << endl;

			cout << endl;

			it = set1.find(6);
			cout << "测试find()函数(不能找到)： " << endl;
			cout << "应输出：6不能找到" << endl;
			cout << "实际是：";
			if (it != set1.end())
				cout << "6能找到" << endl;
			else
				cout << "6不能找到" << endl;

			cout << endl;

			cout << endl;
			set1.erase(3);
			cout << "erase()参数为元素值的测试,容器遍历(正向): " << endl;
			cout << "应输出：1 2 4 5" << endl;
			cout << "实际是：";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			it = set1.find(1);
			set1.erase(it);
			cout << "erase()参数为迭代器的测试,容器遍历(正向): " << endl;
			cout << "应输出：2 4 5" << endl;
			cout << "实际是：";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set1.erase(set1.begin(), set1.end());
			cout << "erase()参数为迭代器区间的测试，判断此时容器大小是否为0: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：";
			cout << set1.size() << endl;

			cout << endl;

			cout << endl;

			set2.clear();
			cout << "clear()清空容器测试，判断此时容器大小是否为0: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：";
			cout << set1.empty() << endl;

			cout << endl;

			cout << endl;
		}

		/* 第3组测试 */
		if (test_int[3]) {
			press_key(1, "第3组测试：\n lower_bound()函数、upper_bound()函数、equal_range()函数");

			set<int> set1;
			set1.insert(1);
			set1.insert(2);
			set1.insert(5);

			cout << "找得到元素的情况：" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "第一个大于或等于3的元素: " << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << *set1.lower_bound(3) << endl;
			cout << "第一个大于或等于2的元素: " << endl;
			cout << "应输出：2" << endl;
			cout << "实际是：" << *set1.lower_bound(2) << endl;
			cout << "第一个大于2的元素: " << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << *set1.upper_bound(2) << endl;

			cout << endl;
			cout << endl;

			cout << "找不到元素的情况：" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "第一个大于或等于6的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.lower_bound(6) == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.lower_bound(6) << endl;

			cout << "第一个大于5的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.upper_bound(5) == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.upper_bound(5) << endl;

			cout << endl << endl;

			cout << "找得到元素的情况：" << endl;

			cout << "equal_range test:" << endl;
			cout << "第一个大于或等于2的元素: " << endl;
			cout << "应输出：2" << endl;
			cout << "实际是：" << *set1.equal_range(2).first << endl;
			cout << "第一个大于2的元素: " << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << *set1.equal_range(2).second << endl;
			cout << endl;
			cout << endl;

			cout << "找不到元素的情况：" << endl;
			cout << "equal_range test:" << endl;
			cout << "第一个大于或等于6的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.equal_range(6).first == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.lower_bound(6) << endl;

			cout << "第一个大于5的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.equal_range(6).second == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.equal_range(6).second << endl;
			cout << endl;
			cout << endl;

		}

		/* 第4组测试 */
		if (test_int[4]) {
			press_key(1, "第4组测试：\n swap()函数");

			set<int> set1, set2;
			set1.insert(100);
			set2.insert(200);
			cout << "swap()函数: " << endl;
			cout << "set1中的元素遍历（正向）：" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2中的元素遍历（正向）：" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << "进行交换" << endl;

			set1.swap(set2);
			cout << "set1中的元素遍历（正向）：" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2中的元素遍历（正向）：" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << endl;
		}

		/* 第5组测试 */
		if (test_int[5]) {
			press_key(1, "第5组测试：\n 按照> == < >= <= !=的顺序对两个set容器进行比较");
			int a[5] = { 1,2,3,4,5 };
			int b[4] = { 1,2,3,4 };
			int c[6] = { 1,2,3,4,5,6 };
			set<int> set1(a, a + 5);
			set<int> set2(set1);
			set<int> set3(b, b + 4);
			set<int> set4(c, c + 6);

			cout << "set1与set2比较: " << endl;
			cout << "应输出：0 1 0 1 1 0" << endl;
			cout << "实际是：" << ((set1 > set2) ? 1 : 0) << " ";
			cout << ((set1 == set2) ? 1 : 0) << " ";
			cout << ((set1 < set2) ? 1 : 0) << " ";
			cout << ((set1 >= set2) ? 1 : 0) << " ";
			cout << ((set1 <= set2) ? 1 : 0) << " ";
			cout << ((set1 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "set2与set3比较: " << endl;
			cout << "应输出：1 0 0 1 0 1" << endl;
			cout << "实际是：" << ((set2 > set3) ? 1 : 0) << " ";
			cout << ((set2 == set3) ? 1 : 0) << " ";
			cout << ((set2 < set3) ? 1 : 0) << " ";
			cout << ((set2 >= set3) ? 1 : 0) << " ";
			cout << ((set2 <= set3) ? 1 : 0) << " ";
			cout << ((set2 != set3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "set4与set2比较: " << endl;
			cout << "应输出：1 0 0 1 0 1" << endl;
			cout << "实际是：" << ((set4 > set2) ? 1 : 0) << " ";
			cout << ((set4 == set2) ? 1 : 0) << " ";
			cout << ((set4 < set2) ? 1 : 0) << " ";
			cout << ((set4 >= set2) ? 1 : 0) << " ";
			cout << ((set4 <= set2) ? 1 : 0) << " ";
			cout << ((set4 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		/* 第6组测试 */
		if (test_int[6]) {

			press_key(1, "第6组测试：\n 自定义排序函数测试");
			set<int, intcmp>s;
			s.insert(1);
			s.insert(2);
			s.insert(6);
			cout << "Test output :" << endl;
			cout << "应输出：6 2 1" << endl;
			cout << "实际是：";
			for (auto it = s.begin(); it != s.end(); it++)
				cout << *it << " ";
			cout << endl;
			cout << endl;
		}
	}
#if 1
	//string
	if (1) {
		int test_string[] = { 1,1,1,1,1,1,1 }; //每个1对应1组if测试

	/* 第0组测试 */
		if (test_string[0]) {
			press_key(1, "第0组测试：\n begin(),end(),rbegin(),rend()函数和set容器的创建");

			string a[5] = { "ab","cd" ,"ef", "gh", "ij" };

			set<string> set1(a, a + 5);
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";

			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "set容器遍历(反向): " << endl;
			cout << "应输出：ij gh ef cd ab" << endl;
			cout << "实际是：";
			for (auto it = set1.rbegin(); it != set1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;


			set<string> set2;
			cout << "测试当容器大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (set2.begin() == set2.end()) << endl;

			cout << endl;

			cout << "测试当容器大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (set2.rbegin() == set2.rend());

			cout << endl << endl;

			set<string> set3(set1);
			cout << "测试容器的复制构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert("kl");
			set3.insert("mn");
			set3.insert("op");

			cout << "测试insert()函数" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij kl mn op" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set3.insert("ab");
			cout << "测试set容器内元素不能相同" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij kl mn op" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "测试插入的元素是否成功" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set3.insert("cd").second << endl;
			cout << "容器中已有的元素的迭代器对应位置的值为：" << endl;
			cout << "应输出：cd" << endl;
			cout << "实际是：" << *set3.insert("cd").first << endl;

			set<string> set4(set1.begin(), set1.end());

			cout << "测试容器的迭代器区间构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";

			for (auto it = set4.begin(); it != set4.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set<string> set5;

			set5.insert(a, a + 5);

			cout << "测试容器的数组区间构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";

			for (auto it = set5.begin(); it != set5.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

		}

		/* 第1组测试 */
		if (test_string[1]) {
			press_key(1, "第1组测试：\n size()、max_size()、count()和empty()函数");

			string a[5] = { "ab","cd" ,"ef", "gh", "ij" };

			set <string> set1(a, a + 5);
			set<string> set2;

			cout << "size()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << set1.size() << endl;
			cout << "set2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set2.size() << endl;

			cout << endl;

			cout << "max_size()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：97612893" << endl;
			cout << "实际是：" << set1.max_size() << endl;
			cout << "set2:" << endl;
			cout << "应输出：97612893" << endl;
			cout << "实际是：" << set2.max_size() << endl;

			cout << endl;

			cout << "empty()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set1.empty() << endl;
			cout << "set2:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << set2.empty() << endl;

			cout << endl;

			//虽然set的count()函数返回值只有0/1两种可能，但还是测一下呗~
			cout << "count()函数: " << endl;
			cout << "set1中ab的个数:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << set1.count("ab") << endl;
			cout << "set1中ac的个数:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set1.count("ac") << endl;
			cout << endl << endl;
		}

		/* 第2组测试 */
		if (test_string[2]) {
			press_key(1, "第2组测试：\n find(),erase(),clear()函数");

			string a[5] = { "ab","cd" ,"ef", "gh", "ij" };
			set<string> set1(a, a + 5);
			set<string> set2(set1);

			auto it = set1.find("ab");
			cout << "测试find()函数(能找到)： " << endl;
			cout << "应输出：ab" << endl;
			cout << "实际是：";
			cout << *it << endl;

			cout << endl;

			cout << endl;

			it = set1.find("ac");
			cout << "测试find()函数(不能找到)： " << endl;
			cout << "应输出：ac不能找到" << endl;
			cout << "实际是：";
			if (it != set1.end())
				cout << "ac能找到" << endl;
			else
				cout << "ac不能找到" << endl;

			cout << endl;

			cout << endl;
			set1.erase("ab");
			cout << "erase()参数为元素值的测试,容器遍历(正向): " << endl;
			cout << "应输出：cd ef gh ij" << endl;
			cout << "实际是：";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			it = set1.find("ef");
			set1.erase(it);
			cout << "erase()参数为迭代器的测试,容器遍历(正向): " << endl;
			cout << "应输出：cd gh ij" << endl;
			cout << "实际是：";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			set1.erase(set1.begin(), set1.end());
			cout << "erase()参数为迭代器区间的测试，判断此时容器大小是否为0: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：";
			cout << set1.size() << endl;

			cout << endl;

			cout << endl;

			set2.clear();
			cout << "clear()清空容器测试，判断此时容器大小是否为0: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：";
			cout << set1.empty() << endl;

			cout << endl;

			cout << endl;

		}

		/* 第3组测试 */
		if (test_string[3]) {
			press_key(1, "第3组测试：\n lower_bound()函数、upper_bound()函数、equal_range()函数");

			set<string> set1;
			set1.insert("ab");
			set1.insert("abc");
			set1.insert("cd");

			cout << "找得到元素的情况：" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "第一个大于或等于ab的元素: " << endl;
			cout << "应输出：ab" << endl;
			cout << "实际是：" << *set1.lower_bound("ab") << endl;
			cout << "第一个大于或等于a的元素: " << endl;
			cout << "应输出：ab" << endl;
			cout << "实际是：" << *set1.lower_bound("a") << endl;
			cout << "第一个大于ab的元素: " << endl;
			cout << "应输出：abc" << endl;
			cout << "实际是：" << *set1.upper_bound("ab") << endl;

			cout << endl;
			cout << endl;

			cout << "找不到元素的情况：" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "第一个大于或等于cde的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.lower_bound("cde") == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.lower_bound("cde") << endl;

			cout << "第一个大于cd的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.upper_bound("cd") == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.upper_bound("cd") << endl;

			cout << endl << endl;

			cout << "找得到元素的情况：" << endl;

			cout << "equal_range test:" << endl;
			cout << "第一个大于或等于ab的元素: " << endl;
			cout << "应输出：ab" << endl;
			cout << "实际是：" << *set1.equal_range("ab").first << endl;
			cout << "第一个大于ab的元素: " << endl;
			cout << "应输出：abc" << endl;
			cout << "实际是：" << *set1.equal_range("ab").second << endl;
			cout << endl;
			cout << endl;

			cout << "找不到元素的情况：" << endl;
			cout << "equal_range test:" << endl;
			cout << "第一个大于或等于cde的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.equal_range("cde").first == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.lower_bound("cde") << endl;

			cout << "第一个大于cd的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.equal_range("cd").second == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.equal_range("cd").second << endl;
			cout << endl;
			cout << endl;
		}

		/* 第4组测试 */
		if (test_string[4]) {
			press_key(1, "第4组测试：\n swap()函数");

			set<string> set1, set2;
			set1.insert("ab");
			set1.insert("cd");
			set1.insert("efgh");
			set2.insert("hijk");
			set2.insert("lmn");
			cout << "swap()函数: " << endl;
			cout << "set1中的元素遍历（正向）：" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2中的元素遍历（正向）：" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << "进行交换" << endl;

			set1.swap(set2);
			cout << "set1中的元素遍历（正向）：" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << "set2中的元素遍历（正向）：" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
			cout << endl;
		}

		/* 第5组测试 */
		if (test_string[5]) {
			press_key(1, "第5组测试：\n 按照> == < >= <= !=的顺序对两个set容器进行比较");

			string a[5] = { "abc", "def", "ghi","jkl", "mno" };
			string b[5] = { "mno", "jkl", "ghi", "def", "abc" };
			string c[5] = { "abc", "def", "ghi","jkl" };
			string d[5] = { "abc", "def", "ghi","jkl", "mnop" };

			set<string> set1(a, a + 5);
			set<string> set2(b, b + 5);
			set<string> set3(c, c + 4);
			set<string> set4(d, d + 5);

			cout << "set1与set2比较: " << endl;
			cout << "应输出：0 1 0 1 1 0" << endl;
			cout << "实际是：" << ((set1 > set2) ? 1 : 0) << " ";
			cout << ((set1 == set2) ? 1 : 0) << " ";
			cout << ((set1 < set2) ? 1 : 0) << " ";
			cout << ((set1 >= set2) ? 1 : 0) << " ";
			cout << ((set1 <= set2) ? 1 : 0) << " ";
			cout << ((set1 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "set2与set3比较: " << endl;
			cout << "应输出：1 0 0 1 0 1" << endl;
			cout << "实际是：" << ((set2 > set3) ? 1 : 0) << " ";
			cout << ((set2 == set3) ? 1 : 0) << " ";
			cout << ((set2 < set3) ? 1 : 0) << " ";
			cout << ((set2 >= set3) ? 1 : 0) << " ";
			cout << ((set2 <= set3) ? 1 : 0) << " ";
			cout << ((set2 != set3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "set4与set2比较: " << endl;
			cout << "应输出：1 0 0 1 0 1" << endl;
			cout << "实际是：" << ((set4 > set2) ? 1 : 0) << " ";
			cout << ((set4 == set2) ? 1 : 0) << " ";
			cout << ((set4 < set2) ? 1 : 0) << " ";
			cout << ((set4 >= set2) ? 1 : 0) << " ";
			cout << ((set4 <= set2) ? 1 : 0) << " ";
			cout << ((set4 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		/* 第6组测试 */
		if (test_string[6]) {
			press_key(1, "第6组测试：\n 自定义排序函数测试");
			set<string, strComp>s;
			s.insert("ab");
			s.insert("cd");
			s.insert("ef");
			cout << "Test output :" << endl;
			cout << "应输出：ef cd ab" << endl;
			cout << "实际是：";
			for (auto it = s.begin(); it != s.end(); it++)
				cout << *it << " ";
			cout << endl;
			cout << endl;
		}


	}

	//student
	if (1) {
		int test_student[] = { 1,1,1,1,1,1,1 }; //每个1对应1组if测试
		const student mother[4] = { {1851846,"鞠璇",'f',(float)(92.2),"河北"},
		{1851801,"刘子云",'f',(float)(94.2),"河北"},
		{1854205,"郑昕瑶",'f',(float)(93.5),"湖北"},
		{1854167,"徐思琪",'f',(float)(91.7),"湖北"} };


		/* 第0组测试 */
		if (test_student[0]) {
			press_key(1, "第0组测试：\n  begin(),end(),rbegin(),rend()函数和set容器的创建");

			set<student> set1(mother, mother + 4);
			student a[3] = { {1853790,"庄振华",'f',(float)(92.7),"山东"},
					{1852024,"李兵磊",'f',(float)(90.9),"河南"},
					{1851909,"聂尧",'f',(float)(92.8),"河北"},
			};
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出：徐思琪，鞠璇，郑昕瑶，刘子云四人信息" << endl;
			cout << "实际是：";
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;


			cout << "set容器遍历(反向): " << endl;
			cout << "应输出：刘子云，郑昕瑶，鞠璇，徐思琪四人信息" << endl;
			cout << "实际是：";
			for (auto it = set1.rbegin(); it != set1.rend(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;



			set<student> set2;
			cout << "测试当容器大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (set2.begin() == set2.end()) << endl;

			cout << endl;

			cout << "测试当容器大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (set2.rbegin() == set2.rend());

			cout << endl << endl;

			set<student> set3(set1);
			cout << "测试容器的复制构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出徐思琪，鞠璇，郑昕瑶，刘子云四人信息 " << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set3.insert(a[0]);
			set3.insert(a[1]);
			set3.insert(a[2]);

			cout << "测试insert()函数" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出李兵磊，徐思琪，鞠璇，庄振华，聂尧，郑昕瑶，刘子云七人信息 " << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set3.insert(a[0]);
			cout << "测试set容器内元素不能相同" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出李兵磊，徐思琪，鞠璇，庄振华，聂尧，郑昕瑶，刘子云七人信息" << endl;
			cout << "实际是：";

			for (auto it = set3.begin(); it != set3.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			cout << "测试插入的元素是否成功" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set3.insert(a[1]).second << endl;
			cout << "容器中已有的元素的迭代器对应位置的值为：" << endl;
			cout << "应输出李兵磊的信息" << endl;
			cout << "实际是：" << *set3.insert(a[1]).first << endl;

			set<student> set4(set1.begin(), set1.end());

			cout << "测试容器的迭代器区间构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出徐思琪，鞠璇，郑昕瑶，刘子云四人信息" << endl;
			cout << "实际是：";

			for (auto it = set4.begin(); it != set4.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set<student> set5;

			set5.insert(mother, mother + 4);

			cout << "测试容器的数组区间构造" << endl;
			cout << "set容器遍历(正向): " << endl;
			cout << "应输出徐思琪，鞠璇，郑昕瑶，刘子云四人信息" << endl;
			cout << "实际是：";

			for (auto it = set5.begin(); it != set5.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

		}

		/* 第1组测试 */
		if (test_student[1]) {
			press_key(1, "第1组测试：\n size()、max_size()、count()和empty()函数");

			set<student> set1(mother, mother + 4);
			set<student> set2;
			student a[3] = { {1853790,"庄振华",'f',(float)(92.7),"山东"},
					{1852024,"李兵磊",'f',(float)(90.9),"河南"},
					{1851909,"聂尧",'f',(float)(92.8),"河北"},
			};


			cout << "size()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：4" << endl;
			cout << "实际是：" << set1.size() << endl;
			cout << "set2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set2.size() << endl;

			cout << endl;

			cout << "max_size()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：63161283" << endl;
			cout << "实际是：" << set1.max_size() << endl;
			cout << "set2:" << endl;
			cout << "应输出：63161283" << endl;
			cout << "实际是：" << set2.max_size() << endl;

			cout << endl;

			cout << "empty()函数: " << endl;
			cout << "set1:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set1.empty() << endl;
			cout << "set2:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << set2.empty() << endl;

			cout << endl;

			//虽然set的count()函数返回值只有0/1两种可能，但还是测一下呗~
			cout << "count()函数: " << endl;
			cout << "set1中徐思琪信息的个数:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << set1.count(mother[3]) << endl;
			cout << "set1中庄振华的个数:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << set1.count(a[0]) << endl;
			cout << endl << endl;

		}

		/* 第2组测试 */
		if (test_student[2]) {

			press_key(1, "第2组测试：\n find(),erase(),clear()函数");

			set<student> set1(mother, mother + 4);
			set<student> set2(set1);
			student a[3] = { {1853790,"庄振华",'f',(float)(92.7),"山东"},
				{1852024,"李兵磊",'f',(float)(90.9),"河南"},
				{1851909,"聂尧",'f',(float)(92.8),"河北"},
			};

			auto it = set1.find(mother[0]);
			cout << "测试find()函数(能找到)： " << endl;
			cout << "应输出鞠璇的个人信息" << endl;
			cout << "实际是：";
			cout << *it << endl;

			cout << endl;

			cout << endl;

			it = set1.find(a[0]);
			cout << "测试find()函数(不能找到)： " << endl;
			cout << "应输出：庄振华的个人信息不能找到" << endl;
			cout << "实际是：";
			if (it != set1.end())
				cout << "庄振华的个人信息能找到" << endl;
			else
				cout << "庄振华的个人信息不能找到" << endl;

			cout << endl;

			cout << endl;
			set1.erase(mother[0]);
			cout << "erase()参数为元素值的测试,容器遍历(正向): " << endl;
			cout << "应输出徐思琪，郑昕瑶，刘子云三人信息" << endl;
			cout << "实际是：";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			it = set1.find(mother[3]);
			set1.erase(it);
			cout << "erase()参数为迭代器的测试,容器遍历(正向): " << endl;
			cout << "应输出郑昕瑶，刘子云两人信息" << endl;
			cout << "实际是：";
			for (it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << endl;

			set1.erase(set1.begin(), set1.end());
			cout << "erase()参数为迭代器区间的测试，判断此时容器大小是否为0: " << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：";
			cout << set1.size() << endl;

			cout << endl;

			cout << endl;

			set2.clear();
			cout << "clear()清空容器测试，判断此时容器大小是否为0: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：";
			cout << set1.empty() << endl;

			cout << endl;

			cout << endl;
		}

		/* 第3组测试 */
		if (test_student[3]) {
			press_key(1, "第3组测试：\n lower_bound()函数、upper_bound()函数、equal_range()函数");

			set<student> set1(mother, mother + 4);
			student a[3] = { {1853790,"庄振华",'f',(float)(92.7),"山东"},
					{1852024,"李兵磊",'f',(float)(90.9),"河南"},
					{1851909,"聂尧",'f',(float)(95.8),"河北"},
			};
			cout << "找得到元素的情况：" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "第一个大于或等于鞠璇的元素: " << endl;
			cout << "应输出鞠璇的个人信息" << endl;
			cout << "实际是：" << *set1.lower_bound(mother[0]) << endl;
			cout << "第一个大于或等于徐思琪的元素: " << endl;
			cout << "应输出徐思琪的个人信息" << endl;
			cout << "实际是：" << *set1.lower_bound(mother[3]) << endl;
			cout << "第一个大于鞠璇的元素: " << endl;
			cout << "应输出郑昕瑶的个人信息" << endl;
			cout << "实际是：" << *set1.upper_bound(mother[0]) << endl;

			cout << endl;
			cout << endl;

			cout << "找不到元素的情况：" << endl;

			cout << "lower_bound & upper_bound test:" << endl;
			cout << "第一个大于或等于聂尧的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.lower_bound(a[2]) == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.lower_bound(a[2]) << endl;

			cout << "第一个大于刘子云的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.upper_bound(mother[1]) == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.upper_bound(mother[1]) << endl;

			cout << endl << endl;

			cout << "找得到元素的情况：" << endl;

			cout << "equal_range test:" << endl;
			cout << "第一个大于或等于鞠璇的元素: " << endl;
			cout << "应输出鞠璇的个人信息" << endl;
			cout << "实际是：" << *set1.equal_range(mother[0]).first << endl;
			cout << "第一个大于鞠璇的元素: " << endl;
			cout << "应输出郑昕瑶的个人信息" << endl;
			cout << "实际是：" << *set1.equal_range(mother[0]).second << endl;
			cout << endl;
			cout << endl;

			cout << "找不到元素的情况：" << endl;
			cout << "equal_range test:" << endl;
			cout << "第一个大于或等于聂尧的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.equal_range(a[2]).first == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.lower_bound(a[2]) << endl;

			cout << "第一个大于刘子云的元素: " << endl;
			cout << "应输出：找不到满足要求的元素" << endl;
			cout << "实际是：";
			if (set1.equal_range(mother[1]).second == set1.end())
				cout << "找不到满足要求的元素" << endl;
			else
				cout << "该元素为" << *set1.equal_range(mother[1]).second << endl;
			cout << endl;
			cout << endl;
		}

		/* 第4组测试 */
		if (test_student[4]) {
			press_key(1, "第4组测试：\n swap()函数");
			student a[3] = { {1853790,"庄振华",'f',(float)(92.7),"山东"},
									{1852024,"李兵磊",'f',(float)(90.9),"河南"},
									{1851909,"聂尧",'f',(float)(95.8),"河北"},
			};
			set<student> set1, set2;
			set1.insert(mother, mother + 4);
			set2.insert(a, a + 3);
			cout << "swap()函数: " << endl;
			cout << "set1中的元素遍历（正向）：" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << "set2中的元素遍历（正向）：" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;

			cout << "进行交换" << endl;

			set1.swap(set2);
			cout << "set1中的元素遍历（正向）：" << endl;
			for (auto it = set1.begin(); it != set1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << "set2中的元素遍历（正向）：" << endl;
			for (auto it = set2.begin(); it != set2.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << endl;
		}

		/* 第5组测试 */
		if (test_student[5]) {
			press_key(1, "第5组测试：\n 按照 == !=的顺序对两个set容器进行比较（比较学号，其它不进行测试）");

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


			cout << "set1与set2比较: " << endl;
			cout << "应输出：1 0" << endl;
			cout << "实际是：";
			cout << ((set1 == set2) ? 1 : 0) << " ";
			cout << ((set1 != set2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "set1与set3比较: " << endl;
			cout << "应输出：0 1" << endl;
			cout << "实际是：";
			cout << ((set1 == set3) ? 1 : 0) << " ";
			cout << ((set1 != set3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		/* 第6组测试 */
		if (test_student[6]) {
			press_key(1, "第6组测试：\n 自定义排序函数测试");
			set<student, studentComp> s;
			s.insert(mother, mother + 4);
			cout << "Test output :" << endl;
			cout << "应输出刘子云，郑昕瑶，鞠璇，徐思琪四人信息" << endl;
			cout << "实际是：";
			for (auto it = s.begin(); it != s.end(); it++)
				cout << *it << endl;
			cout << endl;
			cout << endl;
		}
	}
#endif
	return 0;
}
