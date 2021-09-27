#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"LinkStack.hpp"

void test()
{
	LinkStack<int> ls;

	ls.Push(1);
	ls.Push(2);
	ls.Push(3);
	ls.Push(4);
	ls.Push(5);
	ls.ShowLinkStack();

	int e;
	ls.Pop(e);
	cout << "出栈的元素是：" << e << endl;
	ls.ShowLinkStack();
	
	cout << "栈的大小为：" << ls.LinkStackSize() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}