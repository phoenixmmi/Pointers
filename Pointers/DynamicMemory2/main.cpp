#include<iostream>
using namespace std;

void print(int arr[], const int n);
int* push_back(int arr[], int& n, int value);
int* push_front(int* arr,int& n,int value);
int* insert(int* arr, int& n, int value, int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n,int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cout << (arr[i] = rand() % 100) << "\t";
	cout << endl;
	int value;
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
	/*arr = push_back(arr, n, value);
	print(arr, n);

	cout << "������� ���������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	print(arr, n);

	cout << "������� ���������� ��������: "; cin >> value;
	int index;
	cout << "������� ������:"; cin >> index;
	arr = insert(arr, n, value,index);
	print(arr, n);*/

	/*arr = pop_back(arr, n);
	print(arr, n);
	
	arr = pop_front(arr, n);
	print(arr, n);*/

	int index;
	cout << "������� ������:"; cin >> index;
	arr = erase(arr, n, index);
	print(arr, n);

	delete[] arr;
}


void print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//��������� ������� � �����.
	int* buffer = new int[n + 1];
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
int* push_front(int* arr, int& n, int value)
{
	//��������� ������� � ������.
	int* buffer = new int[n + 1]{};
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
int* insert(int* arr, int& n, int value, int index)
{
	//��������� ������� � ������������ �����.
	int* buffer = new int[n + 1]{};
	for  (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for  (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int* arr, int& n)
{
	//������� ��������� �������.
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
	//������� ������ �������.
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