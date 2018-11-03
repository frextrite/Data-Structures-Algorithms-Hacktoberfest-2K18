#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int x) {
	int found = -1;
	int low = 0, high = n-1;

    while(low <= high) {
    	int mid = (low + high)/2;

    	if(arr[mid] < x) {
    		// search right tree
    		low = mid + 1;
    	}
    	else if(x > arr[mid]) {
    		// search right tree
    		high = mid - 1;
    	}
        else {
            found = mid;
            break;
        }
    }

    return found;
}

int main() {
	int n;
    // input size of array
    cin >> n;

    int arr[n];    
    // input array elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    // element to be found
    cin >> x;

    // sort array
    sort(arr, arr+n);

    int found = binarySearch(arr, n, x);

	if(found >= 0) {
        cout << "Element found!";
    }
    else {
        cout << "Element not found!";
    }

    return 0;
}