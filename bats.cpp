#include "bats.h"
#include "hazard.h"
#include "player.h"
#include <iostream>

Bats::Bats(Board * board, int x, int y, int delta_x, int delta_y) : Hazard(board, x, y), delta_x{delta_x}, delta_y{delta_y} {}

bool Bats::attack(Player * player) {
	bool b = player->setLocation(delta_x, delta_y);
	std::cout << "You were carried away by bats" << std::endl;
	return b;
}

char Bats::display() {
	return 'B';
}

std::string Bats::message() {
	return "I can hear flapping.";
}