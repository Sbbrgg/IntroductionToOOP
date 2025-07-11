#pragma warning(disable: 4326)
#include<iostream>
using namespace std;

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DfeaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
	}
	/*explicit Fraction(double value)
	{
		this->integer = value;
		
		double fraction = value - this->integer;
		numerator = fraction * 1000;
		denominator = 1000;

		int GCD = gcd(numerator, denominator);

		numerator /= GCD;
		denominator /= GCD;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Fraction(double decimal)
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
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	const Fraction& operator++()
	{
		integer++;
		return *this;
	}
	const Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	const Fraction& operator--()
	{
		integer--;
		return *this;
	}
	const Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//			Type-cast operators:
	explicit operator int()const
	{
		//to_improper();
		return integer + numerator / denominator;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	
	//				Methods:
	Fraction& to_improper()
	{
		//перевод в неправильную дробь:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		//перевод в правильную дробь:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	int gcd(int a, int b) const		//НОД
	{
		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	Fraction& reduce()
	{
		int divisor = gcd(numerator, denominator);
		numerator /= divisor;
		denominator /= divisor;
		return *this;
	}
	void print()const
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
};

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
	return is;

	/*is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/
}
//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATORS
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
#define HAVE_A_NICE_DAY

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//default constructor
	A.print();

	Fraction B = 5;	//Single-Argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

#endif // CONSTRUCTORS_CHECK

	/*Fraction A(1, 2, 3);
	A.print();
	Fraction B(2, 3, 4);
	B.print();

	Fraction C = A * B;
	C.print();*/

#ifdef COMPARISON_OPERATORS
	cout << (2 == 3) << endl;
	cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS

#ifdef STREAMS_CHECK

	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif // STREAMS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2;		// No conversion
	double b = 3;	//Conversion from less to more
	int c = b;		//Convertion from more to less without data loss
	int d = 5.5;	//Convertion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;		//Single-Argument constructor
	cout << A << endl;

	Fraction B;
	B = (Fraction)8;				//1ArgConstructor->conversion(From less to more)
	//Single Argument Constructor создаёт из 8 временный 
	//безымянный объект, а оператор присваивания просто записывает его 
	//в существующий объект 'B'

#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	A.to_improper().print();
	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICE_DAY
	Fraction A = (Fraction)3.33;	//Conversion from double to 'Fraction'
	cout << A << endl;
#endif // HAVE_A_NICE_DAY

}