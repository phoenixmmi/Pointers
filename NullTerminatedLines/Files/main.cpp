#include <iostream>
#include <fstream>

//#define WRITE_TO_FILE
//#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	std::cout << "Hello World";
	std::ofstream fout;  // создание потока
	fout.open("File.txt", std::ios::app); // app- дозапись строки .

	fout << "Hello Hell" << std::endl;
	/*fout.open("AnotherFile.txt");
	fout << "Sam privet";*/

	fout.close();

	system("notepad File.txt");
#endif

#ifdef READ_TO_FILE

	std::ifstream fin;// создание потока.
	fin.open("File.txt");

	const int n = 256;
	char sz_buffer[n] = {};
	 char string1[n]={};
	 char string2[n]={};


	while (!fin.eof())
	{
		
		fin.getline(sz_buffer,n);
	 std::cout << sz_buffer << std::endl;
	}
	fin.close();
#endif
	std::ofstream fout("final.txt");
	std::ifstream fin;// создание потока.
	fin.open("File.txt");

	const int n = 256;
	char string_mac[n] = {};
	char string_ip[n] = {};


	while (!fin.eof())
	{		
		fin >> string_mac;
		fin >> string_ip;
		std::cout << string_ip << "\t" << string_mac << std::endl;
		fout << string_ip << "\t" << string_mac << std::endl;
		
	}


	fin.close();
	fout.close();

	system("notepad Final.txt");
}