#include <bits/stdc++.h>
using namespace std
// Recursion + memo
// TC-O(N^3)
// SC-O(N^2)+Stack space O(N)
class Solution {
  public:
  
    int t[101][101];
  
    int solve(vector<int>&arr, int i,int j)
    {
        
        if(i==j)return 0;
        int mini = INT_MAX;
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        
        for(int k = i;k<j;k++)
        {
            int steps = (arr[i-1]*arr[k]*arr[j])+solve(arr,i,k)+solve(arr,k+1,j);
            mini = min(mini,steps);
        }
        return t[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n =arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr,1,n-1);
        
    }
};

// Bottom Up approach
// TC:- O(N^3)
// SC:- O(N^2) 


class Solution {
public:
    int t[101][101];

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();

        
        for (int i = 1; i < n; i++) {
            t[i][i] = 0;
        }

        
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = 1e9;
                for (int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] 
                                + t[i][k] 
                                + t[k + 1][j];
                    mini = min(mini, steps);
                }
                t[i][j] = mini; 
            }
        }

        return t[1][n - 1]; 
    }
};

