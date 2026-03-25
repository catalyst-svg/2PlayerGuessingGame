#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H

#include <iostream>
#include <string>
#include <random>

class player
{
	std::string m_name;
	int m_health;
public:
	player();
	player(std::string name,int health);

	std::string getName() const;
	int getHealth();

	void damage(int numcase);
	void printHealth();

};

class game
{
public:
	static int genNum();

	static int guessNum(int result,int p1Choice,int p2Choice);
};

#endif
