#ifndef HAZARD_H_
#define HAZARD_H_

#include <string>

class Board;
class Player;

class Hazard {
protected:
	Board * board;
	int x, y;
public:
	Hazard(Board * board, int x, int y);
	virtual bool attack(Player * player) = 0;
	virtual char display() = 0;
	virtual std::string message() = 0;
};

#endif