#include <QtCore/QCoreApplication>
#include<iostream>
#include<memory>
using namespace std;
class Student
{
public:
	Student()
	{
		cout << "构造函数1" << endl;
	}
	Student(int k)
	{
		cout << "构造函数2" << endl;
		i = k;
	}
	Student(Student const &m)
	{
		cout << "拷贝构造函数" << endl;
		i = m.i * (-1);
	}

	void p()
	{
		cout << i << endl;
	}
	~Student()
	{
		cout << "析构函数" << endl;
	}
protected:
	int i;
};

int main(int argc, char **argv)
{
	//Student s(9818);
	//// 调用构造函数2
	//s.p();
	//
	//Student t(s);
	//// 调用拷贝构造函数
	//t.p();
	//
	//Student k = s;
	//// 调用拷贝构造函数
	//k.p();
	//
	//Student *p = new Student(s);
	//// 调用拷贝构造函数
	//p->p();

	//Student m;
	//// 调用构造函数1
	//m = s;// 赋值运算
	//m.p();

	auto ps = make_shared<Student>(1);

	return 0;
}

//https://blog.csdn.net/qq_34992845/article/details/69218843