#include <sstream>
#include <iostream>

using namespace std;

int main(void)
{
	ostringstream os, os2;
	string a("hello\n");
	
	os << a;
	cout << "os    : " << os.str().length() << endl;
	cout << "string: " << a.length() << endl;

	os2 << a << a;
	cout << "os2   : " << os2.str().length() << endl;

	cout << "os    : " << os.str().length() << endl;
}