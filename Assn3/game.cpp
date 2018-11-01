#include "game.h"

const char* Game::WordListFileName = "word_name.dat";

void Game::start()
{
	Word::fill_word(word_list, word_source, InGameWordCount, LoadedWordCount, palette_size);
	main_loop();
	system(CLEAR);
	(*output_stream) << "GAME OVER! score: " << player.getScore() << " points" << endl;
}

void Game::main_loop()
{
	string user_input;
	list<string> previous_word_list;
	do
	{
		word_list.sort(Word::cmp_position());
		printScreen();
		(*output_stream) << "input: ";
		(*input_stream) >> user_input;

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
#if DEBUG_MODE
	(*output_stream) << "sorting count: " << Word::cmp_position::pop_count() << endl;
	(*output_stream) << endl;
#endif // DEBUG_MODE
	showPalette();
	(*output_stream) << endl;
	player.printInfo(*output_stream);
	(*output_stream) << endl;
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
				(*output_stream) << endl;
			else
				(*output_stream) << ' ';
		}
		(*it)->print(*output_stream);
		cursor_pos.increasePos((*it)->length(), palette_size);
		if (cursor_pos.changedLine())
			(*output_stream) << endl;
	}
	while (cursor_pos.y < palette_size.y)
	{
		cursor_pos.y++;
		(*output_stream) << endl;
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

Game::Game(ostream & game_output_stream, istream & game_input_stream)
	:palette_size(100, 5), output_stream(&game_output_stream), input_stream(&game_input_stream)
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
