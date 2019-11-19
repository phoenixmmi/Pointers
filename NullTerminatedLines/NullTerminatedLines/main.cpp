#include<iostream>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);


void main()
{
	setlocale(LC_ALL, "");
	//char str[] = {'H','e','l', 'l','o', '\0'};0б
	/*char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str)<< endl;*/
	int a = 0;
	const int n = 20;
	char str[n];
	cout << "¬ведите строку: ";
	//cin >> str;
	InputLine(str, n);
	cout << str << endl; 
	StrLen(str);
	cout << StrLen(str) << endl;
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}