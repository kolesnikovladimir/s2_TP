
#include "family_tree.h"


family_tree::family_tree()
{
	size = 0;
	arr = nullptr;
	cout << "new family tree\n" << endl;
}
family_tree::~family_tree()
{
	cout << "family tree delete\n" << endl;
}

int family_tree::getsize()
{
	return size;
}

void family_tree::setsize(int s)
{
	size = s;
}

member** family_tree::getarr()
{
	return arr;
}
void family_tree::setarr(member** _arr)
{
	arr = _arr;
}
member* family_tree::operator[](int i)
{
	if (i >= size)
		return nullptr;
	return arr[i];
}

