#ifndef INPUT_H
#define INPUT_H

#include <iostream>

inline int inputInRange(const int &lower, const int &upper)
{
	using namespace std;
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

#endif // !INPUT_H
