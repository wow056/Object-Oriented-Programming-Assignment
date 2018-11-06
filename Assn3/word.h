#ifndef WORD_H
#define WORD_H

#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "player.h"

using namespace std;

//struct Position
//=========================
//This structure stores the Word, its derived classes, size of game screen and cursor in console.
//Import this class as member to calculate its position.
struct Position
{
	int x;		//Coordinate
	int y;		//Coordinate
	Position()	//Default Constructor
		:x(0), y(0), line_change_flag(false) {}
	Position(int xpos, int ypos)	//Constructor for pre-setted coordinate 
		:x(xpos), y(ypos), line_change_flag(false) {}
	bool changedLine() const		//Once increasePos is called, it sets flag. If you increase n step and cursor hit x coordinate boundary, this method return true. If not, it returns false.
	{
		return line_change_flag;
	}
	bool increasePos(const Position& boundary, int step = 1)	//Increase the position by step. It sets flag if it hit x coordinate boundary.
	{
		int temp = y * boundary.x + x;
		temp += step;
		if (temp > (boundary.x * boundary.y))
			return false;
		line_change_flag = (temp / boundary.x) > y;
		x = temp % boundary.x;
		y = temp / boundary.x;
		return true;
	}
	bool operator==(const Position &p) const	//Determine if two positions are same.
	{
		return (x == p.x) && (y == p.y);
	}
	bool operator<(const Position &p) const		//Comparision priority of y is higher than one of x. This comparison operator is useful for console cursor, because if you sort list of output in this order, you just increase cursor's position to show element of list.
	{
		if (y < p.y)
			return true;
		else if (y == p.y)
			return x < p.x;
		else
			return false;
	}
private:
	bool line_change_flag;
};

//Class Word
//=============================
//Class for object in game.
//This class is base class for the whole word object in this game.
//It also has static function to load list of words.
class Word
{
private:
	string name;		//Content of word object
	Position pos;		//Position of Word
	bool available_flag;//True when object is constructed. False when expire method is called.

	static Position find_good_place(const list<Word*> &word_list, const Position &palette_size, const int word_size = 10);	//Static function finding position not to overlap words.
protected:
	void expire() { available_flag = false; }	//Set available_flag to false;
public:
	Word(const std::string &word_loaded, const Position pos) :name(word_loaded), pos(pos), available_flag(true) {}	//The only constructor. It need string for content and positon.
	static bool load_word_file(const char *file_name, string word_source[], const int n);	//Static function load word_file to word_source array.
	static void push_word(list<Word*> &word_list, const string word_source[], int n, const Position & palette_size, const list<string> & previous_word_list);	//Select contents from word_source and set proper position from word_list and randomly construct one object Word or derived class and push this object to list.
	static void fill_word(list<Word*> &word_list, const string word_source[], const int maximum_word_num, const int n, const Position & palette_size, const list<string> & previous_word_list = list<string>());	//Call push_word until list is filled by word objects.
	
	//function object cmp_position
	//it have () operation overloading and it compares two word(or derived) object by Position.
	class cmp_position
	{
		static int count;	//To see how sort algorithm calls comparison fuction
	public:
		bool operator()(const Word *w1, const Word *w2) const
		{
			count++;
			return w1->getPos() < w2->getPos();
		}
		static int pop_count()
		{
			int return_val = count;
			count = 0;
			return return_val;
		}
	};

	//function object compare_word_with_name
	//Object is constructed with string
	//It have () operation overloading for parameter Word. This object compares content of word(or derived) object to its construction string.
	//If the content is same with its construction string, it returns true. If not, false.
	class compare_word_with_name
	{
		string name;
	public:
		compare_word_with_name(const string &name)
			:name(name) {}
		bool operator()(const Word *wp)
		{
			return wp->name == name;
		}
	};

	Position getPos() const;			//pos member accessor
	string getName() { return name; }	//name member accessor

	bool is_expired() const { return !available_flag; }	//Return true when it is popped or not available.
	int length() const;					//Calculate length of output when you call fuction print().

	virtual void update() {}				//Call when a game turn is over. Override if needed update when one game iteration is ended.
	virtual void pop(Player &player);		//Call when user's input is matches to its content. Override when object need to give different reward or penalty.
	virtual void print(ostream & os) const;	//Call when you need print object to output stream. Override when object need different appearance. base is raw name string.
};

class HealingWord : public Word
{
public:
	HealingWord(const std::string &word_loaded, const Position pos) :Word(word_loaded, pos) {}	//Constructor. Same to Word.
	virtual void print(ostream & os) const;	//(name)
	virtual void pop(Player &player);		//score reward: 1 health reward: 10
};

class BombWord : public Word
{
public:
	BombWord(const std::string &word_loaded, const Position pos) :Word(word_loaded, pos) {}	//Constructor. Same to Word.
	virtual void print(ostream & os) const;	//<name>
	virtual void pop(Player &player);		//score penalty: 2 health penalty: 20
};

class CompleteHealingWord : public Word
{
private:
	int count;	//lifespan count
public:
	CompleteHealingWord(const std::string &word_loaded, const Position pos) :Word(word_loaded, pos), count(3) {}	//Constructor. The lifespan is set to 3.
	virtual void update();					//Need update: decrease count
	virtual void print(ostream & os) const;	//((name(count)))
	virtual void pop(Player &player);		//health reward: FullHealth
};

class DeathBombWord : public Word
{
private:
	int count;	//lifespan count
public:
	DeathBombWord(const std::string &word_loaded, const Position pos) :Word(word_loaded, pos), count(3) {}	//Constructor. The lifespan is set to 3.
	virtual void update();					//Need update: decrease count
	virtual void print(ostream & os) const;	//<<name(count)>>
	virtual void pop(Player &player);		//health penalty: FullHealth
};

#endif // !WORD_H
