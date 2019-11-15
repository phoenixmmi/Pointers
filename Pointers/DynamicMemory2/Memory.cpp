#include"Functions.h"

template<typename T>T** allocate(const int m, const int n)
{
	T** arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n]{};
	}
	return arr;
}

template<typename T>void clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}