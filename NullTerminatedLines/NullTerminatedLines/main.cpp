#include<iostream>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);
void UpperCase(char str[]);
void LowerCase(char str[]);
void Capitalize(char str[]);
void Shrink(char str[]);
void isPalindrome(char str[], const int n);


void main()
{
	setlocale(LC_ALL, "");
	//char str[] = {'H','e','l', 'l','o', '\0'}; //инициализация строки поэлементно. "\0" обозначает конец строки.
	/*char str[] = "Hello";						 
	cout << str << endl;
	cout << sizeof(str)<< endl;// Размер строки. */
	int a = 0;
	const int n = 200;
	char str[n];
	cout << "Введите строку: ";
	//cin >> str;
	InputLine(str, n);		//ввод строки
	cout << str << endl;
	StrLen(str);			//считает количество символов
	cout << StrLen(str) << endl;
	UpperCase(str);			// Переводит все в верхний регистр
	cout << str << endl;
	LowerCase(str);			//переводит в нижний регистр
	cout << str << endl;
	Capitalize(str);		//Преобразует все первые буквы слов в верхний регистр
	cout << str << endl;
	Shrink(str);			//Убирает лишние пробелы
	cout << str << endl;
	isPalindrome(str,n);	//Определяет,является ли строка палиндромом-
	cout << str << endl;
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

void UpperCase(char str[])//Из нижнего регистра в верхний
{
	for (int i = 0; str[i]; i++)
	{
		if(str[i]>='a' && str[i]<='z' || str[i]>='а' && str[i] <= 'я')str[i] -= 32;
	}
}
void LowerCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;
	}
}
void Capitalize(char str[])
{
	LowerCase(str);
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	for (int i = 0; str[i]; i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') &&
			str[i-1]== ' ')str[i] -= 32;
	}
	//мой вариант
	/*
	if (str[0] != 32)str[0] -= 32;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == 32)
		{
			if (str[i + 1] != 32)
			{
				str[i + 1] -= 32;
			}
		}
	}*/
}
void Shrink(char str[])
{	
	//вариант учителя
	for (int i = 0; str[i]; i++)
	{
		for(int i=0;str[i];i++)

		while(str[i] == ' '&& str[i + 1] == ' ')
		{
			for (int j = i + 1; str[i]; i++)str[i] = str[i + 1];
		}
	}
	//другой вариант
		/*for (int i = 0; str[i]; i++)
		{
			if (str[i] == 32 && str[i+1]==32)
			{
				for (int j = i; str[i]; j++)
				{
					str[j] = str[j + 1];
					i--;
				}
			}
		}*/
}
void isPalindrome(char str[], const int n)
{

}
