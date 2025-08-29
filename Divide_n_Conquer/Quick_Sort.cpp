#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

    int partition(vector<int>& arr, int low, int high) {
        int pi = low;
        int pivot = arr[high];

        for (int i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                swap(arr[i], arr[pi]);
                pi++;
            }
        }
        swap(arr[high], arr[pi]);
        return pi;
    }
};

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    Solution obj;
    obj.quickSort(arr, 0, n - 1);

    cout << "Sorted array (QuickSort): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
