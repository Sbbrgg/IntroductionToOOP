#pragma once
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
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

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
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	//				Operators:
	Point& operator = (const Point& other);
	Point& operator++();	//Prefix increment
	Point operator++(int);	//Postfix (Suffix) increment
	//				Methods;
	/*double distance()const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}*/
	/*	double distance(const Point& second = {})const
	{
		return sqrt(pow(second.x - this->x, 2) + pow(second.y - this->y, 2));
	}*/
	double distance(const Point& other)const;
	void print()const;
};

//double distance(const Point& A, const Point& B);
double distance(const Point& A, const Point& B);

Point operator+(const Point& left, const Point& right);

bool operator==(const Point& left, const Point& right);
bool operator!=(const  Point& left, const Point& right);
