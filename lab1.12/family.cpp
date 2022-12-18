#include "family.h"

	void family::printAll()
	{
		if (getsize() == 0)
		{
			printf("no records found\n");
			return;
		}

		for (int i = 0; i < getsize(); i++)
		{
			cout << "\nfamily member N" << i + 1 << endl;;
			(getarr()[i])->print();
			cout << endl;
		}
	}


	void family::edit_family() 
	{
		int t = 0;
		while (t == 0)
		{

			printf("EDIT FAMILY MENU:\n");
			printf("-1 exit EDIT FAMILY MENU\n");
			printf("1 print all MEMBERS\n");
			printf("2 add new MEMBER\n");
			printf("3 edit MEMBER\n");
			printf("4 delete MEMBER\n");

			printf("\n");
			scan("%d", &t);
			switch (t)
			{
			case -1:
				t = -1;
				break;

			case 1:
				printAll();
				t = 0; break;

			case 2:
				add_member();
				t = 0;	break;

			case 3:
				edit_member();
				t = 0;	break;

			case 4:
				delit_member();
				t = 0;	break;

			default:
				printf("no such command\n");
				t = 0;		break;
			}

		}

	}


	void family::add_member() 
	{
		int originalSize = getsize();
		int size = originalSize + 1;
		member* new_member = new member;

		member** created = new member * [size];
		member** old = getarr();
		for (int i = 0; i < originalSize; i++)
		{
			created[i] = new member;
			created[i] = old[i];
		}

		old = created;
		created[size - 1] = new_member;
		setarr(created);
		setsize(size);
	}

	void family::add_member(member* new_member) 
	{
		int originalSize = getsize();
		int size = originalSize + 1;

		member** created = new member * [size];
		member** old = getarr();
		for (int i = 0; i < originalSize; i++)
		{
			created[i] = new member;
			created[i] = old[i];
		}

		old = created;
		created[size - 1] = new_member;
		setarr(created);
		setsize(size);
	}

	void family::edit_member() 
	{
		int id = -1;
		if (getsize() == 0)
		{
			printf("no records found\n");

			return;
		}
		while (id < 0 || id >= getsize())
		{
			printf("FAMILY EDIT MENU\nthere are %d elements added\n", getsize());
			printf("enter id of MEMBER starting from 0\nor -1 to exit or %d to see all\n", getsize());
			scan("%d", &id);
			if (id == -1)
				return;
			if (id == getsize())
				printAll();
		}
		try {
			getarr()[id]->menu_edit();
		}
		catch (char* m)
		{
			throw m;
		}
	}

	void family::delit_member() 
	{
		int n = -1;
		if (getsize() == 0)
		{
			printf("no records found\n");
			return;
		}

		while (n < 1 || n >= getsize())
		{
			printf("enter id of MEMBER starting from 0\nor -1 to exit or %d to see all\n", getsize());
			scan("%d", &n);
			if (n == getsize())
				printAll();
			if (n == -1)
				return;
		}

		delete getarr()[n];
		for (int i = n; i < getsize(); i++)
		{
			getarr()[i] = getarr()[i + 1];
		}
		setsize(getsize() - 1);

	}



	void family::filePrint(ostream& fp) 
	{
		fp << getsize() << endl;
		for (int i = 0; i < getsize(); i++)
			fp << *(getarr()[i]) << endl;
	}

	