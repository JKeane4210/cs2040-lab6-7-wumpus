#ifndef BATS_H_
#define BATS_H_

#include "hazard.h"
#include <string>

class Board;

class Bats : public Hazard {
	int delta_x, delta_y;
public:
	Bats(Board * board, int x, int y, int delta_x, int delta_y);
	void attack(Player * player) = 0;
	char display() = 0;
	std::string message() = 0;
};

#endif