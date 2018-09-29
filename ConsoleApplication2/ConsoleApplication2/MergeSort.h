#pragma once


// 插入排序，用于和归并排序搭配使用
template<typename T>
void insertionSort(T arr[], int l, int r) {

	for (int i = l + 1; i <= r; i++)
	{
		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

// 将 arr[l...mid] 和 arr[mid...r] 两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

	int c = r - l + 1;
#if defined(_MSC_VER)
	T *aux = new T[c];
#else
	T aux[c];
#endif
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}
	int i = l;
	int j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
#if defined(_MSC_VER)
	delete[] aux;
#endif
}

// 递归使用归并排序，对 arr[l...r] 的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {

	/*if (l >= r)
	{
		return;
	}*/
	if (r - l < 100)
	{
		insertionSort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;	// 这里有一个问题，当 l 和 r 都比较大的时候，两者相加可能会溢出

	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	// 归并排序优化，已排好顺序的就不需要合并。此方法对于本来就比较有序的数组进一步提升性能。
	if (arr[mid] > arr[mid + 1])
	{
		__merge(arr, l, mid, r);
	}
}

// 归并排序，时间复杂度 O(n^logn)，需要额外的空间，空间复杂度提升。
// 自顶向下，递归归并
template<typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n - 1);
}