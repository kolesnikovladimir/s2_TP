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
	}
	int getSize()
	{
		return size;
	}
	member* operator[](int i)
	{
		if (i >= size)
			return nullptr;
		return arr[i];
	}
};