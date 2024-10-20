#include <iostream>
#include <vector>
#include "Header.h"

/* 
* Armon Wilson
* SNHU 
* CS-210-R1800
* 9/17/2023
*/


using namespace std;

// main()
int main() {
	int hour;
	int minute;
	int second;

	InitializeTime(hour, minute, second);

	// boolean value to exit loop
	bool loopExit = false;

	// Main() loop start:
	while (!loopExit) {

		DisplayMenu();

		UserChoice(loopExit, hour, minute, second);

		DisplayTime(hour, minute, second);

	}
	return 0;
}