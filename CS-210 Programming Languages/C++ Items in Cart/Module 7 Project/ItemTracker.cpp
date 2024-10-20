/*
* Armon Wilson
* SNHU
* CS210 - Programming Languages
* Module 7 - Project 3
*/

#include <iostream>
#include <fstream>
#include <map>
#include "ItemTracker.h"
using namespace std;

void ItemTracker::ReadInputData() {
	// Open file
	ifstream inFS;
	inFS.open("CS210_Project_Three_Input_File.txt");

	// Verification file opened correctly
	if (!inFS.is_open()) {
		cout << "Error: Unable to open file." << endl;
		return;
	}

	// Map file to class object
	string item;
	while (!inFS.fail()) {
		inFS >> item;
		itemFrequency[item]++;
	}
	
	inFS.close();
}

void ItemTracker::WriteDataBackup() {
	// Create/Open file 
	ofstream outFS(dataFile);

	// print to dataFile each iteration of map object
	for (map <string, int> ::iterator it = itemFrequency.begin(); it != (itemFrequency.end()); ++it) {
		outFS << it->first << " " << it->second << endl;
	}
	
	outFS.close();

}

// constructor
ItemTracker::ItemTracker() {
	ReadInputData();
	WriteDataBackup();
}

void ItemTracker::FindItemFrequency() {

	string searchItem;
	cout << "Enter the item you wish to look for: " << endl << endl;
	cin >> searchItem;

	// if item to search for exists, output the item and its frequency.
	if (itemFrequency.count(searchItem) == 1) {
		cout << "Frequency of " << searchItem << " is " << itemFrequency.at(searchItem) << endl << endl;
	}
	else {
		cout << searchItem << " not found." << endl << endl;
	}

}

void ItemTracker::PrintAllItemFrequencies() {

	// iterate over map to print all items with frequencies. 
	for (map <string, int> :: iterator it = itemFrequency.begin(); it != (itemFrequency.end()); ++it) { 
		cout << it->first << " " << it->second << endl;
	}
}

void ItemTracker::PrintItemHistogram() {

	// iterate over map to print items with frequencies in histogram format
	for (map <string, int> ::iterator it = itemFrequency.begin(); it != (itemFrequency.end()); ++it) {
		cout << it->first << " ";
		// print a star for each occurance
		for (int i = 0; i < it->second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}
