#include "Pivot.h"

void Pivot::Categorize(const MovieList & movie_list)
{
	list<Movie>::const_iterator movie_it;
	list<CategorizedMovie>::iterator list_it;
	categorized_list.clear();
	switch (category_mode)
	{
	case 1:
		for (movie_it = movie_list.data.begin(); movie_it != movie_list.data.end(); movie_it++)
		{
			for (list_it = categorized_list.begin(); list_it != categorized_list.end(); list_it++)
			{
				if (list_it->category.front() == movie_it->genre)
				{
					list_it->movies.push_back(*movie_it);
					break;
				}
			}
			if (list_it == categorized_list.end())
			{
				CategorizedMovie new_list;
				new_list.category.push_back(movie_it->genre);
				new_list.movies.push_back(*movie_it);
				categorized_list.push_back(new_list);
			}
		}
		break;
	case 2:
		for (movie_it = movie_list.data.begin(); movie_it != movie_list.data.end(); movie_it++)
		{
			for (list_it = categorized_list.begin(); list_it != categorized_list.end(); list_it++)
			{
				if (list_it->category.front() == movie_it->source)
				{
					list_it->movies.push_back(*movie_it);
					break;
				}
			}
			if (list_it == categorized_list.end())
			{
				CategorizedMovie new_list;
				new_list.category.push_back(movie_it->source);
				new_list.movies.push_back(*movie_it);
				categorized_list.push_back(new_list);
			}
		}
		break;
	case 3:
		for (movie_it = movie_list.data.begin(); movie_it != movie_list.data.end(); movie_it++)
		{
			for (list_it = categorized_list.begin(); list_it != categorized_list.end(); list_it++)
			{
				if (list_it->category.front() == movie_it->genre)
				{
					if (list_it->category.back() == movie_it->source)
					{
						list_it->movies.push_back(*movie_it);
						break;
					}
				}
			}
			if (list_it == categorized_list.end())
			{
				CategorizedMovie new_list;
				new_list.category.push_back(movie_it->genre);
				new_list.category.push_back(movie_it->source);
				new_list.movies.push_back(*movie_it);
				categorized_list.push_back(new_list);
			}
		}
		break;
	case 4:
		for (movie_it = movie_list.data.begin(); movie_it != movie_list.data.end(); movie_it++)
		{
			for (list_it = categorized_list.begin(); list_it != categorized_list.end(); list_it++)
			{
				if (list_it->category.front() == movie_it->source)
				{
					if (list_it->category.back() == movie_it->genre)
					{
						list_it->movies.push_back(*movie_it);
						break;
					}
				}
			}
			if (list_it == categorized_list.end())
			{
				CategorizedMovie new_list;
				new_list.category.push_back(movie_it->source);
				new_list.category.push_back(movie_it->genre);
				new_list.movies.push_back(*movie_it);
				categorized_list.push_back(new_list);
			}
		}
	}
	categorized_list.sort();
}

void Pivot::ShowTable()
{
	switch (category_mode)
	{
	case 1:
		cout << "Genre";
		break;
	case 2:
		cout << "Source";
		break;
	case 3:
		cout << "Genre\tSource";
		break;
	case 4:
		cout << "Source\tGenre";
		break;
	}
	cout << "\t";
	switch (figure_mode)
	{
	case 1:
		cout << "Production\n";
		break;
	case 2:
		cout << "Gross\n";
		break;
	case 3:
		cout << "Rating\n";
		break;
	}
	for (list<CategorizedMovie>::iterator it1 = categorized_list.begin(); it1 != categorized_list.end(); it1++)
	{
		for (list<string>::iterator it2 = it1->category.begin(); it2 != it1->category.end(); it2++)
		{
			cout << *it2 << '\t';
		}
		cout << it1->getCalculationResult() << endl;
	}
}

void Pivot::ShowChart() const
{
	Chart chart(categorized_list, category_mode);
	chart.print();
}



void Pivot::SetMode()
{
	cout << "----------Category----------\n";
	cout << "1. Genre\n";
	cout << "2. Source\n";
	cout << "3. Genre and Source\n";
	cout << "4. Source and Genre\n";
	cout << "----------------------------\n";
	category_mode = inputInRange(1, 4);

	cout << "----------Figure----------\n";
	cout << "1. Production\n";
	cout << "2. Gross\n";
	cout << "3. Rating\n";
	cout << "--------------------------\n";
	figure_mode = inputInRange(1, 3);

	cout << "----------Function----------\n";
	cout << "1. Average\n";
	cout << "2. Sum\n";
	cout << "3. Max\n";
	cout << "4. Min\n";
	cout << "----------------------------\n";
	function_mode = inputInRange(1, 4);

	CategorizedMovie::setCalculationMode(figure_mode, function_mode);
	return;
}
