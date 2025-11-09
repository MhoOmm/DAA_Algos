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



#include<stdio.h>

void merge(int l,int r,int mid,int arr[])
{
    int b[r-l+1];
    int i = l;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=r)
    {
        if(arr[i]<arr[j])
        {
            b[k++] = arr[i++];
        }else{
            b[k++] = arr[j++];
        }
    }

    while(i<=mid)
    {
       b[k++] = arr[i++]; 
    }

    while(j<=r)
    {
        b[k++] = arr[j++];
    }

    for(int i=0;i<(r-l+1);i++)
    {
        arr[l+i] = b[i];
    }
}
void mergeSort(int arr[] ,int l ,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(l,r,mid,arr);
}

int main(){

    int arr[] = {1,2,4,3,5,6};
    int l =0;
    int r = 5;
    mergeSort(arr,l,r);

    for(int i =0;i<6;i++)
    {
      printf("%d\n",arr[i]);
    }
    return 0;
}
