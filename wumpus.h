#ifndef WUMPUS_H_
#define WUMPUS_H_

#include "hazard.h"
#include <string>

class Board;

class Wumpus : public Hazard {
public:
	Wumpus(Board * board, int x, int y);
	void attack(Player * player);
	char display();
	std::string message();
};

#endif