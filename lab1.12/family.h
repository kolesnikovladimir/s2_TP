#pragma once
#include <iostream>

#include "family_tree.h"

class family : public family_tree
{
public:

	void printAll()override;
	void edit_family() override;
	void add_member() override;
	void add_member(member* new_member);
	void edit_member() override;
	void delit_member() override;

	void filePrint(ostream& fp) override;

	friend std::istream& operator>>(std::istream& in, family& p)
	{
		int s;
		in >> s;
		if (s < 0)
			throw (string)"size less than zero";
		for (int i = 0; i < s; i++)
		{
			member* new_member = new member;
			try {
				in >> *new_member;
			}
			catch (int c)
			{
				if (c == -1)
					new_member = nullptr;
				else
					throw c;
			}
			p.add_member(new_member);
		}
		return in;
	}

};