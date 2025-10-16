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
                int neigh_wt = temp.first;
                int neigh = temp.second;
                
                pq.push({neigh_wt,neigh});
                
            }
        }
        
        return sum;
        
    }
};




#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int parent[MAX];
int key[MAX];
bool mstSet[MAX];

int minKey(int n) {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n) {
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[1] = 0;
    parent[1] = -1;
    for (int count = 1; count <= n - 1; count++) {
        int u = minKey(n);
        mstSet[u] = true;
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}

void printMST(int n) {
    int sum = 0;
    printf("Edges in the MST:\n");
    for (int i = 2; i <= n; i++) {
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
        sum += graph[i][parent[i]];
    }
    printf("Min cost: %d\n", sum);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    primMST(n);
    printMST(n);
    return 0;
}
