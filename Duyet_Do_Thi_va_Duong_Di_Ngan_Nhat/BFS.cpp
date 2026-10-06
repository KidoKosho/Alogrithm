#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Thuật toán BFS (Breadth-First Search) - Duyệt theo chiều rộng
 * Độ phức tạp: O(V + E)
 * Ứng dụng:
 *  - Tìm đường đi ngắn nhất trên đồ thị không trọng số (hoặc tất cả trọng số bằng nhau = 1).
 *  - Kiểm tra tính liên thông và đếm số thành phần liên thông.
 *  - Kiểm tra đồ thị 2 phía (Bipartite Graph).
 */

void BFS(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);  // Mảng đánh dấu đỉnh đã thăm
    queue<int> q;  // Hàng đợi các đỉnh cần duyệt

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";  // In ra đỉnh đã duyệt

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Đồ thị dạng danh sách kề
    vector<vector<int>> graph = {
        {},          // Đỉnh 0 không có cạnh
        {2, 3},      // Đỉnh 1 kề với 2, 3
        {1, 4, 5},   // Đỉnh 2 kề với 1, 4, 5
        {1},         // Đỉnh 3 kề với 1
        {2},         // Đỉnh 4 kề với 2
        {2}          // Đỉnh 5 kề với 2
    };

    cout << "BFS: ";
    BFS(graph, 1);  // Bắt đầu từ đỉnh 1
    cout << "\n";
    return 0;
}
