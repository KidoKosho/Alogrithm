#include <iostream>
#include <vector>
using namespace std;

void DFS_Recursive(const vector<vector<int>>& graph, int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";  // In ra đỉnh đã duyệt

    // Duyệt các đỉnh kề của đỉnh hiện tại
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS_Recursive(graph, neighbor, visited);
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

    vector<bool> visited(graph.size(), false);
    cout << "DFS (Recursive): ";
    DFS_Recursive(graph, 1, visited);  // Bắt đầu từ đỉnh 1
    return 0;
}
