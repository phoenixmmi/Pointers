#pragma once
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

template<typename T>T** allocate(const int m, const int n);
template<typename T>void clear(T** arr, const int m);

template<typename T>void FillRand(T** Arr, const int m, const int n);

template<typename T>void print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T* arr, int& n, T value);
template<typename T>T* insert(T* arr, int& n, T value, int index);

template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);
template<typename T>T* erase(T* arr, int& n, int index);

template<typename T>T** push_row_back(T** arr, int& m, const int n);
template<typename T>T** push_row_front(T** arr, int& m, const int n);
template<typename T>T** insert(T** arr, int& m, const int n, int index);

template<typename T>T** pop_row_back(T** arr, int& m, const int n);
template<typename T>T** pop_row_front(T** arr, int& m, const int n);
template<typename T>T** erase(T** arr, int& m, const int n, int index);

template<typename T>T** push_col_back(T** arr, const  int m, int& n);
template<typename T>T** push_col_front(T** arr, const  int m, int& n);
template<typename T>T** insert_col(T** arr, const int m, int& n, int index);

template<typename T>T** pop_col_back(T** arr, const int m, int& n);
template<typename T>T** pop_col_front(T** arr, const int m, int& n);
template<typename T>T** erase_col(T** arr, const int m, int& n, int index);