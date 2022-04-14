#include "hazard.h"

class Bats : Hazard {
	int delta_x, delta_y;
public:
	Bats(Board * board, int x, int y, int delta_x, int delta_y);
}