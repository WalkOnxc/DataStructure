#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 100

template<class T>
class SqStack
{
private:
	T* top;	//ջ��ָ��
	T* base;//ջ��ָ��
	int stackSize;//ջ������

public:
	SqStack();

	bool StackEmpty();			//�ж�ջ�Ƿ�Ϊ��
	bool StackFull();			//�ж�ջ�Ƿ�����
	void Push(const T &e);		//ѹջ
	void Pop(T &e);				//��ջ
	void ShowStack();			//��ӡջ
	void ClearStack();			//���ջ
	void DestroyStack();		//����ջ

	~SqStack();
};

template<class T>
SqStack<T>::SqStack()
{
	this->base = new T[MAXSIZE];

	if (this->base == NULL)
	{
		cout << "�ڴ����ʧ��" << endl;
		return;
	}

	this->top = this->base;
	this->stackSize = MAXSIZE;
}

//bool StackEmpty();			//�ж�ջ�Ƿ�Ϊ��
template<class T>
bool SqStack<T>::StackEmpty()
{
	if (this->base == this->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//bool StackFull();			//�ж�ջ�Ƿ�����
template<class T>
bool SqStack<T>::StackFull()
{
	if (this->top - this->base == this->stackSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void Push(const T &e);		//ѹջ
template<class T>
void SqStack<T>::Push(const T &e)
{
	if (this->StackFull())
	{
		cout << "��ջʧ�ܣ�ջ����" << endl;
		return;
	}

	*(this->top) = e;

	this->top++;
}

//void Pop(T &e);			//��ջ
template<class T>
void SqStack<T>::Pop(T &e)
{
	if (this->StackEmpty())
	{
		cout << "��ջʧ�ܣ�ջΪ��" << endl;
		return;
	}

	this->top--;

	e = *this->top;
}

//void ShowStack();			//��ӡջ
template<class T>
void SqStack<T>::ShowStack()
{
	if (this->StackEmpty())
	{
		cout << "��ӡʧ�ܣ�ջΪ��" << endl;
		return;
	}

	T* p = this->base;

	while (p != this->top)
	{
		cout << *p++ << endl;
	}
}

//void ClearStack();			//���ջ
template<class T>
void SqStack<T>::ClearStack()
{
	if (this->base == NULL)
	{
		cout << "ջ�����ڣ��޷����" << endl;
		return;
	}

	this->top = this->base;
}

//void DestroyStack();		//����ջ
template<class T>
void SqStack<T>::DestroyStack()
{
	if (this->base != NULL)
	{
		delete[] this->base;
		this->base = NULL;
		this->top = NULL;
		this->stackSize = 0;
		return;
	}

	cout << "ջ�����ڣ��޷�����" << endl;

}


template<class T>
SqStack<T>::~SqStack()
{
	if (this->base != NULL)
	{
		delete[] this->base;
		this->base = NULL;
		this->top = NULL;
		this->stackSize = 0;
	}
}