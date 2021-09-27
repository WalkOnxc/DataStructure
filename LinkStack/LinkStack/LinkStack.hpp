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
	T data;//������
	LinkStackNode<T>* next;//ָ����

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
	LinkStackNode<T>* head;//ͷָ�룬��ջ��ͷָ�����ջ��

public:
	LinkStack();

	bool LinkStackEmpty();//�ж���ջ�Ƿ�Ϊ��
	int LinkStackSize();  //��ȡ��ջ�Ĵ�С
	void ShowLinkStack(); //��ӡ��ջ
	void Push(const T &e);//��ջ
	void Pop(T &e);		  //��ջ

	~LinkStack();
};

template<class T>
LinkStack<T>::LinkStack()
{
	this->head = NULL;//��ջ����Ҫͷ���
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
		cout << "��ջΪ�գ��޷���ӡ" << endl;
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
	//�����½ڵ�
	LinkStackNode<T>* pNew = new LinkStackNode<T>;
	if (pNew == NULL)
	{
		cout << "�ڴ����ʧ��" << endl;
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
		cout << "��ջʧ�ܣ���ջΪ��" << endl;
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