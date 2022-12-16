#include <iostream>
using namespace std;

int scan(const char* _f, void* _x)
{
	while (1)
	{
		printf("input: ");
		if (scanf(_f, _x) != 1)
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
	void edit()
	{

	}
	int gety()
	{
		return y;
	}

	int operator-(date* obj)
	{
		return (y - obj->gety());
	}

	friend std::ostream& operator<<(std::ostream& out, date& p)
	{
		out << p.d << "/" << p.m << "/" << p.y << endl;

		return out << endl;

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


public:

	member()
	{
		cout << "new member" << endl;
	}
	~member()
	{
		cout << "del member" << endl;
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
	date* getbith() {
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
	void setmom(member* m)
	{
		mom = m;
	}
	void editmom()
	{
		mom->edit();
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
	void editdad()
	{
		dad->edit();		
	}
	void deldad()
	{
		delete dad;
		dad = nullptr;
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
			printf("there are %d elements added\n", children_size);
			printf("enter id of element or -1 to exit or %d to see all\n", children_size);
			scan("%d", &id);
			if (id == -1)
				return ;
			if (id == children_size)
				cout_children();
		}

		try {
			children[id]->edit();
		}
		catch (char* m)
		{
			throw m;
		}

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


	void edit()
	{
		cout<<"now values are:\n" << *this << endl;

		int command = -1;
		cout << "to skip editing enter -1\n" << endl;


	}

	friend std::ostream& operator<<(std::ostream& out, member& p)
	{
		out << "name: " << p.getfio() << endl;
		out << "born in: "<< *(p.getbith())<< endl;

		if (p.getdeath()->gety() != -1)
			out << "died in: "<< *(p.getbith())<< endl;

		out << "aged: "<<p.getage() << endl;
		out << "mother: " << *(p.getmom() )<< endl;
		out << "father: " << *(p.getdad() )<< endl;

		if (p.children_size > 0)
			out << "children: " << *(p.getdad() )<< endl;
		

		return out << endl;

	}
	friend std::istream& operator>>(std::istream& in, member& p)
	{


	}





};