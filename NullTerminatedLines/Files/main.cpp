#include <iostream>
#include <fstream>

//#define WRITE_TO_FILE
//#define READ_TO_FILE
//#define SWAPING 
#define VAR_OF_TEACHER
//#define MY_VAR
//#define NAME
//#define SIZE



void main()
{
	setlocale(LC_ALL, "");

#ifdef NAME
	const int n = 256;
	char name[n] = {};

	std::cout << "¬ведите им€ файла: " << std::endl;
	std::cin >> name;

	if (!strstr(name, ".txt"))
	{
		strcat(name, ".txt");
	}
#ifdef WRITE_TO_FILE
	std::cout << "Hello World";
	std::ofstream fout;  // создание потока
	fout.open(name, std::ios::app); // app- дозапись строки .

	fout << "Hello Hell" << std::endl;
	/*fout.open("AnotherFile.txt");
	fout << "Sam privet";*/

	fout.close();

	system(name);
#endif
#endif

#ifdef READ_TO_FILE

	std::ifstream fin;// создание потока.
	fin.open("File.txt");

	const int n = 256;
	char sz_buffer[n] = {};
	char string1[n] = {};
	char string2[n] = {};


	while (!fin.eof())
	{

		fin.getline(sz_buffer, n);
		std::cout << sz_buffer << std::endl;
	}
	fin.close();
#endif
#ifdef SWAPING
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
#endif
#ifdef VAR_OF_TEACHER

	const int n = 256;
	char source_file_name[n]{};
	char dest_file_name[n]{};
	std::cout << "¬ведите им€ исходного файла: "; std::cin >> source_file_name;
	std::cout << "¬ведите им€ конечного файла: "; std::cin >> dest_file_name;

	if(!strstr(source_file_name, ".txt"))strcat(source_file_name, ".txt");
		if(!strstr(dest_file_name, ".txt"))strcat(dest_file_name,".txt");

		std::ifstream fin(source_file_name);
		std::ofstream fout(dest_file_name);

		char mac_buffer[n]{};
		char ip_buffer[n]{};

		if (fin.is_open())
		{
			for (int i = 1; !fin.eof(); i++)
			{
				fin >> mac_buffer >> ip_buffer;
				fout << "host- " << i << std::endl;
				fout << "{\n";
				fout << "\thardware - ethernet\t" << mac_buffer << ";\n";
				fout << "\tfixed-address\t" << ip_buffer << ";\n";
				fout << "}\n";

				std::cout << "host- " << i << std::endl;
				std::cout << "{\n";
				std::cout << "\thardware - ethernet\t" << mac_buffer << ";\n";
				std::cout << "\tfixed-address\t" << ip_buffer << ";\n";
				std::cout << "}\n";
			}
		}

		fin.close();
			fout.close();

			char command[n] = "notepad ";
			strcat(command, dest_file_name);
			system(command);
#endif
#ifdef MY_VAR
	std::ofstream fout("404result.txt");
	std::ifstream fin;// создание потока.
	fin.open("File.txt");

	const int n = 256;
	char sz_buffer [n] = {};
	int p = 1;
	while (!fin.eof())
	{
		fin.getline(sz_buffer, n);
		int i = 0;
		fout << "host 404-" << p++;
		fout << "\n{\n";
		fout << "\t\t hardware ethernet \t\t";
		do 
		{
			fout << sz_buffer[i]; i++;
		} while (sz_buffer[i] != '\t');
		fout << ";\n";
		fout << "\t\t fixed - address \t\t";
		while (sz_buffer[i] == '\t') 
		{
			i++;
		};
		do { fout << sz_buffer[i]; i++; } while (sz_buffer[i] != 0);
		fout << ";\n";
		fout <<"}\n\n";
	}
	system("PAUSE");
	fin.close();
	fout.close();

	system("notepad 404result.txt");
#endif
#ifdef SIZE
	std::ifstream fin;// создание потока.
	fin.open("File.txt");
	int size = 0;
	file.seekg(0, std::ios::end);
	size = file.tellg();
	std::cout << "‘айл весит : " << size << " байт" << std::endl;
	file.close();
#endif


}