#include "food.h"

#include <iostream>

using namespace std;

ostream * Food::out = &cout;

void Food::set_output_stream(std::ostream * out_stream)
{
	out = out_stream;
}

void Food::set_ingredient_flag(bool & ingredient_flag, int ingredient_enum)
{
	if (base_complete())
	{
		if (ingredient_flag)
		{
			print_error(Error::IngredientRepeat, ingredient_enum);
		}
		else
		{
			ingredient_flag = true;
			*out << ": You added ingredient [" << food_name(ingredient_enum) << "]" << endl;
		}
	}
	else
	{
		print_error(Error::IngredientFirst, ingredient_enum);
	}
}

void Food::print_error(Error error, int foodstuff)
{
	string output_food = food_name(foodstuff);
	*out << ": [Wrong] ";
	switch (error)
	{
	case Food::BaseAlready:
		*out << "You already added base [" << output_food << ']';
		break;
	case Food::BaseWrong:
		*out << "Wrong Base";
		break;
	case Food::IngredientFirst:
		*out << "Select Base First";
		break;
	case Food::IngredientRepeat:
		*out << "You already added ingredient [" << output_food << ']';
		break;
	case Food::IngredientWrong:
		*out << "You should not add ingredient [" << output_food << ']';
		break;
	}
	*out << endl;
}

string Food::food_name(int food_const)
{
	switch (food_const)
	{
	case Food::Pepperoni:
		return "Pepperoni";
	case Food::Potato:
		return "Potato";
	case Food::Shrimp:
		return "Shrimp";
	case Food::Water:
		return "Water";
	case Food::MilkFoam:
		return "Milk Foam";
	case Food::Dough:
		return "Pizza Dough";
	case Food::Espresso:
		return "Espresso";
	}
}


Pepperoni::Pepperoni()
	:Pizza("PepperoniPizza"), pepperoni(false) {}

int Pepperoni::num_of_selection()
{
	return 2;
}

void Pepperoni::add_ingredient(Ingredient ingredient)
{
	switch (ingredient)
	{
	case Food::Pepperoni:
		set_ingredient_flag(pepperoni, ingredient);
		break;
	case Food::Potato:
	case Food::Shrimp:
	case Food::Water:
	case Food::MilkFoam:
		print_error(Error::IngredientWrong, ingredient);
		break;
	}
}

bool Food::provide() const
{
	return ingredient_complete() && base_complete();
}

void Food::print_name() const
{
	*out << name;
}

Food::Food(const std::string & food_name)
	:name(food_name) {}

bool Pepperoni::ingredient_complete() const
{
	return pepperoni;
}

Pizza::Pizza(const std::string & food_name)
	:Food(food_name), dough(false) {}

bool Pizza::base_complete() const
{
	return dough;
}

void Pizza::add_base(Base base)
{
	switch (base)
	{
	case Food::Dough:
		if (base_complete())
		{
			print_error(Error::BaseAlready, base);
		}
		else
		{
			dough = true;
			*out << ": You added base [Pizza Dough]" << endl;
		}
		break;
	case Food::Espresso:
		print_error(Error::BaseWrong, base);
		break;
	}
}

Coffee::Coffee(const std::string & food_name)
	:Food(food_name), espresso(false) {}

bool Coffee::base_complete() const
{
	return espresso;
}

void Coffee::add_base(Base base)
{
	switch (base)
	{
	case Food::Dough:
		print_error(Error::BaseWrong, base);
		break;
	case Food::Espresso:
		if (base_complete())
		{
			print_error(Error::BaseAlready, base);
		}
		else
		{
			espresso = true;
			*out << ": You added base [Espresso]" << endl;
		}
		break;
	}
}

bool Potato::ingredient_complete() const
{
	return potato;
}

Potato::Potato()
	:Pizza("PotatoPizza"), potato(false) {}

int Potato::num_of_selection()
{
	return 2;
}

void Potato::add_ingredient(Ingredient ingredient)
{
	switch (ingredient)
	{
	case Food::Potato:
		set_ingredient_flag(potato, ingredient);
		break;
	case Food::Shrimp:
	case Food::Water:
	case Food::MilkFoam:
	case Food::Pepperoni:
		print_error(Error::IngredientWrong, ingredient);
		break;
	}
}

bool Shrimp::ingredient_complete() const
{
	return pepperoni && shrimp;
}

Shrimp::Shrimp()
	:Pizza("ShrimpPizza"), pepperoni(false), shrimp(false) {}

int Shrimp::num_of_selection()
{
	return 3;
}

void Shrimp::add_ingredient(Ingredient ingredient)
{
	switch (ingredient)
	{
	case Food::Pepperoni:
		set_ingredient_flag(pepperoni, ingredient);
			break;
	case Food::Shrimp:
		set_ingredient_flag(shrimp, ingredient);
			break;
	case Food::Potato:
	case Food::Water:
	case Food::MilkFoam:
		print_error(Error::IngredientWrong, ingredient);
		break;
	}
}

bool Americano::ingredient_complete() const
{
	return water;
}

Americano::Americano()
	:Coffee("Americano"), water(false) {}

int Americano::num_of_selection()
{
	return 2;
}

void Americano::add_ingredient(Ingredient ingredient)
{
	switch (ingredient)
	{
	case Food::Water:
		set_ingredient_flag(water, ingredient);
		break;
	case Food::Pepperoni:
	case Food::Potato:
	case Food::Shrimp:
	case Food::MilkFoam:
		print_error(Error::IngredientWrong, ingredient);
		break;
	}
}

bool Macchiato::ingredient_complete() const
{
	return milk_foam;
}

Macchiato::Macchiato()
	:Coffee("Macchiato"), milk_foam(false) {}

int Macchiato::num_of_selection()
{
	return 2;
}

void Macchiato::add_ingredient(Ingredient ingredient)
{
	switch (ingredient)
	{
	case Food::MilkFoam:
		set_ingredient_flag(milk_foam,ingredient);
		break;
	case Food::Pepperoni:
	case Food::Potato:
	case Food::Shrimp:
	case Food::Water:
		print_error(Error::IngredientWrong, ingredient);
		break;
	default:
		break;
	}
}
