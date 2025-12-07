#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, topo;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
    topo.push_back(u);
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);

    reverse(topo.begin(), topo.end());
    for (int x : topo) cout << x << " ";
    cout << "\n";
}
