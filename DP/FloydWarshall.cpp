#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 100000000;

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != INF && dist[via][j] != INF) {
                        if (dist[i][j] > dist[i][via] + dist[via][j])
                            dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
    }
};




#include <stdio.h>
#define INF 9999
#define N 10

int n, d[N][N], nxt[N][N];

void floyd() {
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]!=INF && d[k][j]!=INF && d[i][j]>d[i][k]+d[k][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                    nxt[i][j]=nxt[i][k];
                }
}

void printPath(int u,int v) {
    if(nxt[u][v]==-1) {
        printf("No path\n");
        return;
    }
    printf("%d",u+1);
    while(u!=v) {
        u=nxt[u][v];
        printf("-->%d",u+1);
    }
    printf("\n");
}

int main() {
    FILE *f=fopen("inDiAdjMat2.dat","r");
    n=5;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            fscanf(f,"%d",&d[i][j]);
            if(d[i][j]==0 && i!=j) d[i][j]=INF;
            if(d[i][j]!=INF) nxt[i][j]=j;
            else nxt[i][j]=-1;
        }
    fclose(f);
    floyd();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            if(d[i][j]==INF) printf("INF ");
            else printf("%d ",d[i][j]);
        printf("\n");
    }
    int u,v;
    printf("Enter source and destination: ");
    scanf("%d%d",&u,&v);
    printf("Shortest Path from vertex %d to vertex %d: ",u,v);
    printPath(u-1,v-1);
    printf("Path weight: %d\n",d[u-1][v-1]);
}
