// Top Down Approach
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int n ;
    int t[1001][1001];
    int solve(int i,vector<int> &val,vector<int> &wt,int W){
        if(i>=n || W<=0)
        {
            return 0;
        }
        if(t[i][W]!=-1)
        {
            return t[i][W];
        }
        
        if(wt[i]>W)
        {
            return t[i][W]=solve(i+1,val,wt,W);
        }
        
        int take =val[i]+ solve(i+1,val,wt,W-wt[i]);
        int skip = solve(i+1,val,wt,W);
        
        return t[i][W]=max(take,skip);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n  = val.size();
        memset(t,-1,sizeof(t));
        return solve(0,val,wt,W);
        
    }
};


// Bottom Up 

