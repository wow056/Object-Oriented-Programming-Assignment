#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <list>
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

struct pivotList
{
public:
	list<string> type;
	list<Movie> data;
};

typedef pivotList PivotList;

#endif // !TYPES_H

