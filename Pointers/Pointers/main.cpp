#include<iostream>
using namespace std;

//#define POINTERS_BASICS
//#define DECLARATION_OF_POINTERS
#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int *pa = &a;//¬енгерской нотации
	//pa - pointer to a.
	//& - оператор вз€ти€ адреса (Address-of operator)
	cout << a << endl;
	cout << &a << endl;
	cout << pa << endl;
	cout << *pa << endl;
	//* - ќператор разыменовани€ (Dereference operator).
	//*
	int *pb;
	int b = 3;
	pb = &b;
	b;//(int)
	pb;//(int*)
	cout << pb << endl;
	cout << *pb << endl;
	//int - int
	//int* - указатель на int.
	//double - double.
	//double* - указатель на double.  
#endif // POINTERS_BASICS

#ifdef DECLARATION_OF_POINTERS
	int a, b, c;	//ќбъ€вление трех переменных одним выражением.
	int *pa, *pb, *pc;	//ќбъ€вление трех указателей одним выражением.
	int* pd, pe, pf;	//ќбъ€витс€ один указатель на int (pd), 
						//и две переменные типа int (pe и pf).
#endif

	const int n = 5;
	short Arr[n] = { 3, 5, 8, 13, 21 };
	cout << *Arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(Arr + i) << "\t";
	}
	cout << endl;
	//+, -, ++, --;
}

/*
type function(parameter1, parameter2, ...)
{
	
}

1. 
2. NUll, INT_MAX, int(), ...

*/