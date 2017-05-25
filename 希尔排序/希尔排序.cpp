// 希尔排序.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 50
int main()
{
	srand((int)time(0));
	int array[N];
	int i = 0;
	for (i = 0; i < N; i++)
	{
		array[i] = rand()%1000;
		cout << " " << array[i];
	}
	cout << endl;

	int h[10];
	for (i = 1, h[0] = 1; i < 10; i++)
		h[i] = 3 * h[i - 1] + 1;

	int hi = 0;
	for (hi = 0; h[hi] < N; hi++);

	for (; hi >= 0; hi--)
	{
		int i = 0;
		int j = 0;
		for (i = h[hi]; i < N; i++)
		{
			for (j = i; j >= h[hi] && array[j] < array[j - h[hi]]; j -= h[hi]) 
			{
				int t = array[j];
				array[j] = array[j - h[hi]];
				array[j - h[hi]] = t;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		cout << " " << array[i];
		if (array[i] < array[i - 1])
			cout << "error";

	}
	cin >> i;
    return 0;
}

