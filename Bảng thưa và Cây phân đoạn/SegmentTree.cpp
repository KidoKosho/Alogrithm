#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void buildSegmentTree(const vector<int> &a,vector<int> &p,int l,int r,int pos){
    if(l==r){
        p[pos]= a[l];
        return;
    }
    int mid = (l+r)/2;
    buildSegmentTree(a,p,l,mid,pos*2+1);
    buildSegmentTree(a,p,mid+1,r,pos*2+2);
    p[pos] = max(p[pos*2+1],p[pos*2 + 2]);
}
vector<int> SegmentTree(const vector<int> a,int n){
    vector<int> p(4*n);
    buildSegmentTree(a,p,0,n-1,0);
    return p;
}
int FindSegmentTree(const vector<int> &p,int l1,int r1,int l,int r,int pos){
    if(l <= l1 && r1 <= r) return p[pos];
    if(l>r1||l1 > r) return INT_MIN;
    int mid = (l+r)/2;
    return max(FindSegmentTree(p,l1,mid,l,r,2*pos+1),FindSegmentTree(p,mid+1,r1,l,r,2*pos+2));
}
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> p = SegmentTree(a,n);
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << FindSegmentTree(p,0,n-1,l-1,r-1,0) << endl;
    }
}