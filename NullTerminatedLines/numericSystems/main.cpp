#include <iostream>
using namespace std;

char* dec_to_bin(int dec);
int bin_to_dec(char* binary);
bool isBin(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	/*int dec;
	cout << "Введите десятичное число: "; cin >> dec;
	char* binary = dec_to_bin(dec);
	cout << binary << endl;
	cout << "My binary " << binary << endl;*/


	const int n = 33;
	char* binary = new char[n] {};
	cout << "Введите двоичное число: "; cin >> binary;
	cout << isBin(binary) << endl;
	cout << bin_to_dec(binary) << endl;

	delete[]binary;
}

char* dec_to_bin(int dec)
{
	int n = 32;
	char* binary = new char[n] {};
	for (int i = 0; dec; i++, dec /= 2)binary[i] = dec % 2 + 48;
	n = strlen(binary);
	for (int i = 0; i < n / 2; i++)swap(binary[i], binary[n - 1 - i]);

	/*for (n--; n >= 0; n--)
	{
		cout << binary[n];
		if (n % 8 == 0)cout << " ";
		if (n % 4 == 0)cout << " ";
	}*/
	cout << endl;
	return binary;
}

bool isBin(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1') return false;
	}
	return true;
}

int bin_to_dec(char* binary)
{
	int dec = 0;
	int pow = 1;
	for (int i = strlen(binary)-1; i >= 0; i--)
	{
		if (binary[i] == '1')dec += pow;
		pow *= 2;
	}
	return dec;

	//var1
	/*int sum = 0;
	int total=0;
	if (isBin(binary))
	{
		for (int i = strlen(binary); i >= 0; i--)
		{
			if (binary[i] == '1')sum += total;
			if (total == 0)total = 1;
			else total *= 2;
		}
	}
	return sum;
	*/

}