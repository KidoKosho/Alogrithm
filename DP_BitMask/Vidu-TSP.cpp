#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

/**
 * Bài toán người du lịch (Traveling Salesperson Problem - TSP)
 * Phương pháp: Quy hoạch động trạng thái Bitmask (DP Bitmask)
 * Độ phức tạp: O(N^2 * 2^N)
 * Không gian: O(N * 2^N)
 * Áp dụng cho: N <= 20
 */

int DP_Bitmask(const vector<vector<int>> &a, const int n, const int start) {
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1 << start][start] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int u = 0; u < n; ++u) {
                    if (mask & (1 << u)) {
                        dp[mask][u] = min(dp[mask][u], dp[mask ^ (1 << u)][i] + a[i][u]);
                    }
                }
            }
        }
    }

    int res = INF;
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            res = min(res, dp[(1 << n) - 1][i] + a[i][start]);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> a(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    cout << "Chi phi hanh trinh nho nhat: " << DP_Bitmask(a, n, 0) << "\n";
    return 0;
}
