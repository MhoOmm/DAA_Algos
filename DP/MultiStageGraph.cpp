#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int n = 7;
    vector<vector<pair<int, int>>> g(n);

    g[0] = {{1,1}, {2,2}, {3,5}};
    g[1] = {{4,4}, {5,11}};
    g[2] = {{4,9}, {5,5}};
    g[3] = {{5,1}};
    g[4] = {{6,2}};
    g[5] = {{6,1}};

    vector<int> d(n, INF), nxt(n, -1);
    d[n-1] = 0;

    for (int i = n-2; i >= 0; i--) {
        for (auto &e : g[i]) {
            int v = e.first, w = e.second;
            if (d[v] + w < d[i]) 
            {
                d[i] = d[v] + w, nxt[i] = v;
            }
        }
    }

    cout << "Cost: " << d[0] << "\nPath: ";
    for (int u = 0; u != -1; u = nxt[u]) cout << u << " ";
    cout << "\n";
}
