#define _CRT_SECURE_NO_WARNINGS
#include "Wallet.h"

Wallet::Wallet(Currency * curr1, Currency * curr2, Currency * curr3, Currency * curr4, Currency * curr5)
{
	wallet[0] = curr1;
	wallet[1] = curr2;
	wallet[2] = curr3;
	wallet[3] = curr4;
	wallet[4] = curr5;
}

Wallet::~Wallet()
{
}

//With the subscript overloaded, can print the array of objects
void Wallet::displayWallet()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << *wallet[i];
	}
}

//void Wallet::displayWallet()
//{
//	//Displaying USD Currency
//	cout << endl;
//	cout << "Displaying USD Currency" << endl;
//	cout << d->getCurrencyName() << ": " << d->getWhole() << endl;
//	cout << d->getFractionalName() << ": " << d->getFractional() << endl;
//	cout << "Total: " << d->getWhole() << "." << d->getFractional() << endl;
//
//	//Displaying Euro Currency
//	cout << endl;
//	cout << "Displaying Euro Currency" << endl;
//	cout << e->getCurrencyName() << ": " << e->getWhole() << endl;
//	cout << e->getFractionalName() << ": " << e->getFractional() << endl;
//	cout << "Total: " << e->getWhole() << "." << e->getFractional() << endl;
//
//	//Displaying Yen Currency
//	cout << endl;
//	cout << "Displaying Yen Currency" << endl;
//	cout << y->getCurrencyName() << ": " << y->getWhole() << endl;
//	cout << y->getFractionalName() << ": " << y->getFractional() << endl;
//	cout << "Total: " << y->getWhole() << "." << y->getFractional() << endl;
//
//	//Displaying Rupee Currency
//	cout << endl;
//	cout << "Displaying Rupee Currency" << endl;
//	cout << r->getCurrencyName() << ": " << r->getWhole() << endl;
//	cout << r->getFractionalName() << ": " << r->getFractional() << endl;
//	cout << "Total: " << r->getWhole() << "." << r->getFractional() << endl;
//	
//	//DIsplaying Peso Currency
//	cout << endl;
//	cout << "Displaying Peso Currency" << endl;
//	cout << p->getCurrencyName() << ": " << p->getWhole() << endl;
//	cout << p->getFractionalName() << ": " << p->getFractional() << endl;
//	cout << "Total: " << p->getWhole() << "." << p->getFractional() << endl;
//
//	cout << endl;
//}

//uses the overloaded operator+ to add Currency objects
void Wallet::addCurrency(Currency & newCurr, int index)
{
	*wallet[index] = *wallet[index] + newCurr;
}

//void Wallet::addCurrency()
//{
//	int menu_choice = 0;
//
//	while (menu_choice != 6)
//	{
//		cout << "Which currency would you like to add?" << endl;
//		cout << "1) USD" << endl;
//		cout << "2) Euros" << endl;
//		cout << "3) Yen" << endl;
//		cout << "4) Rupee" << endl;
//		cout << "5) Peso" << endl;
//		cout << "6) Go Back" << endl << endl;
//
//		cout << "Enter your choice: ";
//		cin >> menu_choice;
//
//		while (menu_choice < 1 || menu_choice > 6)
//		{
//			cout << endl << "Invalid input. Enter a number 1-6.";
//			cout << "Enter your choice: ";
//			cin >> menu_choice;
//		}
//		if (menu_choice == 1)
//		{
//			int addWhole;
//			cout << "You currently have " << d->getWhole() << "." << d->getFractional() << " USD total." << endl;
//			cout << "How much would you like to add?" << endl;
//			cin >> addWhole;
//
//
//			cout << "I have " << totalCurrency.getWhole() << "." << totalCurrency.getFractional() << " monies." << endl;
//		}
//	}
//}

void Wallet::subtractCurrency(Currency & newCurr, int index)
{
	*wallet[index] = *wallet[index] - newCurr;
}

//set all currency values to 0
void Wallet::clearWallet()
{
	int clear = 0;

	for (int i = 0; i < SIZE; i++)
	{
		wallet[i]->setWhole(clear);
		wallet[i]->setFractional(clear);
	}
	
}

//overload subscript
Currency& Wallet::operator[](const int nIndex)
{
	return *wallet[nIndex];
}

