//#include "board.h"
#include <string>

class Hazard {
protected:
	Board * board;
	int x, y;
public:
	Hazard(Board * board, int x, int y);
	void attack(Player * player) = 0;
	char display() = 0;
	std::string message() = 0;
};