#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n] = { 3, 5, 8 };

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

}