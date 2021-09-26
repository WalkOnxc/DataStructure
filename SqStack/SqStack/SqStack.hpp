#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 100

template<class T>
class SqStack
{
private:
	T* top;	//栈顶指针
	T* base;//栈底指针
	int stackSize;//栈的容量

public:
	SqStack();

	bool StackEmpty();			//判断栈是否为空
	bool StackFull();			//判断栈是否已满
	void Push(const T &e);		//压栈
	void Pop(T &e);				//出栈
	void ShowStack();			//打印栈
	void ClearStack();			//清空栈
	void DestroyStack();		//销毁栈

	~SqStack();
};

template<class T>
SqStack<T>::SqStack()
{
	this->base = new T[MAXSIZE];

	if (this->base == NULL)
	{
		cout << "内存分配失败" << endl;
		return;
	}

	this->top = this->base;
	this->stackSize = MAXSIZE;
}

//bool StackEmpty();			//判断栈是否为空
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

//bool StackFull();			//判断栈是否已满
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

//void Push(const T &e);		//压栈
template<class T>
void SqStack<T>::Push(const T &e)
{
	if (this->StackFull())
	{
		cout << "入栈失败，栈已满" << endl;
		return;
	}

	*(this->top) = e;

	this->top++;
}

//void Pop(T &e);			//出栈
template<class T>
void SqStack<T>::Pop(T &e)
{
	if (this->StackEmpty())
	{
		cout << "出栈失败，栈为空" << endl;
		return;
	}

	this->top--;

	e = *this->top;
}

//void ShowStack();			//打印栈
template<class T>
void SqStack<T>::ShowStack()
{
	if (this->StackEmpty())
	{
		cout << "打印失败，栈为空" << endl;
		return;
	}

	T* p = this->base;

	while (p != this->top)
	{
		cout << *p++ << endl;
	}
}

//void ClearStack();			//清空栈
template<class T>
void SqStack<T>::ClearStack()
{
	if (this->base == NULL)
	{
		cout << "栈不存在，无法清空" << endl;
		return;
	}

	this->top = this->base;
}

//void DestroyStack();		//销毁栈
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

	cout << "栈不存在，无法销毁" << endl;

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