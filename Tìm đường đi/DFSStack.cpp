#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
    };

    cout << "DFS (Stack): ";
    DFS_Stack(graph, 1); 
    return 0;
}
