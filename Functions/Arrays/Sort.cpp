#include"Functions.h"

template<typename T>void Sort(T Arr[], const int n)
{
	//Сортировка массива:
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] < Arr[i])
			{
				T buffer = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = buffer;
			}
		}
	}
}

template<typename T>void Sort(T Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int iterations = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				//int l;

				//if (k == i) l = j + 1;else l = 0;
					//(k == i)?l = j + 1 : l = 0;
				//l = (k == i) ? j + 1 : 0;
				//cout << typeid(k == i ? j + 1 : 0.).name() << endl;
				for (int l = k == i ? j + 1 : 0.; l < COLS; l++)
				{
					if (Arr[k][l] < Arr[i][j])
					{
						T buffer = Arr[i][j];
						Arr[i][j] = Arr[k][l];
						Arr[k][l] = buffer;
					}
					iterations++;
				}
			}
		}
	}
	cout << "Массив отсортирован за " << iterations << " итераций\n";
}