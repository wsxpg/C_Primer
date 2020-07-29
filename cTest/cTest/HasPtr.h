#ifndef HASPTR_H
#define HASPTR_H
#include<iostream>
using namespace std;
class HasPtr
{
public:
	HasPtr(const string&s=string())
		:ps(new string(s)), i(0), use(new size_t(1))
	{
	
	}

	HasPtr(HasPtr&hsp)
		:ps(hsp.ps), i(hsp.i), use(hsp.use)
	{
		++*use;
	}

	HasPtr&operator=(HasPtr&hsp)
	{
		++*hsp.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = hsp.ps;
		i = hsp.i;
		use = hsp.use;
		return *this;
	}

	HasPtr&operator=(string &s)
	{
		*ps = s;
		return *this;
	}
	string operator*()
	{
		return*ps;
	}

	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}

private:
	string *ps;
	int i;
	size_t *use;
};

#endif // HASPTR_H
