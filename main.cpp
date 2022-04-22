#include <iostream>
#include <cstdio> 
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

string how_to_play() {
	return "How to Play:\n"
		   "\tCommands:\n"
		   "\t\t- n/N = move north/up\n"
		   "\t\t- e/E = move east/right\n" 
		   "\t\t- s/S = move south/down\n" 
		   "\t\t- w/W = move west/left\n"
		   "\t\t- d/D = debug mode\n" 
		   "\t\t- m/M = view map\n" 
		   "\t\t- a/A = shoot arrow\n" 
		   "\t\t- h/H = pull up help menu\n"
		   "\t\t- q/Q = quit\n\n" 
		   "\tMap Key:\n"
		   "\t\t- . = empty\n"
		   "\t\t- - = arrow\n" 
		   "\t\t- P = player\n" 
		   "\t\t- B = bats\n"
		   "\t\t- @ = pit\n" 
		   "\t\t- ? = treasure\n" 
		   "\t\t- ! = monster\n";
}

void intro(){
	cout << "Welcome to Wumpus Hunt. Find us a Wumpus!" << endl;
}

void invalidAction(){
	cout << "Invalid action!" << endl;
}

void invalidShootingDirection(){
	cout << "Invalid direction for shot!" << endl;
}

char getAction(){
	bool flag = true;
	string input;
	char action;
	while(flag){
		cout << "Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, D)ebug, M)ap, Q)uit: ";
		try {
			cin >> input;
			if (input.length() == 1){
				action = input[0];
				action = tolower(action);
				if (action == 'n' || action == 's' || action == 'e' || action == 'w' || action == 'a' ||
					action == 'h' || action == 'd' || action == 'm' || action == 'q'){
					flag = false;
				} else{
					invalidAction();
				}
			} else{
				invalidAction();
			}
		} catch (const exception& e){
			invalidAction();
		}
	}
	return action;
}

bool performAction(char action, Player *player, Board &board){
	bool ret = true;
	if (action == 'n' || action == 's' || action == 'e' || action == 'w'){
		ret = player->move(action);
	} else if(action == 'a'){
		if (player->getArrows() != 0){
			string input;
			char direction;
			cout << "Which direciton you shootin' dawg? ";
			try{
				cin >> input;
				if (input.length() == 1){
					direction = input[0];
					direction = tolower(direction);
					if (direction == 'n' || direction == 'e' || direction == 's' || direction == 'w'){
						ret = player->shoot(direction);
					} else{
						invalidShootingDirection();
					}
				} else{
					invalidShootingDirection();
				}
			} catch (const exception& e){
				invalidShootingDirection();
			}
		} else{
			cout << "Out of arrows!";
		}
	} else if (action == 'h'){
		cout << how_to_play() << endl;
	} else if (action == 'm'){
			board.displayPlayer();
	} else if (action == 'q'){
		return false;
	}
	return ret;
}

int main() {
	Board board = Board();
	board.createBoard();
	Player *player = board.getPlayer();
	board.displayPlayer();
	intro();
	bool flag = true;
	bool debug = false;
	while (flag){
		if(debug){
			board.displayBoard();
		}
		char action = getAction();
		if (action == 'd'){
			debug = true;
		}
		flag = performAction(action, player, board);
	}
	return 0;
}