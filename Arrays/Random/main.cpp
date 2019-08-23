#include<iostream>
using namespace std;

//Генерация случайных чисел.

const char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n];
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand()%100;
	}

	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
}