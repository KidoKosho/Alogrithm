#include<iostream>
#include<vector>
const int INF = 1e9;
using namespace std;
int DP_Bitmask(const vector<vector<int>> &a,const int n,const int start){
	vector <vector<int>> dp((int)(1<<n),vector<int>(n,INF));
	dp[1<<start][start] = 0;
	for(int mask = 1 ; mask < (1<<n);++mask){
		for(int i=0;i<n;++i){// check xem diem i co trong day khong
			if(mask&(1<<i)){
				for( int u = 0;u<n;++u){// check xem diem u co trong day khong
					if(!(mask&(1<<u))){
						dp[mask|(1<<u)][u] = min(dp[mask|(1<<u)][u],dp[mask][i]+a[i][u]);
					}
				}
			}
		}
	}
	int res =INF;
    for(int i=0;i<n;++i){//(1<<n)-1  là dãy từ 111111...11 hay la cac dinh deu duoc di roi
    	if(i!=start)res = min(dp[(1<<n)-1][i]+a[i][start],res); ////di het r quay ve vi tri start;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,INF));
    for(int i =0;i<n;++i){
        for(int j =0;j<n;++j){
            cin >> a[i][j];
        }
    }
    cout << DP_Bitmask(a,n,0);
}