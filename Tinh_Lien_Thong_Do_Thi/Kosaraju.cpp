#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Kosaraju - Tìm thành phần liên thông mạnh (SCC)
 * Độ phức tạp: O(V + E)
 * Nguyên lý: 2 lần duyệt DFS
 *  - DFS 1 trên đồ thị gốc G: Lưu thứ tự các đỉnh theo thời gian hoàn thành vào stack.
 *  - DFS 2 trên đồ thị đảo G_transpose: Lấy lần lượt các đỉnh từ stack ra duyệt để tìm từng SCC.
 * So sánh với Tarjan:
 *  - Kosaraju cần 2 lần DFS và phải dựng thêm đồ thị đảo, tốn thêm bộ nhớ hơn Tarjan.
 *  - Tarjan chỉ cần đúng 1 lần DFS duy nhất.
 */

const int N = 100010;
vector<int> adj[N], adj_rev[N];
vector<bool> visited;
vector<int> order;
vector<int> component;
vector<vector<int>> all_scc;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adj_rev[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u); // Đồ thị đảo chiều
    }

    // Bước 1: DFS trên đồ thị gốc
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Bước 2: DFS trên đồ thị đảo theo thứ tự đảo ngược của stack/order
    visited.assign(n + 1, false);
    reverse(order.begin(), order.end());

    for (int u : order) {
        if (!visited[u]) {
            component.clear();
            dfs2(u);
            all_scc.push_back(component);
        }
    }

    cout << "So luong SCC (Kosaraju): " << all_scc.size() << "\n";
    for (int i = 0; i < (int)all_scc.size(); ++i) {
        cout << "SCC #" << i + 1 << ": ";
        for (int x : all_scc[i]) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
