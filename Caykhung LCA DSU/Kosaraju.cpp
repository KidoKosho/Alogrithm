#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int color[N], parent[N];
int n, m;
int start_cycle = -1, end_cycle = -1;

bool dfs(int u) {
    color[u] = 1; // đang duyệt
    for (int v : adj[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (color[v] == 1) {
            // phát hiện chu trình
            start_cycle = v;
            end_cycle = u;
            return true;
        }
    }
    color[u] = 2; // duyệt xong
    return false;
}

