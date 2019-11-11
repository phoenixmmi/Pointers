#include<iostream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

void FillRand(int**arr, const int m, const int n);
void Print(int**arr, const int m, const int n);

int** push_row_back(int** arr, int& m, const int n);
int** push_row_front(int** arr, int& m, const int n);
int** insert(int** arr, int& m, const int n, int index);
int** pop_row_back(int** arr, int& m, const int n);
int** pop_row_front(int** arr, int& m, const int n);
int** erase(int** arr, int& m, const int n, int index);


void main()
{
	setlocale(LC_ALL, "");
	int m;//количество строк
	int n;//количество элементов в строке
	int index;
	cout << "¬ведите количество строк: "; cin >> m;
	cout << "¬ведите количество элементов в строке: "; cin >> n;

	//ќбъ€вление двумерного массива
	int** arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	///////////////////////////////////////////////////////////
	FillRand(arr, m, n);
	Print(arr, m, n);
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "¬ведите куда хотите добавить новую строку : "; cin >> index;
	arr = insert(arr, m, n, index);
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "¬ведите откуда хотите удалить строку : "; cin >> index;
	arr = erase(arr, m, n, index);
	Print(arr, m, n);

	//////////////////////////////////////////////////////////
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	//////////////////////////////////////////////////////////
	//”даление двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}
void FillRand(int**arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int**arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int** push_row_back(int** arr, int& m, const int n)
{
	//1)создаем буфферный массив указателей
	int** buffer = new int*[m + 1];
	//2)копируем адреса строк из исходного массива в буферный:
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
	return arr;
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
	if (index > m)return arr;
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
	return arr;

}
int** pop_row_back(int** arr, int& m, const int n)
{
	int** buf = new int*[m - 1]{};
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
}
int** pop_row_front(int** arr, int& m, const int n)
{
	int** buf = new int*[m - 1]{};
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
	return arr;
}
int** erase(int** arr, int& m, const int n, int index)
{
	if (index > m)return arr;
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
	return arr;
}

