/*鞠璇 1851846 数强*/
#include <iostream>
#include <string>
#include <array>
#include"tj_array_ju.cpp"
#include "tj_array_ju.h"
#include"tj_student.h"

using namespace std;


/* 这句宏定义注释掉，就是系统array的测试，
   打开宏定义，则测试自己的 tj_array */
 //  #define	array	tj_array


void press_key(int num, const char *prompt)
{
	int i;
	cout<< endl<<prompt<<"，按任意键继续...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}


int main()
{
	//int
	if (1) {
		int test_int[] = { 0,0,0,0,1,1,1 }; //每个1对应1组if测试
		// 第0组测试 
		if (test_int[0]) {
			press_key(1, "第0组测试：\n begin/end/cbegin/cend()及rbegin/rend/crbegin/crend()函数");

			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			cout << "数组遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";
			for (auto it = arr1.begin(); it != arr1.end(); ++it) {
				cout << *it << " "; 
			}
			cout << endl;

			cout << endl;

			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";
			for (auto it = arr1.cbegin(); it != arr1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "数组遍历(反向): " << endl;
			cout << "应输出：5 4 3 2 1" << endl;
			cout << "实际是：";
			for (auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：5 4 3 2 1" << endl;
			cout << "实际是：";
			for (auto it = arr1.crbegin(); it != arr1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			array<int, 0> arr2;
			cout << "测试当数组大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (arr2.begin() == arr2.end()) << endl;

			cout << endl;

			cout << "测试当数组大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (arr2.rbegin() == arr2.rend());

			cout << endl << endl;
		}
		
		// 第1组测试 
		if (test_int[1]) {
			press_key(1, "第1组测试：\n size()、max_size()和empty()函数");

			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 0> arr2;

			cout << "size()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出："<<sizeof(arr1)/sizeof(int) << endl;
			cout << "实际是：" << arr1.size() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr2.size() << endl;

			cout << endl;

			cout << "max_size()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出："<< sizeof(arr1) / sizeof(int) << endl;
			cout << "实际是：" << arr1.max_size() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr2.max_size() << endl;

			cout << endl;

			cout << "empty()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr1.empty() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << arr2.empty() << endl;

			cout << endl << endl;
		}
		
		// 第2组测试 
		if (test_int[2]) {
			press_key(1, "第2组测试：\n *无越界的*下标[]访问，at(),front(),back(),data()函数");
			array<int, 5> arr1 = { 0, 2, 3, 4, 5 };

			arr1[0] = 1;
			cout << "下标[]访问,数组遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << endl;

			arr1[0] = 0;
			arr1.at(0) = 1;
			cout << "at()访问,数组遍历(正向): " << endl;
			cout << "应输出：1 2 3 4 5" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			arr1[0] = 0;
			arr1.front() =1 ;
			cout << "front()函数: " << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << arr1.front() << endl;

			cout << endl;

			arr1[4] = 0;
			arr1.back() = 5;
			cout << "back()函数: " << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << arr1.back() << endl;

			cout << endl;

			cout << "data()函数: " << endl;
			cout << "应输出：" << &arr1 << endl;
			cout << "实际是：" << arr1.data() << endl;

			cout << endl << endl;

		}
		
		// 第3组测试 
		if (test_int[3]) {
			press_key(1, "第3组测试：\n *有越界的*at()函数");
			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 0> arr2;

			cout << "at()访问越界: " << endl;
			cout << "应输出：invalid array<T, N> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr1.at(5) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "应输出：invalid array<T, N> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr1.at(-1) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "应输出：invalid array<T, 0> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr2.at(1) << endl;
				//throw(std::out_of_range("invalid array<T, 0> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl << endl;
		}
		
		// 第4组测试 
		if (test_int[4]) {
			press_key(1, "第4组测试：\n fill(),swap()函数");
			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 5> arr2 = { 5,4,3,2,1 };

			cout << "fill()函数: " << endl;
			arr1.fill(5);
			cout << "应输出：5 5 5 5 5" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;


			cout << "swap()函数: " << endl;
			arr1.swap(arr2);
			cout << "arr1:" << endl;
			cout << "应输出：5 4 3 2 1" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;
			cout << "arr2:" << endl;
			cout << "应输出：5 5 5 5 5" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr2.size(); i++) {
				cout << arr2.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << endl << endl;
		}
		
		// 第5组测试 
		if (test_int[5]) {
			press_key(1, "第5组测试：\n 按照> == < >= <= !=的顺序对两个array数组容器进行比较");
			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 5> arr2 = { 5, 4, 3, 2, 1 };
			array<int, 5> arr3 = { 5, 4, 3, 2, 1 };
			array<int, 5> arr4 = { 5, 4, 3, 2, 2 };

			cout << "arr1与arr2比较: " << endl;
			cout << "应输出：0 0 1 0 1 1" << endl;
			cout << "实际是：" << ((arr1 > arr2) ? 1 : 0) << " ";
			cout << ((arr1 == arr2) ? 1 : 0) << " ";
			cout << ((arr1 < arr2) ? 1 : 0) << " ";
			cout << ((arr1 >= arr2) ? 1 : 0) << " ";
			cout << ((arr1 <= arr2) ? 1 : 0) << " ";
			cout << ((arr1 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "arr2与arr3比较: " << endl;
			cout << "应输出：0 1 0 1 1 0" << endl;
			cout << "实际是：" << ((arr2 > arr3) ? 1 : 0) << " ";
			cout << ((arr2 == arr3) ? 1 : 0) << " ";
			cout << ((arr2 < arr3) ? 1 : 0) << " ";
			cout << ((arr2 >= arr3) ? 1 : 0) << " ";
			cout << ((arr2 <= arr3) ? 1 : 0) << " ";
			cout << ((arr2 != arr3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "arr4与arr2比较: " << endl;
			cout << "应输出：1 0 0 1 0 1" << endl;
			cout << "实际是：" << ((arr4 > arr2) ? 1 : 0) << " ";
			cout << ((arr4 == arr2) ? 1 : 0) << " ";
			cout << ((arr4 < arr2) ? 1 : 0) << " ";
			cout << ((arr4 >= arr2) ? 1 : 0) << " ";
			cout << ((arr4 <= arr2) ? 1 : 0) << " ";
			cout << ((arr4 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}
	
		// 第6组测试 
		if (test_int[6]) {
			
			press_key(1, "第6组测试：\n 综合测试");
			array<int, 1024/sizeof(int)> arr1 ;
			array<int, 1024 / sizeof(int)> arr2;

			press_key(1, "\n向arr1中填1——1024/sizeof(int)个数");

			int i;
			for (i = 0; i < 1024/ sizeof(int);i++) {
				arr1[i] = i;
			}
			cout << "填入成功，输出几个元素进行检验"<<endl<<endl;

			cout << "应输出：0 255 18 168" << endl;
			cout << "实际是：" << arr1.at(0)<<" "<< arr1.at(1024 / sizeof(int)-1)<<" "<<arr1.at(18) <<" "<< arr1.at(168) << endl;

			cout << endl;
			
			cout << "测试swap,arr1与arr2交换：" << endl;
			
			arr1.swap(arr2);
			cout << "应输出：0 255 18 168" << endl;
			cout << "实际是：" << arr2.at(0) << " " << arr2.at(1024 / sizeof(int) - 1) << " " << arr2.at(18) << " " << arr2.at(168) << endl;

			cout << "测试fill,arr1全部填入1：" << endl;

			arr1.fill(1);

			cout << "应输出：1 1 1 1" << endl;
			cout << "实际是：" << arr1.at(0) << " " << arr1.at(1024 / sizeof(int) - 1) << " " << arr1.at(18) << " " << arr1.at(168) << endl;

			cout << endl << endl;
		}

	}
	
	//string
	if (0) {
		int test_string[] = { 1,1,1,1,1,1,1 }; //每个1对应1组if测试

	// 第0组测试 
		if (test_string[0]) {
			press_key(1, "第0组测试：\n begin/end/cbegin/cend()及rbegin/rend/crbegin/crend()函数");

			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };

			cout << "数组遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";
			for (auto it = arr1.begin(); it != arr1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";
			for (auto it = arr1.cbegin(); it != arr1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "数组遍历(反向): " << endl;
			cout << "应输出：ij gh ef cd ab" << endl;
			cout << "实际是：";
			for (auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：ij gh ef cd ab" << endl;
			cout << "实际是：";
			for (auto it = arr1.crbegin(); it != arr1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			array<int, 0> arr2;
			cout << "测试当数组大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (arr2.begin() == arr2.end()) << endl;

			cout << endl;

			cout << "测试当数组大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (arr2.rbegin() == arr2.rend());

			cout << endl << endl;
		}

		// 第1组测试 
		if (test_string[1]) {
			press_key(1, "第1组测试：\n size()、max_size()和empty()函数");

			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 0> arr2;

			cout << "size()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << arr1.size() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr2.size() << endl;

			cout << endl;

			cout << "max_size()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出：5" << endl;
			cout << "实际是：" << arr1.max_size() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr2.max_size() << endl;

			cout << endl;

			cout << "empty()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr1.empty() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << arr2.empty() << endl;

			cout << endl << endl;
		}

		// 第2组测试 
		if (test_string[2]) {
			press_key(1, "第2组测试：\n *无越界的*下标[]访问，at(),front(),back(),data()函数");
			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 0> arr2;

			cout << "下标[]访问,数组遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << endl;

			cout << "at()访问,数组遍历(正向): " << endl;
			cout << "应输出：ab cd ef gh ij" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << "front()函数: " << endl;
			cout << "应输出：ab" << endl;
			cout << "实际是：" << arr1.front() << endl;

			cout << endl;


			cout << "back()函数: " << endl;
			cout << "应输出：ij" << endl;
			cout << "实际是：" << arr1.back() << endl;

			cout << endl;

			cout << "data()函数: " << endl;
			cout << "应输出：" << &arr1 << endl;
			cout << "实际是：" << arr1.data() << endl;

			cout << endl << endl;

		}

		// 第3组测试 
		if (test_string[3]) {
			press_key(1, "第3组测试：\n *有越界的*at()函数");
			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 0> arr2;

			cout << "at()访问越界: " << endl;
			cout << "应输出：invalid array<T, N> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr1.at(5) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "应输出：invalid array<T, N> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr1.at(-1) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "应输出：invalid array<T, 0> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr2.at(1) << endl;
				//throw(std::out_of_range("invalid array<T, 0> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl << endl;
		}

		// 第4组测试 
		if (test_string[4]) {
			press_key(1, "第4组测试：\n fill(),swap()函数");
			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 5> arr2 = { "ij","gh" ,"ef", "cd", "ab" };

			cout << "fill()函数: " << endl;
			arr1.fill("mn");
			cout << "应输出：mn mn mn mn mn" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;


			cout << "swap()函数: " << endl;
			arr1.swap(arr2);
			cout << "arr1:" << endl;
			cout << "应输出：ij gh ef cd ab" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;
			cout << "arr2:" << endl;
			cout << "应输出：mn mn mn mn mn" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr2.size(); i++) {
				cout << arr2.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << endl << endl;
		}

		// 第5组测试 
		if (test_string[5]) {
			press_key(1, "第5组测试：\n 按照> == < >= <= !=的顺序对两个array数组容器进行比较");
			array<string, 5> arr1 = { "abc", "def", "ghi","jkl", "mno" };
			array<string, 5> arr2 = { "mno", "jkl", "ghi", "def", "abc" };
			array<string, 5> arr3 = { "mno", "jkl", "ghi", "def", "abc" };
			array<string, 5> arr4 = { "mno", "jkl", "ghi", "def", "abd" };

			cout << "arr1与arr2比较: " << endl;
			cout << "应输出：0 0 1 0 1 1" << endl;
			cout << "实际是：" << ((arr1 > arr2) ? 1 : 0) << " ";
			cout << ((arr1 == arr2) ? 1 : 0) << " ";
			cout << ((arr1 < arr2) ? 1 : 0) << " ";
			cout << ((arr1 >= arr2) ? 1 : 0) << " ";
			cout << ((arr1 <= arr2) ? 1 : 0) << " ";
			cout << ((arr1 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "arr2与arr3比较: " << endl;
			cout << "应输出：0 1 0 1 1 0" << endl;
			cout << "实际是：" << ((arr2 > arr3) ? 1 : 0) << " ";
			cout << ((arr2 == arr3) ? 1 : 0) << " ";
			cout << ((arr2 < arr3) ? 1 : 0) << " ";
			cout << ((arr2 >= arr3) ? 1 : 0) << " ";
			cout << ((arr2 <= arr3) ? 1 : 0) << " ";
			cout << ((arr2 != arr3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "arr4与arr2比较: " << endl;
			cout << "应输出：1 0 0 1 0 1" << endl;
			cout << "实际是：" << ((arr4 > arr2) ? 1 : 0) << " ";
			cout << ((arr4 == arr2) ? 1 : 0) << " ";
			cout << ((arr4 < arr2) ? 1 : 0) << " ";
			cout << ((arr4 >= arr2) ? 1 : 0) << " ";
			cout << ((arr4 <= arr2) ? 1 : 0) << " ";
			cout << ((arr4 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		// 第6组测试 
		if (test_string[6]) {
			press_key(1, "第6组测试：\n 可自行编写");

			cout << endl;
		}


	}
	
	//student
	if (0) {
		int test_student[] = { 1,1,1,1,1,1,1 }; //每个1对应1组if测试
		const student mother[4] = { {1851846,"鞠璇",'f',(float)(92.2),"河北"},
		{1851801,"刘子云",'f',(float)(94.2),"河北"},
		{1854205,"郑昕瑶",'f',(float)(93.5),"湖北"},
		{1854167,"徐思琪",'f',(float)(91.7),"湖北"} };

	// 第0组测试 
		if (test_student[0]) {
			press_key(1, "第0组测试：\n begin/end/cbegin/cend()及rbegin/rend/crbegin/crend()函数");

			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };

			cout << "数组遍历(正向): " << endl;
			cout << "应输出：鞠璇，刘子云，郑昕瑶，徐思琪四人信息" << endl;
			cout << "实际是：";
			for (auto it = arr1.begin(); it != arr1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：鞠璇，刘子云，郑昕瑶，徐思琪四人信息" << endl;
			cout << "实际是：";
			for (auto it = arr1.cbegin(); it != arr1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "数组遍历(反向): " << endl;
			cout << "应输出：徐思琪，郑昕瑶，刘子云，鞠璇四人信息" << endl;
			cout << "实际是：";
			for (auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "应输出：徐思琪，郑昕瑶，刘子云，鞠璇四人信息" << endl;
			cout << "实际是：";
			for (auto it = arr1.crbegin(); it != arr1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			array<int, 0> arr2;
			cout << "测试当数组大小为0时begin和end是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (arr2.begin() == arr2.end()) << endl;

			cout << endl;

			cout << "测试当数组大小为0时rbegin和rend是否相等" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << (arr2.rbegin() == arr2.rend());

			cout << endl << endl;
		}

		// 第1组测试 
		if (test_student[1]) {
			press_key(1, "第1组测试：\n size()、max_size()和empty()函数");

			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<student, 0> arr2;

			cout << "size()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出："<<sizeof(arr1)/sizeof(student) << endl;
			cout << "实际是：" << arr1.size() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr2.size() << endl;

			cout << endl;

			cout << "max_size()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出："<< sizeof(arr1) / sizeof(student) << endl;
			cout << "实际是：" << arr1.max_size() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr2.max_size() << endl;

			cout << endl;

			cout << "empty()函数: " << endl;
			cout << "arr1:" << endl;
			cout << "应输出：0" << endl;
			cout << "实际是：" << arr1.empty() << endl;
			cout << "arr2:" << endl;
			cout << "应输出：1" << endl;
			cout << "实际是：" << arr2.empty() << endl;

			cout << endl << endl;
		}

		// 第2组测试 
		if (test_student[2]) {
			press_key(1, "第2组测试：\n *无越界的*下标[]访问，at(),front(),back(),data()函数");
			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<string, 0> arr2;

			cout << "下标[]访问,数组遍历(正向): " << endl;
			cout << "应输出：鞠璇，刘子云，郑昕瑶，徐思琪四人信息" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << endl;

			cout << "at()访问,数组遍历(正向): " << endl;
			cout << "应输出：鞠璇，刘子云，郑昕瑶，徐思琪四人信息" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << "front()函数: " << endl;
			cout << "应输出：1851846 鞠璇 f 92.2 河北" << endl;
			cout << "实际是：" << arr1.front() << endl;

			cout << endl;


			cout << "back()函数: " << endl;
			cout << "应输出：1854167 徐思琪 f 91.7 湖北" << endl;
			cout << "实际是：" << arr1.back() << endl;

			cout << endl;

			cout << "data()函数: " << endl;
			cout << "应输出：" << &arr1 << endl;
			cout << "实际是：" << arr1.data() << endl;

			cout << endl << endl;

		}

		// 第3组测试 
		if (test_student[3]) {
			press_key(1, "第3组测试：\n *有越界的*at()函数");
			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<string, 0> arr2;

			cout << "at()访问越界: " << endl;
			cout << "应输出：invalid array<T, N> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr1.at(4) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "应输出：invalid array<T, N> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr1.at(-1) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "应输出：invalid array<T, 0> subscript" << endl;
			cout << "实际是：";
			try {
				cout << arr2.at(1) << endl;
				//throw(std::out_of_range("invalid array<T, 0> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl << endl;
		}

		// 第4组测试 
		if (test_student[4]) {
			press_key(1, "第4组测试：\n fill(),swap()函数");
			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<student, 4> arr2 = { mother[3],mother[2],mother[1],mother[0] }; 
			cout << "fill()函数: " << endl;
			arr1.fill({ 1854167,"徐思琪",'f',91.0,"湖北" });
			cout << "应输出：四遍徐思琪的信息" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;


			cout << "swap()函数: " << endl;
			arr1.swap(arr2);
			cout << "arr1:" << endl;
			cout << "应输出：徐思琪，郑昕瑶，刘子云，鞠璇四人信息" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;
			cout << "arr2:" << endl;
			cout << "应输出：五遍徐思琪的信息" << endl;
			cout << "实际是：";
			for (int i = 0; i < (int)arr2.size(); i++) {
				cout << arr2.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << endl << endl;
		}

		// 第5组测试 
		if (test_student[5]) {
			press_key(1, "第5组测试：\n 按照 == !=的顺序对两个array数组容器进行比较（比较学号，其它不进行测试）");
			array<student, 4> arr1 = { mother[0], mother[1], mother[2],mother[3] };
			array<student, 4> arr2 = { mother[0], mother[1], mother[2],mother[3] };
			array<student, 4> arr3 = { mother[0], mother[1], mother[2],mother[2] };


			cout << "arr1与arr2比较: " << endl;
			cout << "应输出：1 0" << endl;
			cout << "实际是：";
			cout << ((arr1 == arr2) ? 1 : 0) << " ";
			cout << ((arr1 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "arr1与arr3比较: " << endl;
			cout << "应输出：0 1" << endl;
			cout << "实际是：";
			cout << ((arr1 == arr3) ? 1 : 0) << " ";
			cout << ((arr1 != arr3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		// 第6组测试 
		if (test_student[6]) {
			press_key(1, "第6组测试：\n 可自行编写");

			cout << endl;
		}

	}
	
	return 0;
}
