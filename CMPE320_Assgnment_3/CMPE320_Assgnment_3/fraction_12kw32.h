#pragma once
#ifdef FRACTION12KW32_EXPORTS
#define FRACTION12KW32 __declspec(dllexport)
#else
#define FRACTION12KW32 __declspec(dllimport)
#endif
#include <iostream>

using namespace std;

FRACTION12KW32 int* addition(int a0, int a1, int a2, int a3);
FRACTION12KW32 int* subtraction(int a0, int a1, int a2, int a3);
FRACTION12KW32 int* multiplication(int a0, int a1, int a2, int a3);
FRACTION12KW32 int* division(int a0, int a1, int a2, int a3);

class Fraction {
private:	
	//Numerator
	int nume;
	//Denominator
	int denom;
public:
	//Defualt constructor
	Fraction();
	//Whole number constructor
	Fraction(int number);
	//Fraction constructor
	Fraction(int numerator, int denominator);
	//Finds the greatest common denominator of two numbers
	int findGCD(int nume, int denom);
	//Finds the lowest common multiple of two numbers
	friend int findLCM(int denom1, int denom2);
	//Accessor for numerator
	int numerator();
	//Accessor for denominator
	int denominator();
	//Overload >> operator to build new Fraction
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
	//Overload << operator to output Fraction values
	friend std::istream& operator>> (std::istream& is, Fraction& f);
	//Overload + operator to add two Fractions
	friend Fraction operator + (const Fraction& f1, const Fraction& f2);
	//Overload + operator to add a Fraciton and an integer
	friend Fraction operator + (const Fraction& f, int num);
	//Overload + operator to add an integer and a Fraction
	friend Fraction operator + (int num, Fraction& f);
	//Overload - operator to subtract two Fractions
	friend Fraction operator - (const Fraction& f1, const Fraction& f2);
	//Overload - operator to subtract a Fraciton and an integer
	friend Fraction operator - (const Fraction& f, int num);
	//Overload - operator to subract an integer and a Fraction
	friend Fraction operator - (int num, Fraction& f);
	//Overload * operator to multiply two Fractions
	friend Fraction operator * (const Fraction& f1, const Fraction& f2);
	//Overload * operator to multiply a Fraciton and an integer
	friend Fraction operator * (const Fraction& f, int num);
	//Overload * operator to multiply an integer and a Fraction
	friend Fraction operator * (int num, Fraction& f);
	//Overload / operator to divide two Fractions
	friend Fraction operator / (const Fraction& f1, const Fraction& f2);
	//Overload / operator to divide a Fraciton by an integer
	friend Fraction operator / (const Fraction& f, int num);
	//Overload / operator to divide an integer by a Fraction
	friend Fraction operator / (int num, Fraction& f);
	//Overload == operator to test if two fractions are equal
	friend bool operator == (const Fraction& f1, const Fraction& f2);
	//Overload != operator to test if two fractions aren't equal
	friend bool operator != (const Fraction& f1, const Fraction& f2);
	//Overload <= operator to test for less than/equal to between two Fractions
	friend bool operator <= (const Fraction& f1, const Fraction& f2);
	//Overload >= operator to test for greater than/equal to between two Fractions
	friend bool operator >= (const Fraction& f1, const Fraction& f2);
	//Overload < operator to test for less than between two Fractions
	friend bool operator < (const Fraction& f1, const Fraction& f2);
	//Overload > operator to test for greater than between two Fractions
	friend bool operator > (const Fraction& f1, const Fraction& f2);
	//Overload < operator to test for less than between an integer and a Fraction
	friend bool operator < (int num, const Fraction& f);
	//Overload > operator to test for greater than between a Fraction and an integer
	friend bool operator > (const Fraction& f, int num);
	//Post increment
	Fraction operator++(int);
	//Pre-increment
	Fraction& operator++();
	//Negation
	Fraction& operator-();
	//Plus equal operator
	Fraction& operator+=(const Fraction& f2);
	static bool isNumeric(string st);

};

class FractionException {
private:
	std::string errmsg; //attribute = supplied message
public:
	FractionException(const std::string& message); //constructor
	std::string& what(); //what function returns the attribute
};
/* fraction_12kw32_h */