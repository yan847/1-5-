// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Payment
{
private:
	char fio[100]; //Фио
	double oklad; //оклад
	int year; //год поступления на работу
	double procent; //процент надбавки
	double nalog; //подоходный налог
	int rab_day_month; //кол-во отработанных дней
	int day_month; //кол-во рабочих дней
	double nach_summ; //начисленная сумма
	double yder_summ; //удержанная сумма
	int stag; //стаж (полное кол-во лет)
	double zp; //зарплата
public:
	double vichisl_nach_summ();
	double vichisl_yder_summ();
	double vichisl_zp();
	int vichisl_stag();
	void set();
	void show();
};

double Payment::vichisl_nach_summ()
{
	return (oklad*rab_day_month);
}

double Payment::vichisl_yder_summ()
{
	return (nach_summ*0.01 + nach_summ * 0.13);
}

double Payment::vichisl_zp()
{
	return (rab_day_month*oklad - (rab_day_month*oklad*0.13));
}

int Payment::vichisl_stag()
{
	return (2009 - year);

}

void Payment::set()
{
	cout << "Введите фамилию сотрудника - ";
	cin >> fio;
	cout << "Введите оклад сотрудника  - ";
	cin >> oklad;
	cout << "Введите год поступления сотрудника на работу - ";
	cin >> year;
	cout << "Введите процент надбавки - ";
	cin >> procent;
	cout << "Введите кол-во отработанных дней - ";
	cin >> rab_day_month;

}



void Payment::show()
{
	cout << "Начисленная сумма составляет: " << vichisl_nach_summ() << "\n";
	cout << "Удержанная сумма составляет: " << vichisl_yder_summ() << "\n";
	cout << "Сумма, выдаваемая на руки составляет: " << vichisl_zp() << "\n";
	cout << "Стаж составляет: " << vichisl_stag() << "\n";
}


int main()
{
	setlocale(LC_CTYPE, ".1251");
	Payment n1;
	n1.set();
	n1.show();
}