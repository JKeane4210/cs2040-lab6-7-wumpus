#ifndef CELL_H_
#define CELL_H_

class Hazard;
class Player;
class Board;

class Cell {
	int x, y;
	bool hasPlayer, hasHazard, hasArrow;
	char token;
	Board * board;
	Hazard * hazard;
	Player * player;
public:
	Cell(Board * b, int x, int y);
	void insertPlayer(Player * p);
	void insertHazard(Hazard * h);
	void leavePlayer();
	void leaveHazard();
	void insertArrow();
	void grabArrow();
	bool isOccupied();
	char getToken();
	Hazard * getHazard();
	bool containsArrow();
};

#endif
