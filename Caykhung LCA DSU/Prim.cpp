#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;

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

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue; 
        inMST[u] = true;
        totalWeight += weight;

        for (auto &[w, v] : adj[u]) {
            if (!inMST[v]) pq.push({w, v});
        }
    }
    cout << totalWeight << endl;
    return 0;
}
