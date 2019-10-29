#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;// Размер массива 
	cout << "Введите размер массива: "; cin >> n; 
	double *Arr = new double[n];
	for (int i = 0; i < n; i++)
	{ 
		// Арифметика указателей и оператор разыменования: 
		*(Arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		//[]- Оператор индексирования (subscript operator) 
		cout << Arr[i] << "\t";
	}
	cout << endl;
	cout << Arr << endl;
	delete[] Arr;
	cout << Arr << endl;
}