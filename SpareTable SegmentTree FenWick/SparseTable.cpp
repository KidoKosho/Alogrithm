#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Bảng thưa (Sparse Table) - Range Minimum/Maximum Query (RMQ)
 * Độ phức tạp:
 *  - Tiền xử lý: O(N log N)
 *  - Truy vấn đoạn: O(1)
 * Điều kiện áp dụng: Phép toán có tính chất lũy đẳng (Idempotent) như min, max, gcd.
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int max_log = __lg(n) + 1;
    vector<vector<int>> b(n, vector<int>(max_log));

    for(int i = 0; i < n; ++i) b[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; ++j){
        for(int i = 0; i + (1 << j) <= n; ++i){
            b[i][j] = max(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        --l; --r; // Chuyển về 0-indexed
        int k = __lg(r - l + 1);
        cout << max(b[l][k], b[r - (1 << k) + 1][k]) << "\n";
    }
    return 0;
}
