#include <iostream>
#include <cstdio> 
#include <string>

using namespace std;

string how_to_play() {
	return "How to Play:\n" +
		   "\tCommands:\n" +
		   "\t\t- n/N = move north/up\n" +
		   "\t\t- e/E = move east/right\n" + 
		   "\t\t- s/S = move south/down\n" + 
		   "\t\t- w/W = move west/left\n" +
		   "\t\t- d/D = debug mode\n" + 
		   "\t\t- m/M = view map\n" + 
		   "\t\t- a/A = shoot arrow\n" + 
		   "\t\t- h/H = pull up help menu\n\n" + 
		   "\tMap Key:\n" +
		   "\t\t- . = empty\n" +
		   "\t\t- - = arrow\n" + 
		   "\t\t- P = player\n" + 
		   "\t\t- B = bats\n" +
		   "\t\t- @ = hazard\n" + 
		   "\t\t- ? = treasure\n" + 
		   "\t\t- ! = monster\n\n" + 
		   "Press X to exit help menu";
}


int main() {
	return 0;
}