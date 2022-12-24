#define _CRT_SECURE_NO_WARNINGS
#include "my.h"
#include "string.h"

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


