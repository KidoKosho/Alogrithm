#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Edmonds-Karp tìm Luồng cực đại (Maximum Flow)
 * Độ phức tạp: O(V * E^2)
 * Phương pháp:
 *  - Dùng thuật toán BFS tìm đường tăng luồng ngắn nhất (ít cạnh nhất) từ s đến t trên đồ thị còn dư (Residual Graph).
 *  - Lặp lại cho tới khi không còn đường tăng luồng.
 */

const long long INF = 1e18;

struct EdmondsKarp {
    int n, s, t;
    vector<vector<long long>> capacity;
    vector<vector<int>> adj;

    EdmondsKarp(int n, int s, int t) : n(n), s(s), t(t) {
        capacity.assign(n + 1, vector<long long>(n + 1, 0));
        adj.resize(n + 1);
    }

    void add_edge(int u, int v, long long cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += cap; // Hỗ trợ trường hợp có nhiều cạnh song song
    }

    long long bfs(vector<int> &parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, long long>> q;
        q.push({s, INF});

        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] > 0) {
                    parent[v] = u;
                    long long new_flow = min(flow, capacity[u][v]);
                    if (v == t) return new_flow;
                    q.push({v, new_flow});
                }
            }
        }
        return 0;
    }

    long long max_flow() {
        long long flow = 0;
        vector<int> parent(n + 1);
        long long new_flow;

        while ((new_flow = bfs(parent)) > 0) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) return 0;

    EdmondsKarp ek(n, s, t);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long cap;
        cin >> u >> v >> cap;
        ek.add_edge(u, v, cap);
    }

    cout << "Luong cuc dai (Edmonds-Karp): " << ek.max_flow() << "\n";
    return 0;
}
