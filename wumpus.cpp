#include "wumpus.h"
#include "hazard.h"

Wumpus::Wumpus(Board * board, int x, int y) : Hazard(board, x, y) {}

void Wumpus::attack(Player * player) {
	// player->is_dead = true;
}

char Wumpus::display() {
	return '!';
}

std::string Wumpus::message() {
	return "You can smell the wumpus";
}