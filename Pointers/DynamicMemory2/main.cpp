#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
//#define DymanicMemory1
template<typename T>T** allocate(const int m, const int n);
template<typename T>void clear(T** arr, const int m);

template<typename T>void FillRand(T** Arr, const int m, const int n);

template<typename T>void print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T* arr,int& n,T value);
template<typename T>T* insert(T* arr, int& n, T value, int index);

template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);
template<typename T>T* erase(T* arr, int& n,int index);

template<typename T>T** push_row_back(T** arr, int& m, const int n);
template<typename T>T** push_row_front(T** arr, int& m, const int n);
template<typename T>T** insert(T** arr, int& m, const int n, int index);

template<typename T>T** pop_row_back(T** arr, int& m, const int n);
template<typename T>T** pop_row_front(T** arr, int& m, const int n);
template<typename T>T** erase(T** arr, int& m, const int n, int index);

template<typename T>T** push_col_back(T** arr,const  int m, int& n);
template<typename T>void push_col_front(T** arr, const  int m, int& n);
template<typename T>T** insert_col(T** arr, const int m, int& n, int index);

template<typename T>T** pop_col_back(T** arr, const int m, int& n);
template<typename T>T** pop_col_front(T** arr, const int m, int& n);
template<typename T>T** erase_col(T** arr, const int m, int& n, int index);

#define ADDING_ROWS
#define REMOVING_ROWS
#define ADDING_COLS
#define REMOVING_COLS

void main()
{
	setlocale(LC_ALL, "");
#ifdef DymanicMemory1
	/*
//���������� ��������� � ����� �������:
	//1)������ ��������� ������, �������� �� ���� ������� ������:
	int* buffer = new int[n + 1];
	//2)�������� ���������� ��������� ������� � ���������:
	for  (int i= 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������ �� ������:
	delete[] arr;
	//4) � ��������� ��������� ������� ���������� ������ ������ �������:
	arr = buffer;

	arr[n] = value;
	n++;
	///////////////////
	print(arr, n);*/
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cout << (arr[i] = rand() % 100) << "\t";
	cout << endl;
	 arr = push_back(arr, n, value);
	print(arr, n);

	cout << "������� ���������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	print(arr, n);
	
	int index;
	cout << "������� ���������� ��������: "; cin >> value;
	
	int* old = arr;
	do {
		cout << "������� ������ ������������ ��������"; cin >> index;
	} while (old == (arr = insert(arr, n, value, index)));
	arr = insert(arr, n, value,index);
	print(arr, n);

	arr = pop_back(arr, n);
	print(arr, n);
	
	arr = pop_front(arr, n);
	print(arr, n);

	int index;
	cout << "������� ������:"; cin >> index;
	arr = erase(arr, n, index);
	print(arr, n);
	delete[] arr;
#endif
	int m;//���������� �����
	int n;//���������� ��������� � ������
	int index;
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� � ������: "; cin >> n;

	//���������� ���������� �������
	int** arr = allocate<int>(m, n);
	///////////////////////////////////////////////////////////
	//���������� �������:
	FillRand(arr, m, n);
	Print(arr, m, n);

#ifdef ADDING_ROWS
	cout << "���������� ������ � ����� �������: " << endl;
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������ � ������ �������: " << endl;
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "������� ���� ������ �������� ����� ������ : "; cin >> index;
	arr = insert(arr, m, n, index);
	Print(arr, m, n);
#endif // ADDING_ROWS


#ifdef REMOVING_ROWS
	cout << "�������� ��������� ������: " << endl;
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "�������� ������ ������: " << endl;
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "������� ������ ������ ������� ������ : "; cin >> index;
	arr = erase(arr, m, n, index);
	Print(arr, m, n);
#endif // REMOVING_ROWS


#ifdef ADDING_COLS
	cout << "���������� ������� � ����� �������: " << endl;
	arr = push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������� � ������ �������: " << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������� � ������: " << endl;
	cout << "������� ������: "; cin >> index;
	arr = insert_col(arr, m, n, index);
	Print(arr, m, n);
#endif // ADDING_COLS


#ifdef REMOVING_COLS
	cout << "�������� ���������� �������:" << endl;
	arr = pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "�������� ������� �������:" << endl;
	arr = pop_col_front(arr, m, n);
	Print(arr, m, n);


	cout << "�������� ������� �� �������:" << endl;
	cout << "������� ������"; cin >> index;
	arr = erase_col(arr, m, n, index);
	Print(arr, m, n);
#endif // REMOVING_COLS



//�������� �������.
	clear(arr,m);
}
template<typename T>T** allocate(const int m, const int n)
{
	T** arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n] {};
	}
	return arr;
}

template<typename T>void clear(T** arr, const int m)
{
	for (int i= 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T>void FillRand(T** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Arr[i][j] = rand() % 100;
			Arr[i][j] /= 10;
		}
	}
}

template<typename T>void print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int m, const int n)
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

template<typename T>T* push_back(T arr[], int& n, T value)
{
	//��������� ������� � �����.
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];//�������� �������� ��������������.
	}

	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T* push_front(T* arr, int& n, T value)
{
	//��������� ������� � ������.
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i]; // �������� �������� �� ��������� �� 1 ���� ������� ������.
	}
	
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}


template<typename T>T* insert(T* arr, int& n, T value, int index)
{
	//��������� ������� � ������������ �����.
	if (index > n)return arr;
	T* buffer = new T[n + 1]{};
	for  (int i = 0; i < index; i++) buffer[i] = arr[i];
	for  (int i = index; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

template<typename T>int* pop_back(T* arr, int& n)
{
	//������� ��������� �������.
	T* buffer = new T[n - 1];
	for (int i = 0; i < n-1; i++)
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
	//������� ������ �������.
	T* buffer = new T[n - 1];
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

template<typename T>T** push_row_back(T** arr, int& m, const int n)
{
	//1)������� ��������� ������ ����������
	T** buffer = new T*[m + 1];
	//2)�������� ������ ����� �� ��������� ������� � ��������:
	for (int i = 0; i < m; i++)buffer[i] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[m] = new T[n] {};
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
template<typename T>T** push_row_front(T** arr, int& m, const int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n] {};
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
template<typename T>T** insert(T** arr, int& m, const int n, int index)
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
	T** buf = new T*[m + 1]{};
	
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

template<typename T>T** pop_row_back(T** arr, int& m, const int n)
{
	T** buf = new T*[m - 1]{};
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
template<typename T>T** pop_row_front(T** arr, int& m, const int n)
{
	T** buf = new T*[m - 1]{};
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
template<typename T>T** erase(T** arr, int& m, const int n, int index)
{
	if (index > m)return arr;
	T** buf = new T*[m - 1]{};
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

template<typename T>T** push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buf = new T[n + 1]{};
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
template<typename T>void push_col_front(T** arr, const  int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buf = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buf[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buf;
	}
	n++;
}
template<typename T>T** insert_col(T** arr, const int m, int& n, int index)
{

	for (int i = 0; i < m; i++)
	{
		T* buf = new T[n + 1]{};
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

template<typename T>T** pop_col_back(T** arr, const int m, int& n)
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
template<typename T>T** pop_col_front(T** arr, const int m, int& n)
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
template<typename T>T** erase_col(T** arr, const int m, int& n, int index)
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

