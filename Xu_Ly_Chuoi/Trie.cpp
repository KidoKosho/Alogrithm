#include <bits/stdc++.h>
using namespace std;

/**
 * CÂY TIỀN TỐ (TRIE)
 * Cung cấp 2 dạng bài kinh điển trong Lập trình thi đấu:
 * 1. String Trie: Quản lý tập từ điển, tra cứu từ, đếm số từ có tiền tố chung.
 * 2. Bitwise XOR Trie: Tìm cặp 2 số có XOR lớn nhất trong mảng O(30 * N).
 */

// ============================================================================
// 1. STRING TRIE (CÂY TIỀN TỐ CHO XÂU KÝ TỰ)
// ============================================================================
struct StringTrie {
    struct Node {
        Node* child[26];
        int count_words; // Số từ kết thúc tại node này
        int count_prefixes; // Số từ đi qua node này (có tiền tố tại node này)

        Node() {
            fill(child, child + 26, nullptr);
            count_words = 0;
            count_prefixes = 0;
        }
    };

    Node* root;
    StringTrie() { root = new Node(); }

    void insert(const string &s) {
        Node* cur = root;
        for (char c : s) {
            int id = c - 'a';
            if (!cur->child[id]) cur->child[id] = new Node();
            cur = cur->child[id];
            cur->count_prefixes++;
        }
        cur->count_words++;
    }

    bool search(const string &s) {
        Node* cur = root;
        for (char c : s) {
            int id = c - 'a';
            if (!cur->child[id]) return false;
            cur = cur->child[id];
        }
        return cur->count_words > 0;
    }

    int count_prefix(const string &prefix) {
        Node* cur = root;
        for (char c : prefix) {
            int id = c - 'a';
            if (!cur->child[id]) return 0;
            cur = cur->child[id];
        }
        return cur->count_prefixes;
    }
};

// ============================================================================
// 2. BITWISE XOR TRIE (TÌM XOR LỚN NHẤT)
// ============================================================================
struct XorTrie {
    struct Node {
        Node* child[2];
        Node() { child[0] = child[1] = nullptr; }
    };

    Node* root;
    XorTrie() { root = new Node(); }

    void insert(int x) {
        Node* cur = root;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit]) cur->child[bit] = new Node();
            cur = cur->child[bit];
        }
    }

    // Tìm giá trị max XOR với x trong tập các số đã thêm vào Trie
    int query_max_xor(int x) {
        Node* cur = root;
        int max_val = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            int opposite_bit = 1 - bit;
            if (cur->child[opposite_bit]) {
                max_val |= (1 << i);
                cur = cur->child[opposite_bit];
            } else {
                cur = cur->child[bit];
            }
        }
        return max_val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Thử nghiệm String Trie
    StringTrie trie;
    trie.insert("algorithm");
    trie.insert("algos");
    trie.insert("all");

    cout << "Kiem tra 'algos': " << (trie.search("algos") ? "Co trong Trie\n" : "Khong co\n");
    cout << "So tu co tien to 'algo': " << trie.count_prefix("algo") << "\n";

    // Thử nghiệm XOR Trie
    XorTrie xor_trie;
    vector<int> a = {3, 10, 5, 25, 2, 8};
    for (int x : a) xor_trie.insert(x);

    int max_xor_pair = 0;
    for (int x : a) {
        max_xor_pair = max(max_xor_pair, xor_trie.query_max_xor(x));
    }
    cout << "Cap so co XOR lon nhat: " << max_xor_pair << "\n";

    return 0;
}
