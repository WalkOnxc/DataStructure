#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

template<class T>
class LinkList;

//�����ڵ���
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
	//ͷ���
	LinkNode<T>* head;

public:
	LinkList();  //���캯��
	bool ListEmpty(); //�ж������Ƿ�Ϊ��
	void ShowList();  //��ӡ����
	int GetSize();    //��ȡ������
	void GetElem(int index, T &e);	//��ȡindexλ�õĽڵ�Ԫ�أ�ͨ��e����
	void PushBack(const T &e);	//β��
	void PushFront(const T &e); //ͷ��
	void PopBack();				//βɾ
	void PopFront();			//ͷɾ
	void InsertPos(const int index, const T &e);	//��indexλ�ò���e
	void DeletePos(const int index);	//ɾ��indexλ�õĽڵ�
	LinkNode<T>* FindElem(const T &e);	//��ֵ���ң��ҵ��󷵻ظýڵ�ĵ�ַ���Ҳ�������NULL
	int FindLocateElem(const T &e);		//��ֵ���ң��ҵ��󷵻ظýڵ��λ����ţ��Ҳ�������0
	void ClearList();	//�������
	void DestroyList(); //��������

	~LinkList();
};

//LinkList();  //���캯��
template<class T>
LinkList<T>::LinkList()
{
	this->head = new LinkNode<T>;//����ͷ����ڴ�,�ٽڵ㹹�캯�����ѽ�ͷ����ָ����ָ��NULL
}

//bool ListEmpty(); //�ж������Ƿ�Ϊ��
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

//void ShowList();  //��ӡ����
template<class T>
void LinkList<T>::ShowList()
{
	if (this->ListEmpty())
	{
		cout << "����Ϊ��" << endl;
		return;
	}

	LinkNode<T>* p = this->head;

	while (p = p->next)
	{
		cout << p->data << endl;
	}
}

//	int GetSize();    //��ȡ������
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

//	void GetElem(int index, T &e);	//��ȡindexλ�õĽڵ�Ԫ�أ�ͨ��e����
template<class T>
void LinkList<T>::GetElem(int index, T &e)
{
	if (this->ListEmpty())
	{
		cout << "��ȡʧ�ܣ�����Ϊ��" << endl;
		return;
	}

	//�ж�indexλ�õ���Ч��
	if (index < 1 || index > this->GetSize())
	{
		cout << "����λ����Ϣ����" << endl;
		return;
	}

	int pos = index;
	LinkNode<T>* p = this->head;

	while (pos--)
	{
		p = p->next;
	}

	e = p->data;
	cout << "�ҵ���" << index << "��Ԫ��Ϊ��" << e << endl;
}

//	void PushBack(const T &e);	//β��
template<class T>
void LinkList<T>::PushBack(const T &e)
{
	//�ҵ���������һ���ڵ�
	LinkNode<T>* p = this->head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	//�����½ڵ㣬���½ڵ����������β��
	LinkNode<T>* pNew = new LinkNode<T>;
	pNew->data = e;
	pNew->next = NULL;

	p->next = pNew;
}


//void PushFront(const T &e); //ͷ��
template<class T>
void LinkList<T>::PushFront(const T &e)
{
	LinkNode<T>* pNew = new LinkNode<T>;
	pNew->data = e;

	pNew->next = this->head->next;
	this->head->next = pNew;

}

//void PopBack();				//βɾ
template<class T>
void LinkList<T>::PopBack()
{
	if (this->ListEmpty())
	{
		cout << "ɾ��ʧ�ܣ�����Ϊ��" << endl;
		return;
	}

	LinkNode<T>* p = this->head;

	//�ҵ������ڶ����ڵ�
	while (p->next->next)
	{
		p = p->next;
	}

	//�ͷ����һ���ڵ�
	LinkNode<T>* pLast = p->next;
	delete pLast;
	pLast = NULL;
	//delete p->next;

	//�������ڶ����ڵ��ָ������Ϊ��
	p->next = NULL;

}

//void PopFront();			//ͷɾ
template<class T>
void LinkList<T>::PopFront()
{
	if (this->ListEmpty())
	{
		cout << "ɾ��ʧ�ܣ�����Ϊ��" << endl;
		return;
	}

	LinkNode<T>* p = this->head->next;
	this->head->next = p->next;

	delete p;
	p = NULL;
}

//void InsertPos(const int index, const T &e);	//��indexλ�ò���e
template<class T>
void LinkList<T>::InsertPos(const int index, const T &e)
{
	//�ж�index����Ч��
	if (index < 1 || index > this->GetSize() + 1)
	{
		cout << "����ʧ�ܣ�����λ����������" << endl;
		return;
	}

	//�ҵ�Ҫ����ڵ�λ�õ�ǰһ���ڵ�
	int pos = index - 1;
	LinkNode<T>* p = this->head;

	while (pos--)
	{
		p = p->next;
	}

	//�����½ڵ�
	LinkNode<T>* pNew = new LinkNode<T>;
	pNew->data = e;

	//���½ڵ�����Ҫ����ڵ�λ�õ�ǰһ���ڵ�ĺ���
	pNew->next = p->next;
	p->next = pNew;

}

//void DeletePos(const int index);	//ɾ��indexλ�õĽڵ�
template<class T>
void LinkList<T>::DeletePos(const int index)
{
	//�ж�index����Ч��
	if (index < 1 || index > this->GetSize())
	{
		cout << "ɾ��ʧ�ܣ�������û�е�" << index << "���ڵ�" << endl;
		return;
	}

	//�ҵ�Ҫɾ���ڵ�λ�õ�ǰһ���ڵ�
	int pos = index - 1;
	LinkNode<T>* p = this->head;

	while (pos--)
	{
		p = p->next;
	}

	//��Ҫɾ���Ľڵ㸳��q
	LinkNode<T>* q = p->next;

	p->next = q->next;

	delete q;
	q = NULL;

}

//LinkNode<T>* FindElem(const T &e);	//��ֵ���ң��ҵ��󷵻ظýڵ�ĵ�ַ���Ҳ�������NULL
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

//int FindLocateElem(const T &e);		//��ֵ���ң��ҵ��󷵻ظýڵ��λ����ţ��Ҳ�������0
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

//	void ClearList();	//�������
template<class T>
void LinkList<T>::ClearList()
{
	//ֻ����ͷ��㣬�����Ľڵ�ȫ��ɾ��
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

//void DestroyList(); //��������
template<class T>
void LinkList<T>::DestroyList()
{
	//ɾ�����нڵ�
	LinkNode<T>* p = this->head;

	while (p)
	{
		this->head = p->next;//ͷָ��ָ����һ���ڵ�
		delete p;//�ͷ�ͷ���
		p = this->head;//ָ��ͷ���
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