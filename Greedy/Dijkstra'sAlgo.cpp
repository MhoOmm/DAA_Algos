#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[V];
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(V,INT_MAX);
        
        result[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &temp:adj[node])
            {
                int dist = temp.first;
                int neig = temp.second;
                
                if(d+dist < result[neig]){
                    result[neig] = d+dist;
                    pq.push({d+dist,neig});
                }
                
            }
        }
        return result;
    }
};