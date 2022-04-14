#include "player.h"
#include "board.h"
#include "string"

Player::Player(Board * board) {
	// set x and y position from board
	isDead = false;
}

void Player::move(char direction) {
	char move = tolower(direction);
	if (move == 'n')
	{
		if (y - 1 >= 0)
		{
			// check what is in (x, y - 1) spot
			y -= 1;
		}
	}
	else if (move == 'e')
	{
		if(x + 1 <= 5)
		{
			// check what is in (x + 1, y) spot
			x += 1;
		}
	}
	else if (move == 's')
	{
		if (y + 1 <= 5)
		{
			// check what is in (x, y + 1)
			y += 1;
		}
	}
	else if (move == 'w')
	{
		if (x - 1 >= 0)
		{
			// check what is in (x - 1, y)
			x -= 1;
		}
	}
	else
	{
		// invalid move display
	}
}

void Player::shoot() {
	// TODO
}