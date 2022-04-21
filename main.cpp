#include <iostream>
#include <cstdio> 
#include <string>

using namespace std;

void intro(){
	cout << "Welcome to Wumpus Hunt. Find us a Wumpus!" << endl;
}

char getAction(){
	bool flag = true;
	char action;
	while(flag){
		cout << "Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: ";
		cin >> action;
		if (action == 'n' || action == 's' || action == 'e' || action == 'w' || action == 'a' || action == 'h' || action == 'q'){
			flag = false;
		} else{
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