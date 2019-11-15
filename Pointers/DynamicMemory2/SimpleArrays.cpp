#include"Functions.h"

template<typename T>T* push_back(T arr[], int& n, T value)
{
	//Добавляет элемент в конец.
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];//копируем элементы СООТВЕТСТВЕННО.
	}

	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T* push_front(T* arr, int& n, T value)
{
	//Добавляет элемент в начало.
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i]; // Копируем элементы со смещением на 1 один элемент вправо.
	}

	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>T* insert(T* arr, int& n, T value, int index)
{
	//Добавляет элемент в определенное место.
	if (index > n)return arr;
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

template<typename T>int* pop_back(T* arr, int& n)
{
	//удаляет последний элемент.
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T* pop_front(T* arr, int& n)
{
	//Удаляет первый элемент.
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T* erase(T* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}