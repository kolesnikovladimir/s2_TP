#pragma once
#pragma once
#include "keeper.h"


keeper::keeper() {
	cout << "new keeper" << endl;
	size = 0;
	list = nullptr;

};
keeper::~keeper() {
	cout << "keeper delete" << endl;

};
void keeper::printAll()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n\tfamily N" << i + 1 << endl;
		((family*)list[i])->printAll();
		cout << endl;
	}
}

void keeper::add()
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


void keeper::add(family* new_family)
{
	int originalSize = size;
	size++;
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


int keeper::edit()
{
	int id = -1;
	if (size == 0)
	{
		printf("no records found\n");
		return 0;
	}
	while (id < 0 || id >= size)
	{
		printf("\nthere are %d FAMILIES added\n", size);
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

int keeper::delit()
{
	int n = -1;
	if (size == 0)
	{
		printf("no records found\n");
		return 0;
	}

	while (n < 1 || n >= size)
	{
		printf("\nenter id of element or -1 to exit or %d to see all\n", size);
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

void keeper::save()
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

void keeper::load()
{
	ifstream fin;
	fin.open("text.txt");
	int s;
	fin >> s;
	if (s < 0)
		throw (string)"size less than zero";
	for (int i = 0; i < s; i++)
	{
		family* new_family = new family;
		fin >> *new_family;
		add(new_family);
	}

	fin.close();
}

