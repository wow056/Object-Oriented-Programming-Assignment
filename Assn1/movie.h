#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

//class Movie
//가장 기본적으로 영화의 데이터를 저장해두는 클래스입니다.
class Movie
{
public:
	string name;
	string genre;
	string source;
	double production;
	double gross;
	double rating;
};

#endif // !MOVIE_H
