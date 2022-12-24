#include "fstream"
#include <string>
#include <iostream>


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