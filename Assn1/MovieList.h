#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <list>
#include <numeric>
#include <utility>
#include <algorithm>
#include <iostream>
#include "movie.h"

class MovieList
{
private:
public:
	list<Movie> data;
	void Add();
	void Print();
};

class CategorizedMovie
{
private:
	static int figure_mode;
	static int function_mode;
	static double addMovieData(const double &accumulated, const Movie &m);
	static bool compMovieData(const Movie &m1, const Movie &m2);
	double getMaxMovieData() const;
	double getMinMovieData() const;
public:
	bool operator<(const CategorizedMovie &p) const;
	static void setCalculationMode(int figure_mode, int function_mode);
	double getCalculationResult() const;
	int getFigureMode() const;
	list<string> category;
	list<Movie> movies;
};

#endif // !MOVIELIST_H

