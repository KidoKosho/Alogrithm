#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    // add v to [l,r]
    void add_range(int l, int r, ll v){
        if(l > r) return;
        B1.add(l, v);
        B1.add(r+1, -v);
        B2.add(l, v*(l-1));
        B2.add(r+1, -v*r);
    }
    // prefix sum of [1..x]
    ll prefix_sum(int x){
        if(x <= 0) return 0;
        return B1.sum(x) * x - B2.sum(x);
    }
    // sum of [l..r]
    ll range_sum(int l, int r){
        if(l > r) return 0;
        return prefix_sum(r) - prefix_sum(l-1);
    }
};
