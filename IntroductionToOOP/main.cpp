#include<iostream>
#include<math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;



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

	/*double distance()const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}*/

	/*	double distance(const Point& second = {})const
	{
		return sqrt(pow(second.x - this->x, 2) + pow(second.y - this->y, 2));
	}*/

	double distance(Point other)
	{
		//this - эта точка (находим расстояние от этой точки)
		//other - та точка (до указанной точки)

		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt() - Square Root - (Квадратный корень)
		return distance;
	}
};

//double distance(const Point& A, const Point& B);
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
//#define STRUCT_POINT

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
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от A до B (метод): " << A.distance(B) << endl;
	cout << "Расстояние от B до A (метод): " << B.distance(A) << endl;
	cout << "Расстояние от A до начала координат: " << A.distance(B) << endl;
	
	cout << "Расстаяние от A до B (функцией): " << distance(A, B) << endl;
	cout << "Расстаяние от B до A (функцией): " << distance(B, A) << endl;

}

//double distance(const Point& A, const Point& B)
//{
//	return sqrt( pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
//}

