#include <iostream>
using namespace std;

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

	// cout << overload
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

	void delchild()
	{

	}
	void editchild()
	{
		// get i

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

	}






};