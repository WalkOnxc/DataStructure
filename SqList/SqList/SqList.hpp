#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 100


template<class T>
class SqList
{
private:
	T* elem;         //�洢�ռ��ַ
	int size;		 //˳���ǰ��С
	int capacity;	 //˳�������

public:
	SqList();			//���캯��
	bool ListEmpty();	//�ж�˳����Ƿ�Ϊ��
	bool ListFull();	//�ж�˳����Ƿ�����
	void ShowList();	//��ӡ˳���
	void PushBack(const T &e); //β��
	void PushFront(const T &e);//ͷ��
	void PopBack();		//βɾ
	void PopFront();	//ͷɾ
	void InsertPos(int index, const T &e); //��λ�ò���Ԫ��
	void DeletePos(int index);			   //��λ��ɾ��
	void DeleteVal(const T &e);			   //��ֵɾ��
	int Find(const T &e);  //��ֵ��ѯ�����ص�һ��ֵ��λ��
	void FindPos(int index, T &e); //��λ�ò�ѯ��ͨ��e����
	int GetSize();      //��˳���ĳ���
	void ClearList();   //���˳���
	void DestroyList(); //����˳���
	void Reversal();    //��ת˳���
	void sort();        //��С��������

	~SqList();//��������

};

template<class T>
SqList<T>::SqList()
{
	this->elem = new T[MAXSIZE];
	if (this->elem == NULL)
	{
		cout << "�ڴ����ʧ��" << endl;
		return;
	}

	this->size = 0;
	this->capacity = MAXSIZE;
}

//bool ListEmpty();	//�ж�˳����Ƿ�Ϊ��
template<class T>
bool SqList<T>::ListEmpty()
{
	if (this->size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//bool ListFull();	//�ж�˳����Ƿ�����
template<class T>
bool SqList<T>::ListFull()
{
	if (this->size == this->capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void PushBack(const T &e); //β��
template<class T>
void SqList<T>::PushBack(const T &e)
{
	if (this->ListFull())
	{
		cout << "����ʧ�ܣ�˳�������" << endl;
		return;
	}

	this->elem[this->size] = e;
	this->size++;
}

//void PushFront(const T &e);//ͷ��
template<class T>
void SqList<T>::PushFront(const T &e)
{
	if (this->size == this->capacity)
	{
		cout << "����ʧ�ܣ�˳�������" << endl;
		return;
	}

	for (int i = this->size; i > 0; i--)
	{
		this->elem[i] = this->elem[i - 1];
	}

	this->elem[0] = e;

	this->size++;
}

//void ShowList();	//��ӡ˳���
template<class T>
void SqList<T>::ShowList()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->elem[i] << ' ';
	}

	cout << endl;
}

//void PopBack();		//βɾ
template<class T>
void SqList<T>::PopBack()
{
	if (this->size == 0)
	{
		cout << "ɾ��ʧ�ܣ�˳���Ϊ��" << endl;
		return;
	}

	this->size--;
}

//void PopFront();	//ͷɾ
template<class T>
void SqList<T>::PopFront()
{
	if (this->size == 0)
	{
		cout << "ɾ��ʧ�ܣ�˳���Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		this->elem[i] = this->elem[i + 1];
	}

	this->size--;
}

//void InsertPos(int index, const T &e); //��λ�ò���Ԫ��
template<class T>
void SqList<T>::InsertPos(int index, const T &e)
{
	if (this->size == this->capacity)
	{
		cout << "����ʧ�ܣ�˳�������" << endl;
		return;
	}

	//�жϲ���λ�õ���Ч�� index>=1 && index<=this->size
	if (index < 1 || index > this->size + 1)
	{
		cout << "����λ������" << endl;
		return;
	}

	for (int i = this->size; i > index - 1; i--)
	{
		this->elem[i] = this->elem[i - 1];
	}

	this->elem[index - 1] = e;

	this->size++;
}

// void DeletePos(int index);			   //��λ��ɾ��
template<class T>
void SqList<T>::DeletePos(int index)
{
	if (this->size == 0)
	{
		cout << "ɾ��ʧ�ܣ�˳���Ϊ��" << endl;
		return;
	}

	//�ж�Ҫɾ��λ��Ԫ�ص���Ч��
	if (index < 1 || index > this->size)
	{
		cout << "ɾ��λ������" << endl;
		return;
	}

	for (int i = index; i < this->size; i++)
	{
		this->elem[i - 1] = this->elem[i];
	}

	this->size--;
}

//int Find(const T &e);  //��ֵ��ѯ�����ص�һ��ֵ��λ��
template<class T>
int SqList<T>::Find(const T &e)
{
	int pos = -1;

	for (int i = 0; i < this->size; i++)
	{
		if (this->elem[i] == e)
		{
			pos = i;
			break;
		}
	}

	//û�ҵ�����-1
	//�ҵ����򷵻��±�
	return pos;
}

//void DeleteVal(const T &e);			   //��ֵɾ��
template<class T>
void SqList<T>::DeleteVal(const T &e)
{
	if (this->size == 0)
	{
		cout << "ɾ��ʧ�ܣ�˳���Ϊ��" << endl;
		return;
	}

	int pos = this->Find(e);

	if (pos == -1)
	{
		cout << "ɾ��ʧ�ܣ�" << e << "������" << endl;
		return;
	}

	for (int i = pos; i < this->size - 1; i++)
	{
		this->elem[i] = this->elem[i + 1];
	}

	this->size--;
}

//void FindPos(int index, T &e); //��λ�ò�ѯ��ͨ��e����
template<class T>
void SqList<T>::FindPos(int index, T &e)
{
	//�ж�index����Ч��
	if (index < 1 || index > this->size)
	{
		cout << "λ����Ϣ��������" << endl;
		return;
	}

	e = this->elem[index-1];
}

//int GetSize();      //��˳���ĳ���
template<class T>
int SqList<T>::GetSize()
{
	return this->size;
}

//void ClearList();   //���˳���
template<class T>
void SqList<T>::ClearList()
{
	//�߼����
	this->size = 0;
}

//void DestroyList(); //����˳���
template<class T>
void SqList<T>::DestroyList()
{
	if (this->elem != NULL)
	{
		delete[] this->elem;
		this->elem = NULL;
		this->size = 0;
		this->capacity = 0;
	}
}

//void Reversal();    //��ת˳���
template<class T>
void SqList<T>::Reversal()
{
	int left = 0; //���±�
	int right = this->size - 1;//���±�

	while (left < right)
	{
		T temp = this->elem[left];
		this->elem[left] = this->elem[right];
		this->elem[right] = temp;

		left++;
		right--;
	}
}

//void sort();        //��С��������
template<class T>
void SqList<T>::sort()
{
	int min = 0;

	for (int i = 0; i < this->size - 1; i++)
	{
		min = i;

		for (int j = 1 + i; j < this->size; j++)
		{
			if (this->elem[min] > this->elem[j])
			{
				min = j;
			}
		}

		if (min != i)
		{
			T temp = this->elem[i];
			this->elem[i] = this->elem[min];
			this->elem[min] = temp;
		}
	}
}


//~SqList();//��������
template<class T>
SqList<T>::~SqList()
{
	if (this->elem != NULL)
	{
		delete[] this->elem;
		this->elem = NULL;
		this->capacity = 0;
		this->size = 0;
	}
}