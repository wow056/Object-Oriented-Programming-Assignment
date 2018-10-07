#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

//class Movie
//���� �⺻������ ��ȭ�� �����͸� �����صδ� Ŭ�����Դϴ�.
class Movie
{
public:
	string name;
	string genre;
	string source;
	double production;
	double gross;
	double rating;

	bool operator==(const string &input_name) const//�񱳿����ڴ� ���� �̸��� ��ȭ�� �ԷµǴ� ���� �����ϱ� ���� �����صξ����ϴ�.
	{
		return this->name == input_name;
	}
};

#endif // !MOVIE_H
