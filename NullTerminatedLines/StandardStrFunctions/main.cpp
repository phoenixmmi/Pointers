#include<iostream>

void main()
{
	setlocale(LC_ALL, "");
	const int n = 256;
	/*char str[n] = {};
	std::cout << "¬ведите строку: ";
    std::cin.getline(str, n);
	std::cout << str << std::endl;
	std::cout << strlen(str) << std::endl;

	char buffer[n] = {};
	strncpy(buffer, str,3);
	std::cout << buffer << std::endl;
	strcat()  //  выполн€ет конкатенацию строк.
	*/
	
	/*char str1[n] = "Hello";
	char str2[n] = "World";
	strncat(str1, str2, 4);
	std::cout << str1 << std::endl;
*/
	const char* words[] = 
	{
		"Hello",
		"World",
		"Computer",
		"C++",
		"Imagination"
	};
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		std::cout << words[i] << std::endl;
	}
	std::cout << std::endl;

	

	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		for (int j = i; j < sizeof(words) / sizeof(const char*); j++)
		{
			if (strcmp(words[i], words[j]) > 0)std::swap(words[i], words[j]);

		}
	}
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		std::cout << words[i] << std::endl;
	}
	std::cout << std::endl;
}