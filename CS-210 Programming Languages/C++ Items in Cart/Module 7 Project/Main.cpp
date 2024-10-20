/* 
* Armon Wilson
* SNHU
* CS210 - Programming Languages
* Module 7 - Project 3
*/

#include <iostream>
#include <fstream>
#include "ItemTracker.h"

using namespace std;

int main() {
	// Initialize map object
	ItemTracker itemTracker;

	//initialize user's choice
	int choice = 0;
	
	// start program loop, exits on user input 4
	while (choice != 4) {

		// output menu
		cout << endl << "Menu Options:" << endl;
		cout << endl;
		cout << "Option 1" << endl << "Find the frequency of a specific item." << endl;
		cout << endl << "Option 2" << endl << "Print the frequency of all items." << endl;
		cout << endl << "Option 3" << endl << "Print item frequiencies as a histogram." << endl;
		cout << endl << "Option 4" << endl << "Exit the program" << endl;
		cout << endl << "Enter your choice, 1 - 4." << endl;
		
		try {
			// retrieve user choice
			cin >> choice;
			if (cin.fail()) {
				throw invalid_argument("Invalid input. Please enter a valid option (1-4).");
			}

		}
		catch (const invalid_argument& e) {
			cerr << e.what() << endl;
			cin.clear();
			cin.ignore();
		}

		cout << endl;


		// user choice decision tree, calls appropriate method for each choice.
		switch (choice) {
		case 1: 
			itemTracker.FindItemFrequency();
			break;
		case 2:
			itemTracker.PrintAllItemFrequencies();
			break;
		case 3:
			itemTracker.PrintItemHistogram();
			break;
		case 4:
			cout << endl << "Exiting the program..." << endl;
			break;
		default:
			cout << endl << "Invalid choice.Please try again." << endl << endl;
			break;
		}
		
	}
	
	return 0;
}

