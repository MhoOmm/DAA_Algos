
class Solution {
  public:

    void merge(vector<int>& a, int l,int mid,int r)
    {
        vector<int> b(r - l + 1);
        int i = l;
        int j = mid+1;
        int k = 0;
        
        while(i<= mid && j<=r)
        {
           if(a[i]<a[j])
           {
               b[k] = a[i];
               i++;
           }else{
               b[k] = a[j];
               j++;
           }
           k++;
        }
        while (i <= mid) {
            b[k++] = a[i++];
        }
        while (j <= r) {
            b[k++] = a[j++];
        }
        
        // final copy to the og array
        for (int x = 0; x < b.size(); x++) {
            a[l + x] = b[x];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return ;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};