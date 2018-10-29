#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>
#include <list>
#include "Player.h"

using namespace std;

typedef struct
{
	int x;
	int y;
} Position;

class Word
{
private:
	static const int reward;

	string name;
	Position pos;
public:
	Word(const std::string &word_loaded, const Position pos);
	static bool load_word_file(const string &file_name, list<string> &word_source);
	static bool fill_word(list<Word*> &word_list, const list<string> &word_source);
	
	virtual void pop(Player &player) const;
	virtual void print() const;
	virtual int length() const;
	virtual friend std::ostream& operator<<(std::ostream &os, const Word & w);
};
#endif // !WORD_H