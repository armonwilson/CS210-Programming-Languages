#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


/*
* Armon Wilson
* SNHU
* CS-210-R1800
* 9/17/2023
*/


using namespace std;

// Used to initialize the time. Passes user input to time variables. 
void InitializeTime(int& hour, int& minute, int& second) {
	bool valid = false;
	while (!valid) {	// Will loop until user inputs correct values.

		// Collect user input
		cout << "Initialize the hour (0 - 24):" << endl;
		cin >> hour;
		cout << "Initialize the minute (0 - 59):" << endl;
		cin >> minute;
		cout << "Initialize the second (0-59):" << endl;
		cin >> second;

		// User input validation. Must be integer and valid number for variable.
		if ((hour <= 24) && (minute < 60) && (second < 60)) {
			valid = true;
		}
	}
}

// format numbers as two digits. Leading 0 on 1-9
void FormatNumbers(string& digits) {
	if (digits.size() < 2) {
		digits = "0" + digits;
	}
}

// Top and bottom border string
void starRepeat() {
	cout << setfill('*') << setw(26) << "*" << endl;
}

// Outputs time using 24-hour format
//TODO: test complete
void MilTimeFormat(int hour, int min, int second) {
	string milClockText = "24 - Hour Clock";
	string milClock;
	int width = 26;

	// fixes hour to 0-23 for 24hr format
	if (hour > 23) {
		hour = 0;
	}

	// Convert hour, min, second to string and format with "milClock"
	string hourStr = to_string(hour);
	string minStr = to_string(min);
	string secStr = to_string(second);

	FormatNumbers(hourStr);
	FormatNumbers(minStr);
	FormatNumbers(secStr);

	milClock = hourStr + ":" + minStr + ":" + secStr;

	starRepeat();
	
	// output milClockText with formatting (text centered)
	cout << setfill(' ');
	cout << "*";
	cout << setw(((width - milClockText.size()) / 2) ) << left << " ";
	cout << milClockText;
	cout << setw(((width - milClockText.size()) / 2) -1) << left << " ";
	cout << "*" << endl;

	//output milClock with formatting (text centered)
	cout << "*";
	cout << setw(((width - milClock.size()) / 2) - 1) << left << " ";
	cout << milClock;
	cout << setw(((width - milClock.size()) / 2) - 1) << left << " ";
	cout << "*" << endl;

	starRepeat();
	cout << endl;
}

//Outputs time in standard 12hr format
void StdTimeFormat(int hour, int minute, int second) {
	string clockText = "12 - Hour Clock";
	string clock;
	int width = 26;
	string timeOfDay;
	
	// asign AM or PM to string and fixes hour to 12 hour format.
	if (hour > 12) {
		hour -= 12;
		timeOfDay = "P.M.";
	}
	else {
		timeOfDay = "A.M.";
	}
	
	// Convert hour, min, second to strings for easy formatting  
	string hourStr = to_string(hour);
	string minStr = to_string(minute);
	string secStr = to_string(second);
	bool isAM = true; // for AM or PM

	// format clock numbers (already converted to strings)
	FormatNumbers(hourStr);
	FormatNumbers(minStr);
	FormatNumbers(secStr);

	// set output string
	clock = hourStr + ":" + minStr + ":" + secStr + " " + timeOfDay;

	starRepeat();

	// output milClockText with formatting (text centered)
	cout << setfill(' ');
	cout << "*";
	cout << setw(((width - clockText.size()) / 2)) << left << " ";
	cout << clockText;
	cout << setw(((width - clockText.size()) / 2) - 1) << left << " ";
	cout << "*" << endl;

	//output milClock with formatting (text centered)
	cout << "*";
	cout << setw(((width - clock.size()) / 2) - 1) << left << " ";
	cout << clock;
	cout << setw(((width - clock.size()) / 2)) << left << " ";
	cout << "*" << endl;
	starRepeat();
	cout << endl;
}

//Prints out the menu illustrated in the project and functional requirements documentation.
void DisplayMenu() {
	cout << endl;
	starRepeat();
	cout << setfill(' ');
	cout << setw(25) << left << "* 1 - Add One Hour" << "*" << endl;
	cout << setw(25) << left << "* 2 - Add One Minute" << "*" << endl;
	cout << setw(25) << left << "* 3 - Add One Second" << "*" << endl;
	cout << setw(25) << left << "* 4 - Exit Program" << "*" << endl;
	starRepeat();
	cout << "" << endl;
}

// Add second to clock 
void AddSecond(int& second) {
	second += 1;
	if (second > 59) {
		second = 0; 
	}
}

// Add minute to clock
void AddMinute(int& minute) {
	minute += 1;
	if (minute > 59) {
		minute = 0; 
	}
}

// Add hour to clock
void AddHour(int& hour) {
	hour += 1;
	if (hour > 24) {
		hour = 1;
	}
}

// Processes user input from the menu choices in the user interface.
void UserChoice(bool& exit, int& hour, int& minute, int& second) {
	int userInput;

	cin >> userInput;

	if ((userInput >= 1) && (userInput <= 4)) {

		if (userInput == 1) {
			AddHour(hour);
		}
		if (userInput == 2) {
			AddMinute(minute);
		}
		if (userInput == 3) {
			AddSecond(second);
		}
		if (userInput == 4) {
			exit = true;
		}
	}
}

// outputs formatted time with border formatting
void DisplayTime(int hour, int minute, int second) {

	StdTimeFormat(hour, minute, second);
	MilTimeFormat(hour, minute, second);
}