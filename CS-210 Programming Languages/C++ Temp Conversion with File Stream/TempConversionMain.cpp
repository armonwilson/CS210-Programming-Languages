#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>
#include <vector>
using namespace std;


int main() {
	ifstream inFS;  //Input file stream
	ofstream outFS;  //Output file steam
	vector<string> city(6);
	vector<double> cityTempF(6);
	vector<double> cityTempC(6);

	// open file (with verification that file opened correctly)
	inFS.open("FahrenheitTemperature.txt");
		if (!inFS.is_open()) {
			cout << "FahrenheitTemperature.txt failed to open." << endl;
			return 1;
		}

// Read file to Vectors
int i = 0;
	while (!inFS.eof()) {

		inFS >> city.at(i);
		inFS >> cityTempF.at(i);
		if (!inFS.fail()) {
			++i;
		}
	}

	inFS.close();


	// convert F to C
	i = 0;
	for (i = 0; i < 6; ++i) {
		cityTempC.at(i) = (cityTempF.at(i) - 32.0) * (5.0 / 9.0);
	}

	// test output
/*
	i = 0;
	for (i = 0; i < 6; ++i) {
		cout << fixed << setprecision(1) << cityTempC.at(i) << endl;
	}
*/

	outFS.open("CelsiusTemperature.txt");
	if (!outFS.is_open()) {
		cout << "Failed to open CelsiusTemperature.txt" << endl;
		return 2;
	}

	i = 0;
	for (i = 0; i < 6; ++i) {
		outFS << fixed << setprecision(1) << city.at(i) << " " << cityTempC.at(i) << endl;
	}

	outFS.close();

	return 0;
}