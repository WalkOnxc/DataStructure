#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 5

template<class T>
class SqQueue
{
private:
	T* base;//��̬����Ĵ洢�ռ�
	//��Ϊ��˳��ӣ����Կ��ô洢�±����ﵽָ��ָ���Ч��
	int front;//ͷָ��
	int rear;//βָ��

public:
	SqQueue();
	int QueueLenght();			//��ȡ���еĳ���
	void ShowQueue();			//��ӡ����
	void EnQueue(const T &e);	//��ӣ���e�����β����β����
	void DeQueue(T &e);			//���ӣ��ѳ��ӵ�Ԫ��ͨ��e���أ���ͷɾ��
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
		//�Ӷ�β��ʼ��ӡ
		rear = (rear - 1 + MAXSIZE) % MAXSIZE;

		cout << this->base[rear] << endl;
	}
}

template<class T>
void SqQueue<T>::EnQueue(const T &e)
{
	if ((this->rear + 1) % MAXSIZE == this->front)
	{
		cout << "���ʧ�ܣ���������" << endl;
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
		cout << "����ʧ�ܣ�����Ϊ��" << endl;
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