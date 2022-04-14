#include "wumpus.h"

void Wumpus::attack(Player * player) override {
	// player->is_dead = true;
}

char Wumpus::display() override {
	return '!';
}

std::string Wumpus::message() override {
	return "You can smell the wumpus";
}