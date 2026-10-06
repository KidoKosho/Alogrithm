#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán SPFA (Shortest Path Faster Algorithm)
 * Bản cải tiến bằng Queue của Bellman-Ford để tối ưu thời gian chạy trên đồ thị thực tế.
 * Độ phức tạp: Trung bình O(k * E) với k nhỏ (~ 2-3), trường hợp xấu nhất O(V * E).
 * Ứng dụng:
 *  - Tìm đường đi ngắn nhất nguồn đơn khi có cạnh trọng số âm.
 *  - Phát hiện chu trình âm nhanh hơn nhiều so với Bellman-Ford thông thường.
 *  - Thường được dùng làm thuật toán tìm đường tăng luồng trong Min Cost Max Flow (MCMF).
 */

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

// Trả về true nếu phát hiện chu trình âm, ngược lại false
bool spfa(int start_node, int n, const vector<vector<Edge>> &adj, vector<long long> &dist, vector<int> &parent) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    vector<int> cnt(n + 1, 0);          // Đếm số lần đỉnh vào queue
    vector<bool> in_queue(n + 1, false); // Kiểm tra đỉnh có đang nằm trong queue không
    queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);
    in_queue[start_node] = true;
    cnt[start_node] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (const auto &edge : adj[u]) {
            int v = edge.to;
            long long w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    cnt[v]++;
                    // Nếu một đỉnh được nới lỏng và vào queue > n lần -> tồn tại chu trình âm
                    if (cnt[v] > n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
    }

    vector<long long> dist;
    vector<int> parent;
    bool has_neg_cycle = spfa(start_node, n, adj, dist, parent);

    if (has_neg_cycle) {
        cout << "Do thi chua chu trinh am!\n";
    } else {
        cout << "Khoang cach tu dinh " << start_node << ":\n";
        for (int i = 1; i <= n; ++i) {
            cout << "Dinh " << i << ": ";
            if (dist[i] == INF) cout << "Khong the den duoc\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}
