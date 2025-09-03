#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    typedef pair<int,int>P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<P>>adj(V);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
        
        vector<bool>visited(V,false);
        int sum = 0;
        
        while(!pq.empty())
        {
            int wt= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            if(visited[node])continue;
            
            visited[node] = true;
            sum+=wt;
            
            for(auto &temp:adj[node])
            {
                int neigh = temp.first;
                int neigh_wt = temp.second;
                
                pq.push({neigh,neigh_wt});
                
            }
        }
        
        return sum;
        
    }
};