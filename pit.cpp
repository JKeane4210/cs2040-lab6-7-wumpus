#include "pit.h"
#include "hazard.h"
#include "board.h"

Pit::Pit(Board * board, int x, int y) : Hazard(board, x, y) {}

void Pit::attack(Player * player) {
	// player->is_dead = true;
}

char Pit::display() {
	return '@';
}

std::string Pit::message() {
	return "I feel a breeze.";
}