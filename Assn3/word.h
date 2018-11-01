#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "player.h"

using namespace std;

struct Position
{
	int x;
	int y;
	Position()
		:x(0), y(0), line_change_flag(false) {}
	Position(int xpos, int ypos)
		:x(xpos), y(ypos), line_change_flag(false) {}
	bool changedLine() const
	{
		return line_change_flag;
	}
	bool increasePos(int step, const Position& boundary)
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
	bool operator==(const Position &p) const
	{
		return (x == p.x) && (y == p.y);
	}
	bool operator<(const Position &p) const
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


class Word
{
private:
	
	string name;
	Position pos;
	bool available_flag;

	friend class compare_word_with_name;
	static Position find_good_place(const list<Word*> &word_list, const Position &palette_size, const int word_size = 10);
protected:
	virtual void expire() { available_flag = false; }
public:
	Word(const std::string &word_loaded, const Position pos) :name(word_loaded), pos(pos), available_flag(true) {}
	static bool load_word_file(const char *file_name, string word_source[], const int n);
	static void push_word(list<Word*> &word_list, const string word_source[], int n, const Position & palette_size, const list<string> & previous_word_list = list<string>());
	static void fill_word(list<Word*> &word_list, const string word_source[], const int maximum_word_num, const int n, const Position & palette_size, const list<string> & previous_word_list = list<string>());
	class cmp_position
	{
		static int count;
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

	virtual string getName() { return name; }
	virtual void decreaseCount() {}
	virtual bool vanished() const { return !available_flag; }
	virtual const Position& getPos() const;
	virtual int length() const;
	virtual void pop(Player &player);
	virtual void print(ostream & os) const;
};

class HealingWord : public Word
{
public:
	HealingWord(const std::string &word_loaded, const Position pos) :Word(word_loaded, pos) {}
	virtual int length() const;
	virtual void print(ostream & os) const;
	virtual void pop(Player &player);
};

class BombWord : public Word
{
public:
	BombWord(const std::string &word_loaded, const Position pos) :Word(word_loaded, pos) {}
	virtual int length() const;
	virtual void print(ostream & os) const;
	virtual void pop(Player &player);
};

class CompleteHealingWord : public HealingWord
{
private:
	int count;
public:
	CompleteHealingWord(const std::string &word_loaded, const Position pos) :HealingWord(word_loaded, pos), count(3) {}
	virtual int length() const;
	virtual void decreaseCount();
	virtual bool vanished() const;
	virtual void print(ostream & os) const;
	virtual void pop(Player &player);
};

class DeathBombWord : public BombWord
{
private:
	int count;
public:
	DeathBombWord(const std::string &word_loaded, const Position pos) :BombWord(word_loaded, pos), count(3) {}
	virtual int length() const;
	virtual void decreaseCount();
	virtual bool vanished() const;
	virtual void print(ostream & os) const;
	virtual void pop(Player &player);
};

#endif // !WORD_H
