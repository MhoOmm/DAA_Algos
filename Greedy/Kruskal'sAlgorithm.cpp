#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    vector<int>parent;
    vector<int>rank;
  
    int find(int x)
    {
        if(parent[x]==x)
        {
          return x;  
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);
        
        if(parx == pary)
        {
          return;  
        }
        
        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // code here
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i = 0; i<V; i++)
	        parent[i] = i;
	        
        sort(begin(edges),end(edges),[](auto edge1,auto edge2){
            return edge1[2]<edge2[2];
        });
        int sum= 0;
        
        for(auto &temp:edges)
        {
            int x = temp[0];
            int y = temp[1];
            int wt = temp[2];
            
            int j = find(x);
            int k = find(y);
            
            if(j==k)
            {
                continue;
            }else{
                Union(x,y);
                sum+=wt;
            }
        }
        
        return sum;
        
    }
};