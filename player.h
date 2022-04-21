#ifndef PLAYER_H_
#define PLAYER_H_

class Board;

class Player {
	int x, y;
	int arrows;
	bool isDead;
	Board * board;
	bool checkCurrentPosition(int x, int y);
	void checkNeighbors(int x, int y);
public:
	Player(Board * board);
	bool move(char direction);
	void shoot(char direction);
};

#endif