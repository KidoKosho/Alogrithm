# Duyệt Đồ Thị Và Đường Đi Ngắn Nhất (Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat)

Thư mục này chứa các thuật toán cơ bản và nâng cao để duyệt đồ thị, sắp xếp topo, tìm chu trình/đường đi Euler và giải quyết bài toán tìm đường đi ngắn nhất.

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Tên thuật toán | Độ phức tạp thời gian | Độ phức tạp không gian | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`BFS.cpp`** | Breadth-First Search | $\mathcal{O}(V + E)$ | $\mathcal{O}(V)$ | Duyệt theo từng lớp. Tìm đường đi ngắn nhất trên đồ thị không trọng số hoặc trọng số đều bằng 1. Kiểm tra tính liên thông, kiểm tra đồ thị 2 phía. |
| **`DFSdequy.cpp`** | DFS Đệ quy | $\mathcal{O}(V + E)$ | $\mathcal{O}(V)$ | Duyệt theo chiều sâu bằng đệ quy. Ngắn gọn, trực quan, dùng để đếm thành phần liên thông, duyệt cây. |
| **`DFSStack.cpp`** | DFS Dùng Stack | $\mathcal{O}(V + E)$ | $\mathcal{O}(V)$ | Duyệt theo chiều sâu dùng Stack tường minh. Tránh lỗi tràn ngăn xếp (Stack Overflow) khi độ sâu đồ thị lớn ($V \ge 10^5$). |
| **`Dijkstra.cpp`** | Dijkstra (Min-Heap) | $\mathcal{O}((V + E) \log V)$ | $\mathcal{O}(V + E)$ | Tìm đường đi ngắn nhất từ 1 đỉnh nguồn đến tất cả các đỉnh khác khi **trọng số cạnh không âm ($\ge 0$)**. |
| **`Bellman_Ford.cpp`** | Bellman-Ford | $\mathcal{O}(V \cdot E)$ | $\mathcal{O}(V + E)$ | Tìm đường đi ngắn nhất nguồn đơn khi đồ thị có **trọng số âm**. Phát hiện và báo **chu trình âm**. |
| **`SPFA.cpp`** | Shortest Path Faster Algorithm | Trung bình $\mathcal{O}(k \cdot E)$<br>Xấu nhất $\mathcal{O}(V \cdot E)$ | $\mathcal{O}(V + E)$ | Bản cải tiến của Bellman-Ford dùng Queue. Chạy cực nhanh trên đồ thị thực tế, xử lý được trọng số âm và chu trình âm. Được dùng trong thuật toán Luồng chi phí cực tiểu (MCMF). |
| **`Floyd_Warshall.cpp`** | Floyd-Warshall | $\mathcal{O}(V^3)$ | $\mathcal{O}(V^2)$ | Tìm đường đi ngắn nhất giữa **mọi cặp đỉnh** ($u, v$). Dễ cài đặt nhất (3 vòng for lồng nhau), phù hợp với $V \le 400 - 500$. |
| **`Euler_Hierholzer.cpp`** | Hierholzer's Algorithm | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | Tìm **Chu trình Euler** (đi qua mọi cạnh đúng 1 lần rồi về đỉnh xuất phát) hoặc **Đường đi Euler** cho đồ thị vô hướng và có hướng. |
| **`topo.cpp`** | Sắp xếp Tô-pô | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | Tìm thứ tự tuyến tính các đỉnh trên đồ thị có hướng không chu trình (DAG). |

---

## Hướng dẫn lựa chọn thuật toán Đường đi ngắn nhất

- **Không trọng số / Trọng số = 1:** Dùng `BFS.cpp` ($\mathcal{O}(V + E)$).
- **Trọng số $\ge 0$ (Nguồn đơn):** Dùng `Dijkstra.cpp` ($\mathcal{O}((V + E) \log V)$).
- **Có trọng số âm (Nguồn đơn):** Dùng `SPFA.cpp` (chạy thực tế rất nhanh) hoặc `Bellman_Ford.cpp` ($\mathcal{O}(VE)$).
- **Tìm đường đi giữa mọi cặp đỉnh:** Dùng `Floyd_Warshall.cpp` ($\mathcal{O}(V^3)$ khi $V \le 400$).
