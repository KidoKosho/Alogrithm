#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Floyd-Warshall
 * Độ phức tạp: O(V^3)
 * Bộ nhớ: O(V^2)
 * Ứng dụng:
 *  - Tìm đường đi ngắn nhất giữa MỌI CẶP ĐỈNH (All-Pairs Shortest Path).
 *  - Rất ngắn gọn, dễ cài đặt cho đồ thị nhỏ (V <= 400 - 500).
 *  - Xử lý được trọng số âm và phát hiện chu trình âm khi dist[i][i] < 0.
 */

const long long INF = 1e18;

void floyd_warshall(int n, vector<vector<long long>> &dist, vector<vector<int>> &next_node) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && dist[i][j] < INF) {
                next_node[i][j] = j;
            } else {
                next_node[i][j] = -1;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_node[i][j] = next_node[i][k];
                    }
                }
            }
        }
    }
}

// Truy vết đường đi từ u đến v
vector<int> reconstruct_path(int u, int v, const vector<vector<int>> &next_node) {
    if (next_node[u][v] == -1) return {};
    vector<int> path = {u};
    while (u != v) {
        u = next_node[u][v];
        path.push_back(u);
    }
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    vector<vector<int>> next_node(n + 1, vector<int>(n + 1, -1));
    floyd_warshall(n, dist, next_node);

    // Kiểm tra chu trình âm
    bool has_negative_cycle = false;
    for (int i = 1; i <= n; ++i) {
        if (dist[i][i] < 0) {
            has_negative_cycle = true;
            break;
        }
    }

    if (has_negative_cycle) {
        cout << "Do thi chua chu trinh am!\n";
    } else {
        cout << "Ma tran khoang cach giua moi cap dinh:\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
