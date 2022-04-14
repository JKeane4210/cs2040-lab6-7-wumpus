#include "hazard.h"

class Cell {
	int x, y;
	bool hasPlayer, hasHazard;
	Hazard * hazard;
public:
	Cell();
	void insertPlayer();
	void insertHazard(Hazard h);
	
};