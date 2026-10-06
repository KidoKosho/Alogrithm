#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Bellman-Ford
 * Độ phức tạp: O(V * E)
 * Ứng dụng:
 *  - Tìm đường đi ngắn nhất nguồn đơn trên đồ thị có trọng số âm (không chứa chu trình âm).
 *  - Phát hiện chu trình âm có thể tới được từ đỉnh nguồn.
 */

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

// Trả về true nếu phát hiện chu trình âm, ngược lại false
bool bellman_ford(int start_node, int n, const vector<Edge> &edges, vector<long long> &dist, vector<int> &parent) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    dist[start_node] = 0;

    // Lặp n - 1 lần nới lỏng cạnh
    for (int i = 1; i <= n - 1; ++i) {
        bool any_update = false;
        for (const auto &edge : edges) {
            if (dist[edge.u] < INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                parent[edge.v] = edge.u;
                any_update = true;
            }
        }
        if (!any_update) break; // Tối ưu: Nếu không có cập nhật nào thì dừng sớm
    }

    // Lần lặp thứ n để kiểm tra chu trình âm
    for (const auto &edge : edges) {
        if (dist[edge.u] < INF && dist[edge.u] + edge.w < dist[edge.v]) {
            return true; // Tồn tại chu trình âm tới được
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start_node;
    if (!(cin >> n >> m >> start_node)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist;
    vector<int> parent;
    bool has_negative_cycle = bellman_ford(start_node, n, edges, dist, parent);

    if (has_negative_cycle) {
        cout << "Do thi chua chu trinh am!\n";
    } else {
        cout << "Khoang cach tu " << start_node << ":\n";
        for (int i = 1; i <= n; ++i) {
            cout << "Dinh " << i << ": ";
            if (dist[i] == INF) cout << "Khong the den duoc\n";
            else cout << dist[i] << "\n";
        }
    }

    return 0;
}
