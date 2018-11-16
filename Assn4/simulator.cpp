#include "simulator.h"
#include "food.h"
#include "clear.h"
#include <climits>
#include <cstdlib>

using namespace std;

Simulator::Simulator(std::ostream *output_stream, std::istream *input_stream)
	:out(*output_stream), in(*input_stream), correct_food(0), min_selection(0), start_time(0), user_selection(0)
{
	Food::set_output_stream(output_stream);
	srand(time(NULL));
}

void Simulator::start()
{
	select_mode();
	load_list();

	start_time = time(NULL);
	refreshScreen();
	main_loop();

	system(CLEAR);
	printResult();
}

void Simulator::main_loop()
{
	do
	{
		action(select_action());
	} while (!order_list.empty());
}

void Simulator::select_mode()
{
	int input;
	out << "<Food Truck Simulation>" << endl;
	out << "Mode 1: Static Order List" << endl;
	out << "Mode 2: Random Order List" << endl;
	while (true)
	{
		out << "Choose simulation mode: ";
		in >> input;
		if (in.fail() || (input != 1 && input != 2))
		{
			out << "error" << endl;
			in.clear();
			in.ignore(INT_MAX, '\n');
		}
		else
		{
			break;
		}
	}
	mode = input;
}

void Simulator::load_list()
{
	if (mode == 1)
	{
		order_list.push_back(new Pepperoni);
		order_list.push_back(new Potato);
		order_list.push_back(new Shrimp);
		order_list.push_back(new Americano);
		order_list.push_back(new Macchiato);
	}
	else if (mode == 2)
	{
		while (order_list.size() < MaxOrderList)
		{
			switch (rand() % 5)
			{
			case 0:
				order_list.push_back(new Pepperoni);
				break;
			case 1:
				order_list.push_back(new Potato);
				break;
			case 2:
				order_list.push_back(new Shrimp);
				break;
			case 3:
				order_list.push_back(new Americano);
				break;
			case 4:
				order_list.push_back(new Macchiato);
				break;
			}
		}
	}
}

void Simulator::refreshScreen() const
{
	system(CLEAR);
	printOrderList();
	out << endl;
	printActionList();
	out << endl;
	out << "<User Command>" << endl;
}

void Simulator::printOrderList() const
{
	list<Food*>::const_iterator it;
	int print_count = 0;
	out << "[ ";
	for (it = order_list.begin(); it != order_list.end(); it++)
	{
		(*it)->print_name();
		out << '\t';
		print_count++;
	}
	for (; print_count < MaxOrderList; print_count++)
	{
		out << "\t\t";
	}
	out << " ]" << endl;

}

void Simulator::printActionList() const
{
	out << "<Action List>" << endl;
	out << "1. Prepare base [Pizza Dough]" << endl;
	out << "2. Add ingredient [Pepperoni]" << endl;
	out << "3. Add ingredient [Potato]" << endl;
	out << "4. Add ingredient [Shrimp]" << endl;
	out << "5. Prepare base [Espresso]" << endl;
	out << "6. Add ingredient [Water]" << endl;
	out << "7. Add ingredient [Milk Foam]" << endl;
	out << "8. [Provide Food]" << endl;
}

int Simulator::select_action() const
{
	int input;
	while (true)
	{
		out << "Choose your action: ";
		in >> input;
		if (in.fail() || input < 1 || input > 8)
		{
			out << "error" << endl;
			in.clear();
			in.ignore(INT_MAX, '\n');
		}
		else
		{
			break;
		}
	}
	return input;
}

void Simulator::action(int action_num)
{
	Food &it = *(order_list.front());

	user_selection++;
	switch (action_num)
	{
	case 1:
		it.add_base(Food::Base::Dough);
		break;
	case 2:
		it.add_ingredient(Food::Ingredient::Pepperoni);
		break;
	case 3:
		it.add_ingredient(Food::Ingredient::Potato);
		break;
	case 4:
		it.add_ingredient(Food::Ingredient::Shrimp);
		break;
	case 5:
		it.add_base(Food::Base::Espresso);
		break;
	case 6:
		it.add_ingredient(Food::Ingredient::Water);
		break;
	case 7:
		it.add_ingredient(Food::Ingredient::MilkFoam);
		break;
	case 8:
		provide();
		user_selection--;
		refreshScreen();
		break;
	}
}

void Simulator::provide()
{
	Food *it = order_list.front();
	if (it->provide())
		correct_food++;
	min_selection += it->num_of_selection();

	//memory deallocation
	delete it;
	order_list.pop_front();
}

void Simulator::printResult() const
{
	out << "<Result>" << endl;
	out << "# of correctly provided food: " << correct_food << endl;
	out << "# of wronly provided food: " << MaxOrderList - correct_food << endl;
	out << "Minimum # of selection: " << min_selection << endl;
	out << "Your # of selection: " << user_selection << endl;
	out << "Time you spent: " << time(NULL) - start_time << endl;
}

