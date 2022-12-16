#include <iostream>
using namespace std;

class date
{
	int d; int m; int y;

};

class member
{
	string fio;
	member** parents;
	int parents_size;
	member** children;
	int children_size;
	member* spouse;
	date* birth;
	date* death;
	int age;


};