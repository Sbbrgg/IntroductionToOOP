#pragma warning(disable:4326)
#include"Point.h"
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENTS_CHECK
#define ARITHMETICAL_OPERATORS_CHECK

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

	cout << (Point(2, 3) != Point(2, 3)) << endl;
	
}

//double distance(const Point& A, const Point& B)
//{
//	return sqrt( pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
//}
