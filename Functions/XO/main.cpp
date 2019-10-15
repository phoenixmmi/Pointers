#include<iostream>
#include<conio.h>
using namespace std;

#define HORIZ_OFFSET "\t\t\t\t\t\t"

void PrintField(char Field[], const int n, char Player);
void Move(char Field[], const int n, char Player);
void Check(char Field[], const int n, char Player);

void main()
{
	setlocale(LC_ALL, "Rus");
	const int SIZE = 9;
	char Field[SIZE] = {};	//Игровое поле
	PrintField(Field, SIZE, '0');
	cout << "Еще разочек? (y || Y)";
	if (_getch() == 'y')main();
}

void PrintField(char Field[], const int n, char Player)
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
	Check(Field, n, Player);
}

void Move(char Field[], const int n, char Player)
{
	char key;
	//cout << (int)key << endl;
	bool busy;
	bool miss;
	do
	{
		busy = false;
		do
		{
			miss = false;
			key = _getch();
			if (key == 27)return;
			if (key < '1' || key > '9')miss = true;
			if (miss) cout << "Вы не попали в поле\a" << endl;
		} while (miss);
		if (Field[key - 49] == 0)Field[key - 49] = Player;
		else
		{
			cout << "Cell busy\a" << endl;
			busy = true;
		}
	} while (busy); 


	/*if (Player == 'X')PrintField(Field, n, '0');
	else PrintField(Field, n, 'X');*/
	PrintField(Field, n, Player);
}

void Check(char Field[], const int n, char Player)
{
	bool game_over = false;
		 if (Field[0] == Field[4] && Field[4] == Field[8] && Field[8] != 0) game_over = true;
	else if (Field[2] == Field[4] && Field[4] == Field[6] && Field[6] != 0) game_over = true;

	else if (Field[0] == Field[1] && Field[1] == Field[2] && Field[2] != 0) game_over = true;
	else if (Field[3] == Field[4] && Field[4] == Field[5] && Field[5] != 0) game_over = true;
	else if (Field[6] == Field[7] && Field[7] == Field[8] && Field[8] != 0) game_over = true;

	else if (Field[0] == Field[3] && Field[3] == Field[6] && Field[6] != 0) game_over = true;
	else if (Field[1] == Field[4] && Field[4] == Field[7] && Field[7] != 0) game_over = true;
	else if (Field[2] == Field[5] && Field[5] == Field[8] && Field[8] != 0) game_over = true;

		 if (game_over)
		 {
			 cout << "Player " << Player << " wins." << endl;
			 return;
		 }
		 if(Player == 'X')Move(Field, n, '0');
		 else Move(Field, n, 'X');
}