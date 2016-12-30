/*
Author: Keaton Ward
Net ID: 12KW32
System: Windows 7 64 bit
*/
#include "stdafx.h"
#include "fraction_12kw32.h"
#include <iostream>
#include <string>
using namespace std;

//Default constructor
Fraction::Fraction()
{
	Fraction::nume = 0;
	Fraction::denom = 1;
}

//Whole number constructor
Fraction::Fraction(int number)
{
	Fraction::nume = number;
	Fraction::denom = 1;
}

//Constructor to build Fractions
Fraction::Fraction(int numerator, int denominator)
{
	int m = numerator;
	int n = denominator;
	int GCD = findGCD(m, n);
	//Make sure the denominator isn't 0
	if (GCD == 0) {
		throw FractionException("Tried to divide by zero!");
	}
	//Change the numerator and denominator values
	m = m / GCD;
	n = n / GCD;
	//If numerator and denominator are negative, make them positive
	if (m < 0 && n < 0) {
		Fraction::nume = abs(m);
		Fraction::denom = abs(n);
	}
	//If the denominator is negative, express that in the numerator
	else if (denominator < 0) {
		Fraction::nume = (m *= -1);
		Fraction::denom = abs(n);
	}
	//If both are positive, don't change anything
	else {
		Fraction::nume = m;
		Fraction::denom = n;
	}

}

int Fraction::findGCD(int m, int n)
{
	int r;
	//Check for non-zero inputs
	if ((m == 0) || (n == 0))
		return 0;
	//Run a loop to find the GCD
	do
	{
		r = m % n;
		if (r == 0)
			break;
		m = n;
		n = r;
	} while (true);

	//Return absolute value for GCD, as this will be used to normalize fraction later
	//and we don't want it to be negative
	return abs(n);
}

//Accessor for numerator value
int Fraction::numerator()
{
	return nume;
}

//Accessor for denominator value
int Fraction::denominator()
{
	return denom;
}

//Pre-increment
Fraction& Fraction::operator++()
{
	nume += denom;
	return *this;
}

//Post-increment
Fraction Fraction::operator++(int)
{
	Fraction clone(nume, denom);
	nume += denom;
	return clone;
}

//Negation
Fraction & Fraction::operator-()
{
	nume *= -1;
	return *this;
}

//Plus equals
Fraction & Fraction::operator+=(const Fraction & f2)
{
	int denom1 = denom;
	int denom2 = f2.denom;
	//Need to find lowest common multiple on denominators in order to add them
	int LCM = findLCM(denom1, denom2);

	int factor1, factor2;

	//Determine what factor you need to multiply the numerators by once the denominator has been established
	factor1 = LCM / denom;
	factor2 = LCM / f2.denom;

	//Create the new numerator, set denominator to the LCM
	nume = nume*factor1 + f2.nume*factor2;
	denom = LCM;

	return *this;
}

//Used to check if the input is numeric and throw an exception if it's not
bool Fraction::isNumeric(string st)
{
	int len = st.length();
	for (int i = 0; i < len; i++) {
		if (int(st[i])<48 || int(st[i]) > 57) {
			return false;
		}
	}
	return true;
}

int* addition(int a0, int a1, int a2, int a3)
{
	Fraction frac1 = Fraction(a0, a1);
	Fraction frac2 = Fraction(a2, a3);
	Fraction ret = frac1 + frac2;
	int* results = new int[2];
	results[0] = ret.numerator();
	results[1] = ret.denominator();
	return results;
}

int* subtraction(int a0, int a1, int a2, int a3)
{
	Fraction frac1 = Fraction(a0, a1);
	Fraction frac2 = Fraction(a2, a3);
	Fraction ret = frac1 - frac2;
	int* results = new int[2];
	results[0] = ret.numerator();
	results[1] = ret.denominator();
	return results;
}

int* multiplication(int a0, int a1, int a2, int a3)
{
	Fraction frac1 = Fraction(a0, a1);
	Fraction frac2 = Fraction(a2, a3);
	Fraction ret = frac1 * frac2;
	int* results = new int[2];
	results[0] = ret.numerator();
	results[1] = ret.denominator();
	return results;
}

int* division(int a0, int a1, int a2, int a3)
{
	Fraction frac1 = Fraction(a0, a1);
	Fraction frac2 = Fraction(a2, a3);
	Fraction ret = frac1 / frac2;
	int* results = new int[2];
	results[0] = ret.numerator();
	results[1] = ret.denominator();
	return results;
}

//Find the lowest common multiple
int findLCM(int denom1, int denom2)
{
	//By default is one, tried with 0 and it gave me many divide by zero errors
	int LCM = 1;

	int i = 1;
	//Check which denominator is smaller. If they divide evenly, return that denominator
	if (denom1 < denom2) {
		if ((denom2 % denom1) == 0) {
			return denom2;
		}
		else {
			do {
				//Otherwise, find a multiple that divides evenly, return it
				if (((denom2 * i) % denom1) == 0) {
					return denom2 * i;
				}
				i++;
			} while (true);
		}
	}

	//Do the same thing if the second denominator is smaller
	else if (denom2 < denom1) {
		if ((denom1 % denom2) == 0) {
			return denom1;
		}
		else {
			do {
				if (((denom1 * i) % denom2) == 0) {
					return denom1 * i;
				}
				i++;
			} while (true);
		}
	}

	return LCM;
}

//Output operator
std::ostream & operator<<(std::ostream & os, const Fraction & f)
{
	os << f.nume << "/" << f.denom;
	return os;
}

//Input operator
std::istream & operator >> (std::istream & is, Fraction & f)
{
	string line;
	is >> line;
	int space = 0;
	//Split line at the '/' sign
	space = line.find('/');
	string temp = line.substr(0, space);
	//Check if the fraction is numeric. If not, throw exception
	if (Fraction::isNumeric(temp)) {
		f.nume = stoi(temp);
	}
	else {
		//The only thing I'm not happy with in this program is that I can't figure out how to have the program
		//continue running after this error is thrown. However, error checking wasn't specified in the assignment
		//anyways, so this should be fine
		throw FractionException("Next time, please enter a fraction in the form displayed above");
	}

	//If the above was successful, then find the denominator
	line = line.substr(space + 1);
	space = line.find('\0');
	temp = line.substr(0, space);
	f.denom = stoi(temp);
	if (f.denom == f.nume && space == -1) {
		f.denom = 1;
	}

	return is;
}

//Addition operator between two fractions
Fraction operator+(const Fraction & f1, const Fraction & f2)
{
	int denom1 = f1.denom;
	int denom2 = f2.denom;
	int LCM = findLCM(denom1, denom2);
	int factor1, factor2;

	factor1 = LCM / f1.denom;
	factor2 = LCM / f2.denom;

	return Fraction((f1.nume*factor1 + f2.nume*factor2), f1.denom*factor1);
}

//Addition operator between fraction and int
Fraction operator+(const Fraction & f, int num)
{
	int numerator = f.nume + f.denom*num;
	return Fraction(numerator, f.denom);
}

//Addition operator between int and fraction
Fraction operator+(int num, Fraction & f)
{
	int numerator = num*f.denom + f.nume;
	return Fraction(numerator, f.denom);
}

//Subtraction operator for two fractions
Fraction operator-(const Fraction & f1, const Fraction & f2)
{
	int denom1 = f1.denom;
	int denom2 = f2.denom;
	int LCM = findLCM(denom1, denom2);
	int factor1, factor2;

	factor1 = LCM / f1.denom;
	factor2 = LCM / f2.denom;

	return Fraction((f1.nume*factor1 - f2.nume*factor2), f1.denom*factor1);
	return Fraction();
}

//Subtraction operator between fraction and int
Fraction operator-(const Fraction & f, int num)
{
	int numerator = f.nume - f.denom*num;
	return Fraction(numerator, f.denom);
}

//Subtraction operator between int and fraction
Fraction operator-(int num, Fraction & f)
{
	int numerator = num*f.denom - f.nume;
	return Fraction(numerator, f.denom);
}

//Multiplication of two fractions
Fraction operator*(const Fraction & f1, const Fraction & f2)
{
	return Fraction(f1.nume*f2.nume, f1.denom*f2.denom);
}

//Multiplication of fraction and int
Fraction operator*(const Fraction & f, int num)
{
	return Fraction(f.nume*num, f.denom);
}

//Multiplication of int and fraction
Fraction operator*(int num, Fraction & f)
{
	return Fraction(f.nume*num, f.denom);
}

//Division of two fractions
Fraction operator/(const Fraction & f1, const Fraction & f2)
{
	return Fraction(f1.nume*f2.denom, f1.denom*f2.nume);
}

//Division of fraction by int
Fraction operator/(const Fraction & f, int num)
{
	return Fraction(f.nume, f.denom*num);
}

//Division of int by fraction
Fraction operator/(int num, Fraction & f)
{
	return Fraction(f.denom*num, f.nume);
}

//Equivalency test between two fractions
bool operator==(const Fraction & f1, const Fraction & f2)
{
	double frac1 = (double)f1.nume / f1.denom;
	double frac2 = (double)f2.nume / f2.denom;

	if (frac1 == frac2) {
		return true;
	}
	else {
		return false;
	}
}

//Inequivalency test between two fractions
bool operator!=(const Fraction & f1, const Fraction & f2)
{
	double frac1 = (double)f1.nume / f1.denom;
	double frac2 = (double)f2.nume / f2.denom;

	if (frac1 != frac2) {
		return true;
	}
	else {
		return false;
	}
}

//Less than or equal to test between two fractions
bool operator<=(const Fraction & f1, const Fraction & f2)
{
	double frac1 = (double)f1.nume / f1.denom;
	double frac2 = (double)f2.nume / f2.denom;

	if (frac1 < frac2 || frac1 == frac2) {
		return true;
	}
	else {
		return false;
	}
}

//Greater than or equal to test between two fractions
bool operator>=(const Fraction & f1, const Fraction & f2)
{
	double frac1 = (double)f1.nume / f1.denom;
	double frac2 = (double)f2.nume / f2.denom;

	if (frac1 > frac2 || frac1 == frac2) {
		return true;
	}
	else {
		return false;
	}
}

//Less than test between two fractions
bool operator<(const Fraction & f1, const Fraction & f2)
{
	double frac1 = (double)f1.nume / f1.denom;
	double frac2 = (double)f2.nume / f2.denom;

	if (frac1 < frac2) {
		return true;
	}
	else {
		return false;
	}
}

//Greater than test between two fractions
bool operator>(const Fraction & f1, const Fraction & f2)
{
	double frac1 = (double)f1.nume / f1.denom;
	double frac2 = (double)f2.nume / f2.denom;

	if (frac1 > frac2) {
		return true;
	}
	else {
		return false;
	}
}

//Less than test between int and fraction
bool operator<(int num, const Fraction & f)
{
	double value = (double)num;
	double frac = (double)f.nume / f.denom;

	if (num < frac) {
		return true;
	}
	else {
		return false;
	}
}

//Greater than test between fraction and int
bool operator>(const Fraction & f, int num)
{
	double value = (double)num;
	double frac = (double)f.nume / f.denom;

	if (num < frac) {
		return true;
	}
	else {
		return false;
	}
}

//FractionException method for handling exceptions
FractionException::FractionException(const std::string & message) : errmsg(message) {}
string& FractionException::what() { return errmsg; }