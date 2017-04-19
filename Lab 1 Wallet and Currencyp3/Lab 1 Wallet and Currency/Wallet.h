#ifndef WALLET_H
#define _CRT_SECURE_NO_WARNINGS
#define WALLET_H

#include "Currency.h"
#include <string>
#include <iostream>

using namespace std;

const int SIZE = 5;

class Wallet
{
	private:
		Currency * wallet[SIZE];

	public:
		Wallet(Currency*, Currency*, Currency*, Currency*, Currency*);
		~Wallet();

		void displayWallet();
		void addCurrency(Currency & newCurr, int index);
		void subtractCurrency(Currency & newCurr, int index);
		void clearWallet();

		Currency& operator[](const int nIndex);
};

#endif