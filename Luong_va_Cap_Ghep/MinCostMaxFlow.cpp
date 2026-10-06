#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Luồng cực đại Chi phí cực tiểu (Min-Cost Max-Flow - MCMF)
 * Phương pháp: Successive Shortest Path kết hợp SPFA tìm đường tăng luồng chi phí nhỏ nhất.
 * Độ phức tạp: O(F * E * V) với F là tổng lượng luồng cực đại.
 * Ứng dụng:
 *  - Phân bổ tài nguyên tối ưu với chi phí vận chuyển nhỏ nhất.
 *  - Bài toán gán việc với chi phí nhỏ nhất (Assignment Problem).
 */

const long long INF = 1e18;

struct Edge {
    int to;
    long long cap;
    long long flow;
    long long cost;
    int rev;
};

struct MinCostMaxFlow {
    int n, s, t;
    vector<vector<Edge>> adj;

    MinCostMaxFlow(int n, int s, int t) : n(n), s(s), t(t), adj(n + 1) {}

    void add_edge(int from, int to, long long cap, long long cost) {
        adj[from].push_back({to, cap, 0, cost, (int)adj[to].size()});
        adj[to].push_back({from, 0, 0, -cost, (int)adj[from].size() - 1});
    }

    bool spfa(vector<long long> &dist, vector<int> &parent_node, vector<int> &parent_edge) {
        dist.assign(n + 1, INF);
        parent_node.assign(n + 1, -1);
        parent_edge.assign(n + 1, -1);
        vector<bool> in_queue(n + 1, false);
        queue<int> q;

        dist[s] = 0;
        q.push(s);
        in_queue[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;

            for (int i = 0; i < (int)adj[u].size(); ++i) {
                const auto &e = adj[u][i];
                if (e.cap - e.flow > 0 && dist[u] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[u] + e.cost;
                    parent_node[e.to] = u;
                    parent_edge[e.to] = i;

                    if (!in_queue[e.to]) {
                        q.push(e.to);
                        in_queue[e.to] = true;
                    }
                }
            }
        }
        return dist[t] < INF;
    }

    pair<long long, long long> get_mcmf() {
        long long max_flow = 0;
        long long min_cost = 0;
        vector<long long> dist;
        vector<int> parent_node, parent_edge;

        while (spfa(dist, parent_node, parent_edge)) {
            long long push = INF;
            for (int cur = t; cur != s; cur = parent_node[cur]) {
                int p = parent_node[cur];
                int idx = parent_edge[cur];
                push = min(push, adj[p][idx].cap - adj[p][idx].flow);
            }

            for (int cur = t; cur != s; cur = parent_node[cur]) {
                int p = parent_node[cur];
                int idx = parent_edge[cur];
                adj[p][idx].flow += push;
                adj[cur][adj[p][idx].rev].flow -= push;
                min_cost += push * adj[p][idx].cost;
            }

            max_flow += push;
        }

        return {max_flow, min_cost};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) return 0;

    MinCostMaxFlow mcmf(n, s, t);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long cap, cost;
        cin >> u >> v >> cap >> cost;
        mcmf.add_edge(u, v, cap, cost);
    }

    auto [flow, cost] = mcmf.get_mcmf();
    cout << "Luong cuc dai: " << flow << "\n";
    cout << "Chi phi cuc tieu: " << cost << "\n";

    return 0;
}
