#ifndef CELL_H_
#define CELL_H_

class Hazard;
class Player;
class Board;

class Cell {
	int x, y;		// Where in the board the cell is
	bool hasPlayer, hasHazard, hasArrow;		// Tells if the cell has these items
	char token;		// The token to represent the cell for debugging purposes
	Board * board;		// The board on which the cell is on
	Hazard * hazard;		// The hazard the cell might contain
	Player * player;	// The player the cell might contain
public:
	// Creates a new cell object
	Cell(Board * b, int x, int y);
	// Deconstructor for cell
	~Cell();
	// Puts the player into the cell
	void insertPlayer(Player * p);
	// Puts a hazard into the cell
	void insertHazard(Hazard * h);
	// Enacts the player leaving the cell
	void leavePlayer();
	// Enacts the hazard leaving the cell
	void leaveHazard();
	// Puts an arrow into the cell
	void insertArrow();
	// Takes the arrow away from the cell
	void grabArrow();
	// Says if the cell is occupied or not when generating the board
	bool isOccupied();
	// Gets the token of the cell
	char getToken();
	// Gets the hazard of the cell
	Hazard * getHazard();
	// Says if the cell contains an arrow
	bool containsArrow();
};

#endif
