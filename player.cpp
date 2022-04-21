#include "player.h"
#include "board.h"
#include "cell.h"
#include "hazard.h"
#include <string>
#include <iostream>

Player::Player(Board * board) {
	// set x and y position from board
	isDead = false;
	Player::board = board;
	arrows = STARTING_ARROWS;
}

int Player::getArrows(){
	return arrows;
}

bool Player::move(char direction) {
	char move = tolower(direction);
	bool ret = true;
	if (move == 'n') {
		ret = setLocation(x - 1, y);
	} else if (move == 'e') {
		ret = setLocation(x, y + 1);
	} else if (move == 's') {
		ret = setLocation(x + 1, y);
	} else if (move == 'w') {
		ret = setLocation(x, y - 1);
	} 

	return ret;
}

bool Player::setLocation(int x, int y) {
	board->getCell(this->x, this->y)->leavePlayer();
	this->x = x;
	this->y = y;
	board->getCell(this->x, this->y)->insertPlayer(this);
	bool ret = checkCurrentPosition(x, y);
	if (ret) {
		checkNeighbors(x, y);
	}
	return ret;
}

bool Player::shoot(char direction) {
	bool ret = true;
	arrows -= 1;
	if(direction == 'n'){
		if(board->getCell(x - 1, y)->getToken() == '!'){
			ret = hitWumpus();
		} else{
			missWumpus();
		}
	} else if (direction == 'e'){
		if(board->getCell(x, y + 1)->getToken() == '!'){
			ret = hitWumpus();
		} else{
			missWumpus();
		}
	} else if (direction == 's'){
		if(board->getCell(x + 1, y)->getToken() == '!'){
			ret = hitWumpus();
		} else{
			missWumpus();
		}
	} else if (direction == 'w'){
		if(board->getCell(x, y - 1)->getToken() == '!'){
			ret = hitWumpus();
		} else{
			missWumpus();
		}
	}
	return ret;
}

bool Player::hitWumpus(){
	std::cout << "You got the Wumpus!" << std::endl;
	return false;
}

void Player::missWumpus(){
	std::cout << "You missed!" << std::endl;
}

bool Player::checkCurrentPosition(int x, int y) {
	Cell *currentPCell = board->getCell(x, y);
	bool ret = true;
	if (currentPCell->isOccupied()) {
		if (currentPCell->containsArrow()) {
			currentPCell->grabArrow();
			arrows++;
			std::cout << "You picked up an arrow" << std::endl;
		} else {
			Hazard * hazard = currentPCell->getHazard();
			ret = hazard->attack(this);
		}
	}
	return ret;
}

void Player::checkNeighbors(int x, int y){
	for (int delta_x = -1; delta_x <= 1; ++delta_x) {
		for (int delta_y = -1; delta_y <= 1; ++delta_y) {
			if (delta_x != 0 || delta_y != 0) {
				Cell * curr_cell = board->getCell(x + delta_x, y + delta_y);
				if (curr_cell != nullptr) {
					Hazard * hazard = curr_cell->getHazard();
					if (hazard != nullptr) {
						std::cout << hazard->message() << std::endl;
					}
				}
			}
		}
	}
}
