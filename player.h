#ifndef PLAYER_H_
#define PLAYER_H_

class Board;

class Player {
	int x, y;
	int arrows;
	bool isDead;
	Board * board;
public:
	Player(Board * board);
	void move(char direction);
	void shoot();
};

#endif