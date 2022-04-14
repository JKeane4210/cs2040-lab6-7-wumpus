#ifndef PLAYER_H_
#define PLAYER_H_

class Board;

class Player {
	int x, y;
	int arrows;
	Board * board;
public:
	Player(Board * board);
	void move(char direction);
	void shoot();
};

#endif