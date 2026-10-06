# Cấu Trúc Dữ Liệu và Truy Vấn Đoạn (SpareTable SegmentTree FenWick)

Thư mục này tập hợp các cấu trúc dữ liệu nâng cao hỗ trợ các truy vấn trên đoạn (Range Queries), cập nhật đoạn (Range Updates) và xử lý offline.

---

## Bảng tra cứu các cấu trúc dữ liệu trong thư mục

| Tên file | Cấu trúc dữ liệu | Độ phức tạp thời gian | Bộ nhớ | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`Fenwick_BIT.cpp`** | Fenwick Tree (BIT) cơ bản | Cập nhật điểm: O(log N)<br>Truy vấn tiền tố: O(log N) | O(N) | Tính tổng tiền tố, đếm cặp nghịch thế. Cực kỳ ngắn gọn và nhẹ bộ nhớ. |
| **`BITLazy.cpp`** | Fenwick Tree Range Update Range Query | Cập nhật đoạn: O(log N)<br>Truy vấn đoạn: O(log N) | O(N) | Dùng 2 mảng BIT để cập nhật đoạn và tính tổng đoạn mà không cần đến Segment Tree. |
| **`SegmentTree.cpp`** | Segment Tree cơ bản | Cập nhật điểm: O(log N)<br>Truy vấn đoạn: O(log N) | O(4N) | Cây phân đoạn cơ bản cho Max/Min/Sum. Rất linh hoạt và đa năng. |
| **`SegmentTreelazy.cpp`** | Segment Tree với Lazy Propagation (Sum) | Cập nhật đoạn: O(log N)<br>Truy vấn đoạn: O(log N) | O(4N) | Cập nhật cộng đoạn [u, v] và tính tổng đoạn [u, v] bằng kỹ thuật trì hoãn (Lazy). |
| **`STLazyMax.cpp`** | Segment Tree với Lazy Propagation (Max) | Cập nhật đoạn: O(log N)<br>Truy vấn Max đoạn: O(log N) | O(4N) | Cập nhật cộng đoạn [u, v] và truy vấn giá trị lớn nhất (Range Maximum Query). |
| **`SparseTable.cpp`** | Bảng thưa (Sparse Table) | Tiền xử lý: O(N log N)<br>Truy vấn đoạn: O(1) | O(N log N) | Truy vấn Min/Max/GCD đoạn trong thời gian **O(1)** (mảng tĩnh không cập nhật). |
| **`PST.cpp`** | Persistent Segment Tree (Cây bất biến) | Mỗi lần cập nhật: O(log N)<br>Truy vấn lịch sử: O(log N) | O(N log N) | Lưu lại mọi phiên bản sau mỗi cập nhật. Tìm phần tử nhỏ thứ k (K-th smallest) trên đoạn [L, R], đếm số phần tử trong khoảng. |
| **`Mo_algorithm.cpp`** | Thuật toán Mo (Mo with Updates) | O(N^(5/3)) hoặc O(Q * sqrt(N)) | O(N + Q) | Xử lý các truy vấn đoạn offline thông qua kỹ thuật chia căn (Square Root Decomposition). |
| **`MonoStack.cpp`** | Ngăn xếp đơn điệu (Monotonic Stack) | O(N) | O(N) | Tìm phần tử gần nhất lớn hơn/nhỏ hơn, tìm hình chữ nhật lớn nhất trên biểu đồ cột. |
