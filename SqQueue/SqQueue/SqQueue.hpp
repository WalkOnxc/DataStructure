#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 5

template<class T>
class SqQueue
{
private:
	T* base;//动态分配的存储空间
	//因为是顺序队，所以可用存储下标来达到指针指向的效果
	int front;//头指针
	int rear;//尾指针

public:
	SqQueue();
	int QueueLenght();			//获取队列的长度
	void ShowQueue();			//打印队列
	void EnQueue(const T &e);	//入队，将e插入队尾，队尾插入
	void DeQueue(T &e);			//出队，把出队的元素通过e返回，队头删除
	~SqQueue();
};

template<class T>
SqQueue<T>::SqQueue()
{
	this->base = new T[MAXSIZE];

	this->front = this->rear = 0;
}

template<class T>
int SqQueue<T>::QueueLenght()
{
	return (this->rear - this->front + MAXSIZE) % MAXSIZE;
}

template<class T>
void SqQueue<T>::ShowQueue()
{
	int rear = this->rear;
	int front = this->front;

	while (rear != front)
	{
		//从队尾开始打印
		rear = (rear - 1 + MAXSIZE) % MAXSIZE;

		cout << this->base[rear] << endl;
	}
}

template<class T>
void SqQueue<T>::EnQueue(const T &e)
{
	if ((this->rear + 1) % MAXSIZE == this->front)
	{
		cout << "入队失败，队列已满" << endl;
		return;
	}

	this->base[this->rear] = e;
	this->rear = (this->rear + 1) % MAXSIZE;
}

template<class T>
void SqQueue<T>::DeQueue(T &e)
{
	if (this->rear == this->front)
	{
		cout << "出队失败，队列为空" << endl;
		return;
	}

	e = this->base[this->front];

	this->front = (this->front + 1) % MAXSIZE;
}

template<class T>
SqQueue<T>::~SqQueue()
{
	if (this->base != NULL)
	{
		delete[] this->base;
		this->rear = 0;
		this->front = 0;
	}
}