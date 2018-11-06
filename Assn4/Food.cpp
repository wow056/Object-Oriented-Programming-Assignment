#include "Food.h"

#include <string>
#include <iostream>

using namespace std;

bool Food::provide()
{
	return data == complete_data;
}

void Food::add_base(int foodstuff)
{
	if (is_base(foodstuff))
	{
		set_data(foodstuff);
	}
	else
	{
		print_error(Error::)
	}
}

bool Food::is_base(int input)
{
	return (Base::Dough|Base::Espresso) & input;
}

void Food::set_data(int input)
{
	if (data | input)
	{
		if ((input | Base::Dough) || (input | Base::Espresso))
		{
			print_error(Error::BaseAlready, input);
		}
		else
		{
			print_error(Error::IngredientRepeat, input);
		}
	}
	else
	{
		data |= input;
	}
}

void Food::print_error(Error error, int input_food)
{
	string input;
	switch (input_food)
	{
	case Food::Pepperoni:
		input = "Pepperoni";
		break;
	case Food::Potato:
		input = "Potato";
		break;
	case Food::Shrimp:
		input = "Shrimp";
		break;
	case Food::Water:
		input = "Water";
		break;
	case Food::MilkFoam:
		input = "Milk Foam";
		break;
	case Food::Dough:
		input = "Pizza Dough";
		break;
	case Food::Espresso:
		input = "Espresso";
		break;
	}
	cout << "[Wrong] ";
	switch (error)
	{
	case Food::BaseAlready:
		cout << "You already added base " << '[' << input << ']';
		break;
	case Food::BaseWrong:
		cout << "Wrong Base";
		break;
	case Food::IngredientFirst:
		cout << "Select Base First";
		break;
	case Food::IngredientRepeat:
		cout << "You already added ingredient " << '[' << input << ']';
		break;
	case Food::IngredientWrong:
		cout << "You should not add ingredient " << '[' << input << ']';
		break;
	}
	cout << endl;
}

void Pizza::add_base(int foodstuff)
{
	if (foodstuff | Base::Dough)
	{
		set_data(foodstuff);
	}
	else
	{
		print_error(Error::BaseWrong, foodstuff);
	}
}

void Coffee::add_base(int foodstuff)
{
	if (foodstuff | Base::Espresso)
	{
		set_data(foodstuff);
	}
	else
	{
		print_error(Error::BaseWrong, foodstuff);
	}
}

void Pepperoni::add_ingredient(int foodstuff)
{
	if (is_base(foodstuff))
	{
		print_error(Error::IngredientFirst, foodstuff);
	}
	else if (foodstuff | Ingredient::Pepperoni)
	{
		set_data(foodstuff);
	}
	else
	{
		print_error(Error::IngredientWrong, foodstuff);
	}
}

bool Pepperoni::provide()
{
	return (Base::Dough | Ingredient::Pepperoni) & data;
}
