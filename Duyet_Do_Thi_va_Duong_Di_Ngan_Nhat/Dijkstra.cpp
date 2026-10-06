#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Dijkstra (Tìm đường đi ngắn nhất nguồn đơn với trọng số không âm)
 * Cài đặt: Priority Queue (Min-Heap)
 * Độ phức tạp: O((V + E) log V)
 * Ứng dụng:
 *  - Tìm đường đi ngắn nhất từ đỉnh nguồn s tới tất cả các đỉnh khác khi trọng số cạnh >= 0.
 */

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

void dijkstra(int start_node, int n, const vector<vector<Edge>> &adj, vector<long long> &dist, vector<int> &parent) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &edge : adj[u]) {
            int v = edge.to;
            long long w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// Truy vết đường đi từ đỉnh nguồn tới target
vector<int> get_path(int target, const vector<int> &parent) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start_node;
    if (!(cin >> n >> m >> start_node)) return 0;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Đồ thị vô hướng. Nếu có hướng thì bỏ dòng này
    }

    vector<long long> dist;
    vector<int> parent;
    dijkstra(start_node, n, adj, dist, parent);

    cout << "Khoang cach ngan nhat tu dinh " << start_node << ":\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Dinh " << i << ": ";
        if (dist[i] == INF) cout << "Khong the den duoc\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
