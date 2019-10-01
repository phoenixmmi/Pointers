#include"Functions.h"
#include"FillRand.cpp"
#include"Print.cpp"
#include"Sort.cpp"
#include"Stat.cpp"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n];

	FillRand(Arr, n);
	Print(Arr, n);
	cout << "Сумма элементов масива:\t" << Sum(Arr, n) << endl;
	cout << "Среднее арифметическое:\t" << Avg(Arr, n) << endl;
	//cout << "Минимальное значение в массиве:\t" << minValueIn(Arr, n) << endl;

	double Brr[n];
	FillRand(Brr, n);
	Print(Brr, n);
	Sort(Brr, n);
	Print(Brr, n);
	cout << DELIMITER << endl;

	int Crr[ROWS][COLS];
	FillRand(Crr, ROWS, COLS);
	Print(Crr, ROWS, COLS);
	Sort(Crr, ROWS, COLS);
	cout << DELIMITER << endl;
	Print(Crr, ROWS, COLS);

	double Drr[ROWS][COLS];
	//FillRand(Drr, ROWS, COLS);
}









//int  minValueIn(int Arr[], const int n)
//{
//	int min = Arr[0];
//
//}

//Repository

/*

template<typename T>
template (шаблон)

*/