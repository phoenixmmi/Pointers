#include<iostream>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);
void UpperCase(char str[]);
void LowerCase(char str[]);
void Capitalize(char str[]);
void Shrink(char str[]);
bool isPalindrome(char str[]);
void RemoveSpaces(char str[]);
bool isNumber(char str[]);
int StrToInt(char str[]);
int culk(char str[]);
bool isBin(char str[]);
int BinToDec(char str[]);
void dec_to_bin(int dec);



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
	/*UpperCase(str);			// Переводит все в верхний регистр
	cout << str << endl;
	LowerCase(str);			//переводит в нижний регистр
	cout << str << endl;
	Capitalize(str);		//Преобразует все первые буквы слов в верхний регистр
	cout << str << endl;
	Shrink(str);			//Убирает лишние пробелы
	cout << str << endl;
	cout << isPalindrome(str) << endl;	//Определяет,является ли строка палиндромом-

	cout << isNumber(str) << endl;

	int num = StrToInt(str);
	cout << num << endl;*/
	cout << isBin(str) << endl;

	int num = BinToDec(str);
	cout << num << endl;

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
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;
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
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') &&
			str[i - 1] == ' ')str[i] -= 32;
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
		for (int i = 0; str[i]; i++)

			while (str[i] == ' '&& str[i + 1] == ' ')
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
bool isPalindrome(char str[])
{
	/*int n = StrLen(str);
	char* buffer = new char[n+1] {};
	for (int i = 0; i < n; i++)buffer[i] = str[i];
	LowerCase(buffer);
	RemoveSpaces(buffer);
	n = StrLen(buffer);
	for (int i = 0; i < n/2; i++)
	{
		if (buffer[i] != str[n - 1 - i])return false;

	}
	return true;*/
	int n = StrLen(str);
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] == ' ')i++, n++;
		if (str[n - 1 - i] == ' ')n--;
		if (str[i] != str[n - 1 - i])
		{
			if (str[i] + 32 != str[n - 1 - i] && str[i] != str[n - i - 1] + 32)return false;
		}
	}
	return true;
}
void RemoveSpaces(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ')
		{
			for (int j = 0; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

bool isNumber(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] > '0' && str[i] <= '9'))return false;
	}
	return true;
}

int StrToInt(char str[])
{
	int num = 0;
	if (isNumber(str))
	{
		for (int i=0;str[i];i++)
		{
			num *= 10;
			num += str[i]-48;
		}
	}
	return num;

}
bool isBin(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1') return false;
	}
	return true;
}

int BinToDec(char str[])
{
	int n = StrLen(str);
	int num = 0;
	int two = 1;
	if (isBin(str))
	{
		for (int i = n - 1; i >= 0; i--)
		{
		}

	}
	/*for (int i = 0;str[0] ; i++)
	{
	num = str[i] * two;
	two *= 2;
	   }*/
		/*	if (str[i] == str[0] && str[0] == '48')
			{
				num += 0 * 2 + 0;
			}
			else if (str[i] == str[0] && str[0] == '49')
			{
				num += 0 * 2 + 1;
			}

			if (!str[0])
			{
				num = num * 2 + str[i]-48;
			}*/
	return num;
}