/* 1853790 数强 庄镇华 */
#include<iostream>
#include <string>
#include <vector>
#include"tj_student_vector.h"
#include"tj_vector.cpp"
//这句宏定义注释掉，就是系统vector的测试，
//打开宏定义，则测试自己的tj_vector
#define vector tj_vector
using namespace std;

/* 以下为测试开关，具体测试内容见main函数条件编译上部注释标注 */
#define test1_1 1
#define test1_2 1
#define test1_3 1
#define test1_4 1
#define test1_5 1
#define test1_6 1
#define test2_1 1
#define test3_1 1
#define test4_1 1
struct President
{
	std::string name;
	std::string country;
	int year;
	President() {};
	President(std::string p_name, std::string p_country, int p_year): name((p_name)), country((p_country)), year(p_year){
		std::cout << "I am being constructed.\n";
	}
	President(const President& other): name((other.name)), country((other.country)), year(other.year){
		std::cout << "I am being copy constructed.\n";
	}
	President(President&& other): name(std::move(other.name)), country(std::move(other.country)), year(other.year)
	{
		std::cout << "I am being moved.\n";
	}
};

//vector函数清单
//member functions
//vector::operator=
//vector::assign

//vector::at
//vector::operator[]
//vector::data
//vector::front
//vector::back

//vector::begin
//vector::end
//vector::cbegin
//vector::cend
//vector::rbegin
//vector::rend
//vector::crbegin
//vector::crend

//vector::clear

//vector::empty
//vector::size
//vector::max_size
//vector::capacity

//vector::insert
//vector::erase
//vector::emplace
//vector::emplace_back
//vector::pop_back
//vector::push_back
//vector::reserve
//vector::swap

//vector::resize
//vector::shrink_to_fit

//non-member overloads
//swap(vector)
void _continue(int num, const char *prompt = NULL)
{
	int i;
	cout << endl << "按任意键继续...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}
int main(){
	if (0) {
		vector<President> elections;
		std::cout << "emplace_back:\n";
		cout << "应该输出一句话: \n I am being constructed." << endl;
		cout << "实际\n";
		elections.emplace_back("Nelson Mandela", "South Africa", 1994); //没有类的创建  
		//利用的可变参数包
		vector<President> reElections;
		std::cout << "\npush_back:\n";
		cout << "应该输出两句话:\nI am being constructed \nI am being moved. " << endl;
		cout << "实际\n";

		reElections.emplace_back(President("Franklin Delano Roosevelt", "the USA", 1936));
	    //&&
		std::cout << "\nContents:\n";
		for (President const& president : elections) {
			std::cout << president.name << " was elected president of "
				<< president.country << " in " << president.year << ".\n";
		}
		for (President const& president : reElections) {
			std::cout << president.name << " was re-elected president of "
				<< president.country << " in " << president.year << ".\n";
		}
		_continue(1);
	}
	//测试begin/end/cbegin/cend/rbegin/rend/crbegin/crend/assign函数
#if test1_1
	{
		cout << "test1_1 : 测试begin/end/cbegin/cend/rbegin/rend/crbegin/crend/assign函数" << endl;
		vector<int> first, second, third;
		first.assign(7, 100);             // 7 ints with a value of 100
		auto it = first.begin() + 1;
		second.assign(it, first.end() - 1); // the 5 central values of first
		int myints[] = { 1776,7,4 };
		third.assign(myints, myints + 3);   // assigning from array.

		cout << "应输出： 1 2 3 4 5" << endl;
		cout << "实际是：";
		vector<int> myvector = { 1,2,3,4,5 };
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		cout << "应输出   100 100 100 100 100 100 100" << endl;
		cout << "实际是：";
		for (auto it = first.cbegin(); it != first.cend(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		cout << "应输出   100 100 100 100 100" << endl;
		cout << "实际是：";
		for (auto it = second.crbegin(); it != second.crend(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		cout << "应输出   4 7 1776" << endl;
		cout << "实际是：";
		for (auto it = third.rbegin(); it != third.rend(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		_continue(1);
	}
#endif
	//测试empty/pop_back/push_back/erase/insert函数
#if test1_2
	{
		cout << "test1_2 : 测试empty/pop_back/push_back/erase/insert函数" << endl;
		cout << "应输出  The elements of myvector add up to 600" << endl;
		cout << "实际是：";
		vector<int> myvector;
		int sum(0);
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);
		while (!myvector.empty()) {
			sum += myvector.back();
			myvector.pop_back();
		}
		cout << "The elements of myvector add up to " << sum << endl;

		cout << "应输出  my contains: 10 9 8 7 5 4" << endl;
		cout << "实际是：";
		vector<int> my;
		// set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			my.push_back(i);
		// erase the 6th element
		my.erase(my.begin() + 5);
		// erase the first 3 elements:
		my.erase(my.begin(), my.begin() + 3);
		cout << "my contains:";
		for (auto it = my.rbegin(); it != my.rend(); ++it)
			cout << ' ' << *it;
		cout << endl;

		cout << "应输出  myvector1 contains: 501 502 503 300 300 400 400 200 100 100 100" << endl;
		cout << "实际是：";
		vector<int> myvector1(3, 100);
		vector<int>::iterator it;
		it = myvector1.begin();
		it = myvector1.insert(it, 200);
		for (it = myvector1.begin(); it < myvector1.end(); it++)
			cout << ' ' << *it;
		cout << endl;

		myvector1.insert(it, 2, 300);

		for (it = myvector1.begin(); it < myvector1.end(); it++)
			cout << ' ' << *it;
		cout << endl;
		//"it" no longer valid, get a new one:
		it = myvector1.begin();
		vector<int> anothervector(2, 400);
		myvector1.insert(it + 2, anothervector.begin(), anothervector.end());
		int myarray[] = { 501,502,503 };
		myvector1.insert(myvector1.begin(), myarray, myarray + 3);
		cout << "myvector1 contains:";
		for (it = myvector1.begin(); it < myvector1.end(); it++)
			cout << ' ' << *it;
		cout << endl;

		_continue(2);
	}
#endif
	//测试size/clear/max_size/capacity函数
#if test1_3
	{
		cout << "test1_3 : 测试size/clear/max_size/capacity函数" << endl;
		cout << "应输出  size: 0 size : 10 size : 20 size : 19" << endl;
		cout << "实际是：";
		vector<int> myints;
		cout << "size: " << myints.size() << " ";
		for (int i = 0; i < 10; i++)
			myints.push_back(i);
		cout << "size: " << myints.size() << " ";
		myints.insert(myints.end(), 10, 100);
		cout << "size: " << myints.size() << " ";
		myints.pop_back();
		cout << "size: " << myints.size() << " ";
		cout << endl;

		cout << "应输出  size: 100 capacity: 141 max_size: 1073741823" << endl;
		cout << "实际是：";
		vector<int> myvector;
		// set some content in the vector:
		for (int i = 0; i < 100; i++)
			myvector.push_back(i);
		cout << "size: " << myvector.size() << " ";
		cout << "capacity: " << myvector.capacity() << " ";
		cout << "max_size: " << myvector.max_size() << " ";
		cout << endl;

		cout << "应输出  myvector contains: 1101 2202 0 1" << endl;
		cout << "实际是：";
		myvector.clear();
		myvector.push_back(1101);
		myvector.push_back(2202);
		cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			cout << ' ' << myvector[i];
		for (unsigned i = 0; i < myvector.size(); i++)
			myvector[i] = i;
		for (unsigned i = 0; i < myvector.size(); i++)
			cout << ' ' << myvector[i];
		cout << endl;

		_continue(1);
	}
#endif
	//测试at/data/front/back函数
#if test1_4
	{
		{
			cout << "test1_4 : 测试at/data/front/back函数" << endl;
			vector<int> myvector(5);
			int* p = myvector.data();
			*p = 10;
			++p;
			*p = 20;
			p[2] = 100;
			cout << "应输出  myvector contains: 10 20 0 100 0" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (unsigned i = 0; i < myvector.size(); ++i)
				cout << ' ' << myvector[i];
			cout << '\n';
		}
		{
			vector<int> myvector(10);
			//10 zero-initialized ints
			// assign some values:
			for (unsigned i = 0; i < myvector.size(); i++)
				myvector.at(i) = i;
			cout << "应输出  myvector contains: 0 1 2 3 4 5 6 7 8 9" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (unsigned i = 0; i < myvector.size(); i++)
				cout << ' ' << myvector.at(i);
			cout << endl;
		}
		{
			vector<int> myvector;
			myvector.push_back(10);
			while (myvector.back() != 0)
				myvector.push_back(myvector.back() - 1);
			cout << "应输出  myvector contains: 10 9 8 7 6 5 4 3 2 1 0" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (unsigned i = 0; i < myvector.size(); i++)
				cout << ' ' << myvector[i];
			cout << endl;
		}
		{
			vector<int> myvector;
			myvector.push_back(78);
			myvector.push_back(16);
			// now front equals 78, and back 16
			myvector.front() -= myvector.back();
			cout << "应输出  myvector.front() is now 62" << endl;
			cout << "实际是：";
			cout << "myvector.front() is now " << myvector.front() << endl;
		}
		_continue(2);
	}

#endif
//	//测试=赋值重载/resize/reverse/shrink_to_fit/emplace/emplace_back函数
#if test1_5
	{
		{
			cout << "test1_5 : 测试=赋值重载/resize/reverse/shrink_to_fit/emplace/emplace_back函数" << endl;
			vector<int> foo(3, 0);
			vector<int> bar(5, 0);
			bar = foo;
			foo = vector<int>();
			cout << "应输出  Size of foo: 0" << endl;
			cout << "实际是：";
			cout << "Size of foo: " << int(foo.size()) << '\n';
			cout << "应输出  Size of bar: 3" << endl;
			cout << "实际是：";
			cout << "Size of bar: " << int(bar.size()) << '\n';
		}
		cout << endl;
		{
			vector<int> myvector;
			// set some initial content:
			for (int i = 1; i < 10; i++)
				myvector.push_back(i);
			myvector.resize(5);
			cout << "应输出  myvector contains: 1 2 3 4 5" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (unsigned int i = 0; i < myvector.size(); i++)
				cout << ' ' << myvector[i];
			cout << endl;
			myvector.resize(8, 100);
			cout << "应输出  myvector contains: 1 2 3 4 5 100 100 100" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (unsigned int i = 0; i < myvector.size(); i++)
				cout << ' ' << myvector[i];
			cout << endl;
			myvector.resize(12);
			cout << "应输出  myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (unsigned int i = 0; i < myvector.size(); i++)
				cout << ' ' << myvector[i];
			cout << endl;
		}
		cout << endl;
		{
			vector<int> foo;
			auto sz = foo.capacity();
			cout << "应输出  making foo grow:1 2 3 4 6 9 13 19 28 42 63 94 141" << endl;
			cout << "实际是：";
			cout << "making foo grow:";
			for (int i = 0; i < 100; ++i) {
				foo.push_back(i);
				if (sz != foo.capacity()) {
					sz = foo.capacity();
					cout << sz << " ";
				}
			}
			cout << endl;
			vector<int> bar;
			sz = bar.capacity();
			bar.reserve(100);   // this is the only difference with foo above
			cout << "应输出  making bar grow:100" << endl;
			cout << "实际是：";
			cout << "making bar grow:";
			for (int i = 0; i < 100; ++i) {
				bar.push_back(i);
				if (sz != bar.capacity()) {
					sz = bar.capacity();
					cout << sz << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
		{
			cout << "应输出  capacity of myvector: 100 capacity of myvector: 100 capacity of myvector: 10" << endl;
			cout << "实际是：";
			vector<int> myvector(100);
			cout << "capacity of myvector: " << myvector.capacity() << ' ';
			myvector.resize(10);
			cout << "capacity of myvector: " << myvector.capacity() << ' ';
			myvector.shrink_to_fit();
			cout << "capacity of myvector: " << myvector.capacity() << ' ' << endl;
		}
		cout << endl;
		{
			vector<int> myvector = { 10,20,30 };
			auto it = myvector.emplace(myvector.begin() + 1, 100);
			cout << "应输出  myvector contains: 10 100 20 30" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (auto x = myvector.begin(); x != myvector.end(); x++)
				cout << ' ' << *x;
			cout << endl;
			myvector.emplace(it, 200);
			cout << "应输出  myvector contains: 10 200 100 20 30" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (auto x = myvector.begin(); x != myvector.end(); x++)
				cout << ' ' << *x;
			cout << endl;
			myvector.emplace(myvector.end(), 300);
			cout << "应输出  myvector contains: 10 200 100 20 30 300" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (auto x = myvector.begin(); x != myvector.end(); x++)
				cout << ' ' << *x;
			cout << endl;
		}
		cout << endl;
		{
			vector<int> myvector = { 10,20,30 };
			myvector.emplace_back(100);
			cout << "应输出  myvector contains: 10 20 30 100" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (auto x = myvector.begin(); x != myvector.end(); x++)
				cout << ' ' << *x;
			cout << endl;
			myvector.emplace_back(200);
			cout << "应输出  myvector contains: 10 20 30 100 200" << endl;
			cout << "实际是：";
			cout << "myvector contains:";
			for (auto x = myvector.begin(); x != myvector.end(); x++)
				cout << ' ' << *x;
			cout << endl;
		}
		_continue(1);
	}

#endif
	//测试swap成员友元函数
#if test1_6
	{
		cout << "test1_6 : 测试swap成员友元函数：" << endl;
		{
			vector<int> foo(3, 100);   // three ints with a value of 100
			vector<int> bar(5, 200);   // five ints with a value of 200
			foo.swap(bar);
			cout << "应输出  foo contains: 200 200 200 200 200" << endl;
			cout << "实际是：";
			cout << "foo contains:";
			for (unsigned i = 0; i < foo.size(); i++)
				cout << ' ' << foo[i];
			cout << '\n';
			cout << "应输出  bar contains: 100 100 100" << endl;
			cout << "实际是：";
			cout << "bar contains:";
			for (unsigned i = 0; i < bar.size(); i++)
				cout << ' ' << bar[i];
			cout << '\n';
		}
		cout << endl;
		{
			vector<int> foo(3, 100);   // three ints with a value of 100
			vector<int> bar(5, 200);   // five ints with a value of 200
			swap(foo, bar);
			cout << "应输出  foo contains: 200 200 200 200 200" << endl;
			cout << "实际是：";
			cout << "foo contains:";
			for (vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
				cout << ' ' << *it;
			cout << '\n';
			cout << "应输出  bar contains: 100 100 100" << endl;
			cout << "实际是：";
			cout << "bar contains:";
			for (vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
				cout << ' ' << *it;
			cout << '\n';
		}
		_continue(1);
	}
#endif
	//测试string类
#if test2_1
	{
		cout << "test2_1 : 测试string类" << endl;
		int test_int[] = { 1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			_continue(1, "第1组测试： begin/end  rbegin/rend函数");

			vector<string> t1 = { "test1", "test2", "test3", "test4", "test5" };

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
		}
		cout << endl;
		// 第2组测试 
		if (test_int[1]) {
			_continue(1, "第2组测试：\n push_back() pop_back()函数");
			vector<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			t1.pop_back();
			cout << "pop_back()的测试\n";
			cout << "应输出：test1 test2 test3 test4" << endl;
			cout << "实际是：";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.push_back("test6");
			cout << "push_back()的测试";
			cout << "结果\n应该是:test1 test2 test3 test4 test6    \n" << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}
		cout << endl;
		// 第3组测试 
		if (test_int[2]) {
			_continue(1, "第3组测试： swap()");
			vector<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			vector<string> t2 = { "test-1", "test-2", "test-3", "test-4" };
			cout << "swap()的测试\n" << endl;
			t1.swap(t2);
			cout << "t1 应该是 test-1 test-2 test-3 test-4，\n实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 应该是 test1 test2 test3 test4 test5，\n实际是";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "再次交换的测试\n" << endl;
			t1.swap(t2);
			cout << "t1 应该是 test1 test2 test3 test4 test5，\n实际是";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			cout << "t2 应该是 test-1 test-2 test-3 test-4，\n实际是";
			for (auto p = t2.begin(); p != t2.end(); p++)
				cout << *p << " ";
			cout << endl;
		}

		// 第4组测试 
		if (test_int[3]) {
			_continue(1, "第4组测试： emplace() emplace_back() ");
			vector<string> t1 = { "test1", "test2", "test3", "test4", "test5" };
			t1.emplace_back("test9");
			cout << "emplace_back()的测试\n";
			cout << "应输出：test1 test2 test3 test4 test5 test9" << endl;
			cout << "实际是：";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
			t1.emplace(t1.begin(), "test0");
			cout << "emplace()的测试";
			cout << "结果\n应该是:test0 test1 test2 test3 test4 test5 test9\n" << "实际是: ";
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << " ";
			cout << endl;
		}
		_continue(1);
	}
#endif
	//测试student类
#if test3_1
	{
		cout << "test3_1 : 测试student类" << endl;
		int test_int[] = { 1,1,1,1 }; //每个1对应1组if测试
		// 第1组测试 
		if (test_int[0]) {
			_continue(1, "第1组测试： begin/end  rbegin/rend函数");
			vector<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
								{1003,"t3",'M',83,"test3" } };

			cout << "遍历(正向): " << endl;
			cout << "应输出：1001-t1-M-81-test1 " << endl;
			cout << "        1002-t2-F-82-test2 " << endl;
			cout << "        1003-t3-M-83-test3 " << endl;
			cout << "实际是：";
			for (auto it = t1.begin(); it != t1.end(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << "数组遍历(反向): " << endl;
			cout << "应输出：1003-t3-M-83-test3" << endl;
			cout << "        1002-t2-F-82-test2 " << endl;
			cout << "        1001-t1-M-81-test1 " << endl;
			cout << "实际是：" << endl;
			for (auto it = t1.rbegin(); it != t1.rend(); ++it) {
				cout << *it << endl;
			}
			cout << endl;
			cout << endl;
		}
		// 第2组测试 
		if (test_int[1]) {
			_continue(1, "第2组测试： push_back() pop_back()函数");
			vector<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1003,"t3",'M',83,"test3" } };
			t1.pop_back();
			cout << "pop_back()的测试\n";
			cout << "应输出：1001-t1-M-81-test1 " << endl;
			cout << "        1002-t2-F-82-test2 " << endl;
			cout << "实际是：" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.push_back({ 1004,"t4",'M',84,"test4" });
			cout << "push_back()的测试\n";
			cout << "应输出：1001-t1-M 81-test1 " << endl;
			cout << "        1002-t2-F-82-test2 " << endl;
			cout << "        1004-t4-M-84-test4 " << endl;
			cout << "实际是: " << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			cout << endl;
		}
		// 第3组测试 
		if (test_int[2]) {
			_continue(1, "第3组测试：  emplace() emplace_back()");
			vector<student> t1 = { {1001,"t1",'M',81,"test1" },{1002,"t2",'F',82,"test2" },
							{1003,"t3",'M',83,"test3" } };
			t1.emplace(t1.begin() + 2, student({ 1004,"t4",'M',84,"test4" }));
			cout << "emplace()的测试，结果\n应该是" << endl;
			cout << "        1001-t1-M-81-test1 " << endl;
			cout << "        1002-t2-F-82-test2 " << endl;
			cout << "        1004-t4-M-84-test4 " << endl;
			cout << "        1003-t3-M-83-test3 " << endl;
			cout << "实际是" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
			t1.emplace_back(student({ 1005,"t5",'M',85,"test5" }));
			cout << "emplace_back()的测试，结果\n应该是" << endl;
			cout << "        1001-t1-M-81-test1 " << endl;
			cout << "        1002-t2-F-82-test2 " << endl;
			cout << "        1004-t4-M-84-test4 " << endl;
			cout << "        1003-t3-M-83-test3 " << endl;
			cout << "        1005-t5-M-85-test5 " << endl;
			cout << "实际是" << endl;
			for (auto p = t1.begin(); p != t1.end(); p++)
				cout << *p << endl;
			cout << endl;
		}
	}
#endif
}