#ifndef PIT_H_
#define PIT_H_

#include "hazard.h"
#include <string>

class Board;

class Pit : Hazard {
public:
	Pit(Board * board, int x, int y);
	void attack(Player * player);
	char display();
	std::string message();
};

#endif