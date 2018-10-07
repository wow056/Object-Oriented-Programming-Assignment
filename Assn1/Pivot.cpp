#include "Pivot.h"

void Pivot::Categorize(const MovieList & movie_list)
{
	list<Movie>::const_iterator movie_it;
	list<CategorizedMovie>::iterator list_it;
	for (movie_it = movie_list.data.begin(); movie_it != movie_list.data.end(); movie_it++)
	{
		list_it = FindCategory(*movie_it);
		if (list_it == categorized_list.end())
		{
			AddNewCategory(*movie_it);
		}
		else
		{
			list_it->movies.push_back(*movie_it);
		}
	}
	categorized_list.sort();
}

void Pivot::ShowTable() const
{
	switch (category_mode)
	{
	case 1:
		cout << "Genre\t";
		break;
	case 2:
		cout << "Source\t";
		break;
	case 3:
		cout << "Genre\tSource\t";
		break;
	case 4:
		cout << "Source\tGenre\t";
		break;
	}
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
	for (list<CategorizedMovie>::const_iterator it1 = categorized_list.begin(); it1 != categorized_list.end(); it1++)
	{
		for (list<string>::const_iterator it2 = it1->category.begin(); it2 != it1->category.end(); it2++)
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



list<CategorizedMovie>::iterator Pivot::FindCategory(const Movie & movie)
{
	list<CategorizedMovie>::iterator it = categorized_list.begin();
	while (it != categorized_list.end())
	{
		switch (category_mode)
		{
		case 1:
			if (it->category.front() == movie.genre)
			{
				return it;
			}
			break;
		case 2:
			if (it->category.front() == movie.source)
			{
				return it;
			}
			break;
		case 3:
			if (it->category.front() == movie.genre)
			{
				if (it->category.back() == movie.source)
				{
					return it;
				}
			}
			break;
		case 4:
			if (it->category.front() == movie.source)
			{
				if (it->category.back() == movie.genre)
				{
					return it;
				}
			}
			break;
		}
		it++;
	}
	return it;
}

void Pivot::AddNewCategory(const Movie & movie)
{
	CategorizedMovie new_list;
	switch (category_mode)
	{
	case 1:
		new_list.category.push_back(movie.genre);
		break;
	case 2:
		new_list.category.push_back(movie.source);
		break;
	case 3:
		new_list.category.push_back(movie.genre);
		new_list.category.push_back(movie.source);
		break;
	case 4:
		new_list.category.push_back(movie.source);
		new_list.category.push_back(movie.genre);
		break;
	}
	categorized_list.push_back(new_list);
}

Pivot::Pivot(const MovieList &movie_list)
{
	SetMode();
	Categorize(movie_list);
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
