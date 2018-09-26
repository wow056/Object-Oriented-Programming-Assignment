#ifndef PIVOT_H
#define PIVOT_H

#include "Chart.h"
#include "MovieList.h"
#include "input.h"

class Pivot
{
private:
	int category_mode;
	int figure_mode;
	int function_mode;
	list<CategorizedMovie> categorized_list;
public:
	void SetMode();
	void Categorize(const MovieList &movie_list);
	void ShowTable();
	void ShowChart() const;
};

#endif // !PIVOT_H

