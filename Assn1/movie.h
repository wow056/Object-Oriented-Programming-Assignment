#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie
{
public:
	string name;
	string genre;
	string source;
	double production;
	double gross;
	double rating;

	bool operator==(const Movie &mov)
	{
		return this->name == mov.name;
	}
};

#endif // !MOVIE_H
