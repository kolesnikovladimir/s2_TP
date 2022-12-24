#pragma once
#include "my.h"

#include "keeper.h"
#include "stdio.h"
#include "note.h"
#include "string.h"

Keeper::Keeper()
{
	cout << "new keeper" << endl;
	size = 0;
	list = nullptr;
}


Keeper::~Keeper()
{
	cout << "keeper delete" << endl;
	for (int i = 0; i < size; i++)
		delete list[i];
}

int Keeper::add() {

	note* add = new note;
	add->setNewName();
	add->setNewSurname();
	add->setNewPhone();
	add->setNewDay();
	add->setNewMonth();
	add->setNewYear();

	int originalSize = size;
	size++;

	note** created = new note * [size];

	for (int i = 0; i < originalSize; i++)
	{
		created[i] = new note;
		created[i] = list[i];
	}

	list = created;
	list[size - 1] = add;

	return 0;
};





int Keeper::edit()
{
	int id = -1;
	if (size == 0)
	{
		printf("no records found\n");
		return 0;
	}
	while (id < 0 || id >= size)
	{
		printf("there are %d elements added\n", size);
		printf("enter id of element or -1 to exit or %d to see all\n", size);
		scan("%d", &id);
		if (id == -1)
			return 0;
		if (id == size)
			printAll();
	}
	try {
		list[id]->editMenu();
	}
	catch (char* m)
	{
		throw m;
	}

	return 0;
};

int Keeper::delit() {
	int n = -1;
	if (size == 0)
	{
		printf("no records found\n");
		return 0;
	}

	while (n < 0 || n >= size)
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

	return 0;
};



void Keeper::printAll()
{
	sort();

	printf("\n");
	int  c = 0;
	for (int i = 0; i < size; i++)
	{
		printf("N%d\n", i);
		list[i]->print();
		printf("\n");
		c++;
	}
	if (c == 0)
		printf("no found");
	printf("\n");
}


void Keeper:: sort()
{
	for (int i = 0; i < size-1;)
	{
		if (*list[i] > *list[i + 1])
		{
			// change places
			note* tmp = list[i];
			list[i] = list[i + 1];
			list[i+1] = tmp;
			i = 0;
		}
		else i++;
	}
}

void Keeper::printSearchPhone()
{
	printf("SEARCH: ");
	string str;
	cin >> str;

	int c = 0;
	for (int i = 0; i < size; i++)
	{
		note* item = list[i];

		if (item->getPhone()== str)
		{
			item->print();
			c++;
		}

	}
	if (c == 0)
		printf("no found");
	printf("\n");
}



int Keeper::searchPrint()
{
	int mode = -1;
	printf("EXIT SEACH -1\nSEARCH BY PHONE 1\n");


	while (true)
	{
		scan("%d", &mode);
		switch (mode)
		{
		default:
			printf("invalid input\n");
			break;
		case -1:
			return 0;
		case 1:
			printSearchPhone();
			break;
		

		}
	}

}


