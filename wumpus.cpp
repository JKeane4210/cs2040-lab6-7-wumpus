#include "wumpus.h"

Wumpus::Wumpus(Board * board, int x, int y) : Hazard(board, x, y) {}

void Wumpus::attack(Player * player) override {
	// player->is_dead = true;
}

char Wumpus::display() override {
	return '!';
}

std::string Wumpus::message() override {
	return "You can smell the wumpus";
}