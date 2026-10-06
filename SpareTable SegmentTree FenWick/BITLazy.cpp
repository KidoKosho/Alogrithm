#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Fenwick Tree (Binary Indexed Tree) hỗ trợ Cập nhật đoạn & Truy vấn đoạn (Range Update - Range Query)
 * Độ phức tạp: O(log N) cho cả update và query
 */

struct BIT {
    int n;
    vector<ll> f;
    BIT(int n=0){ init(n); }
    void init(int n_){
        n = n_;
        f.assign(n+1, 0);
    }
    void add(int i, ll delta){
        for(; i <= n; i += i & -i) f[i] += delta;
    }
    ll sum(int i){
        ll s = 0;
        for(; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    int find_kth(int k) {
        int idx = 0;
        int mask = 1;
        while(mask <= n) mask <<= 1;
        mask >>= 1;
        for(; mask; mask >>= 1) {
            int next = idx + mask;
            if(next <= n && f[next] < k) {
                idx = next;
                k -= f[next];
            }
        }
        return idx + 1;
    }
};

struct BIT_RangeUpdate_RangeQuery {
    int n;
    BIT B1, B2;
    BIT_RangeUpdate_RangeQuery(int n=0){ init(n); }
    void init(int n_){
        n = n_;
        B1.init(n);
        B2.init(n);
    }
    void add_range(int l, int r, ll v){
        if(l > r) return;
        B1.add(l, v);
        B1.add(r+1, -v);
        B2.add(l, v*(l-1));
        B2.add(r+1, -v*r);
    }
    ll prefix_sum(int x){
        if(x <= 0) return 0;
        return B1.sum(x) * x - B2.sum(x);
    }
    ll range_sum(int l, int r){
        if(l > r) return 0;
        return prefix_sum(r) - prefix_sum(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    BIT_RangeUpdate_RangeQuery bit(n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            bit.add_range(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.range_sum(l, r) << "\n";
        }
    }
    return 0;
}
