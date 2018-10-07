#include "Chart.h"

bool Chart::cmpData(const chartData & l1, const chartData & l2)
{
	return l1.data < l2.data;
}

int Chart::numOfStick(const double &val) const
{
	int result;
	double interbal = (max_val - min_val) / 20;
	if (val == max_val)
	{
		return 20;
	}
	else if (val == min_val)
	{
		return 0;
	}
	else
	{
		for (result = 0; result < 20; result++)
		{
			if (val > (interbal * result + min_val) && val <= (interbal * (result + 1) + min_val))
			{
				return result;
			}
		}
		return result;
	}
}

char Chart::get_genre_symbol(const string &key) const
{
	char genre_symbol = 'A';
	for (list<string>::const_iterator it = genre.begin(); it != genre.end(); it++)
	{
		if (*it == key)
			return genre_symbol;
		else if (genre_symbol == 'Z')
			genre_symbol = 'a';
		else
			genre_symbol++;
	}
}

int Chart::get_source_symbol(const string & key) const
{
	int source_symbol = 1;
	for (list<string>::const_iterator it = source.begin(); it != source.end(); it++)
	{
		if (*it == key)
			return source_symbol;
		else
			source_symbol++;
	}
}

void Chart::print_body() const
{
	string symbol;

	for (list<chartData>::const_iterator it = chart_data.begin(); it != chart_data.end(); it++)
	{
		switch (mode)
		{
		case 1:
			symbol = get_genre_symbol(it->genre);
			break;
		case 2:
			symbol = itos(get_source_symbol(it->source));
			break;
		case 3:
			symbol = get_genre_symbol(it->genre);
			symbol += itos(get_source_symbol(it->source));
			break;
		case 4:
			symbol = itos(get_source_symbol(it->source));
			symbol += get_genre_symbol(it->genre);
			break;
		default:
			break;
		}
		int stick_num = numOfStick(it->data);
		cout << symbol << '|';
		for (int i = 0; i < stick_num; i++)
			cout << '=';
		cout << it->data << '\n';
		if (it != chart_data.end())
		{
			if (::next(it) != chart_data.end())
			{
				switch (mode)
				{
				case 3:
					if (it->genre != ::next(it)->genre)
						cout << "  |\n";
					break;
				case 4:
					if(it->source != ::next(it)->source)
						cout << "  |\n";
					break;
				default:
					break;
				}
			}
		}
	}
}

void Chart::print_legend() const
{
	switch (mode)
	{
	default:
		break;
	case 1:
		print_genre_legend();
		break;
	case 2:
		print_source_legend();
		break;
	case 3:
		print_genre_legend();
		print_source_legend();
		break;
	case 4:
		print_source_legend();
		print_genre_legend();
		break;
	}
}

void Chart::print_genre_legend() const
{
	char genre_symbol = 'A';
	for (list<string>::const_iterator it = genre.begin(); it != genre.end(); it++)
	{
		cout << genre_symbol << ": " << *it << '\n';
		if (genre_symbol == 'Z')
			genre_symbol = 'a';
		else
			genre_symbol++;
	}
}

void Chart::print_source_legend() const
{
	int source_symbol = 1;
	for (list<string>::const_iterator it = source.begin(); it != source.end(); it++)
	{
		cout << source_symbol << ": " << *it << '\n';
		source_symbol++;
	}
}

Chart::Chart(const list<CategorizedMovie>& categorized_movie_list, const int& category_mode)
{
	if (!categorized_movie_list.empty())
	{
		mode = category_mode;
		char genre_symbol = 'A';
		int source_symbol = 0;
		string previous_genre = categorized_movie_list.front().movies.front().genre;
		string previous_source = categorized_movie_list.front().movies.front().genre;

		for (list<CategorizedMovie>::const_iterator categorized_movie_iterator = categorized_movie_list.begin(); categorized_movie_iterator != categorized_movie_list.end(); categorized_movie_iterator++)
		{
			chartData temp;
			temp.data = categorized_movie_iterator->getCalculationResult();
			switch (category_mode)
			{
			case 1:
				temp.genre = categorized_movie_iterator->category.front();
				if (find(genre.begin(), genre.end(), temp.genre) == genre.end())
				{
					genre.push_back(temp.genre);
				}
				break;
			case 2:
				temp.source = categorized_movie_iterator->category.front();
				if (find(source.begin(), source.end(), temp.source) == source.end())
				{
					source.push_back(temp.source);
				}
				break;
			case 3:
				temp.genre = categorized_movie_iterator->category.front();
				temp.source = categorized_movie_iterator->category.back();
				if (find(genre.begin(), genre.end(), temp.genre) == genre.end())
				{
					genre.push_back(temp.genre);
				}
				if (find(source.begin(), source.end(), temp.source) == source.end())
				{
					source.push_back(temp.source);
				}
				break;
			case 4:
				temp.source = categorized_movie_iterator->category.front();
				temp.genre = categorized_movie_iterator->category.back();
				if (find(genre.begin(), genre.end(), temp.genre) == genre.end())
				{
					genre.push_back(temp.genre);
				}
				if (find(source.begin(), source.end(), temp.source) == source.end())
				{
					source.push_back(temp.source);
				}
				break;
			}
			chart_data.push_back(temp);
			max_val = max_element(chart_data.begin(), chart_data.end(), cmpData)->data;
			min_val = min_element(chart_data.begin(), chart_data.end(), cmpData)->data;
		}
	}
}

void Chart::print() const
{
	print_body();
	cout << "-------------------------" << endl;
	print_legend();
}
