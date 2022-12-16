#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "stdio.h"
#include "date.h"

using namespace std;


class member
{
	string fio;
	member* mom;
	member* dad;

	member** children;
	int children_size;
	member* spouse;
	date* birth;
	date* death;
	int age;

	void menu_editfio();
	void menu_editmom();
	void menu_editdad();
	void menu_editchildren();
	void menu_editspouse();
	void menu_editbirth();
	void menu_editdeath();
	string getfio();
	member* getmom();
	member* getdad();
	member* getspouse();
	date* getbirth();
	date* getdeath();
	int getage();
	void setfio(string f);
	void setbirth(date* bd);
	void setdeath(date* dd);
	void setmom(member* m);
	void delmom();
	void setdad(member* d);
	void deldad();
	void setspouse(member* s);
	void delspouse();
	void setchildren_size(int n);
	void addchild(member* chld);
	void addchild();
	void cout_children();

	void delchild();
	void editchild();
	void editbirth();
	void editdeath();
	void setage();
public:

	member();
	~member();
	void menu_edit();
	void print();

	friend std::ostream& operator<<(std::ostream& out, member& p)
	{
		if (&p == nullptr)
			return out << -1;	
		else
			out << 1 << endl;

		out << p.getfio() << endl;
		out << *(p.getbirth()) << endl;		
		out << *(p.getdeath()) << endl;

		out << *(p.getmom()) << endl;
		out << *(p.getdad()) << endl;
		out << *(p.getspouse()) << endl;

		out << p.children_size << endl;
		for(int i = 0; i < p.children_size; i++)
			out << p.children[i] << endl;
		
		return out;
	}

	friend std::istream& operator>>(std::istream& in, member& p)
	{
		int isthere;
		in >> isthere;
		if (isthere == -1)
		{
			throw isthere;
			return in;
		}
		string str;
		getline(in, str);
		getline(in, str);
		p.setfio(str);

		date* dt = new date;
		in >> *dt;
		p.setbirth(dt);

		date* dd = new date;
		in >> *dd;
		p.setdeath(dd);

		member* mama = new member;
		try {
			in >> *mama;
		}
		catch (int c)
		{
			if (c == -1)
				mama = nullptr;
			else
				throw c;
		}
		p.setmom(mama);

		member* dada = new member;
		
		try {
			in >> *dada;
		}
		catch (int c)
		{
			if (c == -1)
				dada = nullptr;
			else
				throw c;
		}
		p.setdad(dada);

		member* sps = new member;

		try {
			in >> *sps;
		}
		catch (int c)
		{
			if (c == -1)
				sps = nullptr;
			else
				throw c;
		}
		p.setspouse(sps);

		int child_count = 0;
		in >> child_count;
		if (child_count < 0)
			throw (string)"size less than zero";
		if (child_count == 0)
			p.setchildren_size(0);

		for (int i = 0; i < child_count; i++)
		{
			member* new_child = new member;
			in >> *new_child;
			p.addchild(new_child);

		}
	}

};