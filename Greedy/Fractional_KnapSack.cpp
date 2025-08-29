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
