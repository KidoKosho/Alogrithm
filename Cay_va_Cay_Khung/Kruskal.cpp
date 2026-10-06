#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Kruskal tìm Cây khung nhỏ nhất (Minimum Spanning Tree - MST)
 * Độ phức tạp: O(E log E) hoặc O(E log V)
 * Phương pháp:
 *  1. Sắp xếp danh sách cạnh theo trọng số tăng dần.
 *  2. Dùng cấu trúc DSU duyệt qua từng cạnh, nếu 2 đầu mút chưa cùng tập hợp thì thêm vào cây khung.
 */

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    int n;
    vector<int> parent, sz;
    DSU(int n) : n(n), parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        return (u == parent[u]) ? u : (parent[u] = find(parent[u]));
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_weight = 0;
    int edge_count = 0;
    vector<Edge> mst_edges;

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total_weight += e.w;
            mst_edges.push_back(e);
            edge_count++;
            if (edge_count == n - 1) break;
        }
    }

    if (edge_count < n - 1) {
        cout << "Do thi khong lien thong, khong ton tai cay khung!\n";
    } else {
        cout << "Tong trong so cay khung nho nhat (Kruskal): " << total_weight << "\n";
        cout << "Cac canh trong cay khung:\n";
        for (const auto &e : mst_edges) {
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
        }
    }

    return 0;
}
