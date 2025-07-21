#include"Fraction.h"
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//			Constructors:
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DfeaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "SingleArgumentConstructor:" << this << endl;
}
Fraction::Fraction(double decimal)
{
	//decimal - десятичная дробь
	decimal += 1e-10;
	integer = decimal;		//1) получаем целую часть дроби
	decimal -= integer;		//2) убирем целую часть из десятичной дроби
	denominator = 1e+9;		//3) получаем максимально возможный знаменатель
	//1e+9 = 1000000000;
	numerator = decimal * denominator;	//4) вытаскиваем дробную часть в числитель
	reduce();
	cout << "SingleArgumentConstructor:" << this << endl;
	/*this->integer = value;

	double fraction = value - this->integer;
	numerator = fraction * 1000;
	denominator = 1000;

	int GCD = gcd(numerator, denominator);

	numerator /= GCD;
	denominator /= GCD;
	cout << "SingleArgumentConstructor:" << this << endl;*/
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

//				Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

const Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
const Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
const Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}
const Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}

//			Type-cast operators:
Fraction::operator int()const
{
	//to_improper();
	return integer + numerator / denominator;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

//				Methods:
Fraction& Fraction::to_improper()
{
	//перевод в неправильную дробь:
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	//перевод в правильную дробь:
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
int Fraction::gcd(int a, int b) const		//НОД
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
Fraction& Fraction::reduce()
{
	int divisor = gcd(numerator, denominator);
	numerator /= divisor;
	denominator /= divisor;
	return *this;
}
void Fraction::print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}
	else if (integer == 0) cout << 0;
	cout << endl;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	/*Fraction result
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	};
	result.to_proper();
	*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();

}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(Fraction left, Fraction right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator<=(Fraction left, Fraction right)
{
	return !(left > right);
	//return left < right || left == right;
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;	//размер буфера ввода.
	char buffer[SIZE] = {};	//буфер ввода.
	is.getline(buffer, SIZE);
	int n = 0;	//количество введённых чисел
	const char delimiters[] = "(/, )";
	int numbers[3] = {};
	for (
		char* pch = strtok(buffer, delimiters);
		pch && n < 3;
		pch = strtok(NULL, delimiters)
		)
	{
		numbers[n++] = atoi(pch);	//atoi() - ASCII-string to integer
	}
	//for (int i = 0; i < n; i++) cout << numbers[i] << "\t";
	switch (n)
	{
	case 0: obj = Fraction(); break;
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0], numbers[1]); break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return is;
	/*
	int integer = 0, numerator = 0, denominator = 1;
	char symbol;

	if (is >> integer)
	{
		if (is >> symbol && symbol == '/')
		{
			numerator = integer;	//прочитанное кидаем в знаменатель
			is >> denominator;
			integer = 0;
		}
		else if (symbol == '(')
		{
			is >> numerator;
			if (is >> symbol && symbol == '/')
			{
				is >> denominator;
			}
		}
		else
		{
			is.putback(symbol);	//я не смог сделать формат целого числа
		}
	}
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/

	/*is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/
}