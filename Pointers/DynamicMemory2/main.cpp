#include<iostream>
using namespace std;

void print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cout << (arr[i] = rand() % 100) << "\t";
		cout << endl;
	//Добавление элементов в конец массива: 
		int value;
		cout << "Введите добавлямое значение: "; cin >> value; 
		//1)Создаём буфферный массив, размером на один элемент больше: 
		int* buffer = new int[n + 1];
		//2)Копируем содержимое исходного массива в буфферный: 
		for  (int i= 0; i < n; i++)
		{
			buffer[i] = arr[i];
		}
		//3)Удаляем исходный массив из памяти: 
		delete[] arr;
		//4) В указатель исходного массива записываем адресс нового массива: 
		arr = buffer;

		arr[n] = value;
		n++;
		print(arr, n);

		delete[] arr;
}


void print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}