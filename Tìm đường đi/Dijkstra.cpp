#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // Giá trị vô cực

// Đồ thị được biểu diễn dưới dạng danh sách kề
void Dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF);  // Khởi tạo khoảng cách ban đầu là vô cực
    distance[start] = 0;  // Khoảng cách từ đỉnh bắt đầu tới chính nó là 0

    // Hàng đợi ưu tiên để lưu các đỉnh cần duyệt (first: khoảng cách, second: đỉnh)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // Đưa đỉnh bắt đầu vào hàng đợi với khoảng cách 0

    while (!pq.empty()) {
        int current_dist = pq.top().first;  // Khoảng cách hiện tại
        int u = pq.top().second;            // Đỉnh hiện tại
        pq.pop();

        // Nếu khoảng cách đã được tối ưu trước đó, bỏ qua
        if (current_dist > distance[u]) {
            continue;
        }

        // Duyệt các đỉnh kề của đỉnh hiện tại
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;         // Đỉnh kề
            int weight = neighbor.second;   // Trọng số của cạnh

            // Nếu tìm được đường đi ngắn hơn
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;  // Cập nhật khoảng cách
                pq.push({distance[v], v});  // Đưa đỉnh mới vào hàng đợi
            }
        }
    }

    // In kết quả khoảng cách từ đỉnh bắt đầu đến các đỉnh khác
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF) {
            cout << "Khoảng cách từ " << start << " đến " << i << " là vô cực." << endl;
        } else {
            cout << "Khoảng cách từ " << start << " đến " << i << " là " << distance[i] << endl;
        }
    }
}

int main() {
    int n = 6;  // Số đỉnh
    vector<vector<pair<int, int>>> graph(n);

    // Thêm các cạnh (u, v, w) với u là đỉnh, v là đỉnh kề, w là trọng số
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});
    graph[4].push_back({5, 1});

    Dijkstra(graph, 0);  // Gọi thuật toán Dijkstra bắt đầu từ đỉnh 0

    return 0;
}
