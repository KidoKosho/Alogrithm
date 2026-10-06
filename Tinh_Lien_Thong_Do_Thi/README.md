# Tính Liên Thông Đồ Thị (Tinh_Lien_Thong_Do_Thi)

Thư mục này chứa các thuật toán phân tích cấu trúc liên thông nâng cao trên đồ thị: Thành phần liên thông mạnh (SCC), Điểm khớp (Articulation Points) và Cạnh cầu (Bridges).

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Tên thuật toán | Độ phức tạp thời gian | Độ phức tạp không gian | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`Tarjan.cpp`** | Thuật toán Tarjan (1 lần DFS) | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | **Cực kỳ tối ưu**: Chỉ cần đúng **1 lần DFS** duy nhất là tìm được tất cả các Thành phần liên thông mạnh (SCC) trên đồ thị có hướng, đồng thời tìm luôn được các Điểm khớp và Cạnh cầu trên đồ thị vô hướng thông qua 2 mảng `num` (thời điểm thăm) và `low` (thời điểm thăm nhỏ nhất quay về được). |
| **`Kosaraju.cpp`** | Thuật toán Kosaraju (2 lần DFS) | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | Tìm thành phần liên thông mạnh (SCC) trên đồ thị có hướng bằng 2 lần duyệt DFS kết hợp đồ thị đảo (Transpose Graph). Trực quan, dễ hiểu hơn nhưng tốn bộ nhớ và thời gian chạy hơn Tarjan. |

---

## So sánh Tarjan vs Kosaraju

| Tiêu chí | Thuật toán Tarjan | Thuật toán Kosaraju |
| :--- | :--- | :--- |
| **Số lần DFS** | **1 lần DFS duy nhất** (Rất tối ưu) | 2 lần DFS |
| **Bộ nhớ cần dùng** | Thấp (chỉ cần danh sách kề đồ thị gốc) | Cao hơn (cần lưu thêm đồ thị đảo $G^T$) |
| **Tính năng mở rộng** | Tìm luôn được **Khớp** (Cut Vertices) và **Cầu** (Bridges) | Chỉ tìm được SCC |
| **Độ phổ biến trong CP** | ⭐️⭐️⭐️⭐️⭐️ (Khuyên dùng số 1) | ⭐️⭐️⭐️ (Dễ hiểu về mặt lý thuyết) |
