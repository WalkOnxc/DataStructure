#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;


template<class T>
class LinkStack;

template<class T>
class LinkStackNode
{
	friend class LinkStack<T>;

private:
	T data;//数据域
	LinkStackNode<T>* next;//指针域

public:
	LinkStackNode()
	{
		this->next = NULL;
	}

	~LinkStackNode()
	{

	}
};

template<class T>
class LinkStack
{
private:
	LinkStackNode<T>* head;//头指针，链栈的头指针就是栈顶

public:
	LinkStack();

	bool LinkStackEmpty();//判断链栈是否为空
	int LinkStackSize();  //获取链栈的大小
	void ShowLinkStack(); //打印链栈
	void Push(const T &e);//入栈
	void Pop(T &e);		  //出栈

	~LinkStack();
};

template<class T>
LinkStack<T>::LinkStack()
{
	this->head = NULL;//链栈不需要头结点
}

template<class T>
bool LinkStack<T>::LinkStackEmpty()
{
	if (this->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int LinkStack<T>::LinkStackSize()
{
	int count = 0;

	LinkStackNode<T>* p = this->head;
	while (p)
	{
		count++;
		p = p->next;
	}

	return count;
}

template<class T>
void LinkStack<T>::ShowLinkStack()
{
	if (this->LinkStackEmpty())
	{
		cout << "链栈为空，无法打印" << endl;
		return;
	}

	LinkStackNode<T>* p = this->head;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

template<class T>
void LinkStack<T>::Push(const T &e)
{
	//创建新节点
	LinkStackNode<T>* pNew = new LinkStackNode<T>;
	if (pNew == NULL)
	{
		cout << "内存分配失败" << endl;
		return;
	}

	pNew->data = e;
	pNew->next = this->head;

	this->head = pNew;
}

template<class T>
void LinkStack<T>::Pop(T &e)
{
	if (this->LinkStackEmpty())
	{
		cout << "出栈失败，连栈为空" << endl;
		return;
	}

	e = this->head->data;

	this->head = this->head->next;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	if (this->head != NULL)
	{
		while (this->head)
		{
			LinkStackNode<T>* p = this->head;
			this->head = p->next;
			delete p;
			p = this->head;
		}
	}
}