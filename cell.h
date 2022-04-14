#ifndef CELL_H_
#define CELL_H_

class Hazard;

class Cell {
	int x, y;
	bool hasPlayer, hasHazard;
	Hazard * hazard;
public:
	Cell(int x, int y);
	void insertPlayer();
	void insertHazard(Hazard * h);
};

#endif