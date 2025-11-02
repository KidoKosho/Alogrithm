#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 1e9; // hoặc compress giá trị nếu cần

struct Node {
    int cnt;
    Node *left, *right;
    Node(int c=0, Node* l=nullptr, Node* r=nullptr)
        : cnt(c), left(l), right(r) {}
};

// ===== UPDATE =====
Node* update(Node* prev, int l, int r, int val) {
    if (val < l || val > r) return prev;
    if (l == r) return new Node(prev ? prev->cnt + 1 : 1);
    int mid = (l + r) / 2;
    Node* left = prev ? prev->left : nullptr;
    Node* right = prev ? prev->right : nullptr;
    if (val <= mid) left = update(left, l, mid, val);
    else right = update(right, mid+1, r, val);
    int sum = (left ? left->cnt : 0) + (right ? right->cnt : 0);
    return new Node(sum, left, right);
}

// ===== QUERY: ĐẾM SỐ PHẦN TỬ <= w =====
int query(Node* node, int l, int r, int ql, int qr) {
    if (!node || qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return node->cnt;
    int mid = (l + r) / 2;
    return query(node->left, l, mid, ql, qr)
         + query(node->right, mid+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Nén giá trị nếu cần
    vector<int> vals = a;
    sort(vals.begin()+1, vals.end());
    vals.erase(unique(vals.begin()+1, vals.end()), vals.end());
    auto getID = [&](int x) {
        return lower_bound(vals.begin()+1, vals.end(), x) - vals.begin();
    };
    int m = vals.size();

    // ===== Build PST =====
    vector<Node*> root(n+1, nullptr);
    for (int i = 1; i <= n; i++) {
        root[i] = update(root[i-1], 1, m, getID(a[i]));
    }

    // ===== Query =====
    while (q--) {
        int l, r, w;
        cin >> l >> r >> w;
        int id = upper_bound(vals.begin()+1, vals.end(), w) - vals.begin() - 1;
        if (id < 1) cout << 0 << "\n";
        else cout << query(root[r], 1, m, 1, id)
                     - query(root[l-1], 1, m, 1, id) << "\n";
    }
}
