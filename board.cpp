#include "board.h"
#include "cell.h"
#include "hazard.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "player.h"

#include <iostream>
#include <cstdlib>

using namespace std;

// g++ bats.cpp bats.h board.cpp board.h cell.cpp cell.h hazard.cpp hazard.h main.cpp pit.cpp pit.h player.cpp player.h wumpus.cpp wumpus.h

// Creates an instance of board
Board::Board() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; k < WIDTH; k++){
			this->grid[i][k] = new Cell(this, i, k);
		}
	}
}

// When the board is deconstructed
Board::~Board() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; k < WIDTH; k++){
			delete this->grid[i][k];
		}
	}
}

// Populates the board
void Board::createBoard() {
	srand(time(NULL));
	int h = rand()%HEIGHT;
	int w = rand()%WIDTH;
	Wumpus * wumpus = new Wumpus(this, w, h);
	this->grid[h][w]->insertHazard(wumpus);
	for(int i = 0; i < ARROWS; i++){
		do{
			h = rand()%HEIGHT;
			w = rand()%WIDTH;
		} while(this->grid[h][w]->isOccupied());
		this->grid[h][w]->insertArrow();
	}
	for(int i = 0; i < BATS; i++){
		do{
			h = rand()%HEIGHT;
			w = rand()%WIDTH;
		} while(this->grid[h][w]->isOccupied());
		int posX = rand()%WIDTH;
		int posY = rand()%HEIGHT;
		Bats * bat = new Bats(this, w, h, posX, posY);
		this->grid[h][w]->insertHazard(bat);
	}
	for(int i = 0; i < PITS; i++){
		do{
			h = rand()%HEIGHT;
			w = rand()%WIDTH;
		} while(this->grid[h][w]->isOccupied());
		Pit * pit = new Pit(this, w, h);
		this->grid[h][w]->insertHazard(pit);
	}
	do{
		h = rand()%HEIGHT;
		w = rand()%WIDTH;
	} while(this->grid[h][w]->isOccupied());
	this->player = new Player(this);
	//Player * player = new Player(this);
	this->playerX = w;
	this->playerY = h;
	this->grid[h][w]->insertPlayer(this->player);
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

Player* Board::getPlayer(){
	return this->player;
}

Cell* Board::getCell(int h, int w) {
	return h < HEIGHT && h >= 0 && w >= 0 && w < WIDTH ? this->grid[h][w] : nullptr;
}