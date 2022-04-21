#include "pit.h"
#include "hazard.h"
#include "board.h"
#include <iostream>

Pit::Pit(Board * board, int x, int y) : Hazard(board, x, y) {}

void Pit::attack(Player * player) {
	cout << "You fell down a pit. The wumpus comes to eat you." << endl;
	return false;
}

char Pit::display() {
	return '@';
}

std::string Pit::message() {
	return "I feel a breeze.";
}