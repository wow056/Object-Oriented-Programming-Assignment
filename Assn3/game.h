#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Game
{
private:
	const static string WordListFileName;
	list<string> word_list;
	bool loadWordList();
public:
	Game();
	~Game();
};
const string Game::WordListFileName("word_name.dat");
