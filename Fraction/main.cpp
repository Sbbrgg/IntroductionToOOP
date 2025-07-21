#pragma warning(disable: 4326)
#include"Fraction.h"
//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATORS
#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_DAY

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