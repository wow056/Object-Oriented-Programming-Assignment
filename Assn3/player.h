#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
public:
	enum { FullHealth = 100 };
	Player() 
		:health(FullHealth), score(0) {}
	void increaseHealth(int value);
	void decreaseHealth(int value);
	void increaseScore(int value);
	void decreaseScore(int value);
	bool isAlive() const;
	void printInfo(ostream &os) const;
	int getScore() const;
private:
	int health;
	int score;
};

#endif // !PLAYER_H
