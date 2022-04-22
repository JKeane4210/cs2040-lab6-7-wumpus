#ifndef PLAYER_H_
#define PLAYER_H_

class Board;

class Player {
	static constexpr int STARTING_ARROWS = 5;
	int x, y;
	int arrows;
	bool isDead;
	Board * board;
	bool checkCurrentPosition(int x, int y);
	void checkNeighbors(int x, int y);
	bool hitWumpus();
	void missWumpus();
	void shootOutOfBounds();
public:
	Player(Board * board);
	bool move(char direction);
	bool setLocation(int x, int y);
	bool shoot(char direction);
	int getArrows();
};

#endif