#include<iostream>
using namespace std;

//Генерация случайных чисел.

const char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n];

	int minRand;	//Минимально возможное случайное число.
	int maxRand;	//Максимально возможное случайное число.
	do
	{
		system("CLS");
		cout << "Введите минимально возможное случайное число: "; cin >> minRand;
		cout << "Введите максимально возможное случайное число: "; cin >> maxRand;
		if (minRand >= maxRand)
		{
			cout << "Error: user lox V_o_O_v" << endl;
			system("PAUSE");
		}
	} while (minRand >= maxRand);

	//		Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % (maxRand - minRand) + minRand;
	}

	//Вывод исходного массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	//Сортировка:
	int iterations = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			iterations++;
			if (Arr[j] < Arr[i])
			{
				int buffer = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = buffer;
			}
		}
	}

	//Вывод отсортированного массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	cout << "Массив отсортирован за " << iterations << " итераций" << endl;
}