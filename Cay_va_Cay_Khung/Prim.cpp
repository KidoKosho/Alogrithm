#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Prim tìm Cây khung nhỏ nhất (Minimum Spanning Tree - MST)
 * Cài đặt: Priority Queue (Min-Heap)
 * Độ phức tạp: O(E log V)
 * Ứng dụng:
 *  - Tìm cây khung nhỏ nhất trên đồ thị vô hướng liên thông.
 *  - Đặc biệt hiệu quả với đồ thị dày (Dense Graph: E xấp xỉ V^2).
 */

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vector<bool> inMST(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});
    long long totalWeight = 0;
    int count = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue; 
        inMST[u] = true;
        totalWeight += weight;
        count++;

        for (auto &[w, v] : adj[u]) {
            if (!inMST[v]) pq.push({w, v});
        }
    }

    if (count < n) {
        cout << "Do thi khong lien thong, khong ton tai cay khung!\n";
    } else {
        cout << "Tong trong so cay khung nho nhat (Prim): " << totalWeight << "\n";
    }
    return 0;
}
