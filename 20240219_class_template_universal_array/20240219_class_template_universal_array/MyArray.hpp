#define _CRT_SECURE_NO_WARNINGS 1
#pragma once//防止头文件重复包含
#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray//类模板
{
private:
	T* pAddress;//数组本身
	int m_Capacity;//数组的容量
	int m_Size;//数组的总大小

public:

	MyArray(int capacity)//有参构造函数
	{
		cout << "调用MyArray类的有参构造函数\n";
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	MyArray(const MyArray& arr)//拷贝构造函数：防止浅拷贝导致的堆区内存重复释放的问题
	{
		cout << "调用MyArray类的拷贝构造函数\n";
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//不能这么做。这是编译器会帮你做的浅拷贝操作
		
		/*以下为深拷贝操作：*/
		this->pAddress = new T[arr.m_Capacity];
		//将arr当中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 运算符重载，防止浅拷贝导致的堆区内存重复释放的问题
		/*仅仅有拷贝构造函数，还不足以防止浅拷贝导致的堆区内存重复释放的问题。
		当通过赋值操作符 = 将一个对象赋值给另一个对象时，默认的赋值操作符实现也会进行浅拷贝。
		为了避免在赋值时也出现内存重复释放的问题，需要重载赋值操作符“=”，让它的意义符合深拷贝的要求*/
	MyArray& operator=(const MyArray& arr)//返回值为MyArray的引用：链式编程思想，实现“=”的“连等”意义
	{
		cout << "调用MyArray类的operator=运算符重载函数\n";
		//先判断原来的堆区是否还有数据，如果还有数据，先进行释放（以下里面的代码都是为了确保完全释放干净）
		if (this->pAddress != nullptr)
		{
			delete[]this->pAddress;
			this->pAddress = nullptr;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//开始进行深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;//链式编程思想，把对象自身返回
	}

	//尾插法添加数据
	void Push_Back(const T& val)
	{
		//判断当前数组的大小是否等于数组可用的容量（即判断数组的存储是否已满）
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组的末尾插入新的数据
		this->m_Size++;
	}

	//尾删法删除数据
	void Pop_Back()
	{
		//判断数组是否已经为空（已经为空就没有可以删除的东西了）
		if (this->m_Capacity == 0)
		{
			return;
		}
		this->m_Size--;//不一定要让最后一个数据在内存中真的清空，让用户访问不到最后一个数据即为逻辑上的尾删
	}

	//允许用户通过下标的方式访问数组中的元素：需要重载运算符[]，以实现“下标”的意思
	T& operator[](int index)//如果要这个含有下标的数据可以作为左值（例如，可以被赋值），需要使用链式编程思想（返回一个自身）
	{
		return this->pAddress[index];
	}

	//返回数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组的大小
	int getSize()
	{
		return this->m_Size;
	}

	~MyArray()//有在堆区开辟的内存，需要在析构函数中手动释放
	{
		cout << "调用MyArray类的析构函数\n";
		if (this->pAddress != nullptr)
		{
			delete[]this->pAddress;
			this->pAddress = nullptr;//防止出现野指针
			/*发现一个输入小技巧：写完this之后，即使打一个.也可以在待输入列表里面找到pAddress，Tab之后编译器会自动把.改为->*/
		}
	}
};