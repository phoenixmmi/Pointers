#include<iostream>
using namespace std;

//#define BY_POINTER
#define BY_REFERENCE
#ifdef BY_POINTER
//void Exchange(int* a, int* b);
//void ExchangeWithout(int* a, int* b);
template <typename T>void ExchangeXOR(T* a, T* b);
#endif

#ifdef BY_REFERENCE
void Exchange(int& a, int& b);
#endif

void main()
{
	int a = 7;
	int b = -10;
	cout << a << "\t" << b << endl;
	Exchange(a, b);
	cout << a << "\t" << b << endl;
	//ExchangeWithout(&a, &b);
}
#ifdef BY_POINTER
template <typename T>
void ExchangeXOR(T* a, T* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
/*
void Exchange(int* a, int* b)
{
	int buffer = *a;
	*a = *b;
	*b = buffer;
}
*/
//void ExchangeWithout(int* a, int* b)
//{
//	cout << *a << " " << *b << endl;
//	*a = *a + *b;    // 5 + 7 = 12 (a == 12)
//	*b = *a - *b;    // 12 - 7 = 5 ( b == 5)
//	*a = *a - *b;    // 12 - 5 = 7 ( a = 7)
//	cout << *a << " " << *b << endl;
//}
#endif

#ifdef BY_REFERENCE
void Exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
}
#endif