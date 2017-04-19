#define _CRT_SECURE_NO_WARNINGS
#include "Currency.h"

using namespace std;

Currency::Currency()
{
	currency_name = "";
	fractional_name = "";
	whole = 0;
	fractional = 0;
}

Currency::Currency(string wn, string fn) : currency_name(wn), fractional_name(fn)
{
	whole = 0;
	fractional = 0;
}

Currency::Currency(int w, int f) : whole(w), fractional(f)
{
	currency_name = "";
	fractional_name = "";
}

Currency::~Currency()
{

}

void Currency::setCurrencyName(string cn)
{
	currency_name = cn;
}

void Currency::setWhole(int w)
{
	whole = w;
}

void Currency::setFractional(int f)
{
	fractional = f;
}

void Currency::setFractionalName(string fn)
{
	fractional_name = fn;
}

string Currency::getCurrencyName() const
{
	return currency_name;
}

int Currency::getWhole() const
{
	return whole;
}

int Currency::getFractional() const
{
	return fractional;
}

string Currency::getFractionalName() const
{
	return fractional_name;
}

void Currency::calcRealTotal()
{
	//converting cents into dollars & cents
	if (fractional > 100)
	{
		whole += (fractional / 100);
		fractional = fractional % 100;
	}
	//when subtracting fractional and it goes negative, get value from whole
	else if (fractional < 0)
	{
		whole -= ((abs(fractional) / 100) + 1);
		fractional = 100 - (abs(fractional) % 100);
	}
}

ostream &operator<< (ostream &output, Currency &tCurrency)
{
	output << setw(10) << tCurrency.currency_name << ": " << setw(5) << tCurrency.whole << endl;
	output << setw(10) << tCurrency.fractional_name << ": " << setw(5) << tCurrency.fractional << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;

	return output;
}

istream &operator>> (istream &input, Currency &tCurrency)
{
	input >> tCurrency.whole >> tCurrency.fractional;

	return input;
}

Currency Currency::operator+(const Currency &c1)
{
	Currency currency;

	currency.currency_name = this->currency_name;
	currency.fractional_name = this->fractional_name;
	currency.whole = this->whole + c1.whole;
	currency.fractional = this->fractional + c1.fractional;
	currency.calcRealTotal();

	return currency;
}

Currency Currency::operator-(const Currency &c1)
{
	Currency currency;

	currency.currency_name = this->currency_name;
	currency.fractional_name = this->fractional_name;
	currency.whole = this->whole - c1.whole;
	currency.fractional = this->fractional - c1.fractional;
	currency.calcRealTotal();

	return currency;
}


//USD class derived from Currency
USD::USD()
{
	setCurrencyName("Dollars");
	setWhole(0);
	setFractional(0);
	setFractionalName("Cents");
}

USD::~USD()
{
}

//Euro class derived from Currency
Euro::Euro()
{
	setCurrencyName("Euro");
	setWhole(0);
	setFractional(0);
	setFractionalName("Cents");
}

Euro::~Euro()
{
}

//Yen class derived from Currency
Yen::Yen()
{
	setCurrencyName("Yen");
	setWhole(0);
	setFractional(0);
	setFractionalName("Sen");
}

Yen::~Yen()
{
}

//Rupee class derived from Currency
Rupee::Rupee()
{
	setCurrencyName("Rupee");
	setWhole(0);
	setFractional(0);
	setFractionalName("Paisa");
}

Rupee::~Rupee()
{
}

//Peso class derived from Currency
Peso::Peso()
{
	setCurrencyName("Peso");
	setWhole(0);
	setFractional(0);
	setFractionalName("Centavo");
}

Peso::~Peso()
{
}