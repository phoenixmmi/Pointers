#include"Functions.h"

template<typename T>T  Sum(T Arr[], const int n)
{
	int Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += Arr[i];
	}
	return Sum;
}

template<typename T>double Avg(T Arr[], const int n)
{
	return (double)Sum(Arr, n) / n;
}

template<typename T>T minValueIn(T Arr[], const int n)
{
	int min = Arr[0];
	for (int i = 0; i < n; i++)if (Arr[i] < min)min = Arr[i];
	return T();
}