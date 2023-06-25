#include <iomanip>
#include <iostream>
#include "savings.h"
using namespace std;

savings::savings(double investment, double monthDeposit, double rate, int years) {
	this->firstDepo = investment;
	this->newMonthlyDepo = monthDeposit;
	this->annualInterestRate = rate;
	this->numOfYears = years;
}

savings::~savings() {
}

void savings::reportNoMonthlyDeposits() {
		cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout << "========================================================================" << endl;
		// table
		cout << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	
	// interest
	int presentyear = 1;
	double endofyearBalance = this->firstDepo;
	while (presentyear <= this->numOfYears) {
		double earnedinterest = endofyearBalance * this->annualInterestRate / 100;
		endofyearBalance += earnedinterest;
		cout << right << setw(10) << presentyear << fixed << setprecision(2)
			<< setw(20) << endofyearBalance
			<< setw(35) << earnedinterest << endl;
			presentyear++;
	}
}

void savings::reportMonthlyDeposits() {
	cout << " Balance and Interest without additional Monthly Deposits" << endl;
	cout <<
		"========================================================================" << endl;
		cout << setw(10) << "Year"
		<< setw(20) << "Year End Balance"
		<< setw(35) << "Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	int presentyear = 1;
	double endofyearBalance = this->firstDepo;
	while (presentyear <= this->numOfYears) {
		int month = 1;
		double earnedinterest = 0.0;
		double endofmonthbalance = endofyearBalance;
		while (month <= 12) {
				endofmonthbalance += this->newMonthlyDepo;
			double monthlyinterest = endofmonthbalance * this->annualInterestRate / (100 * 12);
			earnedinterest += monthlyinterest;
			endofmonthbalance += monthlyinterest;
			month++;
		}
		
		endofyearBalance = endofmonthbalance;
		cout << right << setw(10) << presentyear << fixed << setprecision(2)
			<< setw(20) << endofyearBalance
			<< setw(35) << earnedinterest << endl;
		presentyear++;
	}
}