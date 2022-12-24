/*
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран только предложения,
начинающиеся с тире, перед которым могут следовать только пробельные символы.
*/

#include "fstream"
#include <string>
#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	

	ifstream fin;
	fin.open("text.txt");
	if (!fin.is_open())
	{
		cout << "file not found" << endl;
		return 0;
	}

	char c;
	char prev = 'a';
	bool coutFlag = false;
	while (!fin.eof())
	{
		fin.get(c);
		//cout << c;
		if (c == '.' || c == '!' || c == '?')
		{

			while (c == '.' || c == '!' || c == '?' && !fin.eof())
			{
				if (coutFlag)
					cout << c;
				if (fin.eof())
					return 0;
				fin.get(c);		
			}

			fin.get(c);

			if (coutFlag)
					cout << endl;
			coutFlag = false;

			while (c == ' ' && !fin.eof())
			{			
				if (fin.eof())
					return 0;
				fin.get(c);

			}
			
			coutFlag = (c == '-');

		}
		if (coutFlag)
			cout << c;

		prev = c;

	}

	fin.close();
}