#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
using namespace std; 
#define delimiter "\n-----------------------------------------------\n" 
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const  Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numenator()const
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
	void set_numenator(int numenator)
	{
		this->numerator = numenator;
	}
	void set_denominator(int denominator)
	{	
		if (denominator == 0)denominator = 1;
		this -> denominator = denominator;
	}

// Constructor 
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 0;
		cout << "Constructor:\t\t" << this << endl ;
	}
	Fraction(int integer, int numenator, int denominator)
	{
		set_integer(integer);
		set_numenator(numenator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int numenator, int denominator)
	{
		this->integer = 0;
		this->numerator = numenator;
		this->denominator = denominator;
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
	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9; // Максимально возможное значение числителя (9 деситичных разрядов) 
		numerator = decimal * denominator;
		reduce(); 

	}
// Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this/other;
	}

// Increment/Decrement
	Fraction& operator++() //Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--() //Prefix increment
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

// Type-cast operators
	operator int()const
	{
		return integer + numerator / denominator;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}



// Methods: 
	Fraction& reduce() 
	{
		int more, less, rest; 
		if (numerator < denominator)
		{
			less = numerator;
			more = denominator;
		}
		else
		{
			more = numerator;
			less = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest); 
		int GCD = more; // GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD; 

		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*( Fraction left,  Fraction right)
{	
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numenator() * right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
	/*result.set_numenator(left.get_numenator() * right.get_numenator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	
}
Fraction operator/( const Fraction& left, const Fraction& right)
{	
	return left * right.inverted();
	
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numenator() + right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
	

}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numenator() - right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
	

}
// Comparison operators:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numenator() * right.get_denominator() ==
		right.get_numenator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
	left.get_numenator() * right.get_denominator() <
	right.get_numenator() * left.get_denominator();

}
bool operator>( Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numenator() * right.get_denominator() >
		right.get_numenator() * left.get_denominator();

}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return(left < right)||(left == right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return!(left < right);

}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numenator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numenator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is,  Fraction& obj)
{
	// is - Input Stream
	/*int integer;
	int numenator;
	int denominator;
	is >> integer >> numenator >> denominator;
	obj.set_integer(integer);
	obj.set_numenator(numenator);
	obj.set_denominator(denominator);
	return is; */

	const int SIZE = 32; 
	char sz_input[SIZE] = {};
	//is >> sz_input;
	is.getline(sz_input, SIZE); //Ввод строки с пробелами
	//cout << sz_input << endl;
	const char delimiters[] = { '(','/',')',' ','.',',',0};
	int numbers[3] = {};
	int n = 0;
	for (char* pch = strtok(sz_input, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);
	//for (int i = 0; i < n; i++) cout << numbers[i] << "\t"; cout << endl;


	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}




	return is;

}
/*
--------------------------------------------------------------------------------
Функция strtok() разбивает строку на токены. 
Разделители (delimeters) - это символы по которым нужно делить строку 
Токены () - это элементы которые нужно достать из строки(все что не разделители)
При поиске ращделителя strtok изменяет входную строку , функция strtok находит все необходимые разделители не за один вызов а за последовательность вызовов. Причем входная строка (первый параметр) передается только при первом вызове! 
При последующих вызовах в качестве первого параметра передается NULL . Если при последующих вызовах передавать входдную строку strtok начинает поиск сначала . 
Функция strtok() возвращает указатель на найденный токен , если токен не найден , то функция фозвращает nullptr
pch - pointer to character , содержит указатель на первый символ токена. 
--------------------------------------------------------------------------------
-------------------------------
Функция atoi() ASCII to Integer , принимает строку ASCII-символов и возвращает целое число соответствующее этой строке
-------------------------------
*/

//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define ISTREAM_OPERATOR
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(3, 1, 2);
	D.print();
	Fraction E = D;
	E.print();
	Fraction F;
	F = E;
	F.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_CHECK
	int a, b, c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	cout << delimiter << endl;
#endif // ASSIGMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Fraction A(4, 4);
	Fraction B(1,2);
	A.print();
	B.print();
	Fraction E;
	E = A <= B;
	E.print();
	
	
	
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A++;
	A.print();
	B.print();
#endif // INCREMENT_DECREMENT
	
#ifdef ISTREAM_OPERATOR
	Fraction A;
	cout << "Введите простую дробь ";
	cin >> A;
	cout << A;
#endif // ISTREAM_OPERATOR
	
	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
}