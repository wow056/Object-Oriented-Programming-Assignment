#ifndef GAME_H
#define GAME_H


#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "player.h"
#include "word.h"

#if _WIN32

const char CLEAR[4] = "cls";

#elif __unix__

const char CLEAR[6] = "clear";

#endif

using namespace std;


class Game
{
private:
	ostream *output_stream;
	istream *input_stream;
	enum { LoadedWordCount = 20, InGameWordCount = 10 };
	static const char *WordListFileName;
	const Position palette_size;
	string* word_source;
	list<Word*> word_list;
	Player player;

	void main_loop();
	void printScreen() const;
	void showPalette() const;
	void update_list(list<string> &previous_word_list);
public:
	Game(ostream &game_output_stream, istream &game_input_stream);
	void start();
	~Game();
};

#endif // !GAME_H
