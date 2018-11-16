#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <list>
#include <ctime>
#include <iostream>

class Food;

class Simulator
{
private:
	std::list<Food*> order_list;
	std::ostream &out;
	std::istream &in;

	enum
	{
		MaxOrderList=5
	};

	
	time_t start_time;
	int correct_food;
	int user_selection;
	int min_selection;
	int mode;

	void select_mode();
	void load_list();
	void refreshScreen() const;
	void printOrderList() const;
	void printActionList() const;
	int select_action() const;
	void action(int action_num);
	void provide();

	void main_loop();
	void printResult() const;
public:
	Simulator(std::ostream *output_stream = &std::cout, std::istream *input_stream = &std::cin);
	void start();
};

#endif // !SIMULATOR_H
