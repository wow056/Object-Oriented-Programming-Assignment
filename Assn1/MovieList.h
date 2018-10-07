#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <list>
#include <numeric>
#include <utility>
#include <algorithm>
#include <iostream>
#include "movie.h"

using namespace std;

//class MovieList
//입력받은 Movie 정보를 분류하지 않고 그 순서대로 list에 저장함.
class MovieList
{
	friend class Pivot;
private:
	list<Movie> data;
public:
	void Add();
	void Print();
};

//class CategorizedMovie
//같은 종류의 영화끼리 모아둔 클래스
//function
class CategorizedMovie
{
private:
	static int figure_mode;//figure(1 = production, 2 = gross, 3 = rating)
	static int function_mode;//function(1 = average, 2 = sum, 3 = max, 4 = min)
	static double addMovieData(const double &accumulated, const Movie &m);//accumulate 함수를 사용하기 위한 함수, figure_mode에 따라 다른 연산을 한다.
	static bool compMovieData(const Movie &m1, const Movie &m2);//max_element, min_element 함수를 사용하기 위한 함수, figure_mode에 따라 다른 연산을 한다.
	double getMaxMovieData() const;//Chart 클래스에서 사용하기 위한 함수, figure_mode에 따라 다른 멤버의 최댓값을 구한다.
	double getMinMovieData() const;//Chart 클래스에서 사용하기 위한 함수, figure_mode에 따라 다른 멤버의 최솟값을 구한다.
public:
	bool operator<(const CategorizedMovie &p) const; //영화 종류를 앞에서부터 대소문자 상관없이 비교하는 연산자
	static void setCalculationMode(int figure_mode, int function_mode); //figure_mode와 function_mode를 설정한다.
	double getCalculationResult() const;//피벗 데이터의 계산 결과를 반환한다. function_mode가 1이면 평균, 2이면 총합, 3이면 최댓값, 4이면 최솟값을 반환한다.
	list<string> category;//저장된 영화의 카테고리
	list<Movie> movies;//저장된 영화들
};

#endif // !MOVIELIST_H

