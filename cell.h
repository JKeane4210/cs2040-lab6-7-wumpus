#include "hazard.h"

class Cell {
	int x, y;
	bool hasPlayer, hasHazard;
	Hazard * hazard;
public:
	Cell(int x, int y);
	void insertPlayer();
	void insertHazard(Hazard h);
	void leavePlayer();
	void leaveHazard();
};