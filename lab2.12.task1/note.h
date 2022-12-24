#pragma once
#include "stdio.h"
#include <iostream>
#include <string>
#define DAY 0
#define MONTH 1
#define YEAR 2

/*
Определить класс с именем NОТЕ, содержащий следующие поля:
● фамилия, имя;
● номер телефона;
● день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа NОТЕ.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по трем первым цифрам номера
телефона;
● вывод на экран информации о человеке, чья фамилия введена с
клавиатуры;
● если такого нет, выдать на дисплей соответствующее сообщение.


*/

using namespace std;

class note
{
	string name;
	string surname;
	string phone;
	
	int BD[3];

	void setName(string n);
	void setSurname(string s);
	void setPhone(string s);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
public:

	note();
	~note();

	bool operator>(note& obj);

	string getName();
	string getSurname();
	string getPhone();
	int getDay();
	int getMonth();
	int getYear();
	void set();

	void setNewName();
	void setNewSurname();
	void setNewPhone();
	void setNewDay();
	void setNewMonth();
	void setNewYear();
	void editMenu();

	void print();
	friend std::ostream& operator<<(std::ostream& out, note& ptr);
	friend std::istream& operator>>(std::istream& in, note& time);

};