#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);  // Mảng đánh dấu đỉnh đã thăm
    queue<int> q;  // Hàng đợi các đỉnh cần duyệt

    // Đánh dấu đỉnh bắt đầu và thêm nó vào hàng đợi
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";  // In ra đỉnh đã duyệt

        // Duyệt các đỉnh kề của đỉnh hiện tại
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
    return 0;
}
