#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Hierholzer - Tìm Chu trình Euler / Đường đi Euler
 * Độ phức tạp: O(V + E)
 * 
 * Điều kiện tồn tại:
 * 1. Đồ thị vô hướng liên thông (bỏ qua đỉnh cô lập):
 *    - Chu trình Euler: Mọi đỉnh đều có bậc chẵn.
 *    - Đường đi Euler: Có đúng 0 hoặc 2 đỉnh bậc lẻ.
 * 2. Đồ thị có hướng liên thông yếu (bỏ qua đỉnh cô lập):
 *    - Chu trình Euler: Mọi đỉnh có bán bậc vào = bán bậc ra (in_deg == out_deg).
 *    - Đường đi Euler: Đúng 1 đỉnh có out - in = 1 (start), đúng 1 đỉnh có in - out = 1 (end), các đỉnh còn lại in == out.
 */

struct EdgeUndirected {
    int to;
    int id; // Đánh số cạnh để đánh dấu khi duyệt qua
};

// Tìm chu trình / đường đi Euler trên ĐỒ THỊ VÔ HƯỚNG
vector<int> euler_undirected(int n, int m, vector<vector<EdgeUndirected>> &adj, int start_node) {
    vector<bool> used_edge(m, false);
    vector<int> path;
    stack<int> st;
    st.push(start_node);

    while (!st.empty()) {
        int u = st.top();
        while (!adj[u].empty() && used_edge[adj[u].back().id]) {
            adj[u].pop_back();
        }

        if (!adj[u].empty()) {
            auto edge = adj[u].back();
            adj[u].pop_back();
            used_edge[edge.id] = true;
            st.push(edge.to);
        } else {
            path.push_back(u);
            st.pop();
        }
    }
    reverse(path.begin(), path.end());
    // Kiểm tra xem đã đi qua đủ m cạnh chưa (đường đi Euler có m + 1 đỉnh)
    if ((int)path.size() != m + 1) return {};
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<EdgeUndirected>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        deg[u]++;
        deg[v]++;
    }

    int odd_count = 0;
    int start_node = 1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] % 2 != 0) {
            odd_count++;
            start_node = i;
        }
    }

    if (odd_count != 0 && odd_count != 2) {
        cout << "Khong ton tai Chu trinh hoac Duong di Euler!\n";
        return 0;
    }

    if (odd_count == 0) {
        for (int i = 1; i <= n; ++i) {
            if (deg[i] > 0) {
                start_node = i;
                break;
            }
        }
    }

    vector<int> path = euler_undirected(n, m, adj, start_node);

    if (path.empty()) {
        cout << "Do thi khong lien thong cac canh!\n";
    } else {
        cout << (odd_count == 0 ? "Chu trinh Euler:\n" : "Duong di Euler:\n");
        for (int u : path) cout << u << " ";
        cout << "\n";
    }

    return 0;
}
