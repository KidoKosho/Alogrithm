#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán KMP (Knuth-Morris-Pratt)
 * Độ phức tạp: O(N + M) với N là độ dài văn bản T, M là độ dài mẫu P.
 * Phương pháp:
 *  - Tiền xử lý mảng tiền tố pi (LPS - Longest Proper Prefix which is also Suffix).
 *  - So khớp chuỗi mẫu P trong chuỗi văn bản T mà không bao giờ quay lui con trỏ trên T.
 */

// Hàm tính mảng tiền tố pi (LPS) của chuỗi pattern
vector<int> compute_pi(const string &p) {
    int m = p.length();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

// Tìm tất cả các vị trí xuất hiện của mẫu p trong văn bản t (0-indexed)
vector<int> kmp_search(const string &t, const string &p) {
    vector<int> occurrences;
    int n = t.length();
    int m = p.length();
    if (m == 0 || n < m) return occurrences;

    vector<int> pi = compute_pi(p);
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }
        if (t[i] == p[j]) {
            j++;
        }
        if (j == m) {
            occurrences.push_back(i - m + 1);
            j = pi[j - 1]; // Tiếp tục tìm kiếm các vị trí tiếp theo
        }
    }

    return occurrences;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    if (!(cin >> text >> pattern)) return 0;

    vector<int> matches = kmp_search(text, pattern);

    cout << "So lan xuat hien: " << matches.size() << "\n";
    cout << "Cac vi tri xuat hien (0-indexed): ";
    for (int idx : matches) cout << idx << " ";
    cout << "\n";

    return 0;
}
