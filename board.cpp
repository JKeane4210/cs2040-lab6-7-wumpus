#include "board.h"
#include "cell.h"
#include "hazard.h"

#include <iostream>

using namespace std;

// g++ bats.cpp bats.h board.cpp board.h cell.cpp cell.h hazard.cpp hazard.h main.cpp pit.cpp pit.h player.cpp player.h wumpus.cpp wumpus.h

Board::Board() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; k < WIDTH; k++){
			this->grid[i][k] = new Cell(i, k);
		}
	}
}

Board::~Board() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; k < WIDTH; k++){
			delete this->grid[i][k];
		}
	}
}

void Board::createBoard() {
	// TODO
}

void Board::displayBoard() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; k < WIDTH; k++){
			if(k != WIDTH - 1){
				cout << this->grid[i][k]->getToken() << " ";
			} else{
				cout << this->grid[i][k]->getToken() << endl;
			}
		}
	}
}

Cell* Board::getCell(int h, int w) {
	return this->grid[h][w];
}