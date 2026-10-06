# Quy Hoạch Động (Dp_bitmask)

Thư mục này chứa các kỹ thuật và bài toán mẫu về Quy hoạch động nâng cao (Dynamic Programming), đặc biệt là Quy hoạch động trạng thái Bitmask (DP Bitmask).

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Dạng bài toán / Thuật toán | Độ phức tạp thời gian | Bộ nhớ | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`Vidu-DPBitmask.cpp`** | DP Bitmask (Bài toán QBSELECT) | O(N * 4^K) với K = 4 | O(N * 2^K) | Quy hoạch động trên ma trận với số hàng nhỏ (K <= 4), nén trạng thái các ô được chọn của mỗi cột vào một số nguyên (Mask). |
| **`Vidu-TSP.cpp`** | Bài toán Người du lịch (TSP) | O(N^2 * 2^N) | O(N * 2^N) | Tìm chu trình ngắn nhất đi qua tất cả các đỉnh đúng 1 lần và quay về điểm xuất phát khi N <= 20. Trạng thái `dp[mask][u]` lưu chi phí nhỏ nhất khi đã thăm tập đỉnh `mask` và hiện đang dừng ở đỉnh `u`. |
