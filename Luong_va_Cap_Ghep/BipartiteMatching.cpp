#include <bits/stdc++.h>
using namespace std;

/**
 * THUẬT TOÁN TÌM CẶP GHÉP CỰC ĐẠI TRÊN ĐỒ THỊ HAI PHÍA (Bipartite Matching)
 * 
 * Cung cấp 2 phương pháp kinh điển trong Lập trình thi đấu:
 * 1. Thuật toán Hopcroft-Karp: Độ phức tạp O(E * sqrt(V)) -> Rất nhanh, giải được N, M lên tới 10^5.
 * 2. Thuật toán DFS (Thuật toán Kuhn): Độ phức tạp O(V * E) -> Cực kỳ ngắn gọn, dễ nhớ, thích hợp N, M <= 1000 - 2000.
 */

// ============================================================================
// 1. THUẬT TOÁN HOPCROFT-KARP O(E * sqrt(V))
// ============================================================================
struct HopcroftKarp {
    int n, m; // n: số đỉnh tập trái (1..n), m: số đỉnh tập phải (1..m)
    vector<vector<int>> adj;
    vector<int> match_left, match_right, dist;

    HopcroftKarp(int n, int m) : n(n), m(m), adj(n + 1), match_left(n + 1, 0), match_right(m + 1, 0), dist(n + 1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; ++u) {
            if (match_left[u] == 0) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = 1e9;
            }
        }

        dist[0] = 1e9;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[0]) {
                for (int v : adj[u]) {
                    if (dist[match_right[v]] == (int)1e9) {
                        dist[match_right[v]] = dist[u] + 1;
                        q.push(match_right[v]);
                    }
                }
            }
        }
        return dist[0] != (int)1e9;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u]) {
                if (dist[match_right[v]] == dist[u] + 1) {
                    if (dfs(match_right[v])) {
                        match_right[v] = u;
                        match_left[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = 1e9;
            return false;
        }
        return true;
    }

    int max_matching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; ++u) {
                if (match_left[u] == 0 && dfs(u)) {
                    matching++;
                }
            }
        }
        return matching;
    }
};

// ============================================================================
// 2. THUẬT TOÁN KUHN (DFS) O(V * E)
// ============================================================================
struct KuhnMappings {
    int n, m;
    vector<vector<int>> adj;
    vector<int> match_right;
    vector<bool> visited;

    KuhnMappings(int n, int m) : n(n), m(m), adj(n + 1), match_right(m + 1, 0), visited(n + 1) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int u) {
        if (visited[u]) return false;
        visited[u] = true;

        for (int v : adj[u]) {
            if (match_right[v] == 0 || dfs(match_right[v])) {
                match_right[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_matching() {
        int matching = 0;
        for (int u = 1; u <= n; ++u) {
            fill(visited.begin(), visited.end(), false);
            if (dfs(u)) {
                matching++;
            }
        }
        return matching;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p; // n: tập trái, m: tập phải, p: số cạnh
    if (!(cin >> n >> m >> p)) return 0;

    HopcroftKarp hk(n, m);
    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        hk.add_edge(u, v);
    }

    int ans = hk.max_matching();
    cout << "So cap ghep cuc dai (Hopcroft-Karp): " << ans << "\n";
    cout << "Cac cap ghep:\n";
    for (int u = 1; u <= n; ++u) {
        if (hk.match_left[u] != 0) {
            cout << "  Trai " << u << " <--> Phai " << hk.match_left[u] << "\n";
        }
    }

    return 0;
}
