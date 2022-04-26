#ifndef PLAYER_H_
#define PLAYER_H_

class Board;

class Player {
	static constexpr int STARTING_ARROWS = 5;
	int x, y;
	int arrows;
	bool isDead;
	Board * board;
	// check to see if current postion is legal and if it is occupied
	bool checkCurrentPosition(int x, int y);
	// checks neighbors to see if hazards are nearby
	void checkNeighbors(int x, int y);
	// notify user if the Wumpus was hit
	bool hitWumpus();
	// notify user if the Wumpus was not hit
	void missWumpus();
	// notify user if shot is out of bounds
	void shootOutOfBounds();
	// if player attempts to move out of bounds, notify them
	void moveOutOfBounds();
public:
	// default constructor for Player
	Player(Board * board);
	// moves player in specific direction
	bool move(char direction);
	// sets the new location of the player
	bool setLocation(int x, int y);
	// shoots an arrow in a given direction
	bool shoot(char direction);
	// get current number of arrows
	int getArrows();
};

#endif