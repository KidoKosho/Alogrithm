#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Sắp xếp Tô-pô (Topological Sort)
 * Độ phức tạp: O(V + E)
 * Áp dụng cho: Đồ thị có hướng không có chu trình (DAG).
 * Cài đặt: DFS và thuật toán Kahn (BFS bán bậc vào).
 */

vector<vector<int>> adj;
vector<int> vis, topo;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
    topo.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    if (!(cin >> n >> m)) return 0;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);

    reverse(topo.begin(), topo.end());
    cout << "Thu tu To-po:\n";
    for (int x : topo) cout << x << " ";
    cout << "\n";

    return 0;
}
