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
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int minH[MAX][2];
int hsize = 0;

void swap(int a, int b) {
    int tempW = minH[a][0];
    int tempN = minH[a][1];
    minH[a][0] = minH[b][0];
    minH[a][1] = minH[b][1];
    minH[b][0] = tempW;
    minH[b][1] = tempN;
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= hsize && minH[left][0] < minH[smallest][0])
        smallest = left;
    if (right <= hsize && minH[right][0] < minH[smallest][0])
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

void push(int wt, int node) {
    hsize++;
    minH[hsize][0] = wt;
    minH[hsize][1] = node;

    int i = hsize;
    while (i > 1 && minH[i][0] < minH[i / 2][0]) {
        swap(i, i / 2);
        i /= 2;
    }
}

void pop(int *wt, int *node) {
    if (hsize == 0) return;

    *wt = minH[1][0];
    *node = minH[1][1];

    minH[1][0] = minH[hsize][0];
    minH[1][1] = minH[hsize][1];
    hsize--;
    heapify(1);
}

int prims(int V) {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    hsize = 0;
    push(0, 0);
    int cost = 0;

    while (hsize > 0) {
        int wt, node;
        pop(&wt, &node);

        if (visited[node]) continue;
        visited[node] = true;
        cost += wt;

        for (int neigh = 0; neigh < V; neigh++) {
            if (adj[node][neigh] != 0 && !visited[neigh]) {
                push(adj[node][neigh], neigh);
            }
        }
    }

    return cost;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int result = prims(V);
    printf("Minimum Spanning Tree Weight: %d\n", result);

    return 0;
}
