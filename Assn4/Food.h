#ifndef FOOD
#define FOOD

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
	enum Error {
		BaseAlready,
		BaseWrong,
		IngredientFirst,
		IngredientRepeat,
		IngredientWrong
	};

	Food(int completeBaseIngredient)
		:data(0), complete_data(completeBaseIngredient) {}
	bool provide();

	void add_base(int foodstuff);
	virtual void add_ingredient(int foodstuff) = 0;
protected:
	bool is_base(int input);
	void set_data(int input);
	void print_error(Error error, int input_food);
private:
	int data;
	int complete_data;
};

class Pizza :public Food
{
public:
	Pizza(int completeIngredient)
		:Food(Base::Dough | completeIngredient) {}
	virtual void add_base(int foodstuff);
};

class Coffee : public Food
{
public:
	Coffee(int completeIngredient)
		:Food(Base::Dough | completeIngredient) {}
	virtual void add_base(int foodstuff);
};

class Pepperoni :public Pizza
{
public:
	Pepperoni()
		:Pizza() {}
	virtual void add_ingredient(int foodstuff);
	virtual bool provide();
};


#endif // !FOOD