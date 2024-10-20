#include <iostream>
using namespace std;

#include "Investment.h"

// initialize main()
int main() {

	bool exitProgram = false; // Boolean used to exit program
	Investment userInvestment; // User's investment object

	// Loop for program. Change boolean value to "true" to exit loop.
	while (!exitProgram) {

		// Get user input
		userInvestment.GetUserInput();

		// Calculate and output into formated table
		userInvestment.UserInvestmentOutput();

		// Continue program or exit
		cout << "Enter another investment?" << endl;
		cout << "Enter \"N\" (capitalized only) to exit. Otherwise, enter any other key to continue..." << endl;
		string exit;
		cin >> exit;
		if (exit == "N") {
			exitProgram = true;
		}
	}

	return 0;
}