#include<iostream>
using namespace std;

#define tab "\t"

#define WITH_BOOL_VARIABLE	//ѕри помощи Ѕулевой переменной
//#define WO_BOOL_VARIABLE	//Ѕез Ѕулевой переменной

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int Arr[n];
	for (int i = 0; i < n; i++)
	{
		cout << (Arr[i] = rand() % 5) << tab;
	}
	cout << endl;

#ifdef WITH_BOOL_VARIABLE
	for (int i = 0; i < n; i++)
	{
		int repeats = 1;
		bool met_before = false;
		for (int j = 0; j < i; j++)
		{
			if (Arr[i] == Arr[j])
			{
				met_before = true;
				break;
			}
		}
		if (!met_before)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (Arr[i] == Arr[j])repeats++;
			}
			if (repeats > 1)
			{
				cout << "«начение " << Arr[i] << " встречаетс€ " << repeats << " раз.\n";
			}
		}
	}
#endif

#ifdef WO_BOOL_VARIABLE
	for (int i = 0; i < n; i++)
	{
		int repeats = 1;
		//ѕеребираем левую часть массива, относительно выбранного элемента:
		for (int j = 0; j < i; j++)
		{
			if (Arr[i] == Arr[j])
			{
				repeats++;
			}
		}
		//≈сли repeats > 1, значит выбранное значение Arr[i] встречалось ранее, 
		//значит мы с ним уже работали, а это значит, что мы уже вывели сколько раз
		//оно встречаетс€.
		if (repeats > 1)continue;

		//≈сли repeats == 1, то мы видим это значение впервые, 
		//и нужно посчитать сколько раз оно встречаетс€.
		//ƒл€ этого, мы и перебираем правую часть массива, 
		//относительно выбранного элемента:
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[i] == Arr[j])repeats++;
		}
		if (repeats > 1)
		{
			cout << "«начение " << Arr[i] << " встречаетс€ " << repeats << " раз.\n";
		}
	}
#endif // WO_BOOL_VARIABLE

}