#ifndef BOARD_H_
#define BOARD_H_

class Cell;
class Hazard;

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

#endif