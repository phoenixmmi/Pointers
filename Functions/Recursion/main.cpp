#include<iostream>
using namespace std;

//#define FACTORIAL
#define POWER

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

void main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	int n;
	cout << "¬ведите число, дл€ вычислени€ факториала: "; cin >> n;
	cout << factorial(n) << endl;
#endif // FACTORIAL

	int a;
	int n;
	cout << "¬ведите основание степени: "; cin >> a;
	cout << "¬ведите показатель степени: "; cin >> n;
	cout << a << " ^ " << n << " = " << power(a, n) << endl;
}