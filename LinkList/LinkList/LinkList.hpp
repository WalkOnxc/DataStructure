#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

template<class T>
class LinkList;

//创建节点类
template<class T>
class LinkNode
{
	friend class LinkList<T>;

public:
	LinkNode()
	{
		this->next = NULL;
	}

	~LinkNode()
	{

	}

private:
	T data;
	LinkNode<T>* next;

};

template<class T>
class LinkList
{
private:
	//头结点
	LinkNode<T>* head;

public:
	LinkList();  //构造函数
	bool ListEmpty(); //判断链表是否为空
	void ShowList();  //打印链表
	int GetSize();    //获取链表长度
	void GetElem(int index, T &e);	//获取index位置的节点元素，通过e返回
	void PushBack(const T &e);	//尾插
	void PushFront(const T &e); //头插
	void PopBack();				//尾删
	void PopFront();			//头删
	void InsertPos(const int index, const T &e);	//在index位置插入e
	void DeletePos(const int index);	//删除index位置的节点
	LinkNode<T>* FindElem(const T &e);	//按值查找，找到后返回该节点的地址，找不到返回NULL
	int FindLocateElem(const T &e);		//按值查找，找到后返回该节点的位置序号，找不到返回0
	void ClearList();	//清空链表
	void DestroyList(); //销毁链表

	~LinkList();
};

//LinkList();  //构造函数
template<class T>
LinkList<T>::LinkList()
{
	this->head = new LinkNode<T>;//分配头结点内存,再节点构造函数中已将头结点的指针域指向NULL
}

//bool ListEmpty(); //判断链表是否为空
template<class T>
bool LinkList<T>::ListEmpty()
{
	if (this->head->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void ShowList();  //打印链表
template<class T>
void LinkList<T>::ShowList()
{
	if (this->ListEmpty())
	{
		cout << "链表为空" << endl;
		return;
	}

	LinkNode<T>* p = this->head;

	while (p = p->next)
	{
		cout << p->data << endl;
	}
}

//	int GetSize();    //获取链表长度
template<class T>
int LinkList<T>::GetSize()
{
	int count = 0;

	LinkNode<T>* p = this->head;

	while (p = p->next)
	{
		count++;
	}

	return count;
}

//	void GetElem(int index, T &e);	//获取index位置的节点元素，通过e返回
template<class T>
void LinkList<T>::GetElem(int index, T &e)
{
	if (this->ListEmpty())
	{
		cout << "获取失败，链表为空" << endl;
		return;
	}

	//判断index位置的有效性
	if (index < 1 || index > this->GetSize())
	{
		cout << "输入位置信息有误" << endl;
		return;
	}

	int pos = index;
	LinkNode<T>* p = this->head;

	while (pos--)
	{
		p = p->next;
	}

	e = p->data;
	cout << "找到第" << index << "个元素为：" << e << endl;
}

//	void PushBack(const T &e);	//尾插
template<class T>
void LinkList<T>::PushBack(const T &e)
{
	//找到链表的最后一个节点
	LinkNode<T>* p = this->head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	//生成新节点，将新节点链在链表的尾端
	LinkNode<T>* pNew = new LinkNode<T>;
	pNew->data = e;
	pNew->next = NULL;

	p->next = pNew;
}


//void PushFront(const T &e); //头插
template<class T>
void LinkList<T>::PushFront(const T &e)
{
	LinkNode<T>* pNew = new LinkNode<T>;
	pNew->data = e;

	pNew->next = this->head->next;
	this->head->next = pNew;

}

//void PopBack();				//尾删
template<class T>
void LinkList<T>::PopBack()
{
	if (this->ListEmpty())
	{
		cout << "删除失败，链表为空" << endl;
		return;
	}

	LinkNode<T>* p = this->head;

	//找到倒数第二个节点
	while (p->next->next)
	{
		p = p->next;
	}

	//释放最后一个节点
	LinkNode<T>* pLast = p->next;
	delete pLast;
	pLast = NULL;
	//delete p->next;

	//将倒数第二个节点的指针域置为空
	p->next = NULL;

}

//void PopFront();			//头删
template<class T>
void LinkList<T>::PopFront()
{
	if (this->ListEmpty())
	{
		cout << "删除失败，链表为空" << endl;
		return;
	}

	LinkNode<T>* p = this->head->next;
	this->head->next = p->next;

	delete p;
	p = NULL;
}

//void InsertPos(const int index, const T &e);	//在index位置插入e
template<class T>
void LinkList<T>::InsertPos(const int index, const T &e)
{
	//判断index的有效性
	if (index < 1 || index > this->GetSize() + 1)
	{
		cout << "插入失败，插入位置输入有误" << endl;
		return;
	}

	//找到要插入节点位置的前一个节点
	int pos = index - 1;
	LinkNode<T>* p = this->head;

	while (pos--)
	{
		p = p->next;
	}

	//创建新节点
	LinkNode<T>* pNew = new LinkNode<T>;
	pNew->data = e;

	//将新节点链在要插入节点位置的前一个节点的后面
	pNew->next = p->next;
	p->next = pNew;

}

//void DeletePos(const int index);	//删除index位置的节点
template<class T>
void LinkList<T>::DeletePos(const int index)
{
	//判断index的有效性
	if (index < 1 || index > this->GetSize())
	{
		cout << "删除失败，链表中没有第" << index << "个节点" << endl;
		return;
	}

	//找到要删除节点位置的前一个节点
	int pos = index - 1;
	LinkNode<T>* p = this->head;

	while (pos--)
	{
		p = p->next;
	}

	//将要删除的节点赋给q
	LinkNode<T>* q = p->next;

	p->next = q->next;

	delete q;
	q = NULL;

}

//LinkNode<T>* FindElem(const T &e);	//按值查找，找到后返回该节点的地址，找不到返回NULL
template<class T>
LinkNode<T>* LinkList<T>::FindElem(const T &e)
{
	LinkNode<T>* findNode = NULL;

	LinkNode<T>* p = this->head;

	while (p = p->next)
	{
		if (p->data == e)
		{
			findNode = p;
			break;
		}
	}

	return findNode;
}

//int FindLocateElem(const T &e);		//按值查找，找到后返回该节点的位置序号，找不到返回0
template<class T>
int LinkList<T>::FindLocateElem(const T &e)
{
	LinkNode<T>* p = this->head;
	int count = 0;

	while (p = p->next)
	{
		count++;

		if (p->data == e)
		{
			break;
		}
	}

	return count;
}

//	void ClearList();	//清空链表
template<class T>
void LinkList<T>::ClearList()
{
	//只保留头结点，其他的节点全部删除
	LinkNode<T> *p, *q;
	p = this->head->next;

	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}

	this->head->next = NULL;

}

//void DestroyList(); //销毁链表
template<class T>
void LinkList<T>::DestroyList()
{
	//删除所有节点
	LinkNode<T>* p = this->head;

	while (p)
	{
		this->head = p->next;//头指针指向下一个节点
		delete p;//释放头结点
		p = this->head;//指向头结点
	}

}

template<class T>
LinkList<T>::~LinkList()
{
	LinkNode<T>* p = this->head;

	while (p)
	{
		this->head = p->next;
		delete p;
		p = this->head;
	}
}