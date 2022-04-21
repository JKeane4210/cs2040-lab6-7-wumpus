#include "cell.h"
#include "hazard.h"

Cell::Cell(int x, int y) : x{x}, y{y} {
	this->hasPlayer = false;
	this->hasHazard = false;
	this->token = '.';
}

void Cell::insertPlayer(){
	this->hasPlayer = true;
	this->token = 'P';
}

void Cell::insertHazard(Hazard * h){
	this->hasHazard = true;
	this->hazard = h;
	this->token = h->display();
}

void Cell::leavePlayer(){
	this->hasPlayer = false;
	this->token = '.';
}

void Cell::leaveHazard(){
	this->hasHazard = false;
	this->hazard = nullptr;
	this->token = '.';
}

char Cell::getToken(){
	return this->token;
}