#include<iostream>
using namespace std;

void print(int n)
{
	if (n == 0)return;
	print(n-1);
	cout << n << ". Hello Recursion" << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	print(10);
}