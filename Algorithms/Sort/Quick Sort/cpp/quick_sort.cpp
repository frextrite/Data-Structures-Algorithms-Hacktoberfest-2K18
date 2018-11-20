#include <iostream>
#include <vector>

using namespace std;

int QuickSortHelper(vector<int>& a, int s, int e) {
    int pivot = a[e];
    int i = s-1;
    int j = e-1;
    while(i < j) {
        while(i < j && a[i+1] < pivot) i++;
        i++;
        while(j > i && a[j] > pivot) j--;
        swap(a[i], a[j]);
    }
    swap(a[j], a[e]);

    return j;
}

void QuickSort(vector<int>& a, int s, int e) {
    if(s >= e || s >= a.size() || e < 0)
        return;

    int index = QuickSortHelper(a, s, e);

    QuickSort(a, s, index-1);
    QuickSort(a, index+1, e);
}

int main() {
    vector<int> a = {5, 4, 8, 9, 2, 1, 3, 0, 6, 7};
    int len = a.size();
    QuickSort(a, 0, len-1);
    for(auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}