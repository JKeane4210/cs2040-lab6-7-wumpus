#include "cell.h"
#include "hazard.h"

Cell::Cell(int x, int y) : x{x}, y{y} {
	this->hasPlayer = false;
	this->hasHazard = false;
}

void Cell::insertPlayer(){
	this->hasPlayer = true;
}

void Cell::insertHazard(Hazard * h){
	this->hasHazard = true;
	this->hazard = h;
}

void Cell::leavePlayer(){
	this->hasPlayer = false;
}

void Cell::leaveHazard(){
	this->hasHazard = false;
	this->hazard = nullptr;
}