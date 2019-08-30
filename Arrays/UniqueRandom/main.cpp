#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	bool unique;//???
	for (int i = 0; i < n; i++)
	{
		/*do
		{
			arr[i] = rand() % n;
			unique = true;	//Предполагаем, что сгенерированное случайное число уникально, но это нужно проверить.
			for (int j = 0; j < i; j++)
			
{
				if (arr[i] == arr[j])unique = false;
			}
		} while (!unique);*/
		arr[i] = rand() % 11;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}