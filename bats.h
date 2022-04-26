#ifndef BATS_H_
#define BATS_H_

#include "hazard.h"
#include <string>

class Board;

// A swarm of bats that can carry a player away
class Bats : public Hazard {
	int delta_x, delta_y;
public:
	// Initializes a bats object on the board at coordinate (x, y) 
	// and will move the player to (delta_x, delta_y)
	Bats(Board * board, int x, int y, int delta_x, int delta_y);

	// The bats attack the player by moving them to (delta_x, delta_y)
	bool attack(Player * player);

	// A 'B' symbol representing the bats on the map
	char display();

	// Message for when bats are close
	std::string message();
};

#endif