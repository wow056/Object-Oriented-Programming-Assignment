#include "word.h"

int Word::cmp_position::count = 0;

void Word::pop(Player & player)
{
	expire();
	player.increaseScore(1);
}

void HealingWord::pop(Player & player)
{
	expire();
	player.increaseScore(1);
	player.increaseHealth(10);
}

void BombWord::pop(Player & player)
{
	expire();
	player.decreaseScore(2);
	player.decreaseHealth(20);
}

void CompleteHealingWord::pop(Player & player)
{
	expire();
	player.increaseHealth(100);
}

void DeathBombWord::pop(Player & player)
{
	expire();
	player.decreaseHealth(100);
}

bool Word::load_word_file(const char* file_name, string word_source[], const int n)
{
	string buffer;
	ifstream file(file_name);
	if (!file)
		return false;
	int index = 0;
	srand(time(NULL));
	while ((file >> buffer) && (index < n))
	{
		word_source[index] = buffer;
		index++;
	}
	return true;
}

void Word::push_word(list<Word*>& word_list, const string word_source[], int n, const Position & palette_size, const list<string> & previous_word_list)
{
	string selected_word;
	int word_class_selector = rand() % 10;
	int word_length;

	while (true)
	{
		selected_word = word_source[rand() % n];	//select random word
		if (find_if(word_list.begin(), word_list.end(), compare_word_with_name(selected_word)) == word_list.end())	//if it does not exist in word_list
			if (find(previous_word_list.begin(), previous_word_list.end(), selected_word) == previous_word_list.end())	//if it does not exist in previous_word_list
				break;	//use this word
	}

	//it has different length according to word class type
	word_length = selected_word.length();
	if (word_class_selector >= 4 && word_class_selector < 8)
		word_length += 2;
	else if (word_class_selector >= 8 && word_class_selector < 10)
		word_length += 7;

	Position word_position = find_good_place(word_list, palette_size, word_length);

	switch (word_class_selector)
	{
	case 0: case 1: case 2: case 3:
		word_list.push_back(new Word(selected_word, word_position));
		break;
	case 4: case 5:
		word_list.push_back(new HealingWord(selected_word, word_position));
		break;
	case 6: case 7:
		word_list.push_back(new BombWord(selected_word, word_position));
		break;
	case 8:
		word_list.push_back(new CompleteHealingWord(selected_word, word_position));
		break;
	case 9:
		word_list.push_back(new DeathBombWord(selected_word, word_position));
		break;
	}
	

}

void Word::fill_word(list<Word*>& word_list, const string word_source[], const int maximum_word_num, const int n, const Position & palette_size, const list<string> & previous_word_list)
{
	while (word_list.size() < maximum_word_num)
	{
		push_word(word_list, word_source, n, palette_size, previous_word_list);
	}
}

Position Word::find_good_place(const list<Word*>& word_list, const Position & palette_size, const int word_size)
{
	bool is_good;
	Position p;
	do
	{
		is_good = true;
		p.x = rand() % (palette_size.x - word_size);	//randomly set coordinate
		p.y = rand() % palette_size.y;
		for (list<Word*>::const_iterator it = word_list.begin(); it != word_list.end(); it++)	//for all elements in word_list
		{
			int word_start_x = (*it)->pos.x;
			int word_end_x = (*it)->pos.x + (*it)->length();
			if (p.y == (*it)->pos.y)	//if new word overlays on them
			{
				if (p.x - 1 >= word_start_x && p.x - 1 <= word_end_x)
				{
					is_good = false;
					break;
				}
				else if (p.x + word_size + 1 >= word_start_x && p.x + word_size + 1 <= word_end_x)
				{
					is_good = false;
					break;
				}
				else if (p.x - 1 <= word_start_x && p.x + word_size + 1 >= word_end_x)
				{
					is_good = false;
					break;
				}	//set coordinate again	
			}
		}
	} while (!is_good);	//until it does not overlay to all elements
	return p;
}

Position Word::getPos() const
{
	return pos;
}

int Word::length() const
{
	ostringstream temporary_stream;
	print(temporary_stream);
	return temporary_stream.str().length();
}

void Word::print(ostream & os) const
{
	os << name;
}

void HealingWord::print(ostream & os) const
{
	os << '(';
	Word::print(os);
	os << ')';
}

void BombWord::print(ostream & os) const
{
	os << '<';
	Word::print(os);
	os << '>';
}

void CompleteHealingWord::update()
{
	count--;
	if (count <= 0)
		expire();
}

void CompleteHealingWord::print(ostream & os) const
{
	os << "((";
	Word::print(os);
	os << '(' << count << ")))";
}

void DeathBombWord::update()
{
	count--;
	if (count <= 0)
		expire();
}

void DeathBombWord::print(ostream & os) const
{
	os << "<<";
	Word::print(os);
	os << '(' << count << ")>>";
}
