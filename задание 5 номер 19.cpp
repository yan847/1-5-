// задание 5 номер 19.cpp : 
/* 19. Функция вычисляет расстояние от точки P(x1,y1) до прямой Ax+By+C=0 по формуле
D=│Ax1+By1+C│/(A^2+B^2)^1/2
Во всех заданиях реализуемые функции должны генерировать подходящие исключения. Обработку исключений нужно выполнять главной функцией, которая должна демонстрировать обработку всех перехватываемых исключений.
Функции, реализуемые в заданиях, обязаны выполнять проверку передаваемых параметров и генерировать исключения в случае ошибочных. Все функции реализуются в четырех вариантах:
- без спецификации исключений;
- со спецификацией throw();
- с конкретной спецификацией с подходящим стандартным исключением;
- спецификация с собственным реализованным исключением.
Собственное исключение должно быть реализовано в трех вариантах: как пустой класс, как независимый класс с полями-параметрами функции, как наследник от стандартного исключения с полями.
*/

#include "pch.h"
#include <iostream>
#include<cmath>

using namespace std;
struct point

{

	double x;

	double y;

};

struct line

{

	double a;

	double b;

	double c;

};

//без спецификации исключений

double length1(const point& p, const line& l)

{

	if (pow(l.a, 2) + pow(l.b, 2) == 0) throw 'e';

	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));

};
double length2(const point& p, const line& l) throw() {

	if (pow(l.a, 2) + pow(l.b, 2) == 0) throw 'e';

	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));

};

//с конкретной спецификацией с подходящим стандартным исключением;

double length3(const point& p, const line& l) throw(invalid_argument) {

	if (pow(l.a, 2) + pow(l.b, 2) == 0) throw invalid_argument("Line doesn't exist\n");

	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));

}

//Спецификация с собственным реализованным исключением (независимый класс с полями-параметрами функции)

class newException

{

public:

	string e;

	newException(string str)

	{

		e = str;

	}

	string what()

	{

		return e;

	}

};

double length4_1(const point& p, const line& l) throw (newException)

{

	if (pow(l.a, 2) + pow(l.b, 2) == 0) throw newException("Line doesn't exist\n");

	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));

}

//Спецификация с собственным реализованным исключением (пустой класс)

class emptyException {};

double length4_2(const point& p, const line& l) throw (emptyException)

{

	if (pow(l.a, 2) + pow(l.b, 2) == 0) throw emptyException();

	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));

}

//Спецификация с собственным реализованным исключением (наследник от стандартного исключения с полями)

class customException : public exception

{

public:

	const char* what() const throw()

	{

		return "Line doesn't exist\n";

	}

};

double length4_3(const point& p, const line& l) throw (customException)

{

	if (pow(l.a, 2) + pow(l.b, 2) == 0) throw customException();

	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));

}

int main()

{

	point p;

	line l;

	cout << "Enter coord of point\nx, y: ";

	cin >> p.x >> p.y;

	cout << "Enter factors of line\nA, B, C: ";

	cin >> l.a >> l.b >> l.c; cout << "Test error 1: ";

	try

	{

		double length;

		length = length1(p, l);

		cout << "length: " << length << endl;

	}

	catch (char)

	{

		cout << "Error 1\n";

	}

	cout << "Test error 2: ";

	try

	{

		double length;

		length = length2(p, l);

		cout << "length: " << length << endl;

	}

	catch (char) {

		cout << "Error 2\n";

	}

	cout << "Test error 3: ";

	try

	{

		double length;

		length = length3(p, l);

		cout << "length: " << length << endl;

	}

	catch (invalid_argument& e)

	{

		cout << e.what();

	}

	cout << "Test error 4_1: ";

	try

	{

		double length;

		length = length4_1(p, l);

		cout << "length: " << length << endl;

	}

	catch (newException& e)

	{

		cout << e.what();

	}

	cout << "Test error 4_2: ";

	try

	{

		double length;

		length = length4_2(p, l);

		cout << "length: " << length << endl;

	}

	catch (emptyException& e) {

		cout << "Error 4_2\n";

	}cout << "Test error 4_3: ";

	try

	{

		double length;

		length = length4_3(p, l);

		cout << "length: " << length << endl;

	}

	catch (customException e)

	{

		cout << e.what();

	}

}
