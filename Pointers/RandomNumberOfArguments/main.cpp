#include<iostream>
using namespace std;

//First parameter - is number of arguments:
//int sum(int n, int value, ...)
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += *(&value + i);
//	}
//	cout << sum << endl;
//	return sum;
//}

int sum(int value ...)
{
	int sum = 0;
	int* p_value = &value;
	while (*p_value != 0)
	{
		sum += *p_value++;
	}
	return sum;
}

void main()
{
	cout << sum(3, 5, 8, 13, 21, 34, 0) << endl;
}

/*

*/