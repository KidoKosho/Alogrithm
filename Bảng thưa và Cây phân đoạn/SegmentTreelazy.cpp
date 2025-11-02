#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> st, lazy;  // st = segment tree, lazy = mảng trì hoãn

    SegmentTree(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(vector<ll> &a, int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void build(vector<ll> &a) { build(a, 1, 1, n); }

    void down(int id, int l, int r) {
        if (lazy[id] == 0) return;
        int mid = (l + r) / 2;
        ll val = lazy[id];

        st[id * 2] += val * (mid - l + 1);
        st[id * 2 + 1] += val * (r - mid);

        lazy[id * 2] += val;
        lazy[id * 2 + 1] += val;

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, ll val) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            st[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    ll get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[id];
        down(id, l, r);
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }

    // wrapper functions
    void update(int l, int r, ll val) { update(1, 1, n, l, r, val); }
    ll query(int l, int r) { return get(1, 1, n, l, r); }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 8;
    vector<ll> a = {0, 1, 2, 3, 4, 5, 6, 7, 8}; // 1-indexed
    SegmentTree seg(n);
    seg.build(a);

    cout << seg.query(2, 5) << "\n"; // sum(2..5) = 2+3+4+5=14

    seg.update(3, 6, 10);            // cộng 10 vào đoạn [3..6]
    cout << seg.query(2, 5) << "\n"; // 2+(3+10)+(4+10)+(5+10)=44

    cout << seg.query(1, 8) << "\n"; // tổng toàn bộ
}
