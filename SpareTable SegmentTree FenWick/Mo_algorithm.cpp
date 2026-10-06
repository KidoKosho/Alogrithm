#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/**
 * Thuật toán Mo (Mo's Algorithm) với Cập nhật (Mo with Updates - 3D Mo)
 * Độ phức tạp: O(N^(5/3)) hoặc O(Q * sqrt(N)) với Mo tĩnh cơ bản
 * Ứng dụng:
 *  - Xử lý các truy vấn đoạn offline có thể thêm/bớt phần tử ở 2 đầu trong O(1).
 *  - Đếm số lượng phần tử phân biệt trên đoạn [L, R].
 */

const int MAXN = 200005;
int N, Q, U;
int block_size;
vector<int> A;
int count_arr[MAXN * 2];
int current_distinct = 0;

struct Query {
    int L, R, T, id;
};

struct Update {
    int P, old_val, new_val;
};

void add(int idx) {
    int val = A[idx];
    if (count_arr[val] == 0) current_distinct++;
    count_arr[val]++;
}

void remove(int idx) {
    int val = A[idx];
    count_arr[val]--;
    if (count_arr[val] == 0) current_distinct--;
}

void apply_update(int T, int current_L, int current_R, const vector<Update>& updates) {
    const Update& u = updates[T];
    int P = u.P;
    if (P >= current_L && P <= current_R) {
        remove(P);
        A[P] = u.new_val;
        add(P);
    } else {
        A[P] = u.new_val;
    }
}

void undo_update(int T, int current_L, int current_R, const vector<Update>& updates) {
    const Update& u = updates[T];
    int P = u.P;
    if (P >= current_L && P <= current_R) {
        remove(P);
        A[P] = u.old_val;
        add(P);
    } else {
        A[P] = u.old_val;
    }
}

bool compareQueries(const Query& a, const Query& b) {
    int block_L_a = a.L / block_size;
    int block_L_b = b.L / block_size;
    if (block_L_a != block_L_b) return block_L_a < block_L_b;

    int block_R_a = a.R / block_size;
    int block_R_b = b.R / block_size;
    if (block_R_a != block_R_b) return block_R_a < block_R_b;

    return a.T < b.T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    N = 10; Q = 5; U = 5;
    block_size = max(1, (int)pow(N, 2.0/3.0));
    A = {1, 2, 1, 3, 4, 2, 5, 1, 3, 4};
    vector<Update> updates = {
        {1, 2, 9},
        {8, 3, 7},
        {0, 1, 6},
        {3, 3, 8},
        {5, 2, 1}
    };
    vector<Query> queries = {
        {0, 3, 0, 0},
        {1, 5, 2, 1},
        {2, 6, 4, 2},
        {0, 9, 3, 3},
        {5, 9, 1, 4}
    };

    sort(queries.begin(), queries.end(), compareQueries);

    vector<int> results(Q);
    int current_L = 0, current_R = -1, current_T = 0;

    for (const auto& q : queries) {
        while (current_T < q.T) {
            apply_update(current_T, current_L, current_R, updates);
            current_T++;
        }
        while (current_T > q.T) {
            current_T--;
            undo_update(current_T, current_L, current_R, updates);
        }

        while (current_L > q.L) add(--current_L);
        while (current_R < q.R) add(++current_R);
        while (current_L < q.L) remove(current_L++);
        while (current_R > q.R) remove(current_R--);

        results[q.id] = current_distinct;
    }

    for (int i = 0; i < Q; ++i) {
        cout << "Truy van " << i << ": " << results[i] << "\n";
    }
    return 0;
}
