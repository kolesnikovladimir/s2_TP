#include "stdio.h"
#include "note.h"
#include "my.h"
#include "keeper.h"

void list()
{
	printf("\n\tlist of main commands:\n");
	printf("-1 exit programm\n");
	printf("1 print all\n");
	printf("2 search\n");
	printf("3 add new\n");
	printf("4 edit one item\n");
	printf("5 delete one item\n");
	printf("\n");
}


int main()
{
	Keeper obj;

	int t = 0;
	while (true)
	{
		list();
		printf("enter menu command:\n");
		scan("%d", &t);
		switch (t)
		{
			case -1:
				return 0;

			case 1:
				obj.printAll();
				break;

			case 2:
				obj.searchPrint();
				break;

			case 3:
				obj.add();
				break;

			case 4:
				try {
					obj.edit();
				}
				catch (char* msg)
				{
					printf("exeption: %s\n", msg);
				}
				break;

			case 5:
				obj.delit();
				break;

			default:
				printf("no such command\n");
				break;
		}


	}

	return 0;
}
