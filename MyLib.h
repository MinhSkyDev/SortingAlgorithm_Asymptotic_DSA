#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct ans {
	double selectionSort;
	double insertionSort;
	double bubbleSort;
	double quickSort;
	double mergeSort;
	double heapSort;
};

void swap(int& a, int& b);
void quickSort(int* a, int left, int right);
void selectionSort(int* a, int n);
void bubbleSort(int* a, int n);
void insertionSort(int* a, int n);
void heapSort(int* a, int n);
void mergeSort(int* a, int left, int right);
void printArray(int* a, int n);


void GenerateReverseData(int a[], int n);
void GenerateRandomData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateSortedData(int a[], int n);


ans getTimeOut(int* arr, int n);