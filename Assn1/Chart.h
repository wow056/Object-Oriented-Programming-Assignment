#ifndef CHART_H
#define CHART_H

#include "MovieList.h"
#include "input.h"

using namespace std;

//class chartData
//카테고리와 해당 카테고리를 피벗 변환한 값이 저장된 클래스
class chartData
{
public:
	string genre;
	string source;
	double data;
};

//class Chart
//카테고리 분류된 영화 데이터를 받아서
//차트를 출력하는 함수
class Chart
{
private:
	int mode;//카테고리의 종류(1 = genre, 2 = source, 3 = genre&source, 4 = source&genre)
	list<chartData> chart_data;//차트에 출력할 데이터가 저장되어 있다.
	list<string> genre;//색인표에 출력할 장르
	list<string> source;//색인표에 출력할 출처
	double max_val;//차트 출력을 위해 최댓값을 저장해둔다.
	double min_val;//차트 출력을 위해 최댓값을 저장해둔다.
	
	static bool cmpData(const chartData &l1, const chartData &l2);//max_val, min_val을 구하기 위해 정의한 함수
	int numOfStick(const double &val) const;//저장된 데이터를 기준으로, 해당 값이 얼마나 긴 막대 그래프를 갖는지 구하는 함수
	char get_genre_symbol(const string &key) const;//색인표에서 장르를 나타내는 기호를 알려줌
	int get_source_symbol(const string &key) const;//색인표에서 출처를 나타내는 기호룰 알려줌
	void print_body() const;//차트의 데이터 부분을 출력함
	void print_legend() const;//차트의 색인표 부분을 출력함
	void print_genre_legend() const;//색인표 중 장르 부분을 출력함
	void print_source_legend() const;// 색인표 중 출처 부분을 출력함
public:
	Chart(const list<CategorizedMovie> &categorized_movie_list, const int &category_mode);//분류된 영화데이터와 카테고리 정보를 얻어 피벗 변환 후 클래스에 저장함 
	void print() const;//category_mode에 따라 차트를 출력함
};

#endif

