#include <QtCore/QCoreApplication>
#include<iostream>
#include<memory>
using namespace std;
class Student
{
public:
	Student()
	{
		cout << "���캯��1" << endl;
	}
	Student(int k)
	{
		cout << "���캯��2" << endl;
		i = k;
	}
	Student(Student const &m)
	{
		cout << "�������캯��" << endl;
		i = m.i * (-1);
	}

	void p()
	{
		cout << i << endl;
	}
	~Student()
	{
		cout << "��������" << endl;
	}
protected:
	int i;
};

int main(int argc, char **argv)
{
	//Student s(9818);
	//// ���ù��캯��2
	//s.p();
	//
	//Student t(s);
	//// ���ÿ������캯��
	//t.p();
	//
	//Student k = s;
	//// ���ÿ������캯��
	//k.p();
	//
	//Student *p = new Student(s);
	//// ���ÿ������캯��
	//p->p();

	//Student m;
	//// ���ù��캯��1
	//m = s;// ��ֵ����
	//m.p();

	auto ps = make_shared<Student>(1);

	return 0;
}

//https://blog.csdn.net/qq_34992845/article/details/69218843