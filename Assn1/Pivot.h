#ifndef PIVOT_H
#define PIVOT_H

#include "Chart.h"
#include "MovieList.h"
#include "input.h"

//class Pivot
//��ȭ ������ ī�װ����� �����ص� ��
//�ǹ� ��ȯ�� ��
//ǥ�� ��Ʈ�� ����Ѵ�.
class Pivot
{
private:
	int category_mode;//category(1 = genre, 2 = source, 3 = genre&source, 4 = source&genre)
	int figure_mode;//figure(1 = production, 2 = gross, 3 = rating)
	int function_mode;//function(1 = average, 2 = sum, 3 = max, 4 = min)
	list<CategorizedMovie> categorized_list;//����� �ǹ� ������.

	void SetMode();//category, figure, function�� ������ �����ϵ��� �Ѵ�.
	void Categorize(const MovieList &movie_list);//category�� ���� ��ȭ�� �з��Ѵ�.

	list<CategorizedMovie>::iterator FindCategory(const Movie &movie);//categorized_list�� �ش� ��ȭ�� ī�װ��� ã�� �ش� ī�װ��� iterator�� ��ȯ�Ѵ�. �������� ������ end iterator�� ��ȯ�Ѵ�.
	void AddNewCategory(const Movie &movie);//categorized_list�� �ش� ��ȭ�� ī�װ��� �߰��Ѵ�.
public:
	Pivot(const MovieList &movie_list);//SetMode()�� ������ ī�װ�, ������ ����, ��� ������ ���ù��� ��, Categorize�� ī�װ��� ���� ��ȭ�� �з��Ѵ�.
	void ShowTable() const;//�ǹ� ǥ�� ����Ѵ�.
	void ShowChart() const;//�ǹ� ��Ʈ�� ����Ѵ�.
};

#endif // !PIVOT_H

