#include<stdio.h>

int linear_search(int Arr[], int n, int find){

	for(int i=0; i<n; i++){
		if(Arr[i] == find){
			return i;
		}
	}
	return -1;
}

int main(){

	int Arr[] = {10,9,8,7,6,11,12,13,14,15}, n=10, loc, find = 6;

	loc = linear_search(Arr, n, find);

	if(loc == -1){
		printf("%d not found in array\n", find);
	}
	else{
		printf("%d found at index %d\n", find, loc);
	}

	return 0;
}
