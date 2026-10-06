#include <bits/stdc++.h>
using namespace std;

/**
 * Cấu trúc Fenwick Tree (Binary Indexed Tree - BIT) cơ bản
 * Độ phức tạp: 
 *  - Cập nhật điểm (Point Update): O(log N)
 *  - Truy vấn tổng tiền tố (Prefix Sum Query): O(log N)
 *  - Bộ nhớ: O(N) (Cực kỳ nhỏ gọn, chỉ 1 mảng kích thước N)
 * Ứng dụng:
 *  - Tính tổng đoạn, đếm số cặp nghịch thế (Inversions).
 *  - Cài đặt nhanh và tiết kiệm bộ nhớ hơn nhiều so với Segment Tree.
 */

struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    // Cộng thêm val vào phần tử tại vị trí idx (1-indexed)
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Tính tổng các phần tử từ 1 đến idx
    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Tính tổng trên đoạn [l, r]
    long long query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    FenwickTree bit(n);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        bit.update(i, x);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx;
            long long val;
            cin >> idx >> val;
            bit.update(idx, val); // Cộng thêm val vào vị trí idx
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.query_range(l, r) << "\n";
        }
    }

    return 0;
}
