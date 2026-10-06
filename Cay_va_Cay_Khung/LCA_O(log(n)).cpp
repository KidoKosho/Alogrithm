#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán LCA (Lowest Common Ancestor) - Tìm tổ tiên chung gần nhất
 * Phương pháp: Binary Lifting (Nhảy nhị phân)
 * Độ phức tạp: 
 *  - Tiền xử lý: O(N log N)
 *  - Mỗi truy vấn: O(log N)
 * Ứng dụng:
 *  - Tìm khoảng cách giữa 2 đỉnh trên cây: dist(u, v) = depth(u) + depth(v) - 2 * depth(LCA(u, v)).
 *  - Xử lý các truy vấn đường đi trên cây.
 */

const int N = 2e5 + 5;
const int LOG = 20;

int parent_table[N][LOG];
int depth_arr[N];
long long dist_to_root[N];
vector<pair<int, int>> adj[N];

void dfs(int u, int p, int d, long long w) {
    depth_arr[u] = d;
    dist_to_root[u] = w;
    parent_table[u][0] = p;

    for (auto edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (v != p) {
            dfs(v, u, d + 1, w + weight);
        }
    }
}

int get_lca(int u, int v) {
    if (depth_arr[u] < depth_arr[v]) swap(u, v);

    // Nhảy u lên cùng độ sâu với v
    for (int j = LOG - 1; j >= 0; --j) {
        if (depth_arr[u] - (1 << j) >= depth_arr[v]) {
            u = parent_table[u][j];
        }
    }

    if (u == v) return u;

    // Cùng nhảy lên gần nhất trước LCA
    for (int j = LOG - 1; j >= 0; --j) {
        if (parent_table[u][j] != parent_table[v][j]) {
            u = parent_table[u][j];
            v = parent_table[v][j];
        }
    }

    return parent_table[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; 
    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i < n; ++i) {
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0, 0, 0);

    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent_table[i][j] = parent_table[parent_table[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int u, v; 
        cin >> u >> v;
        int ancestor = get_lca(u, v);
        long long distance = dist_to_root[u] + dist_to_root[v] - 2 * dist_to_root[ancestor];
        cout << "Khoang cach giua " << u << " va " << v << " la: " << distance << "\n";
    }

    return 0;
}
