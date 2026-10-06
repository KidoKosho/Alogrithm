#include <bits/stdc++.h>
using namespace std;

/**
 * Cấu trúc DSU (Disjoint Set Union) / Cấu trúc các tập hợp rời nhau
 * Tối ưu: Path Compression (Nén đường đi) + Union by Size/Rank
 * Độ phức tạp: O(alpha(N)) gần như O(1) cho mỗi truy vấn
 * Ứng dụng:
 *  - Quản lý các tập hợp rời nhau.
 *  - Dùng trong thuật toán Kruskal tìm cây khung nhỏ nhất.
 *  - Kiểm tra tính liên thông động, phát hiện chu trình trên đồ thị vô hướng.
 */

vector<int> parent, sz;

void init(int n) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
}

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    init(n);

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) unite(u, v);
        else cout << (find(u) == find(v) ? "YES\n" : "NO\n");
    }
    return 0;
}
