#include "keeper.h"


using namespace std;


	note::note()
	{
		cout << "+note" << endl;
		setName("unk");
		setSurname("unk");
		setPhone("unk");
	}

	note::~note()
	{
		cout << "-note" << endl;
	}

	bool note::operator>(note& obj)
	{
		int data1 = this->BD[YEAR] * 10000 + this->BD[MONTH] * 100 + this->BD[DAY];
		int data2 = obj.BD[YEAR] * 10000 + obj.BD[MONTH] * 100 + obj.BD[DAY];

		return (data1 > data2);
	}

	void note::setName(string n)
	{
		name = n;
	}

	void note::setSurname(string s)
	{
		surname = s;
	}

	void note::setPhone(string s)
	{
		phone = s;
	}

	void note::setDay(int d)
	{
		BD[DAY] = d;
	}

	void note::setMonth(int m)
	{
		BD[MONTH] = m;
	}

	void note::setYear(int y)
	{
		BD[YEAR] = y;
	}


	string note::getName()
	{
		return name;
	}

	string note::getSurname()
	{
		return surname;
	}

	string note::getPhone()
	{
		return phone;
	}

	int note::getDay()
	{
		return BD[DAY];
	}

	int note::getMonth()
	{
		return BD[MONTH];
	}

	int note::getYear()
	{
		return BD[YEAR];
	}

	void note::set()
	{
		setNewName();
		setNewSurname();
		setNewPhone();
		setNewDay();
		setNewMonth();
		setNewYear();
	}

	void note::setNewName()
	{
		string str;

		cout << "name: " << endl;
		cin >> str;
		setName(str);
	}

	void note::setNewSurname()
	{
		string str;

		cout << "surname: " << endl;
		cin >> str;
		setSurname(str);
	}

	void note::setNewPhone()
	{
		cin >> (*this);
	}

	void note::setNewDay()
	{
		int num = -1;

		while (num <= 0 || num > 31)
		{
			cout << "day: " << endl;
			scan("%d", &num);
		}
		setDay(num);
	}

	void note::setNewMonth()
	{
		int num = -1;

		while (num <= 0 || num > 12)
		{
			cout << "month: " << endl;
			scan("%d", &num);
		}
		setMonth(num);
	}

	void note::setNewYear()
	{
		int num = -1;

		while (num < 0)
		{
			cout << "year: " << endl;
			scan("%d", &num);
		}
		setYear(num);
	}

	void note::editMenu()
	{
		int choice;
		while (true)
		{
			cout << "edit:\n-1 back\n1 name\n2 surname\n3 phone number\n4 birth day\n5 birth month\n6 birth year" << endl;
			scan("%d", &choice);
			switch (choice)
			{
			case -1:
				return;

			case 1:
				setNewName();
				break;
			case 2:
				setNewSurname();
				break;
			case 3:
				setNewPhone();
				break;
			case 4:
				setNewDay();
				break;
			case 5:
				setNewMonth();
				break;
			case 6:
				setNewYear();
				break;
			default:
				cout << "unknown" << endl;
			}

		}
		throw (char*)"edit menu exeption";
	}

	std::ostream& operator<<(std::ostream& out, note& ptr)
	{
		out << "name: " << ptr.getName() << endl;
		out << "surname: " << ptr.getSurname() << endl;
		out << "phone number: " << ptr.getPhone() << endl;
		out << "birth date: " << ptr.getDay() << "/" << ptr.getMonth() << "/" << ptr.getYear() << endl;
		return out << endl;
	}

	std::istream& operator>>(std::istream& in, note& ptr)
	{
		string str = "11";
		while (str.length() < 3)
		{
			cout << "phone: " << endl;
			in >> str;
			if (str.length() < 3)
				cout << "phone number cannot be shorter than 3 symbols" << endl;
		}

		ptr.setPhone(str);
		return in;
	}



	void note::print()
	{
		cout << "name: " << getName() << endl;
		cout << "surname: " << getSurname() << endl;
		cout << "phone number: " << getPhone() << endl;
		cout << "birth date: " << getDay() << "/" << getMonth() << "/" << getYear() << endl;
	}

