#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;// ������ ������� 
	cout << "������� ������ �������: "; cin >> n; 
	double *Arr = new double[n];
	for (int i = 0; i < n; i++)
	{ 
		// ���������� ���������� � �������� �������������: 
		*(Arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		//[]- �������� �������������� (subscript operator) 
		cout << Arr[i] << "\t";
	}
	cout << endl;
	cout << Arr << endl;
	delete[] Arr;
	cout << Arr << endl;
}