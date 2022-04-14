#include "cell.h"

class Board {
	static constexpr int WIDTH = 6;
	static constexpr int HEIGHT = 6;
	Cell * grid[HEIGHT][WIDTH];
	Hazard * hazards;
public:
	Board();
	void createBoard();
	void displayBoard();
};