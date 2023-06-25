#include <iostream>
#include "savings.h"
#Justin Murray
using namespace std;
int main() {
	while (1) {
		//Heading and userinput
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
		//system("PAUSE");
		system("read -p 'Press Enter to continue . . .' var");
		cout << endl;
		
		cout << "*************************************" << endl;
		cout << "*************Data Input**************" << endl;
		cout << "Initial Investment Amount: $";
		double investment, depositmonthly, rateofinterest;
		int years;

		cin >> investment;
		cout << "Monthly Deposit: $";

		cin >> depositmonthly;
		cout << "Annual Interest: %";

		cin >> rateofinterest;
		cout << "Number of years: ";
			cin >> years;
		//system("PAUSE");
		system("read -p 'Press Enter to continue . . .' var");
		// create a savings
		savings mycurrentsavings = savings(investment, depositmonthly, rateofinterest, years);
		cout << endl;
		mycurrentsavings.reportNoMonthlyDeposits();
		cout << endl;

		if (depositmonthly > 0) {
			mycurrentsavings.reportMonthlyDeposits();
		}
		// continue
		cout << endl << "Do you want to try another? (y/n): ";

		string choice;
		cin >> choice;

		// Break the loop if the user doesn't wish to try another
		if (choice != "y") {
			break;
		}
		cout << endl;
	}
	return 0;
}