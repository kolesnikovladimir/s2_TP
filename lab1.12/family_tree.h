#pragma once
#include <iostream>
#include "member.h"

class family_tree
{
	int size;
	member** arr;

public:
	family_tree();
	~family_tree();
	int getsize();
	void setsize(int s);
	member** getarr();
	void setarr(member** _arr);
	
	member* operator[](int i);

	virtual void add_member()	{};
	virtual void add_member(member* new_member)	{};
	virtual void edit_family()	{};
	virtual void edit_member()	{};
	virtual void delit_member()	{};
	virtual void printAll()	{};
	virtual void filePrint(ostream& fp)	{};
	
};