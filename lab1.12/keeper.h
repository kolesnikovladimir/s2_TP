#include <iostream>
#include "family_tree.h"

class keeper
{
	int size;
	family_tree** list;

public:
	keeper() {};
	~keeper() {};

	int add()
	{
		int originalSize = size;
		size++;
		family_tree* new_family = new family_tree;
		family_tree** created = new family_tree * [size];

		for (int i = 0; i < originalSize; i++)
		{
			created[i] = new family_tree;
			created[i] = list[i];
		}

		list = created;
		list[size - 1] = new_family;
	}

	int edit()
	{

	}
	int delit()
	{

	}
	void save()
	{

	}
	void load()
	{

	}

};