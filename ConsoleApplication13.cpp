// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Задание 4 номер 3

#include "pch.h"
#include <iostream>


using namespace std;

class Figure {

public:



	virtual void calc_square() const = 0;
	virtual void calc_perimeter() const = 0;
};

class Triangle : public Figure { //(треугольник)

private:

	double a, b, c;

public:



	void calc_square() const { //площади треугольника           
		double p = a + b + c;
		cout << sqrt(p * (p - a) * (p - b) * (p - c));
	}

	void calc_perimeter() const { // периметра треугольника            
		cout << a + b + c;
	}



	Triangle(double side_a, double side_b, double side_c)
		: a(side_a), b(side_b), c(side_c) {}
};

class Circle : public Figure { //(круг)

private:

	double r;

public:



	void calc_square() const { // площади (круга)           
		cout << 3, 14 * r * r;
	}

	void calc_perimeter() const { // периметр (круга)            
		cout << 2 * 3, 14 * r;
	}



	Circle(double radius)
		: r(radius) {}
};


class Rectangle : public Figure { // (прямоугольник)

private:

	double a, b;

public:



	void calc_square() const { // площад (прямоугольника)           
		cout << a * b;
	}

	void calc_perimeter() const { // периметр (прямоугольника)            
		cout << 2 * (a + b);
	}



	Rectangle(double side_a, double side_b)
		: a(side_a), b(side_b) {}
};



int main() {
	Figure** figure = new Figure*[5];
	cout << "Output of the program:\n";
	cout << "\nFigure #1 (triangle):";
	figure[0] = new Triangle(3, 4, 5);
	cout << "\nSquare: ";
	figure[0]->calc_square();
	cout << "\nPerimeter: ";
	figure[0]->calc_perimeter();

	cout << "\n\nFigure #2 (circle):";
	figure[1] = new Circle(5);
	cout << "\nSquare: ";
	figure[1]->calc_square();
	cout << "\nPerimeter: ";
	figure[1]->calc_perimeter();



	cout << "\n\nFigure #3 (rectangle):";
	figure[2] = new Rectangle(4, 5);
	cout << "\nSquare: ";
	figure[2]->calc_square();
	cout << "\nPerimeter: ";
	figure[2]->calc_perimeter();
	delete figure[0];
	delete figure[1];
	delete figure[2];
	delete[] figure;
	return 0;
}
