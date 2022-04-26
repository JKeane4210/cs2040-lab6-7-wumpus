#include "cell.h"
#include "hazard.h"
#include "board.h"
#include "player.h"

// Creates a Cell object
Cell::Cell(Board * b, int x, int y) : x{x}, y{y} {
	this->board = b;
	this->x = x;
	this->y = y;
	this->hasPlayer = false;
	this->hasHazard = false;
	this->hasArrow = false;
	this->token = '.';
}

// Deconstructs the cell
Cell::~Cell(){
	delete player;
	delete hazard;
}

// Puts the player into the cell
void Cell::insertPlayer(Player * p){
	this->hasPlayer = true;
	this->player = p;
	this->board->playerX = this->x;
	this->board->playerY = this->y;
}

// Puts a hazard into the cell
void Cell::insertHazard(Hazard * h){
	this->hasHazard = true;
	this->hazard = h;
	this->token = h->display();
}

// Means the player leaves the cell
void Cell::leavePlayer(){
	this->hasPlayer = false;
	this->player = nullptr;
}

// Means the hazard leaves the cell
void Cell::leaveHazard(){
	this->hasHazard = false;
	this->hazard = nullptr;
	this->token = '.';
}

// Puts an arrow into the cell
void Cell::insertArrow(){
	this->hasArrow = true;
	this->token = '-';
}

// Removes an arrow from the cell
void Cell::grabArrow(){
	this->hasArrow = false;
	this->token = '.';
}

// If the cell is occupied for purposes of generating the board
bool Cell::isOccupied(){
	return this->hasArrow || this->hasHazard;
}

// Gets the token from the cell
char Cell::getToken(){
	return hasPlayer ? 'P' : this->token;
}

// Gets the hazard from the cell
Hazard * Cell::getHazard() {
	return this->hazard;
}

// Tells if the cell contains an arrow
bool Cell::containsArrow() {
	return this->hasArrow;
}
