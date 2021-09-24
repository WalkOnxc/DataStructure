#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 100


template<class T>
class SqList
{
private:
	T* elem;         //存储空间基址
	int size;		 //顺序表当前大小
	int capacity;	 //顺序表容量

public:
	SqList();			//构造函数
	bool ListEmpty();	//判断顺序表是否为空
	bool ListFull();	//判断顺序表是否已满
	void ShowList();	//打印顺序表
	void PushBack(const T &e); //尾插
	void PushFront(const T &e);//头插
	void PopBack();		//尾删
	void PopFront();	//头删
	void InsertPos(int index, const T &e); //按位置插入元素
	void DeletePos(int index);			   //按位置删除
	void DeleteVal(const T &e);			   //按值删除
	int Find(const T &e);  //按值查询，返回第一个值得位置
	void FindPos(int index, T &e); //按位置查询，通过e返回
	int GetSize();      //求顺序表的长度
	void ClearList();   //清空顺序表
	void DestroyList(); //销毁顺序表
	void Reversal();    //反转顺序表
	void sort();        //从小到大排序

	~SqList();//析构函数

};

template<class T>
SqList<T>::SqList()
{
	this->elem = new T[MAXSIZE];
	if (this->elem == NULL)
	{
		cout << "内存分配失败" << endl;
		return;
	}

	this->size = 0;
	this->capacity = MAXSIZE;
}

//bool ListEmpty();	//判断顺序表是否为空
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

//bool ListFull();	//判断顺序表是否已满
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

//void PushBack(const T &e); //尾插
template<class T>
void SqList<T>::PushBack(const T &e)
{
	if (this->ListFull())
	{
		cout << "插入失败，顺序表已满" << endl;
		return;
	}

	this->elem[this->size] = e;
	this->size++;
}

//void PushFront(const T &e);//头插
template<class T>
void SqList<T>::PushFront(const T &e)
{
	if (this->size == this->capacity)
	{
		cout << "插入失败，顺序表已满" << endl;
		return;
	}

	for (int i = this->size; i > 0; i--)
	{
		this->elem[i] = this->elem[i - 1];
	}

	this->elem[0] = e;

	this->size++;
}

//void ShowList();	//打印顺序表
template<class T>
void SqList<T>::ShowList()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->elem[i] << ' ';
	}

	cout << endl;
}

//void PopBack();		//尾删
template<class T>
void SqList<T>::PopBack()
{
	if (this->size == 0)
	{
		cout << "删除失败，顺序表为空" << endl;
		return;
	}

	this->size--;
}

//void PopFront();	//头删
template<class T>
void SqList<T>::PopFront()
{
	if (this->size == 0)
	{
		cout << "删除失败，顺序表为空" << endl;
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		this->elem[i] = this->elem[i + 1];
	}

	this->size--;
}

//void InsertPos(int index, const T &e); //按位置插入元素
template<class T>
void SqList<T>::InsertPos(int index, const T &e)
{
	if (this->size == this->capacity)
	{
		cout << "插入失败，顺序表已满" << endl;
		return;
	}

	//判断插入位置的有效性 index>=1 && index<=this->size
	if (index < 1 || index > this->size + 1)
	{
		cout << "插入位置有误" << endl;
		return;
	}

	for (int i = this->size; i > index - 1; i--)
	{
		this->elem[i] = this->elem[i - 1];
	}

	this->elem[index - 1] = e;

	this->size++;
}

// void DeletePos(int index);			   //按位置删除
template<class T>
void SqList<T>::DeletePos(int index)
{
	if (this->size == 0)
	{
		cout << "删除失败，顺序表为空" << endl;
		return;
	}

	//判断要删除位置元素的有效性
	if (index < 1 || index > this->size)
	{
		cout << "删除位置有误" << endl;
		return;
	}

	for (int i = index; i < this->size; i++)
	{
		this->elem[i - 1] = this->elem[i];
	}

	this->size--;
}

//int Find(const T &e);  //按值查询，返回第一个值得位置
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

	//没找到返回-1
	//找到了则返回下标
	return pos;
}

//void DeleteVal(const T &e);			   //按值删除
template<class T>
void SqList<T>::DeleteVal(const T &e)
{
	if (this->size == 0)
	{
		cout << "删除失败，顺序表为空" << endl;
		return;
	}

	int pos = this->Find(e);

	if (pos == -1)
	{
		cout << "删除失败，" << e << "不存在" << endl;
		return;
	}

	for (int i = pos; i < this->size - 1; i++)
	{
		this->elem[i] = this->elem[i + 1];
	}

	this->size--;
}

//void FindPos(int index, T &e); //按位置查询，通过e返回
template<class T>
void SqList<T>::FindPos(int index, T &e)
{
	//判断index的有效性
	if (index < 1 || index > this->size)
	{
		cout << "位置信息输入有误" << endl;
		return;
	}

	e = this->elem[index-1];
}

//int GetSize();      //求顺序表的长度
template<class T>
int SqList<T>::GetSize()
{
	return this->size;
}

//void ClearList();   //清空顺序表
template<class T>
void SqList<T>::ClearList()
{
	//逻辑清空
	this->size = 0;
}

//void DestroyList(); //销毁顺序表
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

//void Reversal();    //反转顺序表
template<class T>
void SqList<T>::Reversal()
{
	int left = 0; //左下标
	int right = this->size - 1;//右下标

	while (left < right)
	{
		T temp = this->elem[left];
		this->elem[left] = this->elem[right];
		this->elem[right] = temp;

		left++;
		right--;
	}
}

//void sort();        //从小到大排序
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


//~SqList();//析构函数
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