#include "pit.h"
#include "hazard.h"
#include "board.h"
#include <iostream>

Pit::Pit(Board * board, int x, int y) : Hazard(board, x, y) {}

bool Pit::attack(Player * player) {
	std::cout << "You fell down a pit. The wumpus comes to eat you." << std::endl;
	return false;
}

char Pit::display() {
	return '@';
}

std::string Pit::message() {
	return "I feel a breeze.";
}