#include<iostream>
#include<ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	/*
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
	cout << Arr << endl;*/
	const int n = 10;
	int arr[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		cout << (arr[i] = rand() % 10) << "\t";

	}
	cout << endl;

	//�������� ���������� ������ � �������� �������� � �������� �������:
	int n_even = 0; // ���������� ������ ���������.
	int n_odd = 0; // ���������� �������� ���������.
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			n_even++;
		}
		else
		{
			n_odd++;
		}
	}
	cout << "���������� ������ ���������: " << n_even << endl;
	cout << "���������� �������� ���������: " << n_odd << endl;

	//�������� ������ ��� ������ � �������� ��������: 
	int* even_values = new int[n_even];
	int* odd_values = new int[n_odd];
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_values[j++] = arr[i];
		}
		else
		{
			odd_values[k++] = arr[i];
		}
	}
	for (int i = 0; i < n_even; i++)
	{
		cout << even_values[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n_odd; i++)
	{
		cout << odd_values[i] << "\t";
	}
	cout << endl;
}