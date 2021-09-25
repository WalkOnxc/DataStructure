#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"LinkList.hpp"
#include<string>

//测试内置数据类型
void test1()
{
	LinkList<int> L;


	L.PushBack(10);
	L.PushBack(50);
	L.PushBack(30);
	L.PushBack(40);
	L.PushBack(20);

	L.ShowList();

	int e = 0;
	L.GetElem(3, e);

	L.PushFront(100);
	L.PushFront(200);
	L.PushFront(300);
	L.ShowList();

	L.PopBack();
	L.ShowList();

	L.PopFront();
	L.ShowList();

	L.InsertPos(L.GetSize() + 1, 10);
	L.ShowList();

	L.DeletePos(1);
	L.ShowList();

	e = 200;
	LinkNode<int>* p = L.FindElem(e);
	if (p != NULL)
	{
		cout << "找到元素：" << e << endl;
	}
	else
	{
		cout << "没找到 " << endl;
	}

	int num = L.FindLocateElem(30);
	cout << "num = " << num << endl;

	L.ClearList();
	L.ShowList();

	L.DestroyList();

}

class Person
{
public:
	Person()
	{

	}

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//重载 == 
	bool operator==(const Person &p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};

//重载 << 
ostream& operator<<(ostream &out, const Person &p)
{
	out << "name: " << p.m_Name << " age: " << p.m_Age;

	return out;
}

//测试自定义数据类型
void test2()
{
	LinkList<Person> L;

	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	Person p5("孙七", 50);

	L.PushBack(p1);
	L.PushBack(p2);
	L.PushBack(p3);
	L.PushBack(p4);
	L.PushBack(p5);
	L.ShowList();
	cout << endl;

	cout << "链表的长度为：" << L.GetSize() << endl;

	Person pp("aaa", 100);
	L.PushFront(pp);
	L.ShowList();
	cout << endl;

	L.PopBack();
	L.PopFront();
	L.ShowList();
	cout << endl;

	L.InsertPos(5, p5);
	L.ShowList();
	cout << endl;

	L.DeletePos(3);
	L.ShowList();
	cout << endl;

	Person e;
	L.GetElem(4, e);

	LinkNode<Person>* p = L.FindElem(e);
	if (p != NULL)
	{
		cout << "找到元素：" << e << endl;
	}
	else
	{
		cout << "没找到 " << endl;
	}

	int pos = L.FindLocateElem(e);
	cout << "pos = " << pos << endl;


	L.ClearList();
	cout << "链表的长度为：" << L.GetSize() << endl;

}

int main()
{
	//test1();

	test2();

	system("pause");

	return 0;
}