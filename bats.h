#ifndef BATS_H_
#define BATS_H_

#include "hazard.h"
#include <string>

class Board;

class Bats : public Hazard {
	int delta_x, delta_y;
public:
	Bats(Board * board, int x, int y, int delta_x, int delta_y);
	bool attack(Player * player);
	char display();
	std::string message();
};

#endif