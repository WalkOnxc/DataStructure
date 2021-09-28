#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include"SqQueue.hpp"


void test()
{
	SqQueue<int> sQ;

	int e = 0;
	sQ.DeQueue(e);

	sQ.EnQueue(1);
	sQ.EnQueue(2);
	sQ.EnQueue(3);
	sQ.EnQueue(4);
	sQ.EnQueue(5);

	sQ.ShowQueue();
	cout << "队列的长度为：" << sQ.QueueLenght() << endl;

	sQ.DeQueue(e);
	sQ.DeQueue(e);
	sQ.DeQueue(e);
	sQ.DeQueue(e);
	sQ.ShowQueue();
	cout << "队列的长度为：" << sQ.QueueLenght() << endl;

	sQ.EnQueue(10);
	sQ.EnQueue(20);
	sQ.EnQueue(30);
	sQ.ShowQueue();
	cout << "队列的长度为：" << sQ.QueueLenght() << endl;

	sQ.DeQueue(e);
	sQ.ShowQueue();
	cout << "队列的长度为：" << sQ.QueueLenght() << endl;
}

int main()
{
	test();

	system("pause");

	return 0;
}