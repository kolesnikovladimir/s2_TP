#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "stdio.h"
using namespace std;

int scan(const char* _f, void* _x)
{
	while (1)
	{
		printf("input: ");
		if (scanf_s(_f, _x) != 1)
			printf("try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}

class date
{
	int d; int m; int y;
public:

	date()
	{
		d = 1;
		m = 12;
		y = 2000;
	}

	void edit()
	{
		int n = 0;
		
		while (n <= 0 || n > 31)
		{
			cout << "enter day: ";
			scan("%d", &n);
		}
		d = n;
		n = 0;
		
		while (n <= 0 || n > 12)
		{
			cout << "enter month: ";
			scan("%d", &n);
		}
		m = n;
		n = 0;
		
		while (n <= 0 )
		{
			cout << "enter year: ";
			scan("%d", &n);
		}
		y = n;
	}

	int gety()
	{
		return y;
	}

	void operator =(int i)
	{
		y = i;
	}

	int operator-(date* obj)
	{
		return (y - obj->gety());
	}


	void print()
	{
		cout << d << "/" << m << "/" << y;
	}

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

	void menu_editfio()
	{
		string str;
		cout << "enter new fio" << endl;
		getline(cin, str);
		setfio(str);
	}

	void menu_editmom()
	{
		int command = 0;
		while (command != -1 && command != 1 && command != 2)
		{
			cout << "mother "; cout << "1 edit; 2 delete; -1 exit" << endl;
			scan("%d", &command);
		}
		if (command == 1)
		{
			cout << "enter new mother info" << endl;
			if (mom == nullptr)
				mom = new member;
			mom->menu_edit();
		}
		if (command == 2)
		{
			delmom();
		}
	}

	void menu_editdad()
	{
		int command = 0;
		while (command != -1 && command != 1 && command != 2)
		{
			cout << "father "; cout << "1 edit; 2 delete; -1 exit" << endl;
			scan("%d", &command);
		}
		if (command == 1)
		{
			cout << "enter new father info" << endl;
			if (dad == nullptr)
				dad = new member;
			dad->menu_edit();
		}
		if (command == 2)
		{
			deldad();
		}
	}

	void menu_editchildren()
	{
		cout_children();
			
		int c = -2;
		while (c != -1) {
			cout << "\n\tCHILDREN EDIT MENU"<< endl;
			cout << "1 add child\n2 edit child\n3 del child\n0 see all children\n-1 exit edit" << endl;
			scan("%d", &c);
			switch (c)
			{
			case 1:
				addchild(); c = 0;
				break;
			case 2:
				if (children_size == 0)
				{
					cout << "none added" << endl;
					break;
				}
					editchild(); c = 0;
				break;
			case 3:
				if (children_size == 0)
				{
					cout << "nonde added" << endl;
					break;
				}
				delchild(); c = 0;
				break;

			case 0:
				cout_children(); c = 0;
				break;
			case -1:
				c = -1;
				break;

			default:
				cout << "unknown command" << endl;
			}
		}
		
	}

	void menu_editspouse()
	{
		int command = 0;
		while (command != -1 && command != 1)
		{
			cout << "spouse "; cout << "1 edit; -1 exit" << endl;
			scan("%d", &command);
		}
		if (command == 1)
		{
			cout << "enter new spouse info" << endl;
			if (spouse == nullptr)
				spouse = new member;
			spouse->menu_edit();
		}
	}

	void menu_editbirth()
	{
		int command = 0;
		while (command != -1 && command != 1)
		{
			cout << "birth "; cout << "1 edit; -1 exit" << endl;
			scan("%d", &command);
		}
		if (command == 1)
		{
			cout << "enter new birth info" << endl;
			birth->edit();
		}
	}

	void menu_editdeath()
	{
		int command = 0;
		while (command != -1 && command != 1)
		{
			cout << "death "; cout << "1 edit; -1 exit" << endl;
			scan("%d", &command);
		}
		if (command == 1)
		{
			cout << "enter new death info" << endl;
			death->edit();
		}
	}

	string getfio()
	{
		return fio;
	}
	member* getmom()
	{
		return mom;
	}
	member* getdad()
	{
		return dad;
	}
	member* getspouse()
	{
		return spouse;
	}
	date* getbirth() {
		return birth;
	}
	date* getdeath() {
		return death;
	}
	int getage() {
		return age;
	}

	void setfio(string f)
	{
		fio = f;
	}
	void setbirth(date* bd)
	{
		birth = bd;
	}
	void setdeath(date* dd)
	{
		death = dd;
	}
	void setmom(member* m)
	{
		mom = m;
	}
	void delmom()
	{
		delete mom;
		mom = nullptr;
	}

	void setdad(member* d)
	{
		dad = d;
	}
	void deldad()
	{
		delete dad;
		dad = nullptr;
	}

	void setspouse(member* s)
	{
		spouse = s;
	}
	void delspouse()
	{
		delete spouse;
		spouse = nullptr;
	}

	void setchildren_size(int n)
	{
		children_size = n;
	}
	void addchild(member* chld)
	{
		int originalSize = children_size;
		children_size++;
		member** created = new member * [children_size];

		for (int i = 0; i < originalSize; i++)
		{
			created[i] = new member;
			created[i] = children[i];
		}

		children = created;
		children[children_size - 1] = chld;
	}
	void addchild()
	{
		int originalSize = children_size;
		children_size++;
		member* new_child = new member;
		member** created = new member * [children_size];

		for (int i = 0; i < originalSize; i++)
		{
			created[i] = new member;
			created[i] = children[i];
		}

		children = created;
		children[children_size - 1] = new_child;
	}
	void cout_children()
	{
		for (int i = 0; i < children_size; i++)
		{
			cout << "child " << i + 1 << "\n";
			children[i]->print();
		}
	}

	void delchild()
	{
		int n = -1;
		if (children_size == 0)
		{
			printf("no records found\n");
			return;
		}

		while (n < 1 || n >= children_size)
		{
			printf("enter id of element or -1 to exit or %d to see all\n", children_size);
			scan("%d", &n);
			if (n == children_size)
				cout_children();
			if (n == -1)
				return;
		}

		delete children[n];
		for (int i = n; i < children_size; i++)
			children[i] = children[i + 1];


		children_size -= 1;
	}
	void editchild()
	{
		int id = -1;
		if (children_size == 0)
		{
			printf("no records found\n");
			return;
		}
		while (id < 0 || id >= children_size)
		{
			printf("there are %d children added\n", children_size);
			printf("enter id of element or -1 to exit or %d to see all\n", children_size);
			scan("%d", &id);
			if (id == -1)
				return;
			if (id == children_size)
				cout_children();
		}

		children[id]->menu_edit();
	}

	void editbirth()
	{
		birth->edit();
	}
	void editdeath()
	{
		death->edit();
	}

	void setage()
	{
		if (death->gety() != -1)
			age = *death - birth;
		else
			age = 2022 - birth->gety();
	}

public:

	member()
	{
		cout << "new member" << endl;
		fio = "unknown";
		mom = nullptr;
		dad = nullptr;
		spouse = nullptr;
		birth = new date();
		death = new date(); *death = -1;
		setage();
	}

	~member()
	{
		cout << "del member" << endl;
	}


	void menu_edit()
	{
		cout << "now values are:" << endl;
		print();
		while (true)
		{
			cout << "MEMBER EDIT MENU" << endl;
			int command = 0;
			cout << "-1 to exit editing" << endl;
			cout << "1 edit fio" << endl;
			cout << "2 edit mother" << endl;
			cout << "3 edit father" << endl;
			cout << "4 edit spouse" << endl;
			cout << "5 edit children" << endl;
			cout << "6 edit birth" << endl;
			cout << "7 edit death" << endl;
			cout << "0 see values" << endl;
			scan("%d", &command);
			switch (command)
			{
			case 1:
				menu_editfio();
				break;
			case 2:
				menu_editmom();
				break;
			case 3:
				menu_editdad();
				break;
			case 4:
				menu_editspouse();
				break;
			case 5:
				menu_editchildren();
				break;
			case 6:
				menu_editbirth();
				break;
			case 7:
				menu_editdeath();
				break;
			case 0:
				cout << "now values are:" << endl;
				print();
				break;
			case -1:
				setage();
				return;

			default:
				cout << "unknown" << endl;
			}
			setage();
		}
		
	}
	
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

	void print()
	{
		if (this == nullptr)
		{
			cout << "no info ";
			return; 
		}

		cout << "\tname: " << getfio();
		if (getdeath()->gety() == -1)
		{
			cout << " ("; 
			getbirth()->print(); 
			cout << ")";
		}
		else
		{
			cout << " (";
			getbirth()->print();
			cout << " - ";
			getdeath()->print();
			cout << ")";
		}
		cout << " aged: " << getage() << endl;

		cout << "\n\tmother:\n\t\t"; mom->print();
		cout << "\n\tfather:\n\t\t"; dad->print();
		cout << "\n\tspouse:\n\t\t"; spouse->print();

		if (children_size > 0)
		{
			cout << "\n\n\tchildren: ";
			cout_children();
		}

		return;

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