#define _CRT_SECURE_NO_WARNINGS 1

#include"SqList.hpp"
#include<string>

//����������������
void test1()
{
	SqList<int> sl;

	for (int i = 0; i < 10; i++)
	{
		sl.PushBack(i);
	}

	sl.PushFront(10);
	sl.ShowList();

	//βɾ��ͷɾ
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

	cout << "˳���ĳ���Ϊ��" << sl.GetSize() << endl;

	//sl.ClearList();
	//cout << "˳���ĳ���Ϊ��" << sl.GetSize() << endl;

	//sl.DestroyList();
	//cout << "˳���ĳ���Ϊ��" << sl.GetSize() << endl;

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

	//����== 
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
	
	//����> �������С��������
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

//����<< ������
ostream& operator<<(ostream &out, const Person &p)
{
	out << "name: " << p.m_Name << " age: " << p.m_Age << endl;

	return out;
}

//�����Զ�����������
void test2()
{
	SqList<Person> sl;

	Person p1("����", 20);
	Person p2("����", 32);
	Person p3("����", 23);
	Person p4("����", 18);
	Person p5("����", 30);

	sl.PushBack(p1);
	sl.PushBack(p2);
	sl.PushBack(p3);
	sl.PushBack(p4);
	sl.PushBack(p5);

	sl.ShowList();

	Person pp("aaa", 50);
	//����ͷ��
	sl.PushFront(pp);
	sl.ShowList();

	//����ͷɾβɾ
	sl.PopBack();
	sl.PopFront();
	sl.ShowList();

	//���԰�λ�ò���
	sl.InsertPos(3, pp);
	sl.ShowList();

	//���԰�λ��ɾ��
	sl.DeletePos(3);
	sl.ShowList();

	//���԰�ֵɾ��
	sl.DeleteVal(p1);
	sl.ShowList();

	//���Բ��Һ���
	int pos = sl.Find(p2);
	if (pos == -1)
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ��±��ǣ�" << pos << endl;
	}

	Person e;
	//���԰�λ�ò���
	sl.FindPos(3, e);
	cout << "name: " << e.m_Name << " age: " << e.m_Age << endl;

	cout << "˳���ĳ���Ϊ��" << sl.GetSize() << endl;

	//��ת˳���
	/*sl.Reversal();
	sl.ShowList();*/

	//����
	sl.sort();
	sl.ShowList();

	//���˳���
	sl.ClearList();
	sl.ShowList();
	cout << "˳���ĳ���Ϊ��" << sl.GetSize() << endl;

}


int main()
{
	//test1();

	test2();

	system("pause");

	return 0;
}