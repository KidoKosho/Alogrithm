#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS_Stack(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);  // Mảng đánh dấu đỉnh đã thăm
    stack<int> s;  // Ngăn xếp các đỉnh cần duyệt

    s.push(start);  // Đưa đỉnh bắt đầu vào ngăn xếp

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";  // In ra đỉnh đã duyệt
            visited[vertex] = true;

            // Duyệt các đỉnh kề của đỉnh hiện tại, thêm vào ngăn xếp
            for (int neighbor : graph[vertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
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

    cout << "DFS (Stack): ";
    DFS_Stack(graph, 1);  // Bắt đầu từ đỉnh 1
    return 0;
}
