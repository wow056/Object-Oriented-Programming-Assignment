#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

inline int inputInRange(const int &lower, const int &upper)
{
	int input;
	while (true)
	{
		cout << "Selection: ";
		cin >> input;
		if ((input < lower) || (input > upper))
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			return input;
		}
	}
}

inline string itos(int i)
{
	ostringstream convert;
	convert << i;
	return convert.str();
}


#endif // !INPUT_H
