#include<iostream>
using namespace std;

#define tab "\t"
//const char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n] = { 3, 5, 8, 13, 21 };

	//Ввод элементов массива:

	/*cout << "Введите элементы массива: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> Arr[i];
	}*/

	//		Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << "\t";
	}
	cout << endl;
	//		Вывод массива на экран в обратном порядке:
	for (int i = n - 1; i >= 0; i--)
	{
		cout << Arr[i] << "\t";
	}
	cout << endl;

	//		Подсчет суммы элементов массива:
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += Arr[i];
	}
	cout << "Сумма элементов массива: " << sum << endl;
	cout << "Среднее арифметическое:  " << (double)sum / n << endl;

	//		Поиск минимального и максимального значения:
	int min, max;
	min = max = Arr[0];
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] < min)min = Arr[i];
		if (Arr[i] > max)max = Arr[i];
	}
	cout << "Минимальное значение в массиве: " << min << endl;
	cout << "Максимальное значение в массиве: " << max << endl;

	cout << "\n-------------------------------\n";
	int Brr[] = { 3, 5, 8, 13, 21, 34, 55, 89 };
	for (int i = 0; i < sizeof(Brr)/sizeof(int); i++)
	{
		cout << Brr[i] << tab;
	}
	cout << endl;
}