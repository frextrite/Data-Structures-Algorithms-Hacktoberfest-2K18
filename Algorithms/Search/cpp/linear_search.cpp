#include <iostream>
using namespace std;

int main() {
    int n;
    // input size of array
    cin >> n;

    int arr[n];    
    // input array elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x, pos = -1;
    // element to be found
    cin >> x;

    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            pos = i;
            break;
        }
    }

    if(pos >= 0) {
        cout << "Found element at position " << pos + 1;
    }
    else {
        cout << "Element not found!";
    }

    return 0;
}