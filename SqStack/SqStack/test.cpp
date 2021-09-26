#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"SqStack.hpp"


void test()
{
	SqStack<int> s;

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);

	s.ShowStack();

	int e;
	s.Pop(e);
	cout << "出栈的元素是：" << e << endl;
	s.ShowStack();

	s.ClearStack();
	s.ShowStack();

	s.DestroyStack();
	s.ShowStack();

}

int main()
{
	test();

	system("pause");

	return 0;
}