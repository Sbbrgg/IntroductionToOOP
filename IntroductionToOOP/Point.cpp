#include "Point.h"
double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
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
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	cout << "Constructor:\t\t" << this << endl;
}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyConstructor: \t" << this << endl;

}
Point::~Point()
{
	cout << "Destructor:\t\t" << this << endl;
}

//				Operators:
Point& Point::operator = (const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

Point& Point::operator++()		//Prefix increment
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)	//Postfix (Suffix) increment
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
double Point::distance(const Point& other)const
{
	//this - эта точка (находим расстояние от этой точки)
	//other - та точка (до указанной точки)
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	//sqrt() - Square Root - (Квадратный корень)
	return distance;
}
void Point::print()const
{
	cout << this << ": X = " << x << ",\t Y = " << y << endl;
}

//double distance(const Point& A, const Point& B);
double distance(const Point& A, const Point& B)
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