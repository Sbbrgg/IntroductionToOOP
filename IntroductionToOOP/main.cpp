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

		double distance(const Point& second = {})const
	{
		return sqrt(pow(second.x - this->x, 2) + pow(second.y - this->y, 2));
	}
};

double Distance(const Point& A, const Point& B);
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
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(5);
	B.set_y(7);

	cout << "Расстояние от A до B (метод): " << A.distance(B) << endl;
	cout << "Расстояние от A до начала координат: " << A.distance() << endl;
	
	cout << "Расстаяние от A до B (функцией): " << Distance(A, B);

}

double Distance(const Point& A, const Point& B)
{
	return sqrt( pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

