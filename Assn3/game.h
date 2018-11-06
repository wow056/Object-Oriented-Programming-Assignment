#ifndef GAME_H
#define GAME_H


#include <list>
#include <string>
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
	ostream *output_stream;				//Get output stream as member to debug easily
	enum
	{
		LoadedWordCount = 20,			//Number of words loaded from word list file
		InGameWordCount = 10			//Number of words shown in game
	};
	static const char *WordListFileName;//Name of word list file
	const Position palette_size;		//Size of screen of words
	string* word_source;				//Array of loaded word from word list file
	list<Word*> word_list;				//List of words shown in game
	Player player;						//object of player information

	void main_loop();					//Repeat loop until the game is end
	void printScreen() const;			//Print game screen into output stream

	void showPalette() const;							//Print screen of words
	void update_list();	//Update word list when an iteration in main loop is ended.
public:
	Game(ostream *game_output_stream = &cout);	//Constructor: load word_source and set input-output stream
	void start();	//start game: call main_loop
	~Game();		//Destructor: deallocate word_source
};

#endif // !GAME_H
