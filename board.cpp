#include "board.h"
#include "cell.h"
#include "hazard.h"

Board::Board() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; i < WIDTH; k++){
			this->grid[i][k] = new Cell(i, k);
		}
	}
}

void Board::createBoard() {
	// TODO
}

void Board::displayBoard() {
	// TODO
}