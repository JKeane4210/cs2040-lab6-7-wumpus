#include "board.h"

class Player {
	int x, y;
	int arrows;
	Board * board;
public:
	Player(Board * board);
	void move(char direction);
	void shoot();
}