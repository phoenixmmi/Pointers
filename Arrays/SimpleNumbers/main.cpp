//Выводит на экран ряд простых чисел до введенного с клавиатуры.

#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите число: "; cin >> n;
	bool simple;//???
	for (int i = 0; i <= n; i++)
	{
		simple = true;//Предположим что число простое, но это нужно проветрить.
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				simple = false;
				break;
			}
		}
		if (simple)	//Если число простое, то выводим его на экран.
		{
			cout << i << "\t";
		}
	}
	cout << endl;
}