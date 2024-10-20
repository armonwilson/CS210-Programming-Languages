#pragma once
#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
#include <vector>
using  namespace std;

class Investment {
	public:
		//Constructor
		Investment();
		// Accessors and Modifiers
		void SetInitialInvestmentAmount(double userAmount);
		double GetInitialInvestmentAmount();
		void SetMonthlyDeposit(double userMonthlyDeposit);
		double GetMonthlyDeposit();
		bool GetRecurringMonthlyDeposit();
		void SetInterestRate(double userInterestRate);
		double GetInterestRate();
		void SetNumYears(int userNumYears);
		// Functions
		int GetNumYears();
		void GetUserInput();
		void EOY_BalanceWithDeposits(vector<double>& yearlyEarnedInterest, vector<double>& yearlyEndBalance);
		void EOY_BalanceWithoutDeposits(vector<double>& yearlyEarnedInterest, vector<double>& yearlyEndBalance);
		void UserInvestmentOutput();

	private:
		// Variables
		double initialInvestmentAmount;
		double monthlyDeposit;
		bool recurringMonthlyDeposit;
		double interestRate;
		int numYears;
};

#endif // !Investment_H
