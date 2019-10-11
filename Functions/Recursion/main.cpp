#include<iostream>
using namespace std;

//#define FACTORIAL
//#define POWER
#define FIBONACCI_1

int factorial(int n)
{
	if (n == 0)return 1;
	return n * factorial(n - 1);
	/*int f = n * factorial(n - 1);
	return f;*/
}

double power(double a, int n)
{
	return (n == 0) ? 1 : (n > 0) ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
	/*if (n == 0)return 1;
	if(n>0)return a * power(a, n - 1);
	else if(n<0) return 1 / a*power(a, n + 1);*/
}
//okovtun@itstep.org

void Fibonacci(int n, int a = 0, int b = 1);//Default parameters
//Function doesn't take N arguments;

void main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	int n;
	cout << "Введите число, для вычисления факториала: "; cin >> n;
	cout << factorial(n) << endl;
#endif // FACTORIAL

#ifdef POWER
	int a;
	int n;
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	cout << a << " ^ " << n << " = " << power(a, n) << endl;
#endif // POWER

#ifdef FIBONACCI_1
	int n;
	cout << "До какого числа вывести ряд Фибоначчи: "; cin >> n;
	Fibonacci(n);
#endif // FIBONACCI_1

}

void Fibonacci(int n, int a, int b)//Default parameters
//Function doesn't take N arguments
{
	if (a > n)
	{
		cout << endl;
		return;
	}
	cout << a << "\t";
	Fibonacci(n, b, a + b);
}