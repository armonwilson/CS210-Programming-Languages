#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "Investment.h"

// Constructor
Investment::Investment() {
	initialInvestmentAmount = 0.0;
	monthlyDeposit = 0.0;
	recurringMonthlyDeposit = false;
	interestRate = 0.0;
	numYears = 0;
}


// Modifiers and Accessors 
void Investment::SetInitialInvestmentAmount(double userAmount) {
	initialInvestmentAmount = userAmount;
}

double Investment::GetInitialInvestmentAmount() {return initialInvestmentAmount;}
	
void Investment::SetMonthlyDeposit(double userMonthlyDeposit) {
	monthlyDeposit = userMonthlyDeposit;
	recurringMonthlyDeposit = (monthlyDeposit > 0.0);  // set Boolean for user monthly deposit
}

bool Investment::GetRecurringMonthlyDeposit() { return recurringMonthlyDeposit; }

double Investment::GetMonthlyDeposit() {return monthlyDeposit;}

void Investment::SetInterestRate(double userInterestRate) {interestRate = userInterestRate;}

double Investment::GetInterestRate() { return interestRate; }

void Investment::SetNumYears(int userNumYears) { numYears = userNumYears; }

int Investment::GetNumYears() { return numYears; }

// Retrieve user input for constructing the class
void Investment::GetUserInput() {
	double userInitialInvested;
	double userMonthlyDeposit;
	double userInterestRate;
	int userNumYears;


	// Output header formatting
	cout << setfill('=') << setw(30) << "=" << endl;
	cout << setfill('*') << setw(20) << " Data Input " << setfill('*') << setw(10) << "*" << endl;
	cout << setfill('=') << setw(30) << "=" << endl << endl;

	cout << "Initial Investment Amount: ";
	cin >> fixed >> setprecision(2) >> userInitialInvested;
	this->SetInitialInvestmentAmount(userInitialInvested);
	cout << "$" << this->GetInitialInvestmentAmount() << endl << endl;

	cout << "Monthly Deposit: ";
	cin >> fixed >> setprecision(2) >> userMonthlyDeposit;
	this->SetMonthlyDeposit(userMonthlyDeposit);
	cout << "$" << this->GetMonthlyDeposit() << endl << endl;

	cout << "Annual Interest: ";
	cin >> fixed >> setprecision(2) >> userInterestRate;
	this->SetInterestRate(userInterestRate);
	cout << "%" << this->GetInterestRate() << endl << endl;

	cout << "Number of years: ";
	cin >> userNumYears;
	this->SetNumYears(userNumYears);
	cout << this->GetNumYears() << endl << endl;

	cout << endl;
	cout << "Press any key to continue..." << endl;
	cin.ignore();
	cin.get();
}

// Calculate end of year (EOY) balance with deposits, stores them into passed vecter args
void Investment::EOY_BalanceWithDeposits(vector<double>& yearlyEarnedInterest, 
	vector<double>& yearlyEndBalance) {
	
	double monthlyInterestRate = interestRate / 100.0 / 12.0;
	double userTotal = initialInvestmentAmount;

	for (int year = 0; year < numYears; ++year) {
		double yearEndBalance = userTotal;
		double yearEarnedInterest = 0.0;

		for (int month = 0; month < 12; ++month) {
			// Calculate interest earned for the month
			double monthlyInterestEarned = yearEndBalance * monthlyInterestRate;

			// Update year-end balance and earned interest
			yearEndBalance += monthlyInterestEarned + monthlyDeposit;
			yearEarnedInterest += monthlyInterestEarned;
		}

		// Store year-end balances and earned interest in the vectors
		yearlyEarnedInterest.at(year) = yearEarnedInterest;
		yearlyEndBalance.at(year) = yearEndBalance;

		// Update initial investment for the next year
		userTotal = yearEndBalance + monthlyDeposit;
	}
}

// Calculate end of year (EOY) balance without deposits, stores them into passed vecter args
void Investment::EOY_BalanceWithoutDeposits(vector<double>& yearlyEarnedInterest, 
	vector<double>& yearlyEndBalance) {

	double monthlyInterestRate = interestRate / 100.0 / 12.0;
	double userTotal = initialInvestmentAmount;

	for (int year = 0; year < numYears; ++year) {
		double yearEndBalance = userTotal;
		double yearEarnedInterest = 0.0;

		for (int month = 0; month < 12; ++month) {
			// Calculate interest earned for the month
			double monthlyInterestEarned = yearEndBalance * monthlyInterestRate;

			// Update year-end balance and earned interest
			yearEndBalance += monthlyInterestEarned;
			yearEarnedInterest += monthlyInterestEarned;
		}

		// Store year-end balances and earned interest in the vectors
		yearlyEarnedInterest.at(year) = yearEarnedInterest;
		yearlyEndBalance.at(year) = yearEndBalance;

		// Update initial investment for the next year
		userTotal = yearEndBalance;
	}
}

void Investment::UserInvestmentOutput() {
	// Vector args to pass to EOY calculation functions
	vector<double> yearlyEarnedInterest(numYears);
	vector<double> yearlyEndBalance(numYears);

	cout << setfill('=') << setw(55) << "=" << endl;

	// Determine if output will print with or without monthly deposit calculations
	if (recurringMonthlyDeposit) {
		cout << " Balance and Interest With Additional Monthly Deposits" << endl;
		EOY_BalanceWithDeposits(yearlyEarnedInterest, yearlyEndBalance);
	}
	else {
		cout << " Balance and Interest Without Additional Monthly Deposits" << endl;
		EOY_BalanceWithoutDeposits(yearlyEarnedInterest, yearlyEndBalance);
	}

	// Table formatting
	cout << setfill('=') << setw(55) << "=" << endl;
	cout << flush;

	cout << left << setw(8) << setfill(' ') << " Year" << setw(21) << "Year End Balance"
		<< right << setw(16) << "Year End Earned Interest" << endl;
	
	cout << setfill(' ') << setw(55) << " " << endl;

	// Output vectors in formatting
	for (int year = 0; year < numYears; ++year) {
		cout << setw(3) << year + 1 << setw(15) << fixed << setprecision(2) << yearlyEndBalance[year]
			<< setw(20) << yearlyEarnedInterest[year] << endl;
	}

	cout << endl;

}