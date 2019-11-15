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

typedef int DataType; //Дает возможность заменить тип данных в коде,не изменяя весь код.

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
	
 	DataType** arr = allocate<DataType>(m, n);
	///////////////////////////////////////////////////////////
	//Заполнение массива:
	FillRand(arr, m, n);
	Print(arr, m, n);

#ifdef ADDING_ROWS
	cout << "Добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление строки в начало массива: " << endl;
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "Введите куда хотите добавить новую строку : "; cin >> index;
	arr = insert(arr, m, n, index);
	Print(arr, m, n);
#endif // ADDING_ROWS


#ifdef REMOVING_ROWS
	cout << "Удаление последней строки: " << endl;
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление первой строки: " << endl;
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "Введите откуда хотите удалить строку : "; cin >> index;
	arr = erase(arr, m, n, index);
	Print(arr, m, n);
#endif // REMOVING_ROWS


#ifdef ADDING_COLS
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
#endif // ADDING_COLS


#ifdef REMOVING_COLS
	cout << "Удаление последнего столбца:" << endl;
	arr = pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление первого столбца:" << endl;
	arr = pop_col_front(arr, m, n);
	Print(arr, m, n);


	cout << "Удаление столбца по индексу:" << endl;
	cout << "Введите индекс"; cin >> index;
	arr = erase_col(arr, m, n, index);
	Print(arr, m, n);
#endif // REMOVING_COLS



//удаление массива.
	clear(arr,m);
}




