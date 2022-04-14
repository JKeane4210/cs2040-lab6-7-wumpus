#include "cell.h"

Cell::Cell(int x, int y) {
	this.x = x;
	this.y = y;
	this.hasPlayer = false;
	this.hasHazard = false;
}

Cell::insertPlayer(){
	this.hasPlayer = true;
}

Cell::insertHazard(Hazard h){
	this.hasHazard = true;
	this.hazard = h;
}