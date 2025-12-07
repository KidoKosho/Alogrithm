#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// --- Global Variables and Constants ---
const int MAXN = 200005; // Maximum size for N, Q, U
int N, Q, U;
int block_size;
vector<int> A; // The initial array data
int count_arr[MAXN * 2]; // Frequency array (adjust size based on max value)
int current_distinct = 0; // Current answer for the distinct count

// --- Query and Update Structures ---
struct Query {
    int L, R, T, id; // L, R are 0-indexed range, T is time (number of updates before this query)
};

struct Update {
    int P, old_val, new_val; // P is 0-indexed position
};

// --- Core Helper Functions (O(1) in this case) ---

// Add element at index 'idx' to the current window
void add(int idx) {
    int val = A[idx];
    // If we're seeing this element for the first time, increment distinct count
    if (count_arr[val] == 0) {
        current_distinct++;
    }
    count_arr[val]++;
}

// Remove element at index 'idx' from the current window
void remove(int idx) {
    int val = A[idx];
    count_arr[val]--;
    // If we removed the last instance, decrement distinct count
    if (count_arr[val] == 0) {
        current_distinct--;
    }
}

// --- Update Functions ---

// Apply the update at index T
void apply_update(int T, int current_L, int current_R, const vector<Update>& updates) {
    const Update& u = updates[T];
    int P = u.P;
    
    // Check if the updated position is inside the current range [L, R]
    if (P >= current_L && P <= current_R) {
        // 1. Undo the contribution of the old value
        remove(P);
        
        // 2. Apply the new value to the array A
        A[P] = u.new_val;
        
        // 3. Add the contribution of the new value
        add(P);
    } else {
        // If outside the range, just update the value in A
        A[P] = u.new_val;
    }
}

// Undo the update at index T (revert to old_val)
void undo_update(int T, int current_L, int current_R, const vector<Update>& updates) {
    const Update& u = updates[T];
    int P = u.P;
    
    // Check if the position is inside the current range [L, R]
    if (P >= current_L && P <= current_R) {
        // 1. Undo the contribution of the current (new) value
        remove(P);
        
        // 2. Revert to the old value in array A
        A[P] = u.old_val;
        
        // 3. Add the contribution of the old value
        add(P);
    } else {
        // If outside the range, just revert the value in A
        A[P] = u.old_val;
    }
}

// --- Custom Sorting Function (Mo's with Updates) ---

bool compareQueries(const Query& a, const Query& b) {
    int block_L_a = a.L / block_size;
    int block_L_b = b.L / block_size;
    
    if (block_L_a != block_L_b) {
        return block_L_a < block_L_b;
    }

    int block_R_a = a.R / block_size;
    int block_R_b = b.R / block_size;
    
    if (block_R_a != block_R_b) {
        return block_R_a < block_R_b;
    }

    // Tertiary key: Time (T)
    return a.T < b.T;
}

// --- Main Mo's Algorithm Logic ---
void solve() {
    // Read input (N, Q, U) and populate A, Queries, Updates here
    // ... (For this template, we skip input reading) ...

    // Set block size: N^(2/3) for optimal complexity
    block_size = max(1, (int)pow(N, 2.0/3.0)); 
    
    vector<Query> queries;
    vector<Update> updates;
    // Assume N=10, Q=5, U=5 for a dummy run:
    N = 10; Q = 5; U = 5;
    A = {1, 2, 1, 3, 4, 2, 5, 1, 3, 4}; // Initial array
    updates = {
        {1, 2, 9}, // Update 0: A[1] = 9 (old 2)
        {8, 3, 7}, // Update 1: A[8] = 7 (old 3)
        {0, 1, 6}, // Update 2: A[0] = 6 (old 1)
        {3, 3, 8}, // Update 3: A[3] = 8 (old 3)
        {5, 2, 1}  // Update 4: A[5] = 1 (old 2)
    };
    queries = {
        {0, 3, 0, 0}, // Q0: Range [0,3] before any update (A: 1,2,1,3) -> Distinct: 3
        {1, 5, 2, 1}, // Q1: Range [1,5] after Update 0 and 1 (A: 6,9,1,3,4,2) -> Distinct: 5
        {2, 6, 4, 2}, // Q2: Range [2,6] after all 4 updates (A: 6,9,1,8,4,1,5) -> Distinct: 5
        {0, 9, 3, 3}, // Q3: Range [0,9] after Update 0,1,2 (A: 6,9,1,8,4,2,5,1,7,4) -> Distinct: 7
        {5, 9, 1, 4}  // Q4: Range [5,9] after Update 0 (A: 1,2,1,3,4,2,5,1,7,4) -> Distinct: 4
    };

    // --- Main Logic ---
    vector<int> results(Q);

    // 1. Sort Queries
    sort(queries.begin(), queries.end(), compareQueries);

    // 2. Initialize Window Pointers
    int current_L = 0;
    int current_R = -1; 
    int current_T = 0; // The time dimension pointer

    // 3. Process Queries
    for (const auto& q : queries) {
        // A. Move T (Time Dimension)
        while (current_T < q.T) {
            apply_update(current_T, current_L, current_R, updates);
            current_T++;
        }
        while (current_T > q.T) {
            current_T--;
            undo_update(current_T, current_L, current_R, updates);
        }

        // B. Move L and R (Range Dimensions)
        // Ensure that T is correct BEFORE moving L and R
        while (current_L > q.L) add(--current_L);
        while (current_R < q.R) add(++current_R);
        while (current_L < q.L) remove(current_L++);
        while (current_R > q.R) remove(current_R--);

        // C. Record Answer
        results[q.id] = current_distinct;
    }

    // 4. Output Results
    cout << "--- Results ---" << endl;
    for (int i = 0; i < Q; ++i) {
        cout << "Query " << i << ": " << results[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}