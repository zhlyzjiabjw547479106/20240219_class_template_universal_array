#define _CRT_SECURE_NO_WARNINGS 1
#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArray//��ģ��
{
private:
	T* pAddress;//���鱾��
	int m_Capacity;//���������
	int m_Size;//������ܴ�С

public:

	MyArray(int capacity)//�вι��캯��
	{
		cout << "����MyArray����вι��캯��\n";
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	MyArray(const MyArray& arr)//�������캯������ֹǳ�������µĶ����ڴ��ظ��ͷŵ�����
	{
		cout << "����MyArray��Ŀ������캯��\n";
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//������ô�������Ǳ��������������ǳ��������
		
		/*����Ϊ���������*/
		this->pAddress = new T[arr.m_Capacity];
		//��arr���е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= ��������أ���ֹǳ�������µĶ����ڴ��ظ��ͷŵ�����
		/*�����п������캯�����������Է�ֹǳ�������µĶ����ڴ��ظ��ͷŵ����⡣
		��ͨ����ֵ������ = ��һ������ֵ����һ������ʱ��Ĭ�ϵĸ�ֵ������ʵ��Ҳ�����ǳ������
		Ϊ�˱����ڸ�ֵʱҲ�����ڴ��ظ��ͷŵ����⣬��Ҫ���ظ�ֵ��������=����������������������Ҫ��*/
	MyArray& operator=(const MyArray& arr)//����ֵΪMyArray�����ã���ʽ���˼�룬ʵ�֡�=���ġ����ȡ�����
	{
		cout << "����MyArray���operator=��������غ���\n";
		//���ж�ԭ���Ķ����Ƿ������ݣ�����������ݣ��Ƚ����ͷţ���������Ĵ��붼��Ϊ��ȷ����ȫ�ͷŸɾ���
		if (this->pAddress != nullptr)
		{
			delete[]this->pAddress;
			this->pAddress = nullptr;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//��ʼ�������
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;//��ʽ���˼�룬�Ѷ���������
	}

	//β�巨�������
	void Push_Back(const T& val)
	{
		//�жϵ�ǰ����Ĵ�С�Ƿ����������õ����������ж�����Ĵ洢�Ƿ�������
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//�������ĩβ�����µ�����
		this->m_Size++;
	}

	//βɾ��ɾ������
	void Pop_Back()
	{
		//�ж������Ƿ��Ѿ�Ϊ�գ��Ѿ�Ϊ�վ�û�п���ɾ���Ķ����ˣ�
		if (this->m_Capacity == 0)
		{
			return;
		}
		this->m_Size--;//��һ��Ҫ�����һ���������ڴ��������գ����û����ʲ������һ�����ݼ�Ϊ�߼��ϵ�βɾ
	}

	//�����û�ͨ���±�ķ�ʽ���������е�Ԫ�أ���Ҫ���������[]����ʵ�֡��±ꡱ����˼
	T& operator[](int index)//���Ҫ��������±�����ݿ�����Ϊ��ֵ�����磬���Ա���ֵ������Ҫʹ����ʽ���˼�루����һ������
	{
		return this->pAddress[index];
	}

	//�������������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��������Ĵ�С
	int getSize()
	{
		return this->m_Size;
	}

	~MyArray()//���ڶ������ٵ��ڴ棬��Ҫ�������������ֶ��ͷ�
	{
		cout << "����MyArray�����������\n";
		if (this->pAddress != nullptr)
		{
			delete[]this->pAddress;
			this->pAddress = nullptr;//��ֹ����Ұָ��
			/*����һ������С���ɣ�д��this֮�󣬼�ʹ��һ��.Ҳ�����ڴ������б������ҵ�pAddress��Tab֮����������Զ���.��Ϊ->*/
		}
	}
};