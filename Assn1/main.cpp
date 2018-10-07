#include "main.h"


int main()
{
	MovieList movie_list;
	Pivot *pivot;
	while (true)
	{
		switch (Menu())
		{
		default:
			break;
		case 1:
			movie_list.Add();
			break;
		case 2:
			movie_list.Print();
			break;
		case 3:
			pivot = new Pivot(movie_list);
			pivot->ShowTable();
			delete pivot;
			break;
		case 4:
			pivot = new Pivot(movie_list);
			pivot->ShowChart();
			delete pivot;
			break;
		case 5:
			return 0;
		}
	}
}

int Menu()
{
	cout << "----------MENU----------\n";
	cout << "1. Add Movie\n";
	cout << "2. Print List\n";
	cout << "3. Pivot Table\n";
	cout << "4. Pivot Chart\n";
	cout << "5. Exit\n";
	cout << "------------------------\n";
	return inputInRange(1, 5);
}

