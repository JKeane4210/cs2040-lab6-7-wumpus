#include "player.h"
#include "board.h"
#include "string"

Player::Player(Board * board) {
	// set x and y position from board
	isDead = false;
	Player::board = board;
}

bool Player::move(char direction) {
	char move = tolower(direction);
	bool ret = true;
	if (move == 'n') {
		y -= 1;
	} else if (move == 'e') {
		x += 1;
	} else if (move == 's') {
		y += 1;
	} else if (move == 'w') {
		x -= 1;
	} 
	ret = checkCurrentPosition(x, y);
	if (ret){
		checkNeighbors(x, y);
	}
	return ret;
}

void Player::shoot(char direction) {
	// see what direction they want to move
	// get cell based on direction
	// get cell token
		// if cell token is wumpus
			// return true
			// "You shot the wumpus!"
		// else
			// return false
			// "You missed!"
}

bool Player::checkCurrentPosition(int x, int y) {
	Cell *currentPCell = board->getCell(x, y);
	bool ret = true;
	// if arrow
		// arrows += 1;
	// if bat
		// move player to random open position
	// if pit
		// "You fell into a pit."
		// ret = false;
	// if wumpus
		// "You were eaten by a wumpus."
		// ret = false;
	return ret;
}

void Player::checkNeighbors(int x, int y){
	// if bat
		// bat message
	// if pit
		// pit message
	// if wumpus
		// wumpus message
}
