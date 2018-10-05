#ifndef CHART_H
#define CHART_H

#include "MovieList.h"
#include "input.h"

class chartData
{
public:
	string genre;
	string source;
	double data;
};

class Chart
{
private:
	int mode;
	list<chartData> chart_data;
	list<string> genre;
	list<string> source;
	double max_val;
	double min_val;
	
	static bool cmpData(const chartData &l1, const chartData &l2);
	int numOfStick(const double &val) const;
	char get_genre_symbol(const string &key) const;
	int get_source_symbol(const string &key) const;
	void print_body() const;
	void print_legend() const;
	void print_genre_legend() const;
	void print_source_legend() const;
public:
	Chart(const list<CategorizedMovie> &categorized_movie_list, const int &category_mode);
	void print() const;
};

#endif