#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <sstream>
#include <string>

//INPUT_H
//입력에 필요한 함수들이 구현되어 있습니다.

//inputInRange 함수
//input에 입력을 받은 뒤
//만약 lower <= input <= upper가 아니라면
//다시 입력을 받습니다.
//숫자가 아닌 문자가 입력될 때는
//입력 버퍼를 비운 뒤 다시 입력을 받습니다.
inline int inputInRange(const int &lower, const int &upper)
{
	int input;
	while (true)
	{
		std::cout << "Selection: ";
		std::cin >> input;
		if ((input < lower) || (input > upper))
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else
		{
			return input;
		}
	}
}

//itos 함수
//int형을 string 클래스로 변환하는 함수는
//C+11에 구현되어 있습니다.
//이전 버전에는 구현되어 있지 않아
//stringstream에 int형 데이터를 입력한 뒤
//이 값을 string으로 변환하여 반환합니다.
inline std::string itos(int i)
{
	std::ostringstream convert;
	convert << i;
	return convert.str();
}


#endif // !INPUT_H
