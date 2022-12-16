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
	keeper();
	~keeper();
	void printAll();
	void add();

	void add(family* new_family);

	int edit();

	int delit();

	void save();
	
	void load();
};