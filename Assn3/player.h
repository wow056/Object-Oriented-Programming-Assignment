#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
public:
	enum { FullHealth = 100 };
	Player()	//Constructor: set player's default information
		:health(FullHealth), score(0) {}
	void increaseHealth(int value);	//Increase Health by value. If result is over FullHealth, set health to FullHealth.
	void decreaseHealth(int value);	//Decrease Health by value. If result is under 0, set heath to 0.
	void increaseScore(int value);	//Increase Score by value. No exception.
	void decreaseScore(int value);	//Decrease Score by value. If result is under 0, set score to 0.
	bool isAlive() const;	//Inform if the player's health is over 0.
	void printInfo(ostream &os) const;	//Print the health and score into stream.
	int getScore() const;	//Return player's score.
private:
	int health;
	int score;
};

#endif // !PLAYER_H
