#include<iostream>
#include<conio.h>
using namespace std;

#define HORIZ_OFFSET "\t\t\t\t\t\t"

void PrintField(char Field[], const int n);
void Move(char Field[], const int n);

void main()
{
	setlocale(LC_ALL, "Rus");
	const int SIZE = 9;
	char Field[SIZE] = {};	//Игровое поле
	PrintField(Field, SIZE);
}

void PrintField(char Field[], const int n)
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n";
	for (int i = 6; i >= 0; i -= 3)
	{
		cout << HORIZ_OFFSET;
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)cout << " ";
			cout << Field[i + j];
			if (j != 2) cout << " | ";
		}
		cout << endl;
		cout << HORIZ_OFFSET;
		if (i != 0)cout << "--- --- ---" << endl;
	}
	Move(Field, n);
}

void Move(char Field[], const int n)
{
	char key;

	key = _getch();
	if (key == 27)return;
	//cout << (int)key << endl;
	Field[key - 49] = key;
	PrintField(Field, n);
}