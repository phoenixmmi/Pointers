#include<iostream>
using namespace std;
#define		FIRST_CONNER			(char)214
#define		SECOND_CONNER			(char)191
#define		THIRD_CONNER			(char)200
#define		FORTH_CONNER			(char)190
#define		HORIZONTAL_LINE_UPPER	(char)196
#define		HORIZONTAL_LINE_LOWER	(char)205
#define		VERTICAL_LINE_LEFT		(char)186
#define		VERTICAL_LINE_RIGHT		(char)179
#define		BOX						(char)219
void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите размер доски: "; cin >> n;
	//n++;
	//setlocale(LC_ALL, "C");
	//for (int i = 0; i <=n; i++)
	//{
	//	/*if (i == 0)
	//	{
	//		cout << FIRST_CONNER;
	//		for (int j = 0; j < n; j++)
	//		{
	//			cout << HORIZONTAL_LINE<< HORIZONTAL_LINE;
	//		}
	//		cout << SECOND_CONNER << endl;
	//	}
	//	cout << VERTICAL_LINE;
	//	if (i % 2 == 0)
	//	{
	//		for (int j = 0; j < n; j++)
	//		{
	//			cout <<BOX<< " ";
	//		}
	//	}
	//	else
	//	{
	//		for (int j = 0; j < n; j++)
	//		{
	//			cout << " "<<BOX;
	//		}
	//	}
	//	
	//	cout << VERTICAL_LINE << endl;
	//	if (i == n-1)
	//	{
	//		cout << THIRD_CONNER;
	//		for (int j = 0; j < n; j++)
	//		{
	//			cout << HORIZONTAL_LINE<<HORIZONTAL_LINE;
	//		}
	//		cout << FORTH_CONNER << endl;
	//	}*/
	//	for (int j = 0; j <= n; j++)
	//	{
	//		if (i == 0 && j == 0)cout <<		FIRST_CONNER;
	//		else if (i == 0 && j == n)cout <<	SECOND_CONNER;
	//		else if (i == n && j == 0)cout <<	THIRD_CONNER;
	//		else if (i == n && j == n)cout <<	FORTH_CONNER;
	//		else if (i == 0) cout <<			HORIZONTAL_LINE_UPPER<<HORIZONTAL_LINE_UPPER;
	//		else if (i == n) cout <<			HORIZONTAL_LINE_LOWER<<HORIZONTAL_LINE_LOWER;
	//		else if (j == 0 )cout <<			VERTICAL_LINE_LEFT;
	//		else if (j == n)cout <<				VERTICAL_LINE_RIGHT;
	//		else if ((i+j)%2==0)cout <<			BOX<<BOX;
	//		else cout <<						"  ";
	//	}
	//	cout << endl;
	//}
	for (int a = 0; a < n; a++)
	{
		if (a % 2 == 0)
		{
			for (int b = 0; b < n; b++)
			{

				for (int i = 0; i < n; i++)
				{
					if (i % 2 == 0)
					{
						for (int j = 0; j < n; j++)
						{
							cout << "* ";
						}
					}
					else
					{
						for (int j = 0; j < n; j++)
						{
							cout << "  ";
						}
					}
				}	cout << endl;
			}
		}
		else
		{
			for (int b = 0; b < n; b++)
			{
				for (int i = 0; i < n; i++)
				{
					if (i % 2 == 0)
					{
						for (int j = 0; j < n; j++)
						{
							cout << "  ";
						}
					}
					else
					{
						for (int j = 0; j < n; j++)
						{
							cout << "* ";
						}
					}
				}	cout << endl;
			}
		}
	}
}