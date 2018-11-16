#ifndef FOOD
#define FOOD

#include <ostream>
#include <string>

class Food
{
public:
	enum Base {
		Dough = 0x001,
		Espresso = 0x002
	};
	enum Ingredient {
		Pepperoni = 0x010,
		Potato = 0x020,
		Shrimp = 0x040,
		Water = 0x080,
		MilkFoam = 0x100
	};
	
	static void set_output_stream(std::ostream *out_stream);

	bool provide() const;

	virtual int num_of_selection() = 0;
	virtual void add_base(Base base) = 0;
	virtual void add_ingredient(Ingredient ingredient) = 0;
	virtual void print_name() const;
protected:
	enum Error {
		BaseAlready,
		BaseWrong,
		IngredientFirst,
		IngredientRepeat,
		IngredientWrong
	};

	Food(const std::string & food_name);

	static std::ostream *out;

	static void print_error(Error error, int foodstuff);
	static std::string food_name(int food_const);

	void set_ingredient_flag(bool & ingredient_flag, int ingredient_enum);

	virtual bool base_complete() const = 0;
	virtual bool ingredient_complete() const = 0;
private:
	std::string name;
};

class Pizza :public Food
{
private:
	bool dough;
protected:
	Pizza(const std::string & food_name);
	virtual bool base_complete() const;
public:
	virtual void add_base(Base base);
};

class Coffee : public Food
{
private:
	bool espresso;
protected:
	Coffee(const std::string & food_name);
	virtual bool base_complete() const;
public:
	virtual void add_base(Base base);
};

class Pepperoni :public Pizza
{
private:
	bool pepperoni;
protected:
	virtual bool ingredient_complete() const;
public:
	Pepperoni();
	virtual int num_of_selection();
	virtual void add_ingredient(Ingredient ingredient);
};

class Potato :public Pizza
{
private:
	bool potato;
protected:
	virtual bool ingredient_complete() const;
public:
	Potato();
	virtual int num_of_selection();
	virtual void add_ingredient(Ingredient ingredient);
};

class Shrimp :public Pizza
{
private:
	bool pepperoni;
	bool shrimp;
protected:
	virtual bool ingredient_complete() const;
public:
	Shrimp();
	virtual int num_of_selection();
	virtual void add_ingredient(Ingredient ingredient);
};

class Americano : public Coffee
{
private:
	bool water;
protected:
	virtual bool ingredient_complete() const;
public:
	Americano();
	virtual int num_of_selection();
	virtual void add_ingredient(Ingredient ingredient);
};

class Macchiato : public Coffee
{
private:
	bool milk_foam;
protected:
	virtual bool ingredient_complete() const;
public:
	Macchiato();
	virtual int num_of_selection();
	virtual void add_ingredient(Ingredient ingredient);
};

#endif // !FOOD