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




// #include <stdio.h>
// #include <stdlib.h>

// int parent[100];
// int rank[100];

// int find(int x)
// {
//     if(parent[x] == x)
//     {
//         return x;
//     }

//     return parent[x] = find(parent[x]);
// }

// void Union(int x,int y)
// {
//     int parx = find(x);
//     int pary = find(y);

//     if(parx==pary)
//     {
//         return;
//     }

//     if(rank[parx] > rank[pary])
//     {
//         parent[pary] = parx; 
//     }
//     else if(rank[parx]< rank[pary])
//     {
//         parent[parx] = pary;
//     }else{
//         parent[parx] = pary;
//         rank[pary]++;
//     }
// }

// int comp(const void *a, const void *b) {
//     const int *p1 = (const int *)a;
//     const int *p2 = (const int *)b;
//     return p1[2] - p2[2]; 
// }
// int kruskal(int n,int edges[n][3])
// {
//     qsort(edges,n,sizeof(edges[0]),comp);
//     int cost = 0;

//     for(int i=0;i<n;i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         int wt = edges[i][2];

//         int p1 = find(u);
//         int p2 = find(v);

//         if(p1==p2)
//         {
//             continue;
//         }else{
//             cost+=wt;
//             Union(u,v);
//         }
//     }

//     return cost;
// }

// int main(){
//     for (int i = 0; i < 5; i++) {
//         parent[i] = i;
//         rank[i] = 0;
//     }
//     int edge[5][3] = { { 0, 1, 10 },
//                        { 0, 2, 6 },
//                        { 0, 3, 5 },
//                        { 1, 3, 15 },
//                        { 2, 3, 4 } };

//     printf("%d",kruskal(5, edge));

//     return 0;
// }



