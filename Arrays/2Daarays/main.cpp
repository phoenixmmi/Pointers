#include<iostream>
using namespace std;

const char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 4;	//количество строк
	const int COLS = 5;	//количество элементов строки (столбцов).
	int Arr[ROWS][COLS] = 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	//Заполнение массива случайными числами:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}

	//Вывод массива на экран:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
}