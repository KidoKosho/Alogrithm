#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Z (Z-Algorithm)
 * Độ phức tạp: O(N) với N là độ dài chuỗi.
 * Ý nghĩa:
 *  - Mảng z[i] lưu độ dài tiền tố chung dài nhất giữa s[0..n-1] và chuỗi con bắt đầu từ i là s[i..n-1].
 *  - Ứng dụng: So khớp xâu mẫu (chuỗi ghép `p + '$' + t`), tìm chu kỳ của xâu, tìm tiền tố đối xứng,...
 */

vector<int> z_function(const string &s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// So khớp chuỗi mẫu p trong văn bản t dùng Z-Algorithm
vector<int> z_search(const string &t, const string &p) {
    string combined = p + "$" + t;
    vector<int> z = z_function(combined);
    vector<int> occurrences;

    int p_len = p.length();
    for (int i = p_len + 1; i < (int)combined.length(); ++i) {
        if (z[i] == p_len) {
            occurrences.push_back(i - p_len - 1);
        }
    }
    return occurrences;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    if (!(cin >> text >> pattern)) return 0;

    vector<int> matches = z_search(text, pattern);

    cout << "So lan xuat hien (Z-Algorithm): " << matches.size() << "\n";
    cout << "Cac vi tri xuat hien (0-indexed): ";
    for (int idx : matches) cout << idx << " ";
    cout << "\n";

    return 0;
}
