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

	bool operator==(const string &input_name) const//비교연산자는 같은 이름의 영화가 입력되는 것을 방지하기 위해 구현해두었습니다.
	{
		return this->name == input_name;
	}
};

#endif // !MOVIE_H
