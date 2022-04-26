#ifndef BOARD_H_
#define BOARD_H_

class Cell;
class Hazard;
class Player;

class Board {
	static constexpr int WIDTH = 6;		// The width of the board
	static constexpr int HEIGHT = 6;		// The height of the board
	static constexpr int ARROWS = 3;	// The number of arrows on the board
	static constexpr int BATS = 2;		// The number of bats on the board
	static constexpr int PITS = 2;		// The number of pits on the board
	Cell * grid[HEIGHT][WIDTH];		// The 2D array of cells that represents the board
	Player * player;		// The player
	Hazard * hazards;		// The hazards
public:
	int playerX, playerY;		// The position of the player
	Board();		// The constructor of the board
	~Board();		// The destructor of the board
	void createBoard();		// Generates the hazards and player to put on the board
	void displayBoard();		// Displays the debugging board
	void displayPlayer();		// Displays the player on an empty map
	Player* getPlayer();		// Gets the player from the board
	Cell* getCell(int h, int w);	// Gets a cell from the board
	int getBoardWidth();		// Gets the width of the board
	int getBoardHeight();		// Gets the height of the board
};

#endif