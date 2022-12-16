#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "stdio.h"

using namespace std;
int scan(const char* _f, void* _x);


class date
{
	int d; int m; int y;
public:

	date();

	void edit();

	int gety();

	void operator =(int i);

	int operator-(date* obj);

	void print();

	friend std::ostream& operator<<(std::ostream& out, date& p)
	{
		out << p.d << endl;
		out << p.m << endl;
		out << p.y << endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, date& p)
	{
		int n;
		in >> n;
		p.d = n;
		in >> n;
		p.m = n;
		in >> n;
		p.y = n;
		return in;
	}
};
