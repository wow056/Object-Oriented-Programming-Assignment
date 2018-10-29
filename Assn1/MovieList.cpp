#include "MovieList.h"

int CategorizedMovie::figure_mode;
int CategorizedMovie::function_mode;

void MovieList::Add()
{
	Movie input_data;

	cout << "Name: ";
	cin >> input_data.name;
	cout << "Genre: ";
	cin >> input_data.genre;
	cout << "Source: ";
	cin >> input_data.source;
	cout << "Production: ";
	cin >> input_data.production;
	cout << "Gross: ";
	cin >> input_data.gross;
	cout << "Rating: ";
	cin >> input_data.rating;

	if (find_if(data.begin(), data.end(), MovieNameComparer(input_data)) == data.end())
	{
		data.push_back(input_data);
		cout << "Movie is added!" << endl;
	}
	else
	{
		cout << "Movie name already exists" << endl;
	}
}

void MovieList::Print()
{
	cout << "Name\tGenre\tSource\tProduction\tGross\tRating\n";
	for (list<Movie>::iterator it = data.begin(); it != data.end(); it++)
	{
		cout << it->name << "\t"
			<< it->genre << "\t"
			<< it->source << "\t"
			<< it->production << "\t"
			<< it->gross << "\t"
			<< it->rating << "\n";
	}
}


void CategorizedMovie::setCalculationMode(int figure_mode, int function_mode)
{
	CategorizedMovie::figure_mode = figure_mode;
	CategorizedMovie::function_mode = function_mode;
}

double CategorizedMovie::addMovieData(const double & accumulated, const Movie & m)
{
	switch (figure_mode)
	{
	case 1:
		return accumulated + m.production;
	case 2:
		return accumulated + m.gross;
	case 3:
		return accumulated + m.rating;
	default:
		return accumulated;
	}
}

bool CategorizedMovie::compMovieData(const Movie & m1, const Movie & m2)
{
	switch (figure_mode)
	{
	case 1:
		return m1.production < m2.production;
	case 2:
		return m1.gross < m2.gross;
	case 3:
		return m1.rating < m2.rating;
	default:
		return false;
	}
}

double CategorizedMovie::getMaxMovieData() const
{
	list<Movie>::const_iterator it = max_element(movies.begin(), movies.end(), compMovieData);
	switch (figure_mode)
	{
	default:
		return 0.0;
	case 1:
		return it->production;
	case 2:
		return it->gross;
	case 3:
		return it->rating;
	}
}

double CategorizedMovie::getMinMovieData() const
{
	list<Movie>::const_iterator it = min_element(movies.begin(), movies.end(), compMovieData);
	switch (figure_mode)
	{
	default:
		return 0.0;
	case 1:
		return it->production;
	case 2:
		return it->gross;
	case 3:
		return it->rating;
	}
}



double CategorizedMovie::getCalculationResult() const
{
	switch (function_mode)
	{
	default:
		return 0.0;
	case 1:
		return accumulate(movies.begin(), movies.end(), 0.0, addMovieData) / movies.size();
	case 2:
		return accumulate(movies.begin(), movies.end(), 0.0, addMovieData);
	case 3:
		return getMaxMovieData();
	case 4:
		return getMinMovieData();
	}
}

bool CategorizedMovie::operator<(const CategorizedMovie & p) const
{
	list<string>::const_iterator it1 = this->category.begin();
	list<string>::const_iterator it2 = p.category.begin();
	string s1_lower;
	string s2_lower;
	while (it1 != this->category.end())
	{
		s1_lower.resize(it1->length());
		s2_lower.resize(it2->length());
		transform(it1->begin(), it1->end(), s1_lower.begin(), ::tolower);
		transform(it2->begin(), it2->end(), s2_lower.begin(), ::tolower);
		if (s1_lower.compare(s2_lower) >= 0)
		{
			return false;
		}
		it1++;
		it2++;
	}
	return true;
}

