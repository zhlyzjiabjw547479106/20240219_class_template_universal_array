#include "MyArray.hpp"

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";//�ж�[]�����������
	}
}

class Person
{
public:
	string m_Name;
	int m_Age;
	//Person(){}//Ĭ�Ϲ��캯������ʵ�֣�����д��������error C2512: ��Person��: û�к��ʵ�Ĭ�Ϲ��캯�����á���
	/*�������ԭ����Person���ж������������캯������ô����������Ϊ�㴴��Ĭ�Ϲ��캯����
	�����ڱ���������Person��Ĭ�Ϲ��캯��ʱ���ͻᡰû�к��ʵ�Ĭ�Ϲ��캯�����á���*/
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "Name: " << arr[i].m_Name << "\t" << "Age: " << arr[i].m_Age << endl;
	}
}

void testInt1()
{
	MyArray <int>arr1(5);//���вι��캯������������
	//MyArray <int>arr2(arr1);//�٢��вι��캯�����������캯����������������������
	MyArray <int>arr3(10);arr3 = arr1;//�٢ۣ���������¸�ֵ������MyArray����вι��캯�����вι��캯����operator = ��������غ�����������������������
}

void testInt2()
{
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(10 - 3 * i);//����β�巨�����鸳ֵ
	}
	cout << "arr1: { ";
	printIntArray(arr1);
	cout << "}" << endl;

	cout << "arr1 Capacity: " << arr1.getCapacity() << endl;
	cout << "arr1 Size: " << arr1.getSize() << endl << endl;

	MyArray <int>arr2(arr1);
	cout << "arr2: { ";
	printIntArray(arr2);
	cout << "}" << endl << endl;

	cout << "��arr2����βɾ����\n";
	arr2.Pop_Back();
	cout << "arr2 Capacity: " << arr2.getCapacity() << endl;
	cout << "arr2 Size: " << arr2.getSize() << endl << endl;
}

void testPerson()
{
	MyArray<Person>arr(10);
	Person p1("��Сң", 18);
	Person p2("ӣ��С��", 18);
	Person p3("��С��", 18);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	printPersonArray(arr);
	cout << endl;

	cout << "arr Capacity: " << arr.getCapacity() << endl;
	cout << "arr Size: " << arr.getSize() << endl << endl;
}

int main()
{
	cout << "��testInt1��" << endl;
	testInt1();

	cout << "--------------------------------" << endl;
	cout << "��testInt2��" << endl;
	testInt2();

	cout << "--------------------------------" << endl;
	cout << "��testPerson��" << endl;
	testPerson();

	system("pause");
	return 0;
}