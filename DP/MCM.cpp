#include <bits/stdc++.h>
using namespace std;
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




#include  <stdio.h>

int t[201][201];
int s[201][201];

int mcm(int arr[],int i,int j)
{
    if(i==j){
        return 0;
    }
    int mini = 1000000000;

    for(int k=i;k<j;k++)
    {
        int steps = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(mini>steps){
            mini = steps;
            s[i][j] = k;
        }
    }
    return mini;
}

void opt(int i,int j){

    if(i==j)
    {
        printf("A%d",i);
        return;
    }else{
        printf("(");
        opt(i,s[i][j]);
        opt(s[i][j]+1, j);
        printf(")");
    }

}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n = 5;
    for(int i =0;i<201;i++)
    {
        for(int j=0;j<201;j++)
        {
            t[i][j] = -1;
            s[i][j] = -1;
        }
    }

    int ans = mcm(arr,1,n-1);
    printf("%d",ans);
    opt(1,n-1);
    return 0;

}