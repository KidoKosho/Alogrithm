# Luồng Trên Đồ Thị và Cặp Ghép (Luong_va_Cap_Ghep)

Thư mục này chứa các thuật toán giải quyết các bài toán Luồng mạng (Network Flow) và Cặp ghép cực đại (Graph Matching).

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Tên thuật toán | Độ phức tạp thời gian | Độ phức tạp không gian | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`Dinic.cpp`** | Thuật toán Dinic (Max Flow) | O(V^2 * E)<br>Mạng đơn vị: O(E * sqrt(V)) | O(V + E) | **Chuẩn mực tìm Luồng cực đại trong CP**: Chạy cực nhanh nhờ kết hợp đồ thị phân tầng BFS và luồng cản DFS. Giải quyết tốt V <= 5000, E <= 30000. |
| **`MaxFlow_Edmonds_Karp.cpp`** | Thuật toán Edmonds-Karp (Max Flow) | O(V * E^2) | O(V^2) | Tìm luồng cực đại bằng BFS đường tăng luồng. Dễ hiểu, dễ cài đặt khi số đỉnh và cạnh nhỏ (V <= 200). |
| **`MinCostMaxFlow.cpp`** | Luồng cực đại Chi phí cực tiểu (MCMF) | O(F * E * V) | O(V + E) | Tìm luồng cực đại đồng thời tối thiểu hóa tổng chi phí vận chuyển. Dùng trong bài toán gán việc, phân phối tài nguyên. |
| **`BipartiteMatching.cpp`** | Cặp ghép cực đại đồ thị 2 phía | **Hopcroft-Karp**: O(E * sqrt(V))<br>**Kuhn (DFS)**: O(V * E) | O(V + E) | Tìm số lượng cặp ghép nhiều nhất giữa 2 tập đỉnh rời rạc (Ví dụ: Thợ - Công việc, Sinh viên - Trường học). |
