#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Dinic tìm Luồng cực đại (Maximum Flow)
 * Độ phức tạp: 
 *  - Đồ thị tổng quát: O(V^2 * E)
 *  - Mạng đơn vị (Unit Networks / Bipartite Matching): O(E * sqrt(V)) -> Cực kỳ nhanh!
 * Phương pháp:
 *  - Dùng BFS để xây dựng đồ thị phân tầng (Level Graph).
 *  - Dùng DFS với con trỏ ptr để tìm luồng cản (Blocking Flow).
 */

struct Edge {
    int to;
    long long cap;
    long long flow;
    int rev; // Chỉ số của cạnh đảo trong adj[to]
};

struct Dinic {
    int n, s, t;
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;

    Dinic(int n, int s, int t) : n(n), s(s), t(t), adj(n + 1), level(n + 1), ptr(n + 1) {}

    void add_edge(int from, int to, long long cap) {
        adj[from].push_back({to, cap, 0, (int)adj[to].size()});
        adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1}); // Cạnh đảo có dung lượng = 0
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto &edge : adj[u]) {
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[u] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int u, long long pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;

        for (int &cid = ptr[u]; cid < (int)adj[u].size(); ++cid) {
            auto &edge = adj[u][cid];
            int trg = edge.to;

            if (level[u] + 1 != level[trg] || edge.cap - edge.flow == 0) continue;

            long long tr = dfs(trg, min(pushed, edge.cap - edge.flow));
            if (tr == 0) continue;

            edge.flow += tr;
            adj[trg][edge.rev].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long max_flow() {
        long long flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, 1e18)) {
                flow += pushed;
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

    Dinic dinic(n, s, t);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long cap;
        cin >> u >> v >> cap;
        dinic.add_edge(u, v, cap);
    }

    cout << "Luong cuc dai (Dinic): " << dinic.max_flow() << "\n";
    return 0;
}
