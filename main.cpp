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

char getAction(){
	bool flag = true;
	string input;
	char action;
	while(flag){
		cout << "Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: ";
		try {
			cin >> input;
			if (input.length() == 1){
				action = input[0];
				action = tolower(action);
				if (action == 'n' || action == 's' || action == 'e' || action == 'w' || action == 'a' || action == 'h' || action == 'q'){
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

bool performAction(char action, Player *player){
	bool ret = true;
	if (action == 'n' || action == 's' || action == 'e' || action == 'w'){
		ret = player->move(action);
	} else if(action == 'a'){
		char direction;
		cout << "Which direciton you shootin' dawg? ";
		cin >> direction;
		player->shoot(direction);
	} else if (action == 'h'){
		cout << how_to_play() << endl;
	} else if (action == 'q'){
		return false;
	}
	return ret;
}

bool debugMode(){
	string input;
	bool ret = false;
	cout << "Debug mode? Yes or No (y/n): ";
	cin >> input;
	cout << endl;
	if (input == "y"){
		ret = true;
	}
	return ret;
}

int main() {
	Board board = Board();
	board.createBoard();
	Player *player = board.getPlayer();
	bool debug = debugMode();
	intro();
	bool flag = true;
	while (flag){
		if(debug){
			board.displayBoard();
		}
		char action = getAction();
		flag = performAction(action, player);
	}
	return 0;
}