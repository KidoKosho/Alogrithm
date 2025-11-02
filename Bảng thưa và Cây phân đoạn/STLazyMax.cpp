#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTreeMax {
    int n;
    vector<ll> st, lazy;
    SegmentTreeMax(int n=0){init(n);}
    void init(int n_){n=n_; st.assign(4*n,0); lazy.assign(4*n,0);}
    void build(vector<ll> &a,int id,int l,int r){
        if(l==r){st[id]=a[l];return;}
        int mid=(l+r)/2;
        build(a,id*2,l,mid);
        build(a,id*2+1,mid+1,r);
        st[id]=max(st[id*2],st[id*2+1]);
    }
    void build(vector<ll> &a){build(a,1,1,n);}
    void down(int id){
        if(lazy[id]==0) return;
        ll v=lazy[id];
        st[id*2]+=v; st[id*2+1]+=v;
        lazy[id*2]+=v; lazy[id*2+1]+=v;
        lazy[id]=0;
    }
    void update(int id,int l,int r,int u,int v,ll val){
        if(v<l||r<u) return;
        if(u<=l&&r<=v){st[id]+=val; lazy[id]+=val; return;}
        down(id);
        int mid=(l+r)/2;
        update(id*2,l,mid,u,v,val);
        update(id*2+1,mid+1,r,u,v,val);
        st[id]=max(st[id*2],st[id*2+1]);
    }
    ll query(int id,int l,int r,int u,int v){
        if(v<l||r<u) return LLONG_MIN;
        if(u<=l&&r<=v) return st[id];
        down(id);
        int mid=(l+r)/2;
        return max(query(id*2,l,mid,u,v), query(id*2+1,mid+1,r,u,v));
    }
    void update(int l,int r,ll val){update(1,1,n,l,r,val);}
    ll query(int l,int r){return query(1,1,n,l,r);}
};
