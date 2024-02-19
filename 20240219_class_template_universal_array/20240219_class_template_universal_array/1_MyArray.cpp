#include "MyArray.hpp"

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";//有对[]的运算符重载
	}
}

class Person
{
public:
	string m_Name;
	int m_Age;
	//Person(){}//默认构造函数，空实现（必须写出，否则“error C2512: “Person”: 没有合适的默认构造函数可用”）
	/*问题出现原因：在Person类中定义了其他构造函数，那么编译器不会为你创建默认构造函数；
	所以在编译器调用Person的默认构造函数时，就会“没有合适的默认构造函数可用”。*/
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
	MyArray <int>arr1(5);//①有参构造函数、析构函数
	//MyArray <int>arr2(arr1);//①②有参构造函数、拷贝构造函数、析构函数、析构函数
	MyArray <int>arr3(10);arr3 = arr1;//①③（深拷贝：重新赋值）调用MyArray类的有参构造函数、有参构造函数、operator = 运算符重载函数、析构函数、析构函数
}

void testInt2()
{
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(10 - 3 * i);//利用尾插法对数组赋值
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

	cout << "对arr2进行尾删……\n";
	arr2.Pop_Back();
	cout << "arr2 Capacity: " << arr2.getCapacity() << endl;
	cout << "arr2 Size: " << arr2.getSize() << endl << endl;
}

void testPerson()
{
	MyArray<Person>arr(10);
	Person p1("珞小遥", 18);
	Person p2("樱花小帮", 18);
	Person p3("华小科", 18);

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
	cout << "【testInt1】" << endl;
	testInt1();

	cout << "--------------------------------" << endl;
	cout << "【testInt2】" << endl;
	testInt2();

	cout << "--------------------------------" << endl;
	cout << "【testPerson】" << endl;
	testPerson();

	system("pause");
	return 0;
}