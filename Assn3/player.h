#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player();
	void increaseHealth(int value);
	void decreaseHealth(int value);
	void increaseScore(int value);
	void decreaseScore(int value);
	void die();
	bool isAlive() const;
private:
	
};

#endif // !PLAYER_H
