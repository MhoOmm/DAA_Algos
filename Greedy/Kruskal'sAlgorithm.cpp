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



#include <stdio.h>
#include <stdlib.h>

int parent[100], rank[100];

int find(int i) {
    if (i == parent[i])
        return i;
    return parent[i] = find(parent[i]);
}

void Union(int x, int y) {
    int parx = find(x);
    int pary = find(y);

    if (parx == pary) return;

    if (rank[parx] > rank[pary]) {
        parent[pary] = parx;
    } else if (rank[pary] > rank[parx]) {
        parent[parx] = pary;
    } else {
        parent[parx] = pary;
        rank[pary]++;
    }
}

int compare(const void *a, const void *b) {
    int w1 = ((int *)a)[2];
    int w2 = ((int *)b)[2];
    return w1 - w2;
}

int main() {
    int n, m;
    printf("enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int adj[m][3];

    printf("enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &adj[i][0], &adj[i][1], &adj[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    qsort(adj, m, sizeof(adj[0]), compare);

    int sum = 0;
    int result[m][3];
    int e = 0;

    for (int i = 0; i < m; i++) {
        int u = adj[i][0];
        int v = adj[i][1];
        int wt = adj[i][2];

        if (find(u) != find(v)) {
            Union(u, v);
            sum += wt;
            result[e][0] = u;
            result[e][1] = v;
            result[e][2] = wt;
            e++;
        }
    }

    printf("edges in the MST:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i][0], result[i][1], result[i][2]);
    }
    printf("min cost: %d\n", sum);

    return 0;
}
