#include <iostream>
using namespace std;

void arrinput(int arr[50], int size){
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
}
void printarr(int arr[50], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}

void bubbleSort(int arr[], int size){
	int nIter = size - 1;

	for(int i = 0; i < nIter; ++i){
		for(int curIdx = 0; curIdx < nIter - i; ++curIdx){
			if (arr[curIdx] > arr[curIdx + 1]){
				int tmp = arr[curIdx];
				arr[curIdx] = arr[curIdx + 1];
				arr[curIdx + 1] = tmp;
			}
		}
	}
}

//WILL WORK WHEN ARRAY DOES NOT HAVE DUPLICATE ELEMENTS
void unionNew(int arr1[50], int arr2[], int size1, int size2){
	int arr[50], k = 0;
	int i, j;
	i = j = 0;
	while (i < size1 && j < size2) {
		if(arr1[i] < arr2[j]) {
			arr[k] = arr1[i];
			i++;
		} else if(arr1[i] > arr2[j]) {
			arr[k] = arr2[j];
			j++;
		} else {
			arr[k] = arr1[i];
			i++;
			j++;
		}
		k++;
	}
	
	while(i < size1) {
		arr[k] = arr1[i];	
		k++;
		i++;
	}
	
	while(j < size2) {
		arr[k] = arr2[j];	
		k++;
		j++;
	}
	
	printarr(arr, k);
}

void intersection_new(int arr1[], int arr2[], int size1, int size2) {
	int ans[50], k = 0, n;
	int i, j;
	i = j = 0;
	while( i < size1 && j < size2) {
		if (arr1[i] == arr2[j]) {
			ans[k] = arr1[i];
			k++;
			i++;
			j++;
		} else if(arr1[i] > arr2[j]) {
			j++;
		} else if (arr1[i] < arr2[j]) {
			i++;
		}
	}
	n = k;
	printarr(ans, n);
}

int main(){
	int arr1[50];
	int arr2[50];
	int size1, size2, n, index;
	cin >> size1;
	cin >> size2;
	arrinput(arr1, size1);
	arrinput(arr2, size2);
	bubbleSort(arr1, size1);
	bubbleSort(arr2, size2);
	cout << "sorted arrays: ";
	printarr(arr1, size1);
	cout << "\n";
	printarr(arr2, size2);
	cout << "\n";
	cout << "union: " << endl;
	unionNew(arr1, arr2, size1, size2);
	cout << "\n";
	cout << "intersection: "<< endl;
	intersection_new(arr1, arr2, size1, size2);
	return 0;
}