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

// Populates the board with player, arrows, and hazards
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
	bool flag = true;
	while(flag){
		h = rand()%HEIGHT;
		w = rand()%WIDTH;
		cout << h << endl;
		cout << w << endl;
		if((h != 0 && w != 0) || (h != 0 && w != WIDTH - 1) || (h != HEIGHT - 1 && w != 0) || (h != HEIGHT - 1 && w != WIDTH - 1) && !this->grid[h][w]->isOccupied()){
			flag = false;
		}
	}
	this->player = new Player(this);
	this->playerX = w;
	this->playerY = h;
	this->player->setLocation(h, w);
}

// Displays the debugging board to the screen
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

// Displays an empty map with just the player to the screen
void Board::displayPlayer() {
	for(int i = 0; i < HEIGHT; i++){
		for(int k = 0; k < WIDTH; k++){
			if(k != WIDTH - 1){
				if(this->grid[i][k]->getToken() == 'P'){
					cout << this->grid[i][k]->getToken() << " ";
				} else{
					cout << '.' << " ";
				}
			} else{
				if(this->grid[i][k]->getToken() =='P'){
					cout << this->grid[i][k]->getToken() << endl;
				} else{
					cout << '.' << endl;
				}
			}
		}
	}
}

// Gets the player
Player* Board::getPlayer(){
	return this->player;
}

// Gets a specific cell from the board
Cell* Board::getCell(int h, int w) {
	return h < HEIGHT && h >= 0 && w >= 0 && w < WIDTH ? this->grid[h][w] : nullptr;
}

// Gets the height of the board
int Board::getBoardHeight(){
	return HEIGHT;
}

// Gets the width of the board
int Board::getBoardWidth(){
	return WIDTH;
}