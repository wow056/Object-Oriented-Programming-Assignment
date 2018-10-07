#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <sstream>
#include <string>

//INPUT_H
//�Է¿� �ʿ��� �Լ����� �����Ǿ� �ֽ��ϴ�.

//inputInRange �Լ�
//input�� �Է��� ���� ��
//���� lower <= input <= upper�� �ƴ϶��
//�ٽ� �Է��� �޽��ϴ�.
//���ڰ� �ƴ� ���ڰ� �Էµ� ����
//�Է� ���۸� ��� �� �ٽ� �Է��� �޽��ϴ�.
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

//itos �Լ�
//int���� string Ŭ������ ��ȯ�ϴ� �Լ���
//C+11�� �����Ǿ� �ֽ��ϴ�.
//���� �������� �����Ǿ� ���� �ʾ�
//stringstream�� int�� �����͸� �Է��� ��
//�� ���� string���� ��ȯ�Ͽ� ��ȯ�մϴ�.
inline std::string itos(int i)
{
	std::ostringstream convert;
	convert << i;
	return convert.str();
}


#endif // !INPUT_H
