#include "MyLib.h"


void selectionSort(int* a, int n) {
	int minIndex = 0;
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIndex])
				minIndex = j;
		}
		swap(a[i], a[minIndex]);
	}
}

void insertionSort(int* a, int n) {
	int key, j;
	for (int i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void bubbleSort(int* a, int n) {
	bool haveSwap = false;
	for (int i = 0; i < n - 1; i++) {
		haveSwap = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		}
		if (haveSwap == false)
			break;
	}
}

void merge(int* a, int left, int mid, int right) {
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;
	int* leftArray = new int[sizeLeft];
	int* rightArray = new int[sizeRight];

	for (int i = 0; i < sizeLeft; i++) {
		leftArray[i] = a[left + i];
	}
	for (int i = 0; i < sizeRight; i++) {
		rightArray[i] = a[mid + 1 + i];
	}
	int iLeft = 0;
	int iRight = 0;
	int iArray = left;
	while (iLeft < sizeLeft && iRight < sizeRight) {
		if (leftArray[iLeft] <= rightArray[iRight]) {
			a[iArray++] = leftArray[iLeft++];
		}
		else {
			a[iArray++] = rightArray[iRight++];
		}
	}
	while (iLeft < sizeLeft) {
		a[iArray++] = leftArray[iLeft++];
	}
	while (iRight < sizeRight) {
		a[iArray++] = rightArray[iRight++];
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int* a, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

int partition(int* a, int left, int right) {

	int pivot = (left + right) / 2;
	int key = a[pivot];
	swap(a[right], a[pivot]); // Dua pivot ve cuoi mang
	int i = left - 1;
	for (int j = left; j <= right -1; j++) {
		if (a[j] < key) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);
	return i + 1;
}

void quickSort(int* a, int left, int right) {
	if (left < right) {

		int pivot = partition(a, left, right);
		quickSort(a, left, pivot-1);
		quickSort(a, pivot+1, right);
	}
}

void heapify(int* a, int n, int root) {
	int indexMax = root;
	int leftChild = 2 * root + 1;
	int rightChild = 2 * root + 2;

	if ( leftChild < n && a[leftChild] > a[indexMax])
		indexMax = leftChild;
	if ( rightChild <n && a[rightChild] > a[indexMax])
		indexMax = rightChild;
	if (indexMax != root) {
		swap(a[root], a[indexMax]);
		heapify(a, n, indexMax);
	}
}

void heapSort(int* a, int n) { // Build maxheap roi sau do ta chuyen ve cuoi mang thi se thanh la tang dan
	//Build heap from array
	for (int i = (n / 2)-1; i >= 0; i--) {
		heapify(a, n, i);
	}
	// Heapsort
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void printArray(int* a, int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int* copyArray(int* a, int n) {
	int* copy = new int[n];
	for (int i = 0; i < n; i++) {
		copy[i] = a[i];
	}
	return copy;
}

ans getTimeOut(int* arr, int n) {
	ans result;

	//selectionSort
	cout << "\t\tTien hanh selectionSort \n";
	int* arr_selectionSort = copyArray(arr, n); //Copy an alternativeArray
	clock_t start_selectionSort, end_selectionSort;
	start_selectionSort = clock();
	selectionSort(arr_selectionSort, n);
	end_selectionSort = clock();
	result.selectionSort = (double)(end_selectionSort - start_selectionSort) / CLOCKS_PER_SEC;
	result.selectionSort *= 1000.0;
	delete[] arr_selectionSort;
	cout << "\t\tDa hoan thanh selectionSort\n";

	//bubbleSort
	cout << "\t\tTien hanh bubbleSort \n";
	int* arr_bubbleSort = copyArray(arr, n);
	clock_t start_bubbleSort, end_bubbleSort;
	start_bubbleSort = clock();
	bubbleSort(arr_bubbleSort, n);
	end_bubbleSort = clock();
	result.bubbleSort = (double)(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;
	result.bubbleSort *= 1000.0;
	delete[] arr_bubbleSort;
	cout << "\t\tDa hoan thanh bubbleSort \n";

	//insertionSort
	cout << "\t\tTien hanh insertionSort \n";
	int* arr_insertionSort = copyArray(arr, n);
	clock_t start_insertionSort, end_insertionSort;
	start_insertionSort = clock();
	insertionSort(arr_insertionSort, n);
	end_insertionSort = clock();
	result.insertionSort = (double)(end_insertionSort - start_insertionSort) / CLOCKS_PER_SEC;
	result.insertionSort *= 1000.0;
	delete[] arr_insertionSort;
	cout << "\t\tDa hoan thanh insertionSort\n";

	//quickSort
	cout << "\t\tTien hanh quickSort \n";
	int* arr_quickSort = copyArray(arr, n);
	clock_t start_quickSort, end_quickSort;
	start_quickSort = clock();
	quickSort(arr_quickSort, 0, n - 1);
	end_quickSort = clock();
	result.quickSort = (double)(end_quickSort - start_quickSort) / CLOCKS_PER_SEC;
	result.quickSort *= 1000.0;
	delete[] arr_quickSort;
	cout << "\t\tDa hoan thanh quickSort \n";

	//mergeSort
	cout << "\t\tTien hanh mergeSort \n";
	int* arr_mergeSort = copyArray(arr, n);
	clock_t start_mergeSort, end_mergeSort;
	start_mergeSort = clock();
	mergeSort(arr_mergeSort, 0, n - 1);
	end_mergeSort = clock();
	result.mergeSort = (double)(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
	result.mergeSort *= 1000.0;
	delete[] arr_mergeSort;
	cout << "\t\tDa hoan thanh mergeSort\n";

	//heapSort
	cout << "\t\tTien hanh heapSort \n";
	int* arr_heapSort = copyArray(arr, n);
	clock_t start_heapSort, end_heapSort;
	start_heapSort = clock();
	heapSort(arr_heapSort, n);
	end_heapSort = clock();
	result.heapSort = (double)(end_heapSort - start_heapSort) / CLOCKS_PER_SEC;
	result.heapSort *= 1000.0;
	delete[] arr_heapSort;
	cout << "\t\tDa hoan thanh heapSort \n";

	return result;
}