# Cây và Cây Khung (Cay_va_Cay_Khung)

Thư mục này tập trung vào cấu trúc dữ liệu trên Cây (Tree), quản lý tập hợp rời nhau (DSU), các thuật toán tìm Cây khung nhỏ nhất (MST) và kỹ thuật phân rã cây nâng cao.

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Tên thuật toán | Độ phức tạp thời gian | Độ phức tạp không gian | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`DSU.cpp`** | Disjoint Set Union | O(alpha(N)) ~ O(1) | O(N) | Quản lý các tập hợp rời nhau, hỗ trợ gộp tập hợp (`unite`) và kiểm tra cùng tập (`find`). Dùng trong Kruskal, đồ thị động. |
| **`Kruskal.cpp`** | Cây khung nhỏ nhất Kruskal | O(E log E) | O(V + E) | Tìm MST bằng cách sắp xếp cạnh và dùng DSU. Phù hợp nhất khi đồ thị thưa (E ~ V). |
| **`Prim.cpp`** | Cây khung nhỏ nhất Prim | O(E log V) | O(V + E) | Tìm MST bằng Priority Queue phát triển dần từ 1 đỉnh. Phù hợp khi đồ thị dày (E ~ V^2). |
| **`LCA_O(log(n)).cpp`** | Tổ tiên chung gần nhất (Binary Lifting) | Tiền xử lý: O(N log N)<br>Truy vấn: O(log N) | O(N log N) | Tìm tổ tiên chung gần nhất của 2 đỉnh trên cây, tính khoảng cách giữa 2 đỉnh trên cây dist(u, v) = depth(u) + depth(v) - 2 * depth(LCA(u, v)). |
| **`HLD.cpp`** | Heavy-Light Decomposition | Phân rã: O(N)<br>Truy vấn: O(log^2 N) | O(N) | Phân rã cây thành các chuỗi nặng-nhẹ để chuyển bài toán truy vấn đường đi trên cây về các thao tác đoạn trên Segment Tree. |
