#include<iostream>
using namespace std;

int add(int a, int b);	//Прототип функции (Function declaration - объявление функции).
int sub(int a, int b);
int mul(int a, int b);
double div_(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int b = 3;
	int c = add(a, b);	//Вызов (использование) функции - Function call.
	cout << a << " + " << b << " = " << c << endl;;
	cout << sub(8, 3) << endl;
	cout << mul(5, 3) << endl;
	cout << div_(5, 2) << endl;
	cout << add(123, 456) << endl;
}

int add(int a, int b)	//Реализация функции (Function definition - Определение функции)
{
	int c = a + b;
	return c;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	//умножение
	return a * b;
}

double div_(int a, int b)
{
	//деление
	double c = (double)a / b;
	return c;
}



/*
	Function doesn't take N arguments
	too few arguments in function call - если мы передали меньше переметров, чем функция принимает;
	too many arguments in function call - 


	(LNK - Link)
	UNRESOLVED EXTERNAL SYMBOL FOUND
*/