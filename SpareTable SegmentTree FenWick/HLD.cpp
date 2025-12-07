#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, q;
vector<int> adj[N];
int Sz[N], Parent[N], Depth[N];

int CurChain = 0, CurPos = 0;
int ChainHead[N], ChainID[N], Pos[N], Arr[N];

long long seg[4*N], val[N];

void build(int node, int l, int r) {
    if(l == r) {
        seg[node] = val[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    seg[node] = seg[2*node] + seg[2*node+1];
}

void update(int node, int l, int r, int idx, int v) {
    if(l == r) {
        seg[node] = v;
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid) update(2*node,l,mid,idx,v);
    else update(2*node+1,mid+1,r,idx,v);
    seg[node] = seg[2*node] + seg[2*node+1];
}

long long query(int node, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return seg[node];
    int mid = (l+r)/2;
    return query(2*node,l,mid,ql,qr) + query(2*node+1,mid+1,r,ql,qr);
}

int dfs(int u, int p) {
    Sz[u] = 1;
    Parent[u] = p;
    Depth[u] = (p == -1 ? 0 : Depth[p] + 1);
    for(int v: adj[u]) {
        if(v == p) continue;
        Sz[u] += dfs(v, u);
    }
    return Sz[u];
}
int lca(int u, int v) {
    while(ChainID[u] != ChainID[v]) {
        if(Depth[ChainHead[ChainID[u]]] < Depth[ChainHead[ChainID[v]]])
            swap(u,v);
        u = Parent[ChainHead[ChainID[u]]];
    }
    return Depth[u] < Depth[v] ? u : v;
}
// HLD
void Hld(int s, int p = -1) {
    if(ChainHead[CurChain] == 0) ChainHead[CurChain] = s;
    ChainID[s] = CurChain;
    Pos[s] = CurPos;
    Arr[CurPos] = s;
    val[CurPos] = 0; // giá trị node (có thể thay bằng edge weight)
    CurPos++;

    int nxt = 0;
    for(int u: adj[s]) {
        if(u != p) {
            if(nxt == 0 || Sz[u] > Sz[nxt]) nxt = u;
        }
    }
    if(nxt) Hld(nxt, s);
    for(int u: adj[s]) {
        if(u != p && u != nxt) {
            CurChain++;
            Hld(u, s);
        }
    }
}

// Query sum từ u → v
long long query_up(int u, int v) { // v là ancestor
    long long res = 0;
    while(ChainID[u] != ChainID[v]) {
        res += query(1,0,n-1,Pos[ChainHead[ChainID[u]]],Pos[u]);
        u = Parent[ChainHead[ChainID[u]]];
    }
    res += query(1,0,n-1,Pos[v],Pos[u]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1;i<n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);
    Hld(1,-1);
    build(1,0,n-1);

    while(q--) {
        string type;
        cin >> type;
        if(type == "update") {
            int u, val; cin >> u >> val;
            update(1,0,n-1,Pos[u],val);
        } else if(type == "query") {
            int u,v; cin >> u >> v;
            if(Depth[u] < Depth[v]) swap(u,v);
            cout << query_up(u,v) << "\n";
        }
    }
    return 0;
}
