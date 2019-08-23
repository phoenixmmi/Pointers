#include<iostream>
using namespace std;

const char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int Arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//Вывод исходного массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	//Сдвиг массива:
	int m;	//количество сдвигов
	cout << "На сколько элементов сдвинуть массив: "; cin >> m;

	/*for (int i = 0; i < m; i++)
	{
		int buffer = Arr[0];
		for (int i = 0; i < n; i++)
		{
			Arr[i] = Arr[i + 1];
		}
		Arr[n - 1] = buffer;
	}*/

	//Вывод сдвинутого массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	///////////////////////////////////////////////////////////////
	int buffer = Arr[n - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		Arr[i] = Arr[i - 1];
	}
	Arr[0] = buffer;

	//Вывод сдвинутого массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
}