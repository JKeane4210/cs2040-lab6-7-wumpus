#include <iostream>
#include <cstdio> 
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

// notify user of commands
string how_to_play() {
	return "How to Play:\n"
			"Player starts with 5 arrows. Your goal is to navigate the map to find\n"
			"and kill the wumpus without falling down pits or getting eaten by the wumpus.\n"
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
		   "\t\t- ! = monster\n"
		   "\tMessages:\n"
		   "\t\t- \"You can smell the wumpus.\": A wumpus is close.\n"
		   "\t\t- \"You can hear flapping.\": Bats are close by.\n"
		   "\t\t- \"You feel a breeze.\": A pit is close by.\n"
		   "\t\t- \"You were eaten by a wumpus.\": You died to a wumpus. Game over.\n"
		   "\t\t- \"You were carried away by bats.\": Bats carries you to an unknown location on the map.\n"
		   "\t\t- \"You fell down a pit. The wumpus comes to eat you.\": You fall down a pit. Game over.\n";
}

// intro message to game
void intro(){
	cout << "Welcome to Wumpus Hunt. Find us a Wumpus!" << endl;
}

// notify of invalid action
void invalidAction(){
	cout << "Invalid action!" << endl;
}

// notify of invalid shooting direction
void invalidShootingDirection(){
	cout << "Invalid direction for shot!" << endl;
}

// get the type of action from user
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
	cout << endl;
	return action;
}

// perform the given action from the user
bool performAction(char action, Player *player, Board &board){
	bool ret = true;
	if (action == 'n' || action == 's' || action == 'e' || action == 'w'){
		ret = player->move(action);
	} else if(action == 'a'){
		if (player->getArrows() != 0){
			string input;
			char direction;
			cout << "Which direction would you like to shoot? ";
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
			cout << "Out of arrows!" << endl;
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

// runs Wumpus Hunt
int main() {
	intro();
	Board board = Board();
	board.createBoard();
	Player *player = board.getPlayer();
	board.displayPlayer();
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