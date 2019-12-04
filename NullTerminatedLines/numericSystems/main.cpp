#include <iostream>


char* dec_to_bin(int dec);
int bin_to_dec(char* binary);
bool isBin(char str[]);
bool is_hex_number(const char* str);
int hex_to_dec(const char* hex);

void main()
{
	setlocale(LC_ALL, "");
	/*int dec;
	cout << "¬ведите дес€тичное число: "; cin >> dec;
	char* binary = dec_to_bin(dec);
	cout << binary << endl;
	cout << "My binary " << binary << endl;*/

	/*
	const int n = 33;
	char* binary = new char[n] {};
	cout << "¬ведите двоичное число: "; cin >> binary;
	cout << isBin(binary) << endl;
	cout << bin_to_dec(binary) << endl;
	delete[]binary;
*/

	const int n = 11;
	char hex[n]{};
	std::cout << "¬ведите hex число: "; std::cin >> hex;
	std::cout << is_hex_number(hex) << std::endl;
	std::cout << hex_to_dec(hex) << std::endl;
}

char* dec_to_bin(int dec)
{
	int n = 32;
	char* binary = new char[n] {};
	for (int i = 0; dec; i++, dec /= 2)binary[i] = dec % 2 + 48;
	n = strlen(binary);
	for (int i = 0; i < n / 2; i++)std::swap(binary[i], binary[n - 1 - i]);

	/*for (n--; n >= 0; n--)
	{
		cout << binary[n];
		if (n % 8 == 0)cout << " ";
		if (n % 4 == 0)cout << " ";
	}*/
	std::cout << std::endl;
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
	for (int i = strlen(binary) - 1; i >= 0; i--)
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

bool is_hex_number(const char* str)
{
	int i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))i = 2;
	if (i == 2 && str[2] == 0)return false;
	for (; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F')
			)
			return false;
	}
	return true;
}

int hex_to_dec(const char* hex)
{
	if (!is_hex_number(hex))return 0;
	int decimal = 0;// дес€тичное число( конечный результат) 
	int power = 1;// весовой коеффициент разр€да(16^i)
	for (int i = hex[1] == 'x' || hex[1] == 'X' ? 2 : 0; hex[i]; i++)
	{
		decimal *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')decimal += hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')decimal += hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')decimal += hex[i] - 'a' + 10;
		else throw 0;
	}

	return decimal;
}