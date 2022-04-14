#include "pit.h"

Pit::Pit(Board * board, int x, int y) : Hazard(board, x, y) {}

void Pit::attack(Player * player) override {
	// player->is_dead = true;
}

char Pit::display() override {
	return '@';
}

std::string Wumpus::message() override {
	return "I feel a breeze.";
}