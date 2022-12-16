#include "member.h"
#include "date.h"

void  member::menu_editfio()
{
	string str;
	cout << "enter new fio" << endl;
	getline(cin, str);
	setfio(str);
}

void  member::menu_editmom()
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

void  member::menu_editdad()
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

void  member::menu_editchildren()
{
	cout_children();

	int c = -2;
	while (c != -1) {
		cout << "\n\tCHILDREN EDIT MENU" << endl;
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

void member::menu_editspouse()
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

void  member::menu_editbirth()
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

void  member::menu_editdeath()
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

string  member::getfio()
{
	return fio;
}
member* member::getmom()
{
	return mom;
}
member* member::getdad()
{
	return dad;
}
member* member::getspouse()
{
	return spouse;
}
date* member::getbirth() {
	return birth;
}
date* member::getdeath() {
	return death;
}
int  member::getage() {
	return age;
}

void  member::setfio(string f)
{
	fio = f;
}
void  member::setbirth(date* bd)
{
	birth = bd;
}
void  member::setdeath(date* dd)
{
	death = dd;
}
void  member::setmom(member* m)
{
	mom = m;
}
void  member::delmom()
{
	delete mom;
	mom = nullptr;
}

void  member::setdad(member* d)
{
	dad = d;
}
void  member::deldad()
{
	delete dad;
	dad = nullptr;
}

void  member::setspouse(member* s)
{
	spouse = s;
}
void  member::delspouse()
{
	delete spouse;
	spouse = nullptr;
}

void  member::setchildren_size(int n)
{
	children_size = n;
}
void  member::addchild(member* chld)
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
void  member::addchild()
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
void  member::cout_children()
{
	for (int i = 0; i < children_size; i++)
	{
		cout << "child " << i + 1 << "\n";
		children[i]->print();
	}
}

void  member::delchild()
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
void  member::editchild()
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

void  member::editbirth()
{
	birth->edit();
}
void  member::editdeath()
{
	death->edit();
}

void  member::setage()
{
	if (death->gety() != -1)
		age = *death - birth;
	else
		age = 2022 - birth->gety();
}


member::member()
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

member::~member()
{
	cout << "del member" << endl;
}


void  member::menu_edit()
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

	
void  member::print()
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

