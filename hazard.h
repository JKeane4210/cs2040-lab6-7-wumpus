#include "board.h"

class Hazard {
	Board * board;
public:
	Hazard(Board * board);
	void attack(Player * player) = 0;
	void display() = 0;
	void message() = 0;
};