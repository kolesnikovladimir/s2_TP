#include <iostream>
using namespace std;

class date
{
	int d; int m; int y;

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

	}
	void delchild()
	{

	}
	void editchild()
	{

	}

	void editbirth()
	{

	}
	void editdeath()
	{

	}
	void editage()
	{

	}
	




	void edit()
	{

	}






};