#pragma once
#include <iostream>
#include "member.h"

class family_tree
{
	int size;
	member** arr;


public:
	family_tree()
	{
		size = 0;
		arr = nullptr;
		cout << "new family tree\n" << endl;
	}
	~family_tree()
	{
		cout << "family tree delete\n" << endl;
	}

	int getsize()
	{
		return size;
	}

	void setsize(int s)
	{
		size = s;
	}
	
	member** getarr()
	{
		return arr;
	}
	void setarr(member** _arr)
	{
		arr = _arr;
	}
	member* operator[](int i)
	{
		if (i >= size)
			return nullptr;
		return arr[i];
	}

	virtual void add_member()	{};
	virtual void add_member(member* new_member)	{};
	virtual void edit_family()	{};
	virtual void edit_member()	{};
	virtual void delit_member()	{};
	virtual void printAll()	{};
	virtual void filePrint(ostream& fp)	{};
	

};