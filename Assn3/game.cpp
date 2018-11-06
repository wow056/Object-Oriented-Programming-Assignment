#include "game.h"

const char* Game::WordListFileName = "word_name.dat";

void Game::start()
{
	Word::fill_word(word_list, word_source, InGameWordCount, LoadedWordCount, palette_size);
	main_loop();
#ifndef DEBUG_MODE
	system(CLEAR);
#endif // !DEBUG_MODE
	(*output_stream) << "GAME OVER! score: " << player.getScore() << " points" << endl;
}

void Game::main_loop()
{
	string user_input;
	list<string> previous_word_list;
	do
	{
		word_list.sort(Word::cmp_position());	//sort by position to print easily
		printScreen();
		(*output_stream) << "input: ";
#ifndef DEBUG_MODE
		cin >> user_input;
#else
		user_input = word_source[rand() % LoadedWordCount];
		(*output_stream) << user_input << endl;
#endif // DEBUG_MODE
		list<Word*>::iterator word_find = find_if(word_list.begin(), word_list.end(), Word::compare_word_with_name(user_input));	//search word by input
		if (word_find == word_list.end())	//if not found
		{
			player.decreaseHealth(10);
		}
		else								//if found
		{
			(*word_find)->pop(player);
		}
		update_list();
	} while (player.isAlive());
}

void Game::printScreen() const
{
#ifndef DEBUG_MODE
	system(CLEAR);
#else
	(*output_stream) << endl;
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
	for (it = word_list.begin(); it != word_list.end(); it++)	//for each word member
	{
		Position word_pos = (*it)->getPos();
		while (cursor_pos < word_pos)	//increase cursor_pos and print ' ' or '\n' until cursor_pos get to word's pos memeber
		{
			cursor_pos.increasePos(palette_size);
			if (cursor_pos.changedLine())
				(*output_stream) << endl;
			else
				(*output_stream) << ' ';
		}
		(*it)->print(*output_stream);	//if cursor_pos get to word's pos memeber, print word and increase cursor_pos by it's output length
		cursor_pos.increasePos(palette_size, (*it)->length());
		if (cursor_pos.changedLine())
			(*output_stream) << endl;
	}
	while (cursor_pos.y < palette_size.y)	//if all word's print is ended, print '\n' until output is correspond to palette_size
	{
		cursor_pos.y++;
		(*output_stream) << endl;
	}
}


void Game::update_list()
{
	list<string> previous_word_list;
	list<Word*>::iterator it = word_list.begin();
	while (it != word_list.end())	//until iteration is ended
	{
		(*it)->update();	//update object
		if ((*it)->is_expired())	//if it is expired(by pop or count)
		{
			previous_word_list.push_back((*it)->getName());	//its name will be not used int this updating.
			delete *it;
			it = word_list.erase(it);	//pop from list and iterate to nexe elemnt
		}
		else
		{
			it++;	//iterate to next element
		}
	}
	Word::fill_word(word_list, word_source, InGameWordCount, LoadedWordCount, palette_size, previous_word_list);	//fill word_list until its size is InGameWordCount
}

Game::Game(ostream *game_output_stream)
	:palette_size(100, 5), output_stream(game_output_stream)
{
	word_source = new string[LoadedWordCount];
	if (!Word::load_word_file(WordListFileName, word_source, LoadedWordCount))
		exit(EXIT_FAILURE);
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
