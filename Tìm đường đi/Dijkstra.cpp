#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); 

void Dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF);  
    distance[start] = 0;  

   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  

    while (!pq.empty()) {
        int current_dist = pq.top().first;  
        int u = pq.top().second;          
        pq.pop();

        if (current_dist > distance[u]) {
            continue;
        }

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;         
            int weight = neighbor.second;  
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;  
                pq.push({distance[v], v}); 
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF) {
            cout << "Khoảng cách từ " << start << " đến " << i << " là vô cực." << endl;
        } else {
            cout << "Khoảng cách từ " << start << " đến " << i << " là " << distance[i] << endl;
        }
    }
}

int main() {
    int n = 6;  
    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});
    graph[4].push_back({5, 1});

    Dijkstra(graph, 0); 

    return 0;
}
