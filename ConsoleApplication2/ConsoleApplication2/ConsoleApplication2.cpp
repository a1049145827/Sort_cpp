// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

// 选择排序
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

// 插入排序 时间复杂度低一些
template<typename T>
void insetionSort(T arr[], int n) {

	for (size_t i = 1; i < n; i++)
	{
		for (int j = i, j > 0 && arr[j] < arr[j - 1], j --) {
			
			swap(arr[j], arr[j - 1]);
		}
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

	int n = 100000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Insetion Sort", insetionSort, arr, n);
	delete[] arr;

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
