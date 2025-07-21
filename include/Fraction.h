#pragma once
#include<iostream>
using namespace std;

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//			Constructors:
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//				Operators:
	Fraction& operator=(const Fraction& other);

	const Fraction& operator++();
	const Fraction operator++(int);
	const Fraction& operator--();
	const Fraction operator--(int);

	//			Type-cast operators:
	explicit operator int()const;
	explicit operator double()const;

	//				Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	int gcd(int a, int b) const;	//НОД
	Fraction& reduce();
	void print()const;
};

Fraction operator*(Fraction left, Fraction right);

bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);