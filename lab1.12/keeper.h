#pragma once
#include <iostream>
#include "family_tree.h"
#include "family.h"
#include <fstream>
class keeper
{
	int size;
	family_tree** list;

public:
	keeper() {
		cout << "new keeper" << endl;
		size = 0;
		list = nullptr;
	
	};
	~keeper() {
		cout << "keeper delete" << endl;
	
	};
	void printAll()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\tfamily N" << i + 1 << endl;
			((family*)list[i])->printAll();
		}
	}

	void add()
	{
		int originalSize = size;
		size++;
		family_tree* new_family = new family;
		family_tree** created = new family_tree * [size];

		for (int i = 0; i < originalSize; i++)
		{
			created[i] = new family_tree;
			created[i] = list[i];
		}

		list = created;
		list[size - 1] = new_family;
		cout << "\tadded!" << endl;
	}

	int edit()
	{
		int id = -1;
		if (size == 0)
		{
			printf("no records found\n");
			return 0;
		}
		while (id < 0 || id >= size)
		{
			printf("there are %d FAMILIES added\n", size);
			printf("enter id of FAMILY starting from 0\nor -1 to exit or %d to see all\n", size);
			scan("%d", &id);

			if (id == -1)
				return 0;
			if (id == size)
				printAll();
		}
		try {
			((family*)list[id])->edit_family();
		}
		catch (char* m)
		{
			throw m;
		}
	}

	int delit()
	{
		int n = -1;
		if (size == 0)
		{
			printf("no records found\n");
			return 0;
		}

		while (n < 1 || n >= size)
		{
			printf("enter id of element or -1 to exit or %d to see all\n", size);
			scan("%d", &n);
			if (n == size)
				printAll();
			if (n == -1)
				return 0;
		}

		delete list[n];
		for (int i = n; i < size; i++)
		{
			list[i] = list[i + 1];
		}

		size -= 1;
	}

	void save()
	{
		if (size == 0)
		{
			printf("list is empty\n");
			return;
		}

		ofstream fout;
		fout.open("text.txt");

		fout << size << endl;
		for (int i = 0; i < size; i++)
		{
			list[i]->filePrint(fout);
		}

		fout.close();
	}
	void load()
	{

	}

};