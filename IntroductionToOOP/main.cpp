#pragma warning(disable:4326)
#include<iostream>
#include<math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-------------------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors;
	
	/*Point()
	{
		x = y = 0;
		cout << "Default constructors: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
		//конструктор с одним параметром
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t" << this << endl;

	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++()		//Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)	//Postfix (Suffix) increment
	{
		Point old = *this;	//Сохраняем старое значение объекта
		x++;
		y++;
		return old;
	}
	//				Methods;
	/*double distance()const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}*/
	/*	double distance(const Point& second = {})const
	{
		return sqrt(pow(second.x - this->x, 2) + pow(second.y - this->y, 2));
	}*/
	double distance(const Point& other)const
	{
		//this - эта точка (находим расстояние от этой точки)
		//other - та точка (до указанной точки)
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt() - Square Root - (Квадратный корень)
		return distance;
	}
	void print()const
	{
		cout << this << ": X = " << x << ",\t Y = " << y << endl;
	}
};

//double distance(const Point& A, const Point& B);
double distance(const Point& A,const Point& B)
{

	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	/*
	if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;
	*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!=(const  Point& left, const Point& right)
{
	return !(left == right);
}
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENTS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;		//Объявление переменной 'а' типа 'int'
	Point A;	//Объявление переменной 'А' типа 'Point'
	//Создание объекта 'А' структуры 'Point'
	//Создание экземпляра 'А' структуры 'Point'
	//'A' is instance of struct 'Point'
	//Instantiate - создать объект
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pa = &A;

	cout << pa->x << "\t" << pa->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << delimiter << endl;
	cout << "Расстояние от A до B (метод): " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от B до A (метод): " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от A до начала координат: " << A.distance(B) << endl;
	cout << delimiter << endl;

	cout << "Расстояние от A до B (функцией): " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от B до A (функцией): " << distance(B, A) << endl;

#endif // DISTANCE_CHECK
#ifdef CONSTRUCTORS_CHECK
	Point A;			//Здесь просто создаём объект, и для этого неявно вызывается конструктор по умолчанию
	A.print();
	/*{
		Point B;
		cout << "Point B существует" << endl;
		B.distance(A);
	}
	cout << "Point A не существует" << endl;*/

	Point B = 5;		//Single-argument constructor - Конструктор с одним параметром
	B.print();

	Point C(7, 8);
	C.print();

	Point D = C;		//Copy constructor
	D.print();

	Point E;			//Default constructor
	E = D;				//Assignment operator:
	E.print();

#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENTS_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << "\t" << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENTS_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	A = B++;
	A.print();
	B.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

	cout << (Point(2, 3) != Point(1, 3)) << endl;
	
}

//double distance(const Point& A, const Point& B)
//{
//	return sqrt( pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
//}
