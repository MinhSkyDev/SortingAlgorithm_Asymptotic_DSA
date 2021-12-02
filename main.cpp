#include "MyLib.h"


int dataSizes[5] = { 3000,10000,30000,100000,300000};

// Quy dinh mot .csv
// Dataset,selectionSort,bubbleSort,insertionSort,quickSort,mergeSort,heapSort


void RandomData() {
	fstream output;
	vector<ans> Ans;
	string comma = ",";
	string endline = "\n";
	output.open("RandomData.csv", ios::out);
	for (int dataSize = 0; dataSize < 5; dataSize++) {
		cout << "\tBo du lieu co so luong phan tu " << dataSizes[dataSize] << endl;
		int* arr = new int[dataSizes[dataSize]];
		GenerateRandomData(arr, dataSizes[dataSize]);
		Ans.push_back(getTimeOut(arr, dataSizes[dataSize]));
		delete[] arr;
	}
	string header = "Dataset,selectionSort,bubbleSort,insertionSort,quickSort,mergeSort,heapSort\n";
	output << header;
	for (int i = 0; i < 5; i++) {
		string ans_string;
		ans_string = "";
		ans_string += to_string(dataSizes[i]) + comma + to_string(Ans[i].selectionSort) + comma + to_string(Ans[i].bubbleSort)
			+ comma + to_string(Ans[i].insertionSort) + comma + to_string(Ans[i].quickSort) + comma + to_string(Ans[i].mergeSort)
			+ comma + to_string(Ans[i].heapSort) + endline;
		output << ans_string;
	}
	output.close();
}

void NearlySortedData() {
	fstream output;
	vector<ans> Ans;
	string comma = ",";
	string endline = "\n";
	output.open("NearlySortedData.csv", ios::out);
	for (int dataSize = 0; dataSize < 5; dataSize++) {
		cout << "\tBo du lieu co so luong phan tu " << dataSizes[dataSize] << endl;
		int* arr = new int[dataSizes[dataSize]];
		GenerateNearlySortedData(arr, dataSizes[dataSize]);
		Ans.push_back(getTimeOut(arr, dataSizes[dataSize]));
		delete[] arr;
	}
	string header = "Dataset,selectionSort,bubbleSort,insertionSort,quickSort,mergeSort,heapSort\n";
	output << header;
	for (int i = 0; i < 5; i++) {
		string ans_string;
		ans_string = "";
		ans_string += to_string(dataSizes[i]) + comma + to_string(Ans[i].selectionSort) + comma + to_string(Ans[i].bubbleSort)
			+ comma + to_string(Ans[i].insertionSort) + comma + to_string(Ans[i].quickSort) + comma + to_string(Ans[i].mergeSort)
			+ comma + to_string(Ans[i].heapSort) + endline;
		output << ans_string;
	}
	output.close();
}

void SortedData() {
	fstream output;
	vector<ans> Ans;
	string comma = ",";
	string endline = "\n";
	output.open("SortedData.csv", ios::out);
	for (int dataSize = 0; dataSize < 5; dataSize++) {
		cout << "\tBo du lieu co so luong phan tu " << dataSizes[dataSize] << endl;
		int* arr = new int[dataSizes[dataSize]];
		GenerateSortedData(arr, dataSizes[dataSize]);
		Ans.push_back(getTimeOut(arr, dataSizes[dataSize]));
		delete[] arr;
	}
	string header = "Dataset,selectionSort,bubbleSort,insertionSort,quickSort,mergeSort,heapSort\n";
	output << header;
	for (int i = 0; i < 5; i++) {
		string ans_string;
		ans_string = "";
		ans_string += to_string(dataSizes[i]) + comma + to_string(Ans[i].selectionSort) + comma + to_string(Ans[i].bubbleSort)
			+ comma + to_string(Ans[i].insertionSort) + comma + to_string(Ans[i].quickSort) + comma + to_string(Ans[i].mergeSort)
			+ comma + to_string(Ans[i].heapSort) + endline;
		output << ans_string;
	}
	output.close();
}

void ReversedData() {
	fstream output;
	vector<ans> Ans;
	string comma = ",";
	string endline = "\n";
	output.open("ReverseData.csv", ios::out);
	for (int dataSize = 0; dataSize < 5; dataSize++) {
		cout << "\tBo du lieu co so luong phan tu " << dataSizes[dataSize] << endl;
		int* arr = new int[dataSizes[dataSize]];
		GenerateReverseData(arr, dataSizes[dataSize]);
		Ans.push_back(getTimeOut(arr, dataSizes[dataSize]));
		delete[] arr;
	}
	string header = "Dataset,selectionSort,bubbleSort,insertionSort,quickSort,mergeSort,heapSort\n";
	output << header;
	for (int i = 0; i < 5; i++) {
		string ans_string;
		ans_string = "";
		ans_string += to_string(dataSizes[i]) + comma + to_string(Ans[i].selectionSort) + comma + to_string(Ans[i].bubbleSort)
			+ comma + to_string(Ans[i].insertionSort) + comma + to_string(Ans[i].quickSort) + comma + to_string(Ans[i].mergeSort)
			+ comma + to_string(Ans[i].heapSort) + endline;
		output << ans_string;
	}
	output.close();
}

int main() {
	cout << "--------Bat Dau Qua Trinh-----------\n";
	for (int dataOrder = 0; dataOrder < 4; dataOrder++) {
		// Thứ tự là : Data ngẫu nhiên -> gần như tăng dần -> có thứ tự tăng dần ->	thứ tự ngược
		if (dataOrder == 0) {
			cout << "Bo du lieu ngau nhien: \n";
			RandomData();
		}
		else if (dataOrder == 1) {
			cout << "Bo du lieu gan nhu co thu tu \n";
			NearlySortedData();
		}
		else if (dataOrder == 2) {
			cout << "Bo du lieu da duoc sap xep hoan toan \n";
			SortedData();
		}
		else if (dataOrder == 3) {
			cout << "Bo du lieu co thu tu giam dan \n";
			ReversedData();
		}
	}
	return 0;
}