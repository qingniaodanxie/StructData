#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper
{
	int *generateRadomArray(int n, int rangL, int rangR)
	{
		int *arr = new int[n];
		srand(time(NULL));
		assert(rangL <= rangR);
		for(int i = 0 ; i < n ; i++)
		{
			arr[i] = rand() % (rangR- rangL + 1) + rangL;
		}
		return arr;
	}
	template<typename T>
	void printArr(T arr[] , int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

}