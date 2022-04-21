#include "wumpus.h"
#include "hazard.h"
#include <iostream>

Wumpus::Wumpus(Board * board, int x, int y) : Hazard(board, x, y) {}

bool Wumpus::attack(Player * player) {
	cout << "You were eaten by a wumpus" << endl;
	return false;
}

char Wumpus::display() {
	return '!';
}

std::string Wumpus::message() {
	return "You can smell the wumpus";
}