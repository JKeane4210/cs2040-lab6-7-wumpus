#ifndef PIT_H_
#define PIT_H_

#include "hazard.h"
#include <string>

class Board;

class Pit : Hazard {
public:
	Pit(Board * board, int x, int y);
	void attack(Player * player) = 0;
	char display() = 0;
	std::string message() = 0;
};

#endif