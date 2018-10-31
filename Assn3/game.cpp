#include "Game.h"

const string Game::WordListFileName = "word_name.dat";

void Game::start()
{
	Word::fill_word(word_list, word_source, InGameWordCount, LoadedWordCount, palette_size);
	main_loop();
	system(CLEAR);
	cout << "GAME OVER! score: " << player.getScore() << " points" << endl;
}

void Game::main_loop()
{
	string user_input;
	list<string> previous_word_list;
	do
	{
		word_list.sort(Word::cmp_position());
		printScreen();
		cout << "input: ";
		cin >> user_input;

		list<Word*>::iterator word_find = find_if(word_list.begin(), word_list.end(), Word::compare_word_with_name(user_input));
		if (word_find == word_list.end())
		{
			player.decreaseHealth(10);
		}
		else
		{
			(*word_find)->pop(player);
		}
		update_list(previous_word_list);
	} while (player.isAlive());
}

void Game::printScreen() const
{
	system(CLEAR);
	cout << endl;
	showPalette();
	cout << endl;
	player.printInfo();
	cout << endl;
}

void Game::showPalette() const
{
	Position cursor_pos(0, 0);
	list<Word*>::const_iterator it;
	for (it = word_list.begin(); it != word_list.end(); it++)
	{
		while (cursor_pos < (*it)->getPos())
		{
			cursor_pos.increasePos(1, palette_size);
			if (cursor_pos.changedLine())
				cout << endl;
			else
				cout << ' ';
		}
		(*it)->print();
		cursor_pos.increasePos((*it)->length(), palette_size);
		if (cursor_pos.changedLine())
			cout << endl;
	}
	while (cursor_pos.y < palette_size.y)
	{
		cursor_pos.y++;
		cout << endl;
	}
}


void Game::update_list(list<string> &previous_word_list)
{
	list<Word*>::iterator it = word_list.begin();
	while (it != word_list.end())
	{
		(*it)->decreaseCount();
		if ((*it)->vanished())
		{
			previous_word_list.push_back((*it)->getName());
			delete *it;
			it = word_list.erase(it);
		}
		else
		{
			it++;
		}
	}
	Word::fill_word(word_list, word_source, InGameWordCount, LoadedWordCount, palette_size, previous_word_list);
	previous_word_list.clear();
}

Game::Game()
	:palette_size(100, 5)
{
	word_source = new string[LoadedWordCount];
	Word::load_word_file(WordListFileName, word_source, LoadedWordCount);
}




Game::~Game()
{
	while (!word_list.empty())
	{
		delete word_list.front();
		word_list.pop_front();
	}
	delete[] word_source;
}
