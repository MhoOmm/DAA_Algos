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




#include <stdio.h>
#include <stdbool.h>

#define Max 100
#define INF 100000

int minH[Max][2];
int visited[Max];
int adj[Max][Max];
int size = 0;

void swap(int a, int b) {
    int tempw = minH[a][0];
    int tempn = minH[a][1];
    minH[a][0] = minH[b][0];
    minH[a][1] = minH[b][1];
    minH[b][0] = tempw;
    minH[b][1] = tempn;
}

void heapify(int i) {
    int smallest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= size && minH[left][0] < minH[smallest][0])
        smallest = left;
    if (right <= size && minH[right][0] < minH[smallest][0])
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

void push(int wt, int node) {
    size++;
    minH[size][0] = wt;
    minH[size][1] = node;

    int i = size;
    while (i > 1 && minH[i][0] < minH[i / 2][0]) {
        swap(i, i / 2);
        i = i / 2;
    }
}

void pop(int *wt, int *node) {
    if (size == 0) return;

    *wt = minH[1][0];
    *node = minH[1][1];

    minH[1][0] = minH[size][0];
    minH[1][1] = minH[size][1];
    size--;
    heapify(1);
}

void dijkstra(int V, int src, int dist[]) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    size = 0;
    dist[src] = 0;
    push(0, src);

    while (size > 0) {
        int d, node;
        pop(&d, &node);

        if (visited[node])
            continue;
        visited[node] = true;

        for (int neig = 0; neig < V; neig++) {
            if (adj[node][neig] != 0 && !visited[neig]) {
                int wt = adj[node][neig];
                if (d + wt < dist[neig]) {
                    dist[neig] = d + wt;
                    push(dist[neig], neig);
                }
            }
        }
    }
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

    int src;
    scanf("%d", &src);

    int dist[Max];
    dijkstra(V, src, dist);

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }

    return 0;
}
