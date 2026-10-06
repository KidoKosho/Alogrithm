# Thuật Toán Xử Lý Chuỗi (Xu_Ly_Chuoi)

Thư mục này bao gồm các thuật toán xử lý chuỗi (String Algorithms) quan trọng và thường xuyên xuất hiện nhất trong các kỳ thi Lập trình thi đấu (CP) và tin học trẻ.

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Tên thuật toán | Độ phức tạp thời gian | Bộ nhớ | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`KMP.cpp`** | Knuth-Morris-Pratt | $\mathcal{O}(N + M)$ | $\mathcal{O}(M)$ | Tìm kiếm tất cả các vị trí xuất hiện của chuỗi mẫu $P$ trong văn bản $T$ bằng mảng tiền tố LPS $\pi$. Không quay lui con trỏ văn bản. |
| **`Z_Algorithm.cpp`** | Z-Algorithm | $\mathcal{O}(N + M)$ | $\mathcal{O}(N + M)$ | Tính mảng độ dài tiền tố chung dài nhất giữa chuỗi và các hậu tố của nó. So khớp xâu, tìm chu kỳ xâu, nén xâu. |
| **`Trie.cpp`** | Cây tiền tố (Prefix Tree & XOR Trie) | Mỗi thao tác: $\mathcal{O}(\text{length})$ hoặc $\mathcal{O}(31)$ | $\mathcal{O}(\text{Tổng độ dài ký tự})$ | Tra cứu từ điển, đếm số từ có tiền tố chung, tìm cặp 2 số có XOR lớn nhất $\mathcal{O}(31 \cdot N)$. |
| **`HashString.cpp`** | Rolling Hash kép (Double Hash) | Tiền xử lý: $\mathcal{O}(N)$<br>So sánh 2 xâu con: $\mathcal{O}(1)$ | $\mathcal{O}(N)$ | So sánh 2 xâu con bất kỳ trong $\mathcal{O}(1)$. Kết hợp 2 modulo lớn ($10^9+7, 10^9+9$) để triệt tiêu hoàn toàn va chạm Hash. |
