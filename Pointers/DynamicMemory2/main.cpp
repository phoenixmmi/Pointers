#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
//#define DymanicMemory1
void FillRand(int** Arr, const int m, const int n);

void print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int* arr,int& n,int value);
int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n,int index);

int** push_row_back(int** arr, int& m, const int n);
int** push_row_front(int** arr, int& m, const int n);
int** insert(int** arr, int& m, const int n, int index);
int** pop_row_back(int** arr, int& m, const int n);
int** pop_row_front(int** arr, int& m, const int n);
int** erase(int** arr, int& m, const int n, int index);

int** push_col_back(int** arr,const  int m, int& n);
void push_col_front(int** arr, const  int m, int& n);
int** insert_col(int** arr, const int m, int& n, int index);

int** pop_col_back(int** arr, const int m, int& n);
int** pop_col_front(int** arr, const int m, int& n);
int** erase_col(int** arr, const int m, int& n, int index);

int** allocate(const int m, const int n);
void clear(int** arr, const int m);



void main()
{
	setlocale(LC_ALL, "");
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
	int m;//количество строк
	int n;//количество элементов в строке
	int index;
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов в строке: "; cin >> n;

	//Объявление двумерного массива
	int** arr = allocate(m, n);
	///////////////////////////////////////////////////////////
	//Заполнение массива:
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление строки в начало массива: " << endl;
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "Введите куда хотите добавить новую строку : "; cin >> index;
	arr = insert(arr, m, n, index);
	Print(arr, m, n);

	cout << "Удаление последней строки: " << endl;
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление первой строки: " << endl;
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "Введите откуда хотите удалить строку : "; cin >> index;
	arr = erase(arr, m, n, index);
	Print(arr, m, n);

	cout << "Добавление столбца в конце массива: " << endl;
	arr = push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в начало массива: " << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в массив: " << endl;
	cout << "Введите индекс: "; cin >> index;
	arr = insert_col(arr, m, n, index);
	Print(arr, m, n);

	cout << "Удаление последнего столбца:"<< endl;
	arr = pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление первого столбца:" << endl;
	arr = pop_col_front(arr, m, n);
	Print(arr, m, n);


	cout << "Удаление столбца по индексу:" << endl;
	cout << "Введите индекс"; cin >> index;
	arr = erase_col(arr, m, n, index);
	Print(arr, m, n);


//удаление массива.
	clear(arr,m);
}
int** allocate(const int m, const int n)
{
	int** arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
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
void Print(int ** arr, const int m, const int n)
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

int** push_row_back(int** arr, int& m, const int n)
{
	//1)создаем буфферный массив указателей
	int** buffer = new int*[m + 1];
	//2)копируем адреса строк из исходного массива в буферный:
	for (int i = 0; i < m; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
	return arr;
	/*int** buffer = new int*[m + 1];
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
	return arr;*/
}
int** push_row_front(int** arr, int& m, const int n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	return arr;
	/*int** buf = new int*[m + 1]{};
	for (int i = 0; i < m + 1; i++)
	{
		buf[i] = new int[n] {};

	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buf;
	arr[0] = new int [n] {};
	m++;
	return arr;*/
}
int** insert(int** arr, int& m, const int n, int index)
{
	/*if (index > m)return arr;
	int** buf = new int*[m + 1]{};
	for (int i = 0; i < m + 1; i++)
	{
		buf[i] = new int[n] {};

	}
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i][j] = arr[i][j];
		}
	}
	for (int i = index; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buf;
	arr[index] = new int [n] {};
	m++;
	return arr;*/
	if (index > m)return arr;
	int** buf = new int*[m + 1]{};
	
	for (int i = 0; i < index; i++)
	{
		buf[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buf[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buf;
	arr[index] = new int [n] {};
	m++;
	return arr;

}

int** pop_row_back(int** arr, int& m, const int n)
{
	int** buf = new int*[m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		buf[i] = arr[i];
	}
	delete[]arr;
	arr = buf;
	m--;
	return arr;
	/*int** buf = new int*[m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		buf[i] = new int[n] {};

	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buf;
	m--;
	return arr;
}*/
}
int** pop_row_front(int** arr, int& m, const int n)
{
	int** buf = new int*[m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		buf[i] = arr[i+1];
	}
	delete[] arr;
	arr = buf;
	m--;
	return arr;
	/*int** buf = new int*[m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		buf[i] = new int[n] {};

	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i][j] = arr[i + 1][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buf;
	m--;
	return arr;*/
}
int** erase(int** arr, int& m, const int n, int index)
{
	if (index > m)return arr;
	int** buf = new int*[m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		if (i < index) buf[i] = arr[i];
		else buf[i] = arr[i+1];
	}
	delete[] arr;
	arr = buf;
	m--;
	return arr;
	/*if (index > m)return arr;
	int** buf = new int*[m - 1]{};
	for (int i = 0; i < m - 1; i++)
	{
		buf[i] = new int[n] {};
	}
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i][j] = arr[i][j];
		}
	}
	for (int i = index; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i][j] = arr[i + 1][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buf;
	m--;
	return arr;*/
}

int** push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buf[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n++;
    return arr;
}
void push_col_front(int** arr, const  int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buf[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n++;
}
int** insert_col(int** arr, const int m, int& n, int index)
{

	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			buf[j] = arr[i][j];
		}

		for (int j = index; j < n + 1; j++)
		{
			buf[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n++;
	return arr;
}

int** pop_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n - 1];
		for (int j = 0; j < n - 1; j++)
		{
			buf[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n--;
	return arr;
}
int** pop_col_front(int** arr, const int m, int& n)
{

	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n - 1];
		for (int j = 0; j < n; j++)
		{
			buf[j] = arr[i][j + 1];
		}

		delete[] arr[i];
		arr[i] = buf;
	}

	n--;
	return arr;
}
int** erase_col(int** arr, const int m, int& n, int index)
{

	for (int i = 0; i < m; i++)
	{
		int* buf = new int[n - 1]{};
		for (int j = 0; j < index; j++)
		{
			buf[j] = arr[i][j];
		}

		for (int j = index; j < n; j++)
		{
			buf[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n--;
	return arr;
}

void clear(int** arr, const int m)
{
	for (int i= 0; i < m; i++)
	{
		delete[] arr;
	}
	delete[] arr;
}
