#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Mã băm chuỗi (Polynomial Rolling Hash / Double Hash)
 * Phương pháp:
 *  - Dùng 2 cặp cơ số và modulo khác nhau (Double Hash) để triệt tiêu tỷ lệ va chạm (Collision probability < 10^-18).
 *  - So sánh 2 chuỗi con bất kỳ trong O(1) thời gian sau O(N) tiền xử lý.
 * Ứng dụng:
 *  - So khớp xâu mẫu, tìm xâu con chung dài nhất, đếm số xâu con phân biệt, tìm chuỗi đối xứng (Palindromes).
 */

struct StringHash {
    int n;
    string s;
    const long long BASE1 = 311, MOD1 = 1e9 + 7;
    const long long BASE2 = 331, MOD2 = 1e9 + 9;

    vector<long long> hash1, hash2;
    vector<long long> pow1, pow2;

    StringHash(const string &str) : s(str) {
        n = s.length();
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
            hash1[i] = (hash1[i - 1] * BASE1 + s[i - 1]) % MOD1;
            hash2[i] = (hash2[i - 1] * BASE2 + s[i - 1]) % MOD2;
        }
    }

    // Lấy giá trị hash kép của đoạn con s[l..r] (1-indexed)
    pair<long long, long long> get_hash(int l, int r) {
        long long h1 = (hash1[r] - hash1[l - 1] * pow1[r - l + 1]) % MOD1;
        if (h1 < 0) h1 += MOD1;

        long long h2 = (hash2[r] - hash2[l - 1] * pow2[r - l + 1]) % MOD2;
        if (h2 < 0) h2 += MOD2;

        return {h1, h2};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text = "abacaba";
    StringHash h(text);

    // So sánh chuỗi con "aba" ở vị trí [1..3] và [5..7]
    auto sub1 = h.get_hash(1, 3);
    auto sub2 = h.get_hash(5, 7);

    if (sub1 == sub2) {
        cout << "Hai xau con bang nhau! (aba == aba)\n";
    } else {
        cout << "Hai xau con khac nhau!\n";
    }

    return 0;
}
