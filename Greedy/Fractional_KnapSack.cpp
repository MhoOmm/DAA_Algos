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

//**************************************************C-Code***************************************************************************** */

// #include <stdio.h>
// struct Item{
//     int weight;
//     int value;
//     double ratio;
// };
// int main(){

//     int wt[] = {10,20,30};
//     int val[] = {60,100,120};

//     struct Item it[3];
//     int n=3;
//     for(int i=0;i<3;i++)
//     {
//         it[i].weight= wt[i];
//         it[i].value = val[i];
//         it[i].ratio = (double)it[i].value/it[i].weight;
//     }
//     int W = 60;

//     for (int i = 1; i < n; i++) {
//         struct Item key = it[i];
//         int j = i - 1;

//         while (j >= 0 && it[j].ratio < key.ratio) {
//             it[j + 1] = it[j];
//             j--;
//         }
//         it[j + 1] = key;
//     }


//     double profit = 0;

//     for(int i=0;i<n;i++)
//     {
//         if(it[i].weight <= wt)
//         {
//             profit+=it[i].value;
//             W-= it[i].weight;
//         }else{
//             profit += it[i].value * ((double)W/it[i].weight);
//             break;
//         }
//     }

//     printf("%f",profit);

//     return 0;

// }