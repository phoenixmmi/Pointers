#pragma once
#include<iostream>
using namespace std;

#define DELIMITER "\n---------------------------------------------------\n"

const int ROWS = 4;	//Количество строк двумерного массива
const int COLS = 5;	//Количество элементов строки

template<typename T>void FillRand(T Arr[], const int n);
void FillRand(double Arr[], const int n);
template<typename T>void FillRand(T Arr[ROWS][COLS], const int ROWS, const int COLS);
void FillRand(double Arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void Print(T Arr[], const int n);
template<typename T>void Print(T Arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void Sort(T Arr[], const int n);
template<typename T>void Sort(T Arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T  Sum(T Arr[], const int n);
template<typename T>double Avg(T Arr[], const int n);

template<typename T>T  minValueIn(T Arr[], const int n);