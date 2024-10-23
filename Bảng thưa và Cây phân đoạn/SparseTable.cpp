#include<iostream>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    int a[n];
    for(auto &x:a) cin >> x;
    int b[n+5][17];
    for(int i=0;i<n;++i) b[i][0] = a[i];
    for(int j =1;(1<<j)<n;++j){
        for(int i=0;i+(1<<j) <=n;++i){
            b[i][j] = max(b[i][j-1],b[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        --l;--r;
        int k = __lg(r-l+1);
        cout << max(b[l][k],b[r-(1<<k)+1][k]) << endl;
    }
}