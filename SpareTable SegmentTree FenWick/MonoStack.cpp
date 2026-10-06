#include <bits/stdc++.h>
using namespace std;

/**
 * Ngăn xếp đơn điệu (Monotonic Stack)
 * Độ phức tạp: O(N) thời gian và O(N) bộ nhớ.
 * Ứng dụng:
 *  - Tìm phần tử đầu tiên lớn hơn / nhỏ hơn ở bên trái / bên phải (Next Greater Element).
 *  - Tìm hình chữ nhật lớn nhất trong biểu đồ cột (Largest Rectangle in Histogram).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n), res(n, -1);
    for (int &x : a) cin >> x;

    stack<int> st;

    // Tìm phần tử gần nhất bên trái lớn hơn a[i]
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (!st.empty()) res[i] = a[st.top()];
        st.push(i);
    }

    cout << "Phan tu gan nhat ben trai lon hon:\n";
    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
