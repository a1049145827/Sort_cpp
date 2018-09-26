// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

// 选择排序，时间复杂度 O(n^2)，swap函数时间复杂度 O(n^2)，效率很低。优化过后，可以将swap函数的时间复杂度将为O(n)，效率会比选择排序还略高一点;
template<typename T>
void bubbleSort(T arr[], int n) {
	// 未优化的代码，性能最差
	/*for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}*/
	
	// 优化过后，由于swap函数比较耗时，所以尽量减少调用次数，每次调用swap都把最大的数字放到最后，这样每次就可以少遍历一个元素，跟选择排序性能差不多。
	int max = n - 1;
	while (max > 0)
	{
		int j = 0;
		for (size_t i = j + 1; i < max + 1; i++)
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

// 选择排序，时间复杂度 O(n^2)，swap函数时间复杂度 O(n);
template<typename T>
void selectionSort(T arr[], int n) {
	for (size_t i = 0; i < n; i++)
	{
		int minIndex = i;
		for (size_t j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

// 插入排序 时间复杂度低一些，每次for循环可以提前终止，并且赋值语句代替了交换函数，所以效率会高很多。对近乎有序的数组，效率会更高。
template<typename T>
void insetionSort(T arr[], int n) {

	// 首次实现，swap函数时间复杂度大一些，所以性能不一定比选择排序高
	/*for (size_t i = 1; i < n; i ++)
	{
		for (size_t j = i; j > 0 && (arr[j] < arr[j - 1]); j--) {
			swap(arr[j], arr[j - 1]);
		}
	}*/

	// 插入排序 优化
	for (size_t i = 1; i < n; i++)
	{
		T e = arr[i];	// 拷贝副本
		int j;
		for (j = i; j > 0 && arr[j-1] > e; j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}

void sortA() {

	int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	selectionSort(a, 10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
}

void sortB() {

	float b[4] = { 4.4, 3.3, 2.2, 1.1 };
	selectionSort(b, 4);
	for (size_t i = 0; i < 4; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	delete[] b;
}

void sortC() {

	string c[4] = { "D", "C", "B", "A" };
	selectionSort(c, 4);
	for (size_t i = 0; i < 4; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	delete[] c;
}

void sortStudent() {

	const int n = 5;
	Student s[n] = { {"A", 98}, {"E", 96}, {"F", 99}, {"D", 95}, {"C", 96} };
	selectionSort(s, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i];
	}
	cout << endl;

	delete[] s;
}

int main()
{
    std::cout << "Hello World!\n"; 

	/*sortA();

	sortB();

	sortC();

	sortStudent();*/

	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	// int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Insetion Sort", insetionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	
	delete[] arr;
	delete[] arr2;
	delete[] arr3;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
