#ifndef CURRENCY_H
#define _CRT_SECURE_NO_WARNINGS
#define CURRENCY_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Currency
{
	private:
		string currency_name;	//USD, Euro, Yen, Rupee, Peso
		int whole;				//1
		int fractional;			//50	
		string fractional_name;	//Cents, Cents, Sen, Paisa, Centavo

	public:
		Currency();
		Currency(int, int);
		Currency(string, string);

		virtual ~Currency();

		//setters
		void setCurrencyName(string);
		void setWhole(int);
		void setFractional(int);
		void setFractionalName(string);

		//getters
		string getCurrencyName() const;
		int getWhole() const;
		int getFractional() const;
		string getFractionalName() const;

		void calcRealTotal();

		//overloading the + 
		Currency operator+(const Currency &);
		//overloading the -
		Currency operator-(const Currency &);
		//overloading input stream
		friend istream &operator>>(istream &input, Currency &tCurrency);
		//overloading output stream
		friend ostream &operator<<(ostream &output, Currency &tCurrency);
};

class USD : public Currency
{
	public:
		//constructor
		USD();

		//destructor
		~USD();
};

class Euro : public Currency
{
	public:
		//constructor
		Euro();

		//destructor
		~Euro();
};

class Yen : public Currency
{
	public:
		//constructor
		Yen();

		//destructor
		~Yen();
}; 

class Rupee : public Currency
{
	public:
		//constructor
		Rupee();

		//destructor
		~Rupee();
};

class Peso : public Currency
{
	public:
		//constructor
		Peso();

		//destructor
		~Peso();
};
#endif
