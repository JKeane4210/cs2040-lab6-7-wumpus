#include "bats.h"
#include "hazard.h"

Bats::Bats(Board * board, int x, int y, int delta_x, int delta_y) : Hazard(board, x, y), delta_x{delta_x}, delta_y{delta_y} {}

void Bats::attack(Player * player) {
	// player->move(delta_x, delta_x);
}

char Bats::display() {
	return 'B';
}

std::string Bats::message() {
	return "I can hear flapping.";
}