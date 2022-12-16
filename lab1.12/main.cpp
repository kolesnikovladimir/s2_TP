#include <iostream>
#include "member.h"

using namespace std;

int main()
{
	member* m = new member;
	cout << *m << endl;

	m->menu_edit();

	return 0;
}