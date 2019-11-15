#include"Functions.h"
#include"Memory.cpp"
#include"BaseFunctions.cpp"
#include"SimpleArrays.cpp"
#include"MultidimensionalArrays.cpp"

//#define DymanicMemory1
#define ADDING_ROWS
#define REMOVING_ROWS
#define ADDING_COLS
#define REMOVING_COLS

typedef int DataType; //���� ����������� �������� ��� ������ � ����,�� ������� ���� ���.

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
	
 	DataType** arr = allocate<DataType>(m, n);
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




