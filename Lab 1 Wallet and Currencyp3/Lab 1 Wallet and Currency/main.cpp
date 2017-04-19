#include "Wallet.h"
#include "Currency.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void mainMenu(Wallet&);
void addition(Wallet &);
void subtraction(Wallet &);
int currencyMenu();
Currency inputAmount();

int main()
{
	//instantiating currencies objects
	Currency * d = new USD();
	Currency * e = new Euro();
	Currency * y = new Yen();
	Currency * r = new Rupee();
	Currency * p = new Peso();

	//instantiating wallet objects with curremcy objects in param
	Wallet myWallet(d, e, y, r, p);

	mainMenu(myWallet);

	//delete currencies
	delete d;
	delete e;
	delete y;
	delete r;
	delete p;

}

void mainMenu(Wallet & myWallet)
{
	int menu_choice = 0;

	while (menu_choice != 5)
	{
		cout << endl;
		cout << "\tMain Menu " << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1) Display Wallet " << endl;
		cout << "2) Add Currency " << endl;
		cout << "3) Subtract Currency " << endl;
		cout << "4) Clear Wallet " << endl;
		cout << "5) Exit the program " << endl << endl;

		cout << "Enter your choice: ";
		cin >> menu_choice;

		while (menu_choice < 1 || menu_choice > 5)
		{
			cout << endl << "Invalid input. Enter a number 1-5." << endl;
			cout << "Enter your choice: ";
			cin >> menu_choice;
		}

		switch (menu_choice)
		{
		case 1:
			myWallet.displayWallet();
			break;
		case 2:
			addition(myWallet);
			break;
		case 3:
			subtraction(myWallet);
			break;
		case 4:
			cout << "Wallet contents have been cleared." << endl << endl;
			myWallet.clearWallet();
			myWallet.displayWallet();
			break;
		case 5: //will not display message, exits the first while loop
			cout << "Exiting Program";
			break;
		}
	}
}

void addition(Wallet &myWallet)
{
	int walletIndex;
	Currency amount;

	walletIndex = currencyMenu();
	amount = inputAmount();

	myWallet.addCurrency(amount, walletIndex);
}

void subtraction(Wallet &myWallet)
{
	int walletIndex;
	Currency amount;

	walletIndex = currencyMenu();
	amount = inputAmount();

	myWallet.subtractCurrency(amount, walletIndex);
}

int currencyMenu()
{
	int currency_choice = 0;
	string input = "";
	bool good = false;

	do
	{
		cout << endl;
		cout << "\tCurrency Menu " << endl << endl;
		cout << "1) Dollars " << endl;
		cout << "2) Euros " << endl;
		cout << "3) Yen " << endl;
		cout << "4) Rupee " << endl;
		cout << "5) Peso " << endl;
		//cout << "6) Return to Main Menu" << endl << endl;

		cout << "Enter your choice: ";

		getline(cin, input);

		stringstream stream(input);

		stream >> fixed >> setprecision(2) >> currency_choice;

		//validate input
		if (currency_choice < 1 || currency_choice > 6)
		{
			cout << endl << "Invalid input. Enter a number 1-5." << endl;
		}
		else
		{
			good = true;
		}

	} while (good == false);

	return currency_choice - 1;
}

Currency inputAmount()
{
	int wholeNum;
	int fractionalNum;
	double currency;
	bool good = false;
	Currency amount;
	string input = "";
	stringstream stream;

	do
	{
		cout << "Enter the amount of currency: " << endl;

		getline(cin, input);
		stream << input;
		stream >> fixed >> setprecision(2) >> currency;

		//validate input
		if (currency >= 0)
			good = true;
		else
			cout << "Invalid input. Please try again.\n";

	} while (good == false);

	//clear
	stream.str("");
	stream.clear();

	//double into two integers
	wholeNum = currency;
	fractionalNum = (currency - wholeNum) * 100;
	stream << wholeNum << " " << fractionalNum;

	stream >> amount;

	return amount;
}
