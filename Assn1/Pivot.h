#ifndef PIVOT_H
#define PIVOT_H

#include "Chart.h"
#include "MovieList.h"
#include "input.h"

//class Pivot
//영화 정보를 카테고리별로 저장해둔 뒤
//피벗 변환한 뒤
//표와 차트를 출력한다.
class Pivot
{
private:
	int category_mode;//category(1 = genre, 2 = source, 3 = genre&source, 4 = source&genre)
	int figure_mode;//figure(1 = production, 2 = gross, 3 = rating)
	int function_mode;//function(1 = average, 2 = sum, 3 = max, 4 = min)
	list<CategorizedMovie> categorized_list;//저장된 피벗 데이터.

	void SetMode();//category, figure, function을 유저가 선택하도록 한다.
	void Categorize(const MovieList &movie_list);//category에 따라 영화를 분류한다.

	list<CategorizedMovie>::iterator FindCategory(const Movie &movie);//categorized_list에 해당 영화의 카테고리를 찾아 해당 카테고리의 iterator를 반환한다. 존재하지 않으면 end iterator를 반환한다.
	void AddNewCategory(const Movie &movie);//categorized_list에 해당 영화의 카테고리를 추가한다.
public:
	Pivot(const MovieList &movie_list);//SetMode()를 실행해 카테고리, 데이터 종류, 계산 종류를 선택받은 뒤, Categorize로 카테고리에 따라 영화를 분류한다.
	void ShowTable() const;//피벗 표를 출력한다.
	void ShowChart() const;//피벗 차트를 출력한다.
};

#endif // !PIVOT_H

