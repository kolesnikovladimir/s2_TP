#include <iostream>
#include "keeper.h"

using namespace std;
void list()
{
	printf("\n\tlist of main commands:\n");
	printf("-1 exit programm\n");
	printf("1 print all FAMILIES\n");
	printf("2 add new FAMILY\n");
	printf("3 edit FAMILY\n");
	printf("4 delete FAMILY\n");
	printf("5 save to file\n");
	printf("6 load from file\n");

	printf("\n");
}

int main()
{
	keeper conf;

	int t = 0;
	while (t == 0)
	{
		list();
		printf("enter menu command:\n");
		scan("%d", &t);
		switch (t)
		{
		case -1:
			t = -1;
			break;

		case 1:
		
			conf.printAll();
			
		t = 0; break;

		
		case 2:
			conf.add();
			t = 0;	break;

		case 3:
			try {
				conf.edit();
			}
			catch (char* msg)
			{
				printf("exeption: %s\n", msg);
			}
			t = 0;	break;

		case 4:
			conf.delit();
			t = 0;	break;

		case 5:
			conf.save();
			t = 0;	break;

		case 6:
			try {
				conf.load();
			}
			catch (int c)
			{
				cout << "exeption caugth when loading: met " << c<< "where 1 or -1 should be"<<endl;
			}
			catch(string str)
			{
				cout << "exeption caugth when loadin: " << str << endl;
			}

			t = 0;	break;

		default:
			printf("no such command\n");
			t = 0;		break;
		}

	}

	return 0;
}