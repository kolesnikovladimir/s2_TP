#include "date.h"
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


date::date()
{
	d = 1;
	m = 12;
	y = 2000;
}

void date::edit()
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

	while (n <= 0)
	{
		cout << "enter year: ";
		scan("%d", &n);
	}
	y = n;
}

int date::gety()
{
	return y;
}

void date::operator =(int i)
{
	y = i;
}

int date::operator-(date* obj)
{
	return (y - obj->gety());
}


void date::print()
{
	cout << d << "/" << m << "/" << y;
}


