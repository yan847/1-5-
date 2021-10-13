// задание 3 номер 5.cpp : 
/*	Создать класс Triad (тройка чисел); определить методы изменения полей и вычисления суммы чисел.
	Определить производный класс Triangle с полями-сторонами.
	Определить методы вычисления углов и площади треугольника.*/
#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

class Triad
{
private:
	double a;
	double b;
	double c;
public:
	double GetA();
	double GetB();
	double GetC();
	void SetA(double A);
	void SetB(double B);
	void SetC(double C);
	double GetSum();
};

class Trangle :public Triad
{
public:
	double GetArea();
	double GetAlpha();
	double GetBeta();
	double GetGamma();
};

double Triad::GetA()
{
	return a;
}

double Triad::GetB()
{
	return b;
}

double Triad::GetC()
{
	return c;
}

void Triad::SetA(double A)
{
	a = A;
}

void Triad::SetB(double B)
{
	b = B;
}

void Triad::SetC(double C)
{
	c = C;
}

double Triad::GetSum()
{
	return a + b + c;
}

double Trangle::GetArea()
{
	double p = GetSum() / 2.0;
	return sqrt(p*(p - GetA())*(p - GetB())*(p - GetC()));
}

double Trangle::GetAlpha()
{
	return 180.0 - GetBeta() - GetGamma();
}

double Trangle::GetBeta()
{
	return asin(2.0*GetArea() / (GetC()*GetA())) * 180 / PI;
}

double Trangle::GetGamma()
{
	return acos((GetC()*GetC() - GetA()*GetA() - GetB()*GetB()) / (-2.0*GetA()*GetB())) * 180 / PI;
}


int main()
{
	Trangle t;
	t.SetA(3.0);
	t.SetB(4.0);
	t.SetC(5.0);
	cout << t.GetArea() << endl;
	cout << t.GetAlpha() << endl;
	cout << t.GetBeta() << endl;
	cout << t.GetGamma() << endl;
	getchar();
	return 0;
}


