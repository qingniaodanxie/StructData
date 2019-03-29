/*
 * @Author:Jiyuan Wang
 * @Date:29/03/2019
 * @Platform:Visual Studio 2017 Professional
 * Note:此代码中使用了Template 函数 namespace 来处理函数之间的调用。
 */

#include <iostream>
#include <algorithm>
#include "SortHelper.h"

using namespace std;

namespace BoolSort	//冒泡排序
{
	int *BoolSort(int *arr , int len)
	{
		for(int i = 0 ;i < len ;i++)
		{
			for(int j = 0;j < len ;j++)
			{
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
		}
		return arr;
	}
}

template<typename T>		//选择排序
	void ChooiceSort(int *arr , int len)
	{
		for(int i=0;i<len-1;i++)
		{
			int minIndex = i;
			for(int j = i+1 ;j <len ;j++ )
				if (arr[j] > arr[minIndex])
					minIndex = j;
				swap(arr[minIndex] , arr[i]);
			
		}
	}

namespace InsertSort		//插入排序
{

	int* InsertSort(int *arr, int n)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (arr[j] > arr[j-1])
					swap(arr[j], arr[j-1]);
				else
					break;
			}
		}
		return arr;
	}
}

template<typename T>
void __merge(T arr[] , int l ,int mid ,int r)
{
	/**
	 *  i j ,指向当前正要考虑排序的数组，K指向下一个将要排序的数组
	 */

	T *aux= new T[r - l + 1];
	for(int i=l;i<=r;i++)
	{
		aux[i-l] = arr[i];
	}
	int i = l, j = mid + 1;
	for(int k =l;k<=r;k++)
	{
		if(i>mid)
		{
			arr[k] = aux[j - l];
			j++;
		}

		else if( j >r)
		{
			arr[k] = aux[i - l];
			i++;
		}

		else if(aux[i-l] <aux[j-l])
		{
			arr[k] = aux[i - l];
			i++;
		}

		else
		{
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}



//[l...r] 区间的排序
template<typename T>
void __mergeSort(T arr[] , int l ,int r) 
{
	if (l >= r)
		return;
	int mid = (l + r) / 2; // L+R有可能发生溢出
	__mergeSort(arr ,l ,mid);
	__mergeSort(arr, mid+1, r);
	__merge(arr ,l , mid ,r);
}


template<typename T>
void MergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1);   //__的命名。视为私有对象

}

/*
 * 快速排序 
 */

//f返回值 p 。使得 [l..p-1] < arr[p] <[p+1...r]
template<typename T>
int __partition(T arr[] ,int l , int r)
{
	T v = arr[l];
	int j = l;
	for(int i = l+1; i <= r; i++)
	{
			if(arr[i] < v)
			{
				swap(arr[j + 1], arr[i]);
				j++;
			}
	}
	swap(arr[l] , arr[j]);
	return j;
}

template<typename T>
void __quickSort(T arr[] , int l, int r)
{
	if (l >= r)
		return;
	int p = __partition(arr , l ,r);
	__partition(arr, l, p - 1);
	__partition(arr, p+1, r);
}


template<typename T>
void QuickSort(T arr[] , int n)
{
	//对arr [0....r]进行排序；
	__quickSort(arr, 0, n - 1);
}

int main( void )

{
	int n = 10;	//生成随机数的个数
	int *arr = SortTestHelper::generateRadomArray(n, 0, n);

	/**
	 * 冒泡排序的调用
	 */
	// SortTestHelper::printArr<>(arr, n);
	// BoolSort::BoolSort(arr, n);
	// SortTestHelper::printArr<>(arr, n);

	/*
	 * 插入排序的调用
	 */
	// SortTestHelper::printArr(arr, n);
	// InsertSort::InsertSort(arr, n);
	// SortTestHelper::printArr(arr, n);

	/*
	 * 归并排序的调用
	 */
	// SortTestHelper::printArr(arr, n);
	// MergeSort(arr, n);
	// SortTestHelper::printArr(arr, n);

	/*
	 * 快速排序的调用
	 */
	SortTestHelper::printArr(arr, n);
	QuickSort(arr, n);
	SortTestHelper::printArr(arr, n);

	 
	delete[] arr;
	system("pause");
	return 0;
}