#include <iostream>
using namespace std; 


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
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	// Constructors
	Point()
	{	
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Point(int x)
	{	
		this -> x = x;
		this -> y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}	
	
	Point(double x , double y)
	{	
		this -> x = x;
		this -> y = y;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//      Methods
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
};
//#define STRUCT_POINT
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}


void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a; // Объяление переменной "a" 
	Point A; // Объявление переменной А типа Point 
			// Создание объекта а структуры "Point"
			// Создание экземпляра A структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	//A.set_x();
	//A.set_y();
	A.print();
	Point B = 5;
	B.print();
	Point C(7, 8);
	C.print();
	cout << A.distance(C) << endl;
	cout << distance(A , C) << endl;

}