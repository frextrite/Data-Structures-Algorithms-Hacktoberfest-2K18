#include<stdio.h>

int binary_search(int Arr[], int n, int find){

	int low = 0, high = n-1, mid;

	while(low <= high){
		mid = (low+high)/2;

		if(Arr[mid] == find){
			return mid;
		}
		else if(Arr[mid] > find){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return -1;
}

int main(){

	int Arr[] = {1,2,3,4,5,11,12,13,14,15}, n=10, loc, find = 2;

	loc = binary_search(Arr, n, find);

	if(loc == -1){
		printf("%d not found in array\n", find);
	}
	else{
		printf("%d found at index %d\n", find, loc);
	}

	return 0;
}
