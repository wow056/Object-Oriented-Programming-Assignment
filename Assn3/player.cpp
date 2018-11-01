#include "player.h"

void Player::increaseHealth(int value)
{
	if (health + value < FullHealth)
	{
		health += value;
	}
	else
	{
		health = FullHealth;
	}
}

void Player::decreaseHealth(int value)
{
	if (health - value > 0)
	{
		health -= value;
	}
	else
	{
		health = 0;
	}
}

void Player::increaseScore(int value)
{
	score += value;
}

void Player::decreaseScore(int value)
{
	if (score - value > 0)
	{
		score -= value;
	}
	else
	{
		score = 0;
	}
}

bool Player::isAlive() const
{
	return health > 0;
}

void Player::printInfo(ostream & os) const
{
	os << "health: " << health << "\t\t\t\t\t\t\t\tscore: " << score;
}

int Player::getScore() const
{
	return score;
}
