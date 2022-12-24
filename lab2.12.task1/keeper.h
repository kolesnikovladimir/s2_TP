#pragma once
#include "stdio.h"
#include "note.h"
#include "my.h"
#include "string.h"

class Keeper
{
	int size;
	note** list;
	void printSearchPhone();

public:

	Keeper();
	~Keeper();

	int add();
	int edit();
	int delit();

	void printAll();

	int searchPrint();

	void sort();

};
