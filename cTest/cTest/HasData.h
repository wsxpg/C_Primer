#ifndef HASDATA_H
#define HASDATA_H
#include<QDebug>
#include<iostream>
using namespace std;
class HasData 
{
public:
	HasData(const std::string&s=std::string())
		:ps(new std::string(s)), i(0)
	{
		qDebug() << QStringLiteral("构造函数") << endl;
	}
	HasData(const HasData& hd)
		:ps(new std::string(*hd.ps)),i(hd.i){
		qDebug() << QStringLiteral("拷贝构造函数") << endl;
	}

	HasData& operator = (const HasData& hd)
	{
		qDebug() << QStringLiteral("拷贝赋值运算符 HasData") << endl;
		auto newps = new string(*hd.ps);
		delete ps;
		ps = newps;
		i = hd.i;
		return *this;
	}

	HasData& operator = (const string& s)
	{
		qDebug() << QStringLiteral("拷贝赋值运算符 string") << endl;
		*ps = s;
		return *this;
	}

	string& operator* ()
	{
		return *ps;
	}

	~HasData(){};

private:

	std::string *ps;
	int i;
};

#endif // HASDATA_H
