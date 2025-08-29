#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int,int>>job;
        int maxD = 0;

        for(int i =0;i<n;i++)
        {
            maxD = max(maxD,deadline[i]);
            job.push_back({deadline[i],profit[i]});
        }
        
        int maxProfit= 0;
        int count =0;
        
        sort(begin(job),end(job),[](auto&a,auto &b){
            return a.second>b.second;
        });
        
        vector<int>slot(maxD+1,-1);
        for(int i=0;i<n;i++)
        {
            int d = job[i].first;
            for(int j=d;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    maxProfit += job[i].second;
                    slot[j]=i;
                    count++;
                    break;
                }
            }
        }
        
        
        return {count,maxProfit};
    }
};