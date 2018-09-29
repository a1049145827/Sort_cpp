#pragma once


// �����������ں͹鲢�������ʹ��
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

// �� arr[l...mid] �� arr[mid...r] �����ֽ��й鲢
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

// �ݹ�ʹ�ù鲢���򣬶� arr[l...r] �ķ�Χ��������
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

	int mid = (l + r) / 2;	// ������һ�����⣬�� l �� r ���Ƚϴ��ʱ��������ӿ��ܻ����

	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	// �鲢�����Ż������ź�˳��ľͲ���Ҫ�ϲ����˷������ڱ����ͱȽ�����������һ���������ܡ�
	if (arr[mid] > arr[mid + 1])
	{
		__merge(arr, l, mid, r);
	}
}

// �鲢����ʱ�临�Ӷ� O(n^logn)����Ҫ����Ŀռ䣬�ռ临�Ӷ�������
// �Զ����£��ݹ�鲢
template<typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n - 1);
}