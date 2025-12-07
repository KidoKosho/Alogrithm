#include <bits/stdc++.h>
using namespace std;

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
    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) unite(u, v);
        else cout << (find(u) == find(v) ? "YES" : "NO") << endl;
    }
    return 0;
}
