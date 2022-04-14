#ifndef WUMPUS_H_
#define WUMPUS_H_

#include "hazard.h"
#include <string>

class Board;

class Wumpus : public Hazard {
public:
	Wumpus(Board * board, int x, int y);
	void attack(Player * player) = 0;
	char display() = 0;
	std::string message() = 0;
};

#endif