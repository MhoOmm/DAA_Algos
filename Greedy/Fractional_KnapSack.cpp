#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n= wt.size();
        
        vector<pair<double,pair<int,int>>>profit;
        
        for(int i=0;i<n;i++)
        {
            double ratio = (double)val[i] / wt[i];
            profit.push_back({ratio, {val[i], wt[i]}});
            
        }
        
        sort(profit.begin(),profit.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });
        
        double mxval = 0.0;
        
        for(int i = 0;i<n;i++)
        {
            int value  = profit[i].second.first; 
            int weight = profit[i].second.second;
            
            if(weight <= capacity)
            {
                mxval += value;
                capacity -= weight;
            }else{
                mxval +=profit[i].first * capacity;
                capacity = 0;
            
            }
        }
        
        return mxval;
    }
};

// C-code

#include <stdio.h>
#include <stdlib.h>

struct item {
    int id;
    int weight;
    int profit;
    double ratio;
};

void heapify(struct item arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].ratio > arr[largest].ratio) {
        largest = l;
    }
    if (r < n && arr[r].ratio > arr[largest].ratio) {
        largest = r;
    }

    if (largest != i) {
        struct item temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(struct item arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        struct item temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    struct item s[100];
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("id: ");
        scanf("%d", &s[i].id);
        printf("weight: ");
        scanf("%d", &s[i].weight);
        printf("profit: ");
        scanf("%d", &s[i].profit);

        s[i].ratio = (double)s[i].profit / s[i].weight;
    }

    heapSort(s, n);
    heapSort(s, n);

    for (int i = 0; i < n / 2; i++) {
        struct item temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }


    int cap;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &cap);

    double maxval = 0.0;
    double taken[n];

    for (int i = 0; i < n; i++) {
        taken[i] = 0.0;
    }

    for (int i = 0; i < n; i++) {
        if (cap == 0) break;

        if (s[i].weight <= cap) {
            maxval += s[i].profit;
            cap -= s[i].weight;
            taken[i] = 1.0;
        } else {
            taken[i] = (double)cap / s[i].weight;
            maxval += s[i].profit * taken[i];
            cap = 0;
        }
    }
    printf("\nitem   profit   weight   amount\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d \t %d \t %.5f\n",
               s[i].id, s[i].profit, s[i].weight, taken[i]);
    }
    printf("Maximum profit: %.5f\n", maxval);

    return 0;
}

