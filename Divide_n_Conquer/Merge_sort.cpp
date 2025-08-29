#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& a, int l, int mid, int r) {
        vector<int> b(r - l + 1);
        int i = l;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= r) {
            if (a[i] < a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }

        while (i <= mid) {
            b[k++] = a[i++];
        }
        while (j <= r) {
            b[k++] = a[j++];
        }

        // copy back to original array
        for (int x = 0; x < b.size(); x++) {
            a[l + x] = b[x];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    Solution obj;
    obj.mergeSort(arr, 0, n - 1);

    cout << "Sorted array (MergeSort): ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
