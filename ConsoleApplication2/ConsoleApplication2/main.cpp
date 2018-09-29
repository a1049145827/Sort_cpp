//
//  main.cpp
//  Sort_cpp
//
//  Created by Bruce on 2018/9/27.
//  Copyright © 2018 qianbao. All rights reserved.
//

#include "pch.h"

#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

// 冒泡排序，双层for循环，每次**比较到不符合顺序就**把两个元素位置互换
// 冒泡排序，时间复杂度 O(n^2)，swap函数时间复杂度 O(n^2)，效率很低。优化过后，可以将swap函数的时间复杂度将为O(n)，效率会比选择排序还略高一点;
template<typename T>
void bubbleSort(T arr[], int n) {
    if (n < 2) {
        return;
    }
    
    // 未优化的代码，性能最差
    /*for (int i = 0; i < n; i++)
     {
     for (int j = i; j < n; j++)
     {
     if (arr[i] > arr[j]) {
     swap(arr[i], arr[j]);
     }
     }
     }*/
    
    // 有一个疑惑，此处这么优化是否合理，冒泡排序本身就是每次判断到不符合条件就交换，这样改完更像是选择排序了。
    // 优化过后，由于swap函数比较耗时，所以尽量减少调用次数，每次调用swap都把最大的数字放到最后，这样每次就可以少遍历一个元素，跟选择排序性能差不多。
    int max = n - 1;
    while (max > 0)
    {
        int j = 0;
        for (int i = j + 1; i < max + 1; i++)
        {
            if (arr[i] > arr[j]) {
                j = i;
            }
        }
        
        // cout << j << " " << max << " " << arr[j] << " " << arr[max] << endl;
        swap(arr[j], arr[max]);
        
        max --;
    }
}

// 选择排序，双层for循环，每次内循环**挑选**出本轮循环的最小/大值，然后与本轮循环的第一个元素互换位置
// 选择排序，时间复杂度 O(n^2)，swap函数时间复杂度 O(n);
template<typename T>
void selectionSort(T arr[], int n) {
    if (n < 2) {
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 插入排序 时间复杂度比 O(n^2) 低一些，每次for循环可以提前终止，并且赋值语句代替了交换函数，所以效率会高。对近乎有序的数组，效率会更高。
template<typename T>
void insetionSort(T arr[], int n) {
    
    // 首次实现，swap函数时间复杂度大一些，所以性能不一定比选择排序高
    /*for (int i = 1; i < n; i ++)
     {
     for (int j = i; j > 0 && (arr[j] < arr[j - 1]); j--) {
		swap(arr[j], arr[j - 1]);
     }
     }*/
    
    // 插入排序 优化
    for (int i = 1; i < n; i++)
    {
        T e = arr[i];    // 拷贝副本
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

// 希尔排序，插入排序的衍变
template<typename T>
void shellSort(T arr[], int n) {
    
}

// 归并排序，自底向上归并排序
template<typename T>
void mergeSortBU(T arr[], int n) {
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz < n; i += sz + sz) {
			// 对 arr[i...i+sz-1] 和 arr[i+sz...i+sz+sz-1] 进行归并
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}
}

template<typename T>
int __quick(T arr[], int l, int r) {

	T v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
    
	return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {

	if (l >= r) {
		return;
	}

	int q = __quick(arr, l, r);

	__quickSort(arr, l, q - 1);
	__quickSort(arr, q + 1, r);
}

// 快速排序
template<typename T>
void quickSort(T arr[], int n) {
	__quickSort(arr, 0, n - 1);
}

void sortA() {
    
    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    selectionSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sortB() {
    
    double b[4] = { 4.4, 3.3, 2.2, 1.1 };
    selectionSort(b, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

void sortC() {
    
    string c[4] = { "D", "C", "B", "A" };
    selectionSort(c, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

void sortStudent() {
    
    const int n = 5;
    Student s[n] = { {"A", 98}, {"E", 96}, {"F", 99}, {"D", 95}, {"C", 96} };
    selectionSort(s, n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    std::cout << " - Hello World!\n";
    
    /*sortA();
     
     sortB();
     
     sortC();
     
     sortStudent();*/
    
    int n = 500000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    //int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
//    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    //int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);
	int *arr5 = SortTestHelper::copyIntArray(arr, n);
    
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
//    SortTestHelper::testSort("Insertion Sort", insetionSort, arr2, n);
    //SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr4, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr5, n);
    
	/*insertionSort(arr, 0, n - 1);
	if (SortTestHelper::isSorted(arr, n - 1))
	{
		cout << "Success !" << endl;
	}
	else {
		cout << "Failed !" << endl;
	}*/

    delete[] arr;
//    delete[] arr2;
    //delete[] arr3;
    delete[] arr4;
	delete[] arr5;

	std::cout << " - The End!\n";

    return 0;
}

// 条件编译：识别编译器
//How to detect the compiler name
//Compiler name macros indicate a specific compiler, such as Intel ICC or Microsoft Visual Studio. There are exceptions. See the notes after the table.
//
//#if defined(__clang__)
///* Clang/LLVM. ---------------------------------------------- */
//
//#elif defined(__ICC) || defined(__INTEL_COMPILER)
///* Intel ICC/ICPC. ------------------------------------------ */
//
//#elif defined(__GNUC__) || defined(__GNUG__)
///* GNU GCC/G++. --------------------------------------------- */
//
//#elif defined(__HP_cc) || defined(__HP_aCC)
///* Hewlett-Packard C/aC++. ---------------------------------- */
//
//#elif defined(__IBMC__) || defined(__IBMCPP__)
///* IBM XL C/C++. -------------------------------------------- */
//
//#elif defined(_MSC_VER)
///* Microsoft Visual Studio. --------------------------------- */
//
//#elif defined(__PGI)
///* Portland Group PGCC/PGCPP. ------------------------------- */
//
//#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
///* Oracle Solaris Studio. ----------------------------------- */
//
//#endif
