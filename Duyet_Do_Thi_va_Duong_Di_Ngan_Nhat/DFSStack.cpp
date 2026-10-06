#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Thuật toán DFS bằng Stack (Duyệt theo chiều sâu không đệ quy)
 * Độ phức tạp: O(V + E)
 * Ứng dụng:
 *  - Tránh nguy cơ tràn bộ nhớ ngăn xếp (Stack Overflow) khi cây đệ quy có độ sâu lớn (V >= 10^5).
 */

void DFS_Stack(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);  
    stack<int> s; 
    s.push(start);  

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";  
            visited[vertex] = true;

            for (int neighbor : graph[vertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {},          
        {2, 3},      
        {1, 4, 5},   
        {1},         
        {2},         
        {2}
    };

    cout << "DFS (Stack): ";
    DFS_Stack(graph, 1); 
    cout << "\n";
    return 0;
}
