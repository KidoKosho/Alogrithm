#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int LOG = 20;
int parent[100005][20];
int dp[N] ={0};
int hight[N] = {0};
vector<vector<pair<int,int>>> adj;
void dfs(int u,int par){
    for(auto v:adj[u]){
        if(v.first!=par){
            parent[v.first][0]=u;
            hight[v.first]=hight[u]+1;
            dp[v.first]=dp[u]+v.second;
            dfs(v.first,u);
        }
    }
}
int lca(int u,int v){
    if(hight[u]<hight[v]) return lca(v,u);
    for(int i =LOG-1;i>=0;--i){
        if(hight[parent[u][i]]>=hight[v]){
            u=parent[u][i];
        }
    }
    if(u==v) return u;
    for(int i =LOG-1;i>=0;--i){
        if(parent[u][i]!=parent[v][i]){
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    return parent[u][0];
}
int main(){
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; 
    cin >> n >> q;
    adj.resize(n + 1);
    for(int i =1 ;i<n;++i){
        int u,v,k; cin>>u>>v>>k;
        adj[u].push_back({v,k});
        adj[v].push_back({u,k});
    }
    dfs(1,-1);
    for(int j =1;j<LOG;++j){
        for(int i =1;i<=n;++i){
            if(parent[i][j-1]!=0)
                parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
    while(q--){
        int u,v; cin>>u>>v;
        int w=lca(u,v);
        cout<<dp[u]+dp[v]-2*dp[w]<<"\n";
    }
} 