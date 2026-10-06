# Thuật Toán Xử Lý Chuỗi (Xu_Ly_Chuoi)

Thư mục này bao gồm các thuật toán xử lý chuỗi (String Algorithms) quan trọng và thường xuyên xuất hiện nhất trong các kỳ thi Lập trình thi đấu (CP) và tin học trẻ.

---

## Bảng tra cứu các thuật toán trong thư mục

| Tên file | Tên thuật toán | Độ phức tạp thời gian | Bộ nhớ | Tác dụng & Khi nào nên sử dụng |
| :--- | :--- | :--- | :--- | :--- |
| **`KMP.cpp`** | Knuth-Morris-Pratt | O(N + M) | O(M) | Tìm kiếm tất cả các vị trí xuất hiện của chuỗi mẫu P trong văn bản T bằng mảng tiền tố LPS pi. Không quay lui con trỏ văn bản. |
| **`Z_Algorithm.cpp`** | Z-Algorithm | O(N + M) | O(N + M) | Tính mảng độ dài tiền tố chung dài nhất giữa chuỗi và các hậu tố của nó. So khớp xâu, tìm chu kỳ xâu, nén xâu. |
| **`Trie.cpp`** | Cây tiền tố (Prefix Tree & XOR Trie) | Mỗi thao tác: O(length) hoặc O(31) | O(Alphabet * N) | Tra cứu từ điển, đếm số từ có tiền tố chung, tìm cặp 2 số có XOR lớn nhất O(31 * N). |
| **`HashString.cpp`** | Rolling Hash kép (Double Hash) | Tiền xử lý: O(N)<br>So sánh 2 xâu con: O(1) | O(N) | So sánh 2 xâu con bất kỳ trong O(1). Kết hợp 2 modulo lớn (10^9+7, 10^9+9) để triệt tiêu hoàn toàn va chạm Hash. |
