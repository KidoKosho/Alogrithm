#include <bits/stdc++.h>
using namespace std;

/**
 * THUẬT TOÁN TARJAN (1 LẦN DFS)
 * Độ phức tạp: O(V + E)
 * 
 * Thuật toán Tarjan dùng 2 mảng chính:
 *  - num[u]: Thứ tự thăm đỉnh u trong quá trình DFS (discovery time).
 *  - low[u]: Thứ tự thăm nhỏ nhất của các đỉnh mà từ cây con gốc u có thể đi tới qua tối đa 1 cạnh ngược (back-edge).
 * 
 * Tác dụng vượt trội:
 *  1. Tìm Thành phần liên thông mạnh (Strongly Connected Components - SCC) trên Đồ thị có hướng trong đúng 1 lần DFS.
 *  2. Tìm Điểm khớp (Cut Vertices / Articulation Points) và Cạnh cầu (Bridges) trên Đồ thị vô hướng.
 */

// ============================================================================
// PHẦN 1: TÌM THÀNH PHẦN LIÊN THÔNG MẠNH (SCC) TRÊN ĐỒ THỊ CÓ HƯỚNG
// ============================================================================
namespace TarjanSCC {
    const int N = 100010;
    vector<int> adj[N];
    int num[N], low[N], timer = 0;
    stack<int> st;
    bool in_stack[N];
    int scc_count = 0;
    vector<vector<int>> all_scc;

    void dfs_scc(int u) {
        num[u] = low[u] = ++timer;
        st.push(u);
        in_stack[u] = true;

        for (int v : adj[u]) {
            if (!num[v]) {
                dfs_scc(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = min(low[u], num[v]);
            }
        }

        // Nếu u là gốc của một SCC
        if (low[u] == num[u]) {
            scc_count++;
            vector<int> current_scc;
            while (true) {
                int v = st.top();
                st.pop();
                in_stack[v] = false;
                current_scc.push_back(v);
                if (u == v) break;
            }
            all_scc.push_back(current_scc);
        }
    }

    void solve(int n) {
        for (int i = 1; i <= n; ++i) {
            if (!num[i]) dfs_scc(i);
        }
        cout << "[SCC] So luong thanh phan lien thong manh: " << scc_count << "\n";
        for (int i = 0; i < (int)all_scc.size(); ++i) {
            cout << "  SCC #" << i + 1 << ": ";
            for (int node : all_scc[i]) cout << node << " ";
            cout << "\n";
        }
    }
}

// ============================================================================
// PHẦN 2: TÌM KHỚP VÀ CẦU TRÊN ĐỒ THỊ VÔ HƯỚNG
// ============================================================================
namespace TarjanBridgeArticulation {
    const int N = 100010;
    vector<int> adj[N];
    int num[N], low[N], timer = 0;
    bool is_cut[N];
    vector<pair<int, int>> bridges;

    void dfs_cut_bridge(int u, int parent = -1) {
        num[u] = low[u] = ++timer;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (num[v]) {
                low[u] = min(low[u], num[v]);
            } else {
                children++;
                dfs_cut_bridge(v, u);
                low[u] = min(low[u], low[v]);

                // 1. Điều kiện Cầu (Bridge): low[v] > num[u]
                if (low[v] > num[u]) {
                    bridges.push_back({u, v});
                }

                // 2. Điều kiện Khớp (Cut Vertex) cho đỉnh không phải gốc DFS
                if (parent != -1 && low[v] >= num[u]) {
                    is_cut[u] = true;
                }
            }
        }

        // Điều kiện Khớp cho đỉnh gốc DFS: có từ 2 con trở lên trong cây DFS
        if (parent == -1 && children >= 2) {
            is_cut[u] = true;
        }
    }

    void solve(int n) {
        for (int i = 1; i <= n; ++i) {
            if (!num[i]) dfs_cut_bridge(i);
        }

        vector<int> cut_nodes;
        for (int i = 1; i <= n; ++i) {
            if (is_cut[i]) cut_nodes.push_back(i);
        }

        cout << "[Khop va Cau]\n";
        cout << "  So dinh khop (Cut Vertices): " << cut_nodes.size() << " -> ";
        for (int u : cut_nodes) cout << u << " ";
        cout << "\n";

        cout << "  So canh cau (Bridges): " << bridges.size() << "\n";
        for (auto [u, v] : bridges) {
            cout << "    " << u << " - " << v << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Nhập đồ thị có hướng (dùng cho SCC)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        TarjanSCC::adj[u].push_back(v);
        // Nếu là đồ thị vô hướng thì bỏ comment dòng dưới cho Khớp/Cầu:
        // TarjanBridgeArticulation::adj[u].push_back(v);
        // TarjanBridgeArticulation::adj[v].push_back(u);
    }

    TarjanSCC::solve(n);
    // TarjanBridgeArticulation::solve(n);

    return 0;
}
