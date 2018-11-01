#include "game.h"

int main()
{

#ifdef DEBUG_MODE
	ofstream log_file("log.txt",ofstream::ate);
	ifstream input_file("input_file.txt");
	if (!input_file)
	{
		cerr << "No input stream" << endl;
	}
	else
	{
		Game game(log_file, input_file);
		game.start();
	}
	log_file.close();
	input_file.close();
#else
	Game game(cout, cin);
	game.start();
#endif
	return 0;
}
