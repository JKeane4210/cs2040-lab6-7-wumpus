#ifndef BOARD_H_
#define BOARD_H_

class Cell;
class Hazard;
class Player;

class Board {
	static constexpr int WIDTH = 6;
	static constexpr int HEIGHT = 6;
	static constexpr int ARROWS = 3;
	static constexpr int BATS = 2;
	static constexpr int PITS = 2;
	Cell * grid[HEIGHT][WIDTH];
	Player * player;
	Hazard * hazards;
public:
	int playerX, playerY;
	Board();
	~Board();
	void createBoard();
	void displayBoard();
	Cell* getCell(int h, int w);
};

#endif