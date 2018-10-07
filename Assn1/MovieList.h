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
//�Է¹��� Movie ������ �з����� �ʰ� �� ������� list�� ������.
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
//���� ������ ��ȭ���� ��Ƶ� Ŭ����
//function
class CategorizedMovie
{
private:
	static int figure_mode;//figure(1 = production, 2 = gross, 3 = rating)
	static int function_mode;//function(1 = average, 2 = sum, 3 = max, 4 = min)
	static double addMovieData(const double &accumulated, const Movie &m);//accumulate �Լ��� ����ϱ� ���� �Լ�, figure_mode�� ���� �ٸ� ������ �Ѵ�.
	static bool compMovieData(const Movie &m1, const Movie &m2);//max_element, min_element �Լ��� ����ϱ� ���� �Լ�, figure_mode�� ���� �ٸ� ������ �Ѵ�.
	double getMaxMovieData() const;//Chart Ŭ�������� ����ϱ� ���� �Լ�, figure_mode�� ���� �ٸ� ����� �ִ��� ���Ѵ�.
	double getMinMovieData() const;//Chart Ŭ�������� ����ϱ� ���� �Լ�, figure_mode�� ���� �ٸ� ����� �ּڰ��� ���Ѵ�.
public:
	bool operator<(const CategorizedMovie &p) const; //��ȭ ������ �տ������� ��ҹ��� ������� ���ϴ� ������
	static void setCalculationMode(int figure_mode, int function_mode); //figure_mode�� function_mode�� �����Ѵ�.
	double getCalculationResult() const;//�ǹ� �������� ��� ����� ��ȯ�Ѵ�. function_mode�� 1�̸� ���, 2�̸� ����, 3�̸� �ִ�, 4�̸� �ּڰ��� ��ȯ�Ѵ�.
	list<string> category;//����� ��ȭ�� ī�װ�
	list<Movie> movies;//����� ��ȭ��
};

#endif // !MOVIELIST_H

