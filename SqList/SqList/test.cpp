#define _CRT_SECURE_NO_WARNINGS 1

#include"SqList.hpp"
#include<string>

//测试内置数据类型
void test1()
{
	SqList<int> sl;

	for (int i = 0; i < 10; i++)
	{
		sl.PushBack(i);
	}

	sl.PushFront(10);
	sl.ShowList();

	//尾删，头删
	sl.PopBack();
	sl.PopFront();
	sl.ShowList();

	sl.InsertPos(10, 10);
	sl.ShowList();

	sl.DeletePos(9);
	sl.ShowList();

	int pos = sl.Find(5);

	cout << "pos = " << pos << endl;

	sl.DeleteVal(7);
	sl.ShowList();

	int e = 0;
	sl.FindPos(8, e);
	cout << "e = " << e << endl;

	cout << "顺序表的长度为：" << sl.GetSize() << endl;

	//sl.ClearList();
	//cout << "顺序表的长度为：" << sl.GetSize() << endl;

	//sl.DestroyList();
	//cout << "顺序表的长度为：" << sl.GetSize() << endl;

	sl.Reversal();
	sl.ShowList();


	sl.sort();
	sl.ShowList();
}

class Person
{
public:
	Person()
	{}

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//重载== 
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//重载> 按年龄从小到大排序
	bool operator>(const Person &p)
	{
		if (this->m_Age > p.m_Age)
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

//重载<< 操作符
ostream& operator<<(ostream &out, const Person &p)
{
	out << "name: " << p.m_Name << " age: " << p.m_Age << endl;

	return out;
}

//测试自定义数据类型
void test2()
{
	SqList<Person> sl;

	Person p1("张三", 20);
	Person p2("李四", 32);
	Person p3("王五", 23);
	Person p4("赵六", 18);
	Person p5("孙七", 30);

	sl.PushBack(p1);
	sl.PushBack(p2);
	sl.PushBack(p3);
	sl.PushBack(p4);
	sl.PushBack(p5);

	sl.ShowList();

	Person pp("aaa", 50);
	//测试头插
	sl.PushFront(pp);
	sl.ShowList();

	//测试头删尾删
	sl.PopBack();
	sl.PopFront();
	sl.ShowList();

	//测试按位置插入
	sl.InsertPos(3, pp);
	sl.ShowList();

	//测试按位置删除
	sl.DeletePos(3);
	sl.ShowList();

	//测试按值删除
	sl.DeleteVal(p1);
	sl.ShowList();

	//测试查找函数
	int pos = sl.Find(p2);
	if (pos == -1)
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了，下标是：" << pos << endl;
	}

	Person e;
	//测试按位置查找
	sl.FindPos(3, e);
	cout << "name: " << e.m_Name << " age: " << e.m_Age << endl;

	cout << "顺序表的长度为：" << sl.GetSize() << endl;

	//反转顺序表
	/*sl.Reversal();
	sl.ShowList();*/

	//排序
	sl.sort();
	sl.ShowList();

	//清空顺序表
	sl.ClearList();
	sl.ShowList();
	cout << "顺序表的长度为：" << sl.GetSize() << endl;

}


int main()
{
	//test1();

	test2();

	system("pause");

	return 0;
}