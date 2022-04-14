#include "bats.h"

Bats::Bats(Board * board, int x, int y, int delta_x, int delta_y) : Hazard(board, x, y), delta_x{delta_x}, delta_y{delta_y} {}

void Bars::attack(Player * player) override {
	// player->move(delta_x, delta_x);
}

char Wumpus::display() override {
	return 'B';
}

std::string Wumpus::message() override {
	return "I can hear flapping.";
}