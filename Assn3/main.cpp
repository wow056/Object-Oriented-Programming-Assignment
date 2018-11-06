/*Assn3
2018-11-02
20170225 Kang Minsu
I completed this take-home programming exam without help of anybody else.
*/

#include "game.h"
#include <iostream>


int main()
{

#ifdef DEBUG_MODE
	ofstream log_file("log.txt");
	Game game(&log_file);
	game.start();
	log_file.close();
#else
	Game game;
	game.start();
#endif
	return 0;
}
