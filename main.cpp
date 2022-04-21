#include <iostream>
#include <cstdio> 
#include <string>

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
		   "\t\t- h/H = pull up help menu\n\n" 
		   "\tMap Key:\n"
		   "\t\t- . = empty\n"
		   "\t\t- - = arrow\n" 
		   "\t\t- P = player\n" 
		   "\t\t- B = bats\n"
		   "\t\t- @ = hazard\n" 
		   "\t\t- ? = treasure\n" 
		   "\t\t- ! = monster\n\n" 
		   "Press X to exit help menu";
}

void intro(){
	cout << "Welcome to Wumpus Hunt. Find us a Wumpus!" << endl;
}

char getAction(){
	bool flag = true;
	char action;
	while(flag){
		cout << "Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: ";
		try {
			cin >> action;
			action = tolower(action);
		if (action == 'n' || action == 's' || action == 'e' || action == 'w' || action == 'a' || action == 'h' || action == 'q'){
			flag = false;
		} else{
			cout << "Invalid action!" << endl;
		}
		} catch (const exception& e){
			cout << "Invalid action!" << endl;
		}
	}
	return action;
}

bool performAction(char action){
	bool ret = true;
	if (action == 'n' || action == 's' || action == 'e' || action == 'w'){
		// player move (action)
		// ret = true 	-> if move was valid
		// ret = false	-> if player dead
	} else if(action == 'a'){
		// player shoot
		// ret = false 	-> if player shot wumpus 
		// ret = true 	-> if player miss wumpus 
	} else if (action == 'h'){
		// intro on how to play
	} else if (action == 'q'){
		return false;
	}
	return ret;
}

int main() {
	intro();
	bool flag = true;
	while (flag){
		char action = getAction();
		flag = performAction(action);
	}
	return 0;
}