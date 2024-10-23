//https://oj.vnoi.info/problem/qbselect (Bai tap vidu DP BitMask)

#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
int dp[10002][16]={0};
int a[4][10001];
int oke[16]={1,1,1,0,1,1,0,0,1,1,1,0,0,0,0,0};
int Getvalue(int i,int k){
    int value  = 0;
    for(int j=0;j<4;++j){
        if((k >> j)&1){//neu bit day la 1 thi co nghia la lay o day
            value += a[j][i];
        }
    }
    return value;
}
int main(){
    int n;cin >> n;
    for(int i =0;i<4;++i){
        for(int j=0;j<n;++j){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<16;++j){
            int T = Getvalue(i-1,j);
            if(oke[j]){
                for(int z = 0;z<16;z++){
                    if(oke[z]&&(z&j)==0){
                        dp[i][j] = max(dp[i][j],dp[i-1][z]+T);
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i =0;i<16;i++){
        if(oke[i]) res = max(res,dp[n][i]);
    }
    cout << res;
}