#ifndef HAZARD_H_
#define HAZARD_H_

#include <string>

class Board;
class Player;

// A hazard on the map. This is an abstract class that is extended by Bats, Wumpus, and Pit
class Hazard {
protected:
	Board * board;
	int x, y;
public:
	// Initializes a hazard on the board at (x, y)
	Hazard(Board * board, int x, int y);

	// Abstract method for what the hazard should do if the player moves onto the hazard's square
	virtual bool attack(Player * player) = 0;

	// Abstract method for getting the symbol of the hazard to display on the board
	virtual char display() = 0;

	// Abstract method for the message to display when the player is close the hazard
	virtual std::string message() = 0;
};

#endif