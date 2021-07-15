/*��� 1851846 ��ǿ*/
#include <iostream>
#include <string>
#include <array>
#include"tj_array_ju.cpp"
#include "tj_array_ju.h"
#include"tj_student.h"

using namespace std;


/* ���궨��ע�͵�������ϵͳarray�Ĳ��ԣ�
   �򿪺궨�壬������Լ��� tj_array */
 //  #define	array	tj_array


void press_key(int num, const char *prompt)
{
	int i;
	cout<< endl<<prompt<<"�������������...";
	for (i = 0; i < num; i++)
		getchar();
	cout << endl;
}


int main()
{
	//int
	if (1) {
		int test_int[] = { 0,0,0,0,1,1,1 }; //ÿ��1��Ӧ1��if����
		// ��0����� 
		if (test_int[0]) {
			press_key(1, "��0����ԣ�\n begin/end/cbegin/cend()��rbegin/rend/crbegin/crend()����");

			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			cout << "�������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.begin(); it != arr1.end(); ++it) {
				cout << *it << " "; 
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.cbegin(); it != arr1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "�������(����): " << endl;
			cout << "Ӧ�����5 4 3 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�����5 4 3 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.crbegin(); it != arr1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			array<int, 0> arr2;
			cout << "���Ե������СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (arr2.begin() == arr2.end()) << endl;

			cout << endl;

			cout << "���Ե������СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (arr2.rbegin() == arr2.rend());

			cout << endl << endl;
		}
		
		// ��1����� 
		if (test_int[1]) {
			press_key(1, "��1����ԣ�\n size()��max_size()��empty()����");

			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 0> arr2;

			cout << "size()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����"<<sizeof(arr1)/sizeof(int) << endl;
			cout << "ʵ���ǣ�" << arr1.size() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr2.size() << endl;

			cout << endl;

			cout << "max_size()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����"<< sizeof(arr1) / sizeof(int) << endl;
			cout << "ʵ���ǣ�" << arr1.max_size() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr2.max_size() << endl;

			cout << endl;

			cout << "empty()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr1.empty() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << arr2.empty() << endl;

			cout << endl << endl;
		}
		
		// ��2����� 
		if (test_int[2]) {
			press_key(1, "��2����ԣ�\n *��Խ���*�±�[]���ʣ�at(),front(),back(),data()����");
			array<int, 5> arr1 = { 0, 2, 3, 4, 5 };

			arr1[0] = 1;
			cout << "�±�[]����,�������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << endl;

			arr1[0] = 0;
			arr1.at(0) = 1;
			cout << "at()����,�������(����): " << endl;
			cout << "Ӧ�����1 2 3 4 5" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			arr1[0] = 0;
			arr1.front() =1 ;
			cout << "front()����: " << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << arr1.front() << endl;

			cout << endl;

			arr1[4] = 0;
			arr1.back() = 5;
			cout << "back()����: " << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << arr1.back() << endl;

			cout << endl;

			cout << "data()����: " << endl;
			cout << "Ӧ�����" << &arr1 << endl;
			cout << "ʵ���ǣ�" << arr1.data() << endl;

			cout << endl << endl;

		}
		
		// ��3����� 
		if (test_int[3]) {
			press_key(1, "��3����ԣ�\n *��Խ���*at()����");
			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 0> arr2;

			cout << "at()����Խ��: " << endl;
			cout << "Ӧ�����invalid array<T, N> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr1.at(5) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "Ӧ�����invalid array<T, N> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr1.at(-1) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "Ӧ�����invalid array<T, 0> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr2.at(1) << endl;
				//throw(std::out_of_range("invalid array<T, 0> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl << endl;
		}
		
		// ��4����� 
		if (test_int[4]) {
			press_key(1, "��4����ԣ�\n fill(),swap()����");
			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 5> arr2 = { 5,4,3,2,1 };

			cout << "fill()����: " << endl;
			arr1.fill(5);
			cout << "Ӧ�����5 5 5 5 5" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;


			cout << "swap()����: " << endl;
			arr1.swap(arr2);
			cout << "arr1:" << endl;
			cout << "Ӧ�����5 4 3 2 1" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����5 5 5 5 5" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr2.size(); i++) {
				cout << arr2.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << endl << endl;
		}
		
		// ��5����� 
		if (test_int[5]) {
			press_key(1, "��5����ԣ�\n ����> == < >= <= !=��˳�������array�����������бȽ�");
			array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
			array<int, 5> arr2 = { 5, 4, 3, 2, 1 };
			array<int, 5> arr3 = { 5, 4, 3, 2, 1 };
			array<int, 5> arr4 = { 5, 4, 3, 2, 2 };

			cout << "arr1��arr2�Ƚ�: " << endl;
			cout << "Ӧ�����0 0 1 0 1 1" << endl;
			cout << "ʵ���ǣ�" << ((arr1 > arr2) ? 1 : 0) << " ";
			cout << ((arr1 == arr2) ? 1 : 0) << " ";
			cout << ((arr1 < arr2) ? 1 : 0) << " ";
			cout << ((arr1 >= arr2) ? 1 : 0) << " ";
			cout << ((arr1 <= arr2) ? 1 : 0) << " ";
			cout << ((arr1 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "arr2��arr3�Ƚ�: " << endl;
			cout << "Ӧ�����0 1 0 1 1 0" << endl;
			cout << "ʵ���ǣ�" << ((arr2 > arr3) ? 1 : 0) << " ";
			cout << ((arr2 == arr3) ? 1 : 0) << " ";
			cout << ((arr2 < arr3) ? 1 : 0) << " ";
			cout << ((arr2 >= arr3) ? 1 : 0) << " ";
			cout << ((arr2 <= arr3) ? 1 : 0) << " ";
			cout << ((arr2 != arr3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "arr4��arr2�Ƚ�: " << endl;
			cout << "Ӧ�����1 0 0 1 0 1" << endl;
			cout << "ʵ���ǣ�" << ((arr4 > arr2) ? 1 : 0) << " ";
			cout << ((arr4 == arr2) ? 1 : 0) << " ";
			cout << ((arr4 < arr2) ? 1 : 0) << " ";
			cout << ((arr4 >= arr2) ? 1 : 0) << " ";
			cout << ((arr4 <= arr2) ? 1 : 0) << " ";
			cout << ((arr4 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}
	
		// ��6����� 
		if (test_int[6]) {
			
			press_key(1, "��6����ԣ�\n �ۺϲ���");
			array<int, 1024/sizeof(int)> arr1 ;
			array<int, 1024 / sizeof(int)> arr2;

			press_key(1, "\n��arr1����1����1024/sizeof(int)����");

			int i;
			for (i = 0; i < 1024/ sizeof(int);i++) {
				arr1[i] = i;
			}
			cout << "����ɹ����������Ԫ�ؽ��м���"<<endl<<endl;

			cout << "Ӧ�����0 255 18 168" << endl;
			cout << "ʵ���ǣ�" << arr1.at(0)<<" "<< arr1.at(1024 / sizeof(int)-1)<<" "<<arr1.at(18) <<" "<< arr1.at(168) << endl;

			cout << endl;
			
			cout << "����swap,arr1��arr2������" << endl;
			
			arr1.swap(arr2);
			cout << "Ӧ�����0 255 18 168" << endl;
			cout << "ʵ���ǣ�" << arr2.at(0) << " " << arr2.at(1024 / sizeof(int) - 1) << " " << arr2.at(18) << " " << arr2.at(168) << endl;

			cout << "����fill,arr1ȫ������1��" << endl;

			arr1.fill(1);

			cout << "Ӧ�����1 1 1 1" << endl;
			cout << "ʵ���ǣ�" << arr1.at(0) << " " << arr1.at(1024 / sizeof(int) - 1) << " " << arr1.at(18) << " " << arr1.at(168) << endl;

			cout << endl << endl;
		}

	}
	
	//string
	if (0) {
		int test_string[] = { 1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����

	// ��0����� 
		if (test_string[0]) {
			press_key(1, "��0����ԣ�\n begin/end/cbegin/cend()��rbegin/rend/crbegin/crend()����");

			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };

			cout << "�������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.begin(); it != arr1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.cbegin(); it != arr1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "�������(����): " << endl;
			cout << "Ӧ�����ij gh ef cd ab" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�����ij gh ef cd ab" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.crbegin(); it != arr1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			array<int, 0> arr2;
			cout << "���Ե������СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (arr2.begin() == arr2.end()) << endl;

			cout << endl;

			cout << "���Ե������СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (arr2.rbegin() == arr2.rend());

			cout << endl << endl;
		}

		// ��1����� 
		if (test_string[1]) {
			press_key(1, "��1����ԣ�\n size()��max_size()��empty()����");

			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 0> arr2;

			cout << "size()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << arr1.size() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr2.size() << endl;

			cout << endl;

			cout << "max_size()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����5" << endl;
			cout << "ʵ���ǣ�" << arr1.max_size() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr2.max_size() << endl;

			cout << endl;

			cout << "empty()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr1.empty() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << arr2.empty() << endl;

			cout << endl << endl;
		}

		// ��2����� 
		if (test_string[2]) {
			press_key(1, "��2����ԣ�\n *��Խ���*�±�[]���ʣ�at(),front(),back(),data()����");
			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 0> arr2;

			cout << "�±�[]����,�������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << endl;

			cout << "at()����,�������(����): " << endl;
			cout << "Ӧ�����ab cd ef gh ij" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << "front()����: " << endl;
			cout << "Ӧ�����ab" << endl;
			cout << "ʵ���ǣ�" << arr1.front() << endl;

			cout << endl;


			cout << "back()����: " << endl;
			cout << "Ӧ�����ij" << endl;
			cout << "ʵ���ǣ�" << arr1.back() << endl;

			cout << endl;

			cout << "data()����: " << endl;
			cout << "Ӧ�����" << &arr1 << endl;
			cout << "ʵ���ǣ�" << arr1.data() << endl;

			cout << endl << endl;

		}

		// ��3����� 
		if (test_string[3]) {
			press_key(1, "��3����ԣ�\n *��Խ���*at()����");
			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 0> arr2;

			cout << "at()����Խ��: " << endl;
			cout << "Ӧ�����invalid array<T, N> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr1.at(5) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "Ӧ�����invalid array<T, N> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr1.at(-1) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "Ӧ�����invalid array<T, 0> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr2.at(1) << endl;
				//throw(std::out_of_range("invalid array<T, 0> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl << endl;
		}

		// ��4����� 
		if (test_string[4]) {
			press_key(1, "��4����ԣ�\n fill(),swap()����");
			array<string, 5> arr1 = { "ab","cd" ,"ef", "gh", "ij" };
			array<string, 5> arr2 = { "ij","gh" ,"ef", "cd", "ab" };

			cout << "fill()����: " << endl;
			arr1.fill("mn");
			cout << "Ӧ�����mn mn mn mn mn" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;


			cout << "swap()����: " << endl;
			arr1.swap(arr2);
			cout << "arr1:" << endl;
			cout << "Ӧ�����ij gh ef cd ab" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����mn mn mn mn mn" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr2.size(); i++) {
				cout << arr2.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << endl << endl;
		}

		// ��5����� 
		if (test_string[5]) {
			press_key(1, "��5����ԣ�\n ����> == < >= <= !=��˳�������array�����������бȽ�");
			array<string, 5> arr1 = { "abc", "def", "ghi","jkl", "mno" };
			array<string, 5> arr2 = { "mno", "jkl", "ghi", "def", "abc" };
			array<string, 5> arr3 = { "mno", "jkl", "ghi", "def", "abc" };
			array<string, 5> arr4 = { "mno", "jkl", "ghi", "def", "abd" };

			cout << "arr1��arr2�Ƚ�: " << endl;
			cout << "Ӧ�����0 0 1 0 1 1" << endl;
			cout << "ʵ���ǣ�" << ((arr1 > arr2) ? 1 : 0) << " ";
			cout << ((arr1 == arr2) ? 1 : 0) << " ";
			cout << ((arr1 < arr2) ? 1 : 0) << " ";
			cout << ((arr1 >= arr2) ? 1 : 0) << " ";
			cout << ((arr1 <= arr2) ? 1 : 0) << " ";
			cout << ((arr1 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "arr2��arr3�Ƚ�: " << endl;
			cout << "Ӧ�����0 1 0 1 1 0" << endl;
			cout << "ʵ���ǣ�" << ((arr2 > arr3) ? 1 : 0) << " ";
			cout << ((arr2 == arr3) ? 1 : 0) << " ";
			cout << ((arr2 < arr3) ? 1 : 0) << " ";
			cout << ((arr2 >= arr3) ? 1 : 0) << " ";
			cout << ((arr2 <= arr3) ? 1 : 0) << " ";
			cout << ((arr2 != arr3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;


			cout << "arr4��arr2�Ƚ�: " << endl;
			cout << "Ӧ�����1 0 0 1 0 1" << endl;
			cout << "ʵ���ǣ�" << ((arr4 > arr2) ? 1 : 0) << " ";
			cout << ((arr4 == arr2) ? 1 : 0) << " ";
			cout << ((arr4 < arr2) ? 1 : 0) << " ";
			cout << ((arr4 >= arr2) ? 1 : 0) << " ";
			cout << ((arr4 <= arr2) ? 1 : 0) << " ";
			cout << ((arr4 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		// ��6����� 
		if (test_string[6]) {
			press_key(1, "��6����ԣ�\n �����б�д");

			cout << endl;
		}


	}
	
	//student
	if (0) {
		int test_student[] = { 1,1,1,1,1,1,1 }; //ÿ��1��Ӧ1��if����
		const student mother[4] = { {1851846,"���",'f',(float)(92.2),"�ӱ�"},
		{1851801,"������",'f',(float)(94.2),"�ӱ�"},
		{1854205,"֣���",'f',(float)(93.5),"����"},
		{1854167,"��˼��",'f',(float)(91.7),"����"} };

	// ��0����� 
		if (test_student[0]) {
			press_key(1, "��0����ԣ�\n begin/end/cbegin/cend()��rbegin/rend/crbegin/crend()����");

			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };

			cout << "�������(����): " << endl;
			cout << "Ӧ�������诣������ƣ�֣�������˼��������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.begin(); it != arr1.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�������诣������ƣ�֣�������˼��������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.cbegin(); it != arr1.cend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "�������(����): " << endl;
			cout << "Ӧ�������˼����֣����������ƣ����������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.rbegin(); it != arr1.rend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			cout << "Ӧ�������˼����֣����������ƣ����������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (auto it = arr1.crbegin(); it != arr1.crend(); ++it) {
				cout << *it << " ";
			}
			cout << endl;

			cout << endl;

			array<int, 0> arr2;
			cout << "���Ե������СΪ0ʱbegin��end�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (arr2.begin() == arr2.end()) << endl;

			cout << endl;

			cout << "���Ե������СΪ0ʱrbegin��rend�Ƿ����" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << (arr2.rbegin() == arr2.rend());

			cout << endl << endl;
		}

		// ��1����� 
		if (test_student[1]) {
			press_key(1, "��1����ԣ�\n size()��max_size()��empty()����");

			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<student, 0> arr2;

			cout << "size()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����"<<sizeof(arr1)/sizeof(student) << endl;
			cout << "ʵ���ǣ�" << arr1.size() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr2.size() << endl;

			cout << endl;

			cout << "max_size()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����"<< sizeof(arr1) / sizeof(student) << endl;
			cout << "ʵ���ǣ�" << arr1.max_size() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr2.max_size() << endl;

			cout << endl;

			cout << "empty()����: " << endl;
			cout << "arr1:" << endl;
			cout << "Ӧ�����0" << endl;
			cout << "ʵ���ǣ�" << arr1.empty() << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ�����1" << endl;
			cout << "ʵ���ǣ�" << arr2.empty() << endl;

			cout << endl << endl;
		}

		// ��2����� 
		if (test_student[2]) {
			press_key(1, "��2����ԣ�\n *��Խ���*�±�[]���ʣ�at(),front(),back(),data()����");
			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<string, 0> arr2;

			cout << "�±�[]����,�������(����): " << endl;
			cout << "Ӧ�������诣������ƣ�֣�������˼��������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1[i] << " ";
			}
			cout << endl;

			cout << endl;

			cout << "at()����,�������(����): " << endl;
			cout << "Ӧ�������诣������ƣ�֣�������˼��������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << "front()����: " << endl;
			cout << "Ӧ�����1851846 ��� f 92.2 �ӱ�" << endl;
			cout << "ʵ���ǣ�" << arr1.front() << endl;

			cout << endl;


			cout << "back()����: " << endl;
			cout << "Ӧ�����1854167 ��˼�� f 91.7 ����" << endl;
			cout << "ʵ���ǣ�" << arr1.back() << endl;

			cout << endl;

			cout << "data()����: " << endl;
			cout << "Ӧ�����" << &arr1 << endl;
			cout << "ʵ���ǣ�" << arr1.data() << endl;

			cout << endl << endl;

		}

		// ��3����� 
		if (test_student[3]) {
			press_key(1, "��3����ԣ�\n *��Խ���*at()����");
			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<string, 0> arr2;

			cout << "at()����Խ��: " << endl;
			cout << "Ӧ�����invalid array<T, N> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr1.at(4) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "Ӧ�����invalid array<T, N> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr1.at(-1) << endl;
				//throw(std::out_of_range("invalid array<T, N> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl;

			cout << "Ӧ�����invalid array<T, 0> subscript" << endl;
			cout << "ʵ���ǣ�";
			try {
				cout << arr2.at(1) << endl;
				//throw(std::out_of_range("invalid array<T, 0> subscript"));
			}
			catch (out_of_range &error) {
				cout << error.what() << endl;
			}

			cout << endl << endl;
		}

		// ��4����� 
		if (test_student[4]) {
			press_key(1, "��4����ԣ�\n fill(),swap()����");
			array<student, 4> arr1 = { mother[0],mother[1],mother[2],mother[3] };
			array<student, 4> arr2 = { mother[3],mother[2],mother[1],mother[0] }; 
			cout << "fill()����: " << endl;
			arr1.fill({ 1854167,"��˼��",'f',91.0,"����" });
			cout << "Ӧ������ı���˼������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;

			cout << endl;


			cout << "swap()����: " << endl;
			arr1.swap(arr2);
			cout << "arr1:" << endl;
			cout << "Ӧ�������˼����֣����������ƣ����������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr1.size(); i++) {
				cout << arr1.at(i) << " ";
			}
			cout << endl;
			cout << "arr2:" << endl;
			cout << "Ӧ����������˼������Ϣ" << endl;
			cout << "ʵ���ǣ�";
			for (int i = 0; i < (int)arr2.size(); i++) {
				cout << arr2.at(i) << " ";
			}
			cout << endl;

			cout << endl;

			cout << endl << endl;
		}

		// ��5����� 
		if (test_student[5]) {
			press_key(1, "��5����ԣ�\n ���� == !=��˳�������array�����������бȽϣ��Ƚ�ѧ�ţ����������в��ԣ�");
			array<student, 4> arr1 = { mother[0], mother[1], mother[2],mother[3] };
			array<student, 4> arr2 = { mother[0], mother[1], mother[2],mother[3] };
			array<student, 4> arr3 = { mother[0], mother[1], mother[2],mother[2] };


			cout << "arr1��arr2�Ƚ�: " << endl;
			cout << "Ӧ�����1 0" << endl;
			cout << "ʵ���ǣ�";
			cout << ((arr1 == arr2) ? 1 : 0) << " ";
			cout << ((arr1 != arr2) ? 1 : 0) << " ";
			cout << endl;

			cout << endl;

			cout << "arr1��arr3�Ƚ�: " << endl;
			cout << "Ӧ�����0 1" << endl;
			cout << "ʵ���ǣ�";
			cout << ((arr1 == arr3) ? 1 : 0) << " ";
			cout << ((arr1 != arr3) ? 1 : 0) << " ";
			cout << endl;

			cout << endl << endl;
		}

		// ��6����� 
		if (test_student[6]) {
			press_key(1, "��6����ԣ�\n �����б�д");

			cout << endl;
		}

	}
	
	return 0;
}
