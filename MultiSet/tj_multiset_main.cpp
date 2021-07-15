// 1851909 ��Ң ��ǿ
#include <iostream>
#include <set>
#include <string>
#include <functional>  // for std::less
#include<fstream>
#include "tj_student.h"
#include "tj_multiset.cpp"

using namespace std;
ofstream out("out1.txt", ios::out);
// ��ע�ͣ��Լ���tj_multiset����
// �ر�ע�ͣ�STL��multiset����
#define multiset tj_multiset

// ��ע�ͣ����жԸ��������͵Ĳ���
// �ر�ע�ͣ������жԸ��������͵Ĳ���
#define INT
#define STRING
#define STUDENT

// ���Ժ���
void test_set();

int main()
{
    out << "���Կ�ʼ...\n" << std::endl;
    test_set();
    out << "���Խ�����\n" << std::endl;
    out.close();
    return 0;
}

// ���������
void continue_key(std::string prompt, int num = 1);
// ��ӡ��׼�����ʵ������ıȽϣ����ϣ�
template <class K, class C = std::less<K>>
void print_compare(std::string std_out, multiset<K, C>& s);
// ��ӡ��׼�����ʵ������ıȽϣ�Ԫ�أ�
template <class T>
void print_compare(std::string std_out, T ele);
// ��ӡ��׼�����ʵ������ıȽϣ�student��
template <class K, class C>
void print_compare_stu(std::string std_out, multiset<K, C>& s);

struct IntCmp {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

void test_set()
{
#ifdef INT
    continue_key("int��������");

    int index_int[6] = { 1, 1, 1, 1, 1, 1 };

    if (index_int[0]) {  //��ʼ����������/����/=
        continue_key("��1�飺��ʼ����");

        continue_key("���캯��");

        // �޲ι��캯��
        multiset<int> a;
        print_compare("<None>", a);

        // ���������캯��
        for (int i = 1; i <= 5; i++)
            a.insert(i);
        multiset<int> b(a.find(3), a.end());
        print_compare("3 4 5", b);

        // ���ƹ��캯��
        multiset<int> c(a);
        print_compare("1 2 3 4 5", c);

        // �ƶ����캯��
        // �ݲ�Ҫ��

        // initializer_list ���캯��
        multiset<int> d{ 6, 7, 8, 9, 10 };
        print_compare("6 7 8 9 10", d);

        multiset<int> e{ 10, 9, 8, 7, 6 };  //����
        print_compare("6 7 8 9 10", e);

        multiset<int> f{ 1,2,1,3 };  //���ظ�Ԫ��
        print_compare("1 1 2 3", f);

        // �Զ���Ƚ����Ĺ��캯��
        multiset<int, IntCmp> g{ 10, 9, 8, 7, 6 };
        print_compare("10 9 8 7 6", g);

        continue_key("��������");
        // ��������
        for (int i = 0; i < 1e5; i++) {  //ѭ�������ɵ���
            if (1)
                multiset<int> s{ 1,2,3,4,5,6,7,8 };
        }

        continue_key("���ƹ���");
        // ���ƹ���=
        multiset<int> h;
        h = f;
        print_compare("1 1 2 3", h);

        // ���ƹ���=��initializer_list��
        multiset<int> i;
        i = { 1,2,3 };
        print_compare("1 2 3", i);
    }
    if (index_int[1]) {  //��������begin/cbegin/end/cend/rbegin/crbegin/rend/crend
        continue_key("��2�飺������");

        multiset<int> a{ 1,2,3,4,5 }, b{ 5,1,4,1,3,2 };
        multiset<int, IntCmp> c{ 5,1,4,1,3,2 };

        // begin/cbegin
        continue_key("begin/cbegin");

        print_compare("1", *a.begin());

        print_compare("1", *b.cbegin());

        print_compare("5", *c.begin());

        // end/cend
        continue_key("end/cend");

        print_compare("5", *--a.end());

        print_compare("5", *--b.end());

        print_compare("1", *--c.cend());

        // rbegin/crbegin
        continue_key("rbegin/crbegin");

        print_compare("5", *a.crbegin());

        print_compare("5", *b.rbegin());

        print_compare("1", *c.rbegin());

        // rend/crend
        continue_key("rend/crend");

        print_compare("1", *--a.rend());

        print_compare("1", *--b.crend());

        print_compare("5", *--c.crend());
    }
    if (index_int[2]) {  //������empty/size/max_size
        continue_key("��3�飺����");

        // empty
        continue_key("empty");

        multiset<int> a;
        print_compare("1", a.empty());

        a.insert(1);
        print_compare("0", a.empty());

        // size
        continue_key("size");

        multiset<int> b{ 1,1,2,3,4,5,6,7,8,9,10 };
        print_compare("11", b.size());

        a.erase(1);
        print_compare("0", a.size());

        // max_size����ͬƽ̨�в��죩
        continue_key("max_size");

        print_compare("214748364", a.max_size());
        print_compare("214748364", b.max_size());
    }
    if (index_int[3]) {  //�޸�����clear/insert/emplace/erase/swap/extract/merge
        continue_key("��4�飺�޸���");

        // clear 
        continue_key("clear");

        multiset<int> a{ 1,1,2,3,4,5 };
        a.clear();
        print_compare("<None>", a);

        a.clear();  // �ռ������clear
        print_compare("<None>", a);

        // insert
        continue_key("insert");

        a.insert(1);
        print_compare("1", a);

        a.insert(1);  //������ͬԪ��
        print_compare("1 1", a);

        multiset<int> b{ 2,3,4 };
        auto it = a.insert(5);
        a.insert(b.begin(), b.find(4));  // ����������
        print_compare("1 1 2 3 5", a);
        print_compare("5", *it);

        a.insert(b.find(3), b.end());  // ���������룬����ͬԪ��
        print_compare("1 1 2 3 3 4 5", a);

        a.insert({ 6,7,8 });  // initializer_list ����
        print_compare("1 1 2 3 3 4 5 6 7 8", a);

        a.insert({ 8,9 });  // initializer_list ���룬����ͬԪ��
        print_compare("1 1 2 3 3 4 5 6 7 8 8 9", a);

        // emplace 
        // �ݲ�Ҫ��

        // erase
        continue_key("erase");

        a.erase(a.find(5));
        print_compare("1 1 2 3 3 4 6 7 8 8 9", a);

        a.erase(a.find(1));  //�����ظ�Ԫ��
        print_compare("1 2 3 3 4 6 7 8 8 9", a);

        a.erase(a.begin(), a.find(3));  //erase ������
        print_compare("3 3 4 6 7 8 8 9", a);

        a.erase(a.find(3), a.find(3));  //�����غϣ�������βΪ�ظ�Ԫ�أ�
        print_compare("3 3 4 6 7 8 8 9", a);

        a.erase(a.find(3), a.find(4));  //�����غϣ���������ظ�Ԫ�أ�
        print_compare("4 6 7 8 8 9", a);

        a.erase(8);   //erase �ظ���ֵ
        print_compare("4 6 7 9", a);

        a.erase(10);  //erase �����ڵ�ֵ
        print_compare("4 6 7 9", a);

        // swap 
        continue_key("swap");

        a.swap(b);
        print_compare("2 3 4", a);
        print_compare("4 6 7 9", b);

        // extract 
        // �ݲ�Ҫ��c++17��

        // merge
        // �ݲ�Ҫ��c++17��
    }
    if (index_int[4]) {  //���ң�count/find/equal_range/lower_bound/upper_bound
        continue_key("��5�飺����");

        // count
        continue_key("count");

        multiset<int> a{ 1,1,2,3,4,5 };
        print_compare("2", a.count(1));
        print_compare("0", a.count(6));

        // find 
        continue_key("find");
        auto it = a.find(1);
        print_compare("1", (it != a.end() ? std::to_string(*it) : "Not Found"));

        it = a.find(0);
        print_compare("Not Found", (it != a.end() ? std::to_string(*it) : "Not Found"));

        // equal_range 
        continue_key("equal_range");
        auto res = a.equal_range(1);  // ֵ����
        print_compare("1", *res.first);
        print_compare("2", *res.second);

        a.erase(3);
        res = a.equal_range(3);  // ֵ������
        print_compare("4", *res.first);
        print_compare("4", *res.second);

        // lower_bound 
        continue_key("lower_bound");
        it = a.lower_bound(2);
        print_compare("2", *it);

        it = a.lower_bound(3);
        print_compare("4", *it);

        // upper_bound
        continue_key("upper_bound");
        it = a.upper_bound(4);
        print_compare("5", *it);

        it = a.upper_bound(3);
        print_compare("4", *it);
    }
    if (index_int[5]) {  //�Ƚ��������==/!=/>/>=/</<=
        continue_key("��6�飺�Ƚ������");

        multiset<int> a{ 1,1,2,3 }, b{ 6,7,8,9 }, c{ 1,2,3 };

        // ==
        continue_key("==");

        print_compare("false", a == b ? "true" : "false");  //�����set
        print_compare("false", a == c ? "true" : "false");  //���set

        // != 
        continue_key("!=");

        print_compare("true", a != b ? "true" : "false");  //�����set
        print_compare("true", a != c ? "true" : "false");  //���set

        // > 
        continue_key(">");

        print_compare("false", a > b ? "true" : "false");  //�����set
        print_compare("false", a > c ? "true" : "false");  //���set

        // >=
        continue_key(">=");

        print_compare("false", a >= b ? "true" : "false");  //�����set
        print_compare("false", a >= c ? "true" : "false");  //���set

        // < 
        continue_key("<");

        print_compare("true", a < b ? "true" : "false");  //�����set
        print_compare("true", a < c ? "true" : "false");  //���set

        // <=
        continue_key("<=");

        print_compare("true", a <= b ? "true" : "false");  //���set
        print_compare("true", a <= c ? "true" : "false");  //�����set
    }
#endif

#ifdef STRING
    continue_key("string��������");

    int index_str[4] = { 1, 1, 1, 1 };

    if (index_str[0]) {  //������empty/size/max_size
        continue_key("��1�飺����");

        // empty
        continue_key("empty");

        multiset<std::string> a;
        print_compare("1", a.empty());

        a.insert("bird");
        print_compare("0", a.empty());

        // size
        continue_key("size");

        multiset<std::string> b{ "bird","bird","cat","cow","dog","fox","horse","rabbit","sheep","wolf" };
        print_compare("10", b.size());

        a.erase("bird");
        print_compare("0", a.size());

        // max_size����ͬƽ̨�в��죩
        continue_key("max_size");

        print_compare("97612893", a.max_size());
        print_compare("97612893", b.max_size());
    }
    if (index_str[1]) {  //�޸�����clear/insert/emplace/erase/swap/extract/merge
        continue_key("��2�飺�޸���");

        // clear 
        continue_key("clear");

        multiset<std::string> a{ "bird","bird","cat","cow","dog","fox" };
        a.clear();
        print_compare("<None>", a);

        a.clear();  // �ռ������clear
        print_compare("<None>", a);

        // insert
        continue_key("insert");

        a.insert("bird");
        print_compare("bird", a);

        a.insert("bird");  //������ͬԪ��
        print_compare("bird bird", a);

        multiset<std::string> b{ "cat","cow","dog" };
        auto it = a.insert("fox");
        a.insert(b.begin(), b.find("dog"));  // ����������
        print_compare("bird bird cat cow fox", a);
        print_compare("fox", *it);

        a.insert(b.find("cow"), b.end());  // ���������룬����ͬԪ��
        print_compare("bird bird cat cow cow dog fox", a);

        a.insert({ "horse","rabbit","sheep" });  // initializer_list ����
        print_compare("bird bird cat cow cow dog fox horse rabbit sheep", a);

        a.insert({ "sheep","wolf" });  // initializer_list ���룬����ͬԪ��
        print_compare("bird bird cat cow cow dog fox horse rabbit sheep sheep wolf", a);

        // emplace 
        // �ݲ�Ҫ��

        // erase
        continue_key("erase");

        a.erase(a.find("fox"));
        print_compare("bird bird cat cow cow dog horse rabbit sheep sheep wolf", a);

        a.erase(a.find("bird"));  //�����ظ�Ԫ��
        print_compare("bird cat cow cow dog horse rabbit sheep sheep wolf", a);

        a.erase(a.begin(), a.find("cow"));  //erase ������
        print_compare("cow cow dog horse rabbit sheep sheep wolf", a);

        a.erase(a.find("cow"), a.find("cow"));  //�����غϣ�������βΪ�ظ�Ԫ�أ�
        print_compare("cow cow dog horse rabbit sheep sheep wolf", a);

        a.erase(a.find("cow"), a.find("dog"));  //�����غϣ���������ظ�Ԫ�أ�
        print_compare("dog horse rabbit sheep sheep wolf", a);

        a.erase("sheep");   //erase �ظ���ֵ
        print_compare("dog horse rabbit wolf", a);

        a.erase("apple");  //erase �����ڵ�ֵ
        print_compare("dog horse rabbit wolf", a);

        // swap 
        continue_key("swap");

        a.swap(b);
        print_compare("cat cow dog", a);
        print_compare("dog horse rabbit wolf", b);

        // extract 
        // �ݲ�Ҫ��c++17��

        // merge
        // �ݲ�Ҫ��c++17��
    }
    if (index_str[2]) {  //���ң�count/find/equal_range/lower_bound/upper_bound
        continue_key("��3�飺����");

        // count
        continue_key("count");

        multiset<int> a{ 1,1,2,3,4,5 };
        print_compare("2", a.count(1));
        print_compare("0", a.count(6));

        // find 
        continue_key("find");
        auto it = a.find(1);
        print_compare("1", (it != a.end() ? std::to_string(*it) : "Not Found"));

        it = a.find(0);
        print_compare("Not Found", (it != a.end() ? std::to_string(*it) : "Not Found"));

        // equal_range 
        continue_key("equal_range");
        auto res = a.equal_range(1);  // ֵ����
        print_compare("1", *res.first);
        print_compare("2", *res.second);

        a.erase(3);
        res = a.equal_range(3);  // ֵ������
        print_compare("4", *res.first);
        print_compare("4", *res.second);

        // lower_bound 
        continue_key("lower_bound");
        it = a.lower_bound(2);
        print_compare("2", *it);

        it = a.lower_bound(3);
        print_compare("4", *it);

        // upper_bound
        continue_key("upper_bound");
        it = a.upper_bound(4);
        print_compare("5", *it);

        it = a.upper_bound(3);
        print_compare("4", *it);
    }
    if (index_str[3]) {  //�Ƚ��������==/!=/>/>=/</<=
        continue_key("��4�飺�Ƚ������");

        multiset<std::string> a{ "bird","bird","cat","cow" }, b{ "horse","rabbit","sheep","wolf" }, c{ "bird","cat","cow" };

        // ==
        continue_key("==");

        print_compare("false", a == b ? "true" : "false");  //�����set
        print_compare("false", a == c ? "true" : "false");  //���set

        // != 
        continue_key("!=");

        print_compare("true", a != b ? "true" : "false");  //�����set
        print_compare("true", a != c ? "true" : "false");  //���set

        // > 
        continue_key(">");

        print_compare("false", a > b ? "true" : "false");  //�����set
        print_compare("false", a > c ? "true" : "false");  //���set

        // >=
        continue_key(">=");

        print_compare("false", a >= b ? "true" : "false");  //�����set
        print_compare("false", a >= c ? "true" : "false");  //���set

        // < 
        continue_key("<");

        print_compare("true", a < b ? "true" : "false");  //�����set
        print_compare("true", a < c ? "true" : "false");  //���set

        // <=
        continue_key("<=");

        print_compare("true", a <= b ? "true" : "false");  //���set
        print_compare("true", a <= c ? "true" : "false");  //�����set
    }
#endif

#ifdef STUDENT
    continue_key("student��������");

    int index_stu[4] = { 1, 1, 1, 1 };

    const student stu[] = {
       {1850001,"����",'m',(float)(83.5),"ɽ��"},
       {1850002,"����",'f',(float)(89.5),"ɽ��"},
       {1850003,"����",'m',(float)(91),"�ӱ�"},
       {1850004,"����",'f',(float)(95),"����"},
       {1850005,"�",'m',(float)(96),"�й�"},
       {1850006,"Jenny",'f',(float)(98.5),"US"},
       {1850007,"Danny",'m',(float)(100),"UK"}
    };

    const std::string str[] = {
       "1850001 ���� m 83.5 ɽ��",
       "1850002 ���� f 89.5 ɽ��",
       "1850003 ���� m 91 �ӱ�",
       "1850004 ���� f 95 ����",
       "1850005 � m 96 �й�",
       "1850006 Jenny f 98.5 US",
       "1850007 Danny m 100 UK"
    };

    if (index_stu[0]) {  //������empty/size/max_size
        continue_key("��1�飺����");

        // empty
        continue_key("empty");

        multiset<student> a;
        print_compare("1", a.empty());

        a.insert(stu[0]);
        print_compare("0", a.empty());

        // size
        continue_key("size");

        multiset<student> b{ stu[0],stu[0],stu[1],stu[2],stu[3],stu[4],stu[5],stu[6] };
        print_compare("8", b.size());

        a.erase(stu[0]);
        print_compare("0", a.size());

        // max_size����ͬƽ̨�в��죩
        continue_key("max_size");

        print_compare("63161283", a.max_size());
        print_compare("63161283", b.max_size());
    }
    if (index_stu[1]) {  //�޸�����clear/insert/emplace/erase/swap/extract/merge
        continue_key("��2�飺�޸���");

        // clear 
        continue_key("clear");

        multiset<student> a{ stu[0],stu[0],stu[1],stu[2],stu[3],stu[4] };
        a.clear();
        print_compare("<None>", a);

        a.clear();  // �ռ������clear
        print_compare("<None>", a);

        // insert
        continue_key("insert");

        a.insert(stu[0]);
        print_compare_stu(str[0], a);

        a.insert(stu[0]);  //������ͬԪ��
        print_compare_stu(str[0] + "\n" + str[0], a);

        multiset<student> b{ stu[1],stu[2],stu[3] };
        auto it = a.insert(stu[4]);
        a.insert(b.begin(), b.find(stu[3]));  // ����������
        print_compare_stu(str[0] + "\n" + str[0] + "\n" + str[1] + "\n" + str[2] + "\n" + str[4], a);
        print_compare(str[4], *it);

        a.insert(b.find(stu[2]), b.end());  // ���������룬����ͬԪ��
        print_compare_stu(str[0] + "\n" + str[0] + "\n" + str[1] + "\n" + str[2] + "\n" + str[2]
            + "\n" + str[3] + "\n" + str[4], a);

        a.insert({ stu[5] });  // initializer_list ����
        print_compare_stu(str[0] + "\n" + str[0] + "\n" + str[1] + "\n" + str[2] + "\n" + str[2]
            + "\n" + str[3] + "\n" + str[4] + "\n" + str[5], a);

        a.insert({ stu[5],stu[6] });  // initializer_list ���룬����ͬԪ��
        print_compare_stu(str[0] + "\n" + str[0] + "\n" + str[1] + "\n" + str[2] + "\n" + str[2]
            + "\n" + str[3] + "\n" + str[4] + "\n" + str[5] + "\n" + str[5] + "\n" + str[6], a);

        // emplace 
        // �ݲ�Ҫ��

        // erase
        continue_key("erase");

        a.erase(a.find(stu[4]));
        print_compare_stu(str[0] + "\n" + str[0] + "\n" + str[1] + "\n" + str[2] + "\n" + str[2]
            + "\n" + str[3] + "\n" + str[5] + "\n" + str[5] + "\n" + str[6], a);

        a.erase(a.find(stu[0]));  //�����ظ�Ԫ��
        print_compare_stu(str[0] + "\n" + str[1] + "\n" + str[2] + "\n" + str[2]
            + "\n" + str[3] + "\n" + str[5] + "\n" + str[5] + "\n" + str[6], a);

        a.erase(a.begin(), a.find(stu[2]));  //erase ������
        print_compare_stu(str[2] + "\n" + str[2] + "\n" + str[3] + "\n" + str[5] + "\n" + str[5] + "\n" + str[6], a);

        a.erase(a.find(stu[2]), a.find(stu[2]));  //�����غϣ�������βΪ�ظ�Ԫ�أ�
        print_compare_stu(str[2] + "\n" + str[2] + "\n" + str[3] + "\n" + str[5] + "\n" + str[5] + "\n" + str[6], a);

        a.erase(a.find(stu[2]), a.find(stu[3]));  //�����غϣ���������ظ�Ԫ�أ�
        print_compare_stu(str[3] + "\n" + str[5] + "\n" + str[5] + "\n" + str[6], a);

        a.erase(stu[5]);   //erase �ظ���ֵ
        print_compare_stu(str[3] + "\n" + str[6], a);

        a.erase({ 1859999, "Mars", 'm', (float)(100), "����" });  //erase �����ڵ�ֵ
        print_compare_stu(str[3] + "\n" + str[6], a);

        // swap 
        continue_key("swap");

        a.swap(b);
        print_compare_stu(str[1] + "\n" + str[2] + "\n" + str[3], a);
        print_compare_stu(str[3] + "\n" + str[6], b);

        // extract 
        // �ݲ�Ҫ��c++17��

        // merge
        // �ݲ�Ҫ��c++17��
    }
    if (index_stu[2]) {  //���ң�count/find/equal_range/lower_bound/upper_bound
        continue_key("��3�飺����");

        // count
        continue_key("count");

        multiset<student> a{ stu[0],stu[0],stu[1],stu[2],stu[3],stu[4] };
        print_compare("2", a.count(stu[0]));
        print_compare("0", a.count(stu[5]));

        // find 
        continue_key("find");
        auto it = a.find(stu[0]);
        if (it != a.end())
            print_compare("1", *it);
        else
            print_compare("1", "Not Found");

        it = a.find({ 1859999, "Mars", 'm', (float)(100), "����" });
        if (it != a.end())
            print_compare("Not Found", *it);
        else
            print_compare("Not Found", "Not Found");

        // equal_range 
        continue_key("equal_range");
        auto res = a.equal_range(stu[0]);  // ֵ����
        print_compare(str[0], *res.first);
        print_compare(str[1], *res.second);

        a.erase(stu[2]);
        res = a.equal_range(stu[2]);  // ֵ������
        print_compare(str[3], *res.first);
        print_compare(str[3], *res.second);

        // lower_bound 
        continue_key("lower_bound");
        it = a.lower_bound(stu[1]);
        print_compare(str[1], *it);

        it = a.lower_bound(stu[2]);
        print_compare(str[3], *it);

        // upper_bound
        continue_key("upper_bound");
        it = a.upper_bound(stu[3]);
        print_compare(str[4], *it);

        it = a.upper_bound(stu[2]);
        print_compare(str[3], *it);
    }
    if (index_stu[3]) {  //�Ƚ��������==/!=/>/>=/</<=
        continue_key("��4�飺�Ƚ������");

        multiset<student> a{ stu[0],stu[0],stu[1],stu[2] },
            b{ stu[3],stu[4],stu[5],stu[6] },
            c{ stu[0],stu[1],stu[2] };

        // ==
        continue_key("==");

        print_compare("false", a == b ? "true" : "false");  //�����set
        print_compare("false", a == c ? "true" : "false");  //���set

        // != 
        continue_key("!=");

        print_compare("true", a != b ? "true" : "false");  //�����set
        print_compare("true", a != c ? "true" : "false");  //���set

        // > 
        continue_key(">");

        print_compare("false", a > b ? "true" : "false");  //�����set
        print_compare("false", a > c ? "true" : "false");  //���set

        // >=
        continue_key(">=");

        print_compare("false", a >= b ? "true" : "false");  //�����set
        print_compare("false", a >= c ? "true" : "false");  //���set

        // < 
        continue_key("<");

        print_compare("true", a < b ? "true" : "false");  //�����set
        print_compare("true", a < c ? "true" : "false");  //���set

        // <=
        continue_key("<=");

        print_compare("true", a <= b ? "true" : "false");  //���set
        print_compare("true", a <= c ? "true" : "false");  //�����set
    }
#endif
}

// ���������
void continue_key(std::string prompt, int num)
{
    out << std::endl << "��ʼ" << prompt << "���ԣ������������...";
    if (0) {
        for (int i = 0; i < num; i++)
            char c = getchar();
    }
    out << std::endl;
}

// ��ӡ��׼�����ʵ������ıȽϣ����ϣ�
template <class K, class C>
void print_compare(std::string std_out, multiset<K, C>& s)
{
    out << "Ӧ�����" << std_out << std::endl;
    out << "ʵ���ǣ�";
    if (s.size() != 0) {
        for (auto& ele : s)
            out << ele << " ";
    }
    else {
        out << "<None>";
    }
    out << "\n" << std::endl;
}

// ��ӡ��׼�����ʵ������ıȽϣ�student��
template <class K, class C>
void print_compare_stu(std::string std_out, multiset<K, C>& s)
{
    out << "Ӧ�����\n" << std_out << std::endl;
    out << "ʵ���ǣ�\n";
    if (s.size() != 0) {
        for (auto& ele : s)
            out << ele << std::endl;
    }
    else {
        out << "<None>";
    }
    out << std::endl;
}

// ��ӡ��׼�����ʵ������ıȽϣ�Ԫ�أ�
template <class T>
void print_compare(std::string std_out, T ele)
{
    out << "Ӧ�����" << std_out << std::endl;
    out << "ʵ���ǣ�" << ele << "\n" << std::endl;
}