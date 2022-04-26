#ifndef PIT_H_
#define PIT_H_

#include "hazard.h"
#include <string>

class Board;

// A pit that can be placed on the map as a hazard
class Pit : public Hazard {
public:
	// Create a pit on the game board at location (x, y)
	Pit(Board * board, int x, int y);

	// Attacks the player by dropping them down a hole
	bool attack(Player * player);

	// An @ character represents the pit on the board
	char display();

	// The message to display if you are close to a pit
	std::string message();
};

#endif