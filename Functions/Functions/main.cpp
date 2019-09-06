#include<iostream>
using namespace std;

int add(int a, int b)
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

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int b = 3;
	int c = add(a, b);
	cout << a << " + " << b << " = " << c << endl;;
	cout << sub(8, 3) << endl;;
	cout << mul(5, 3) << endl;
	cout << div_(5, 2) << endl;
}