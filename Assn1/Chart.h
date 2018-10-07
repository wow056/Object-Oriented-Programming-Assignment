#ifndef CHART_H
#define CHART_H

#include "MovieList.h"
#include "input.h"

using namespace std;

//class chartData
//ī�װ��� �ش� ī�װ��� �ǹ� ��ȯ�� ���� ����� Ŭ����
class chartData
{
public:
	string genre;
	string source;
	double data;
};

//class Chart
//ī�װ� �з��� ��ȭ �����͸� �޾Ƽ�
//��Ʈ�� ����ϴ� �Լ�
class Chart
{
private:
	int mode;//ī�װ��� ����(1 = genre, 2 = source, 3 = genre&source, 4 = source&genre)
	list<chartData> chart_data;//��Ʈ�� ����� �����Ͱ� ����Ǿ� �ִ�.
	list<string> genre;//����ǥ�� ����� �帣
	list<string> source;//����ǥ�� ����� ��ó
	double max_val;//��Ʈ ����� ���� �ִ��� �����صд�.
	double min_val;//��Ʈ ����� ���� �ִ��� �����صд�.
	
	static bool cmpData(const chartData &l1, const chartData &l2);//max_val, min_val�� ���ϱ� ���� ������ �Լ�
	int numOfStick(const double &val) const;//����� �����͸� ��������, �ش� ���� �󸶳� �� ���� �׷����� ������ ���ϴ� �Լ�
	char get_genre_symbol(const string &key) const;//����ǥ���� �帣�� ��Ÿ���� ��ȣ�� �˷���
	int get_source_symbol(const string &key) const;//����ǥ���� ��ó�� ��Ÿ���� ��ȣ�� �˷���
	void print_body() const;//��Ʈ�� ������ �κ��� �����
	void print_legend() const;//��Ʈ�� ����ǥ �κ��� �����
	void print_genre_legend() const;//����ǥ �� �帣 �κ��� �����
	void print_source_legend() const;// ����ǥ �� ��ó �κ��� �����
public:
	Chart(const list<CategorizedMovie> &categorized_movie_list, const int &category_mode);//�з��� ��ȭ�����Ϳ� ī�װ� ������ ��� �ǹ� ��ȯ �� Ŭ������ ������ 
	void print() const;//category_mode�� ���� ��Ʈ�� �����
};

#endif

