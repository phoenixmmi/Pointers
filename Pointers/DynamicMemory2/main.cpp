#include<iostream>
using namespace std;
//#define DymanicMemory1
void FillRand(int** Arr, const int m, const int n);

void print(int arr[], const int n);
void print(int ** arr, const int m, const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int* arr,int& n,int value);
int** push_row_back(int** arr,  int& m, const int n);
int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n,int index);

void main()
{
	setlocale(LC_ALL, "");
	int m;// Количество строк 
	int n;//Количество элементов строки
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количеств строк: "; cin >> n;
	//обьявление двумерного динамического массива: 
	int** Arr= new int*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new int[n] {};
	}
	////////////////////////////////////////////
	//Использование двумерного динамического массива:
	FillRand(Arr, m, n);
	print(Arr, m, n);
	Arr = push_row_back(Arr,m,n);
	print(Arr, m, n);

	////////////////////////////////////////////
	//Удаление двумерного динамического массива:  
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
#ifdef DymanicMemory1
	/*
//Добавление элементов в конец массива:
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
	///////////////////
	print(arr, n);*/
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cout << (arr[i] = rand() % 100) << "\t";
	cout << endl;
	 arr = push_back(arr, n, value);
	print(arr, n);

	cout << "Введите добавлямое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	print(arr, n);
	
	int index;
	cout << "Введите добавлямое значение: "; cin >> value;
	
	int* old = arr;
	do {
		cout << "Введите индекс добавляемого значения"; cin >> index;
	} while (old == (arr = insert(arr, n, value, index)));
	arr = insert(arr, n, value,index);
	print(arr, n);

	arr = pop_back(arr, n);
	print(arr, n);
	
	arr = pop_front(arr, n);
	print(arr, n);

	int index;
	cout << "Введите индекс:"; cin >> index;
	arr = erase(arr, n, index);
	print(arr, n);
	delete[] arr;
#endif
}
void FillRand(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}
}


void print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void print(int ** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for  ( int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//Добавляет элемент в конец.
	int* buffer = new int[n + 1];
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
int* push_front(int* arr, int& n, int value)
{
	//Добавляет элемент в начало.
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i]; // Копируем элементы со смещением на 1 один элемент вправо.
	}
	
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int** push_row_back(int** arr, int& m, const int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	//Добавляет элемент в определенное место.
	if (index > n)return arr;
	int* buffer = new int[n + 1]{};
	for  (int i = 0; i < index; i++) buffer[i] = arr[i];
	for  (int i = index; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int* arr, int& n)
{
	//удаляет последний элемент.
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	//Удаляет первый элемент.
	int* buffer = new int[n - 1];
	for (int i = 0;i < n-1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	
	n--;
	return arr;
}
int* erase(int* arr, int& n,int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
