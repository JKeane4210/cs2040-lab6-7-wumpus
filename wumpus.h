#ifndef WUMPUS_H_
#define WUMPUS_H_

#include "hazard.h"
#include <string>

class Board;

// Class representing the wumpus on the board
class Wumpus : public Hazard {
public:
	// Creates a hungry wumpus at the location (x, y)
	Wumpus(Board * board, int x, int y);

	// The wumpus kills the player (chomp chomp)
	bool attack(Player * player);

	// The wumpus is represented by a '!' on the board
	char display();

	// The message to display when the wumpus is near
	std::string message();
};

#endif