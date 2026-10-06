# 📚 THƯ VIỆN THUẬT TOÁN VÀ CẤU TRÚC DỮ LIỆU C++ (CP CHEATSHEET)

Kho lưu trữ toàn diện các thuật toán và cấu trúc dữ liệu kinh điển chuẩn thi đấu **Lập trình thi đấu (Competitive Programming - VNOI, Codeforces, ICPC, HSG)** và **Phỏng vấn Kỹ thuật**.

---

## 📑 MỤC LỤC NHANH

1. [Duyệt Đồ Thị & Đường Đi Ngắn Nhất](#1-duyệt-đồ-thị--đường-đi-ngắn-nhất)
2. [Cây & Cây Khung Nhỏ Nhất (MST)](#2-cây--cây-khung-nhỏ-nhất-mst)
3. [Tính Liên Thông Đồ Thị (SCC, Khớp, Cầu)](#3-tính-liên-thông-đồ-thị)
4. [Luồng Trên Đồ Thị & Cặp Ghép](#4-luồng-trên-đồ-thị--cặp-ghép)
5. [Cấu Trúc Dữ Liệu & Truy Vấn Đoạn](#5-cấu-trúc-dữ-liệu--truy-vấn-đoạn)
6. [Thuật Toán Xử Lý Chuỗi (String)](#6-thuật-toán-xử-lý-chuỗi)
7. [Quy Hoạch Động (Dynamic Programming)](#7-quy-hoạch-động)
8. [Hình Học Tính Toán (Geometry)](#8-hình-học-tính-toán)

---

## 1. Duyệt Đồ Thị & Đường Đi Ngắn Nhất

📂 **Thư mục:** [`./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/README.md)

| File mã nguồn | Thuật toán | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`BFS.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/BFS.cpp) | Breadth-First Search | $\mathcal{O}(V + E)$ | $\mathcal{O}(V)$ | • Đồ thị không trọng số hoặc trọng số các cạnh đều bằng nhau (trọng số 1).<br>• Tìm số bước di chuyển ít nhất trên mê cung/bàn cờ.<br>• Kiểm tra đồ thị 2 phía (Bipartite coloring). |
| [`DFSdequy.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/DFSdequy.cpp) | DFS (Đệ quy) | $\mathcal{O}(V + E)$ | $\mathcal{O}(V)$ | • Duyệt theo nhánh sâu, đếm số thành phần liên thông.<br>• Kiểm tra tính liên thông, duyệt cây con.<br>• Code ngắn gọn, dễ triển khai. |
| [`DFSStack.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/DFSStack.cpp) | DFS (Stack tường minh) | $\mathcal{O}(V + E)$ | $\mathcal{O}(V)$ | • Dùng khi đồ thị có độ sâu rất lớn ($V \ge 10^5$) để **chống tràn bộ nhớ ngăn xếp (Stack Overflow)**. |
| [`Dijkstra.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/Dijkstra.cpp) | Dijkstra (Min-Heap) | $\mathcal{O}((V + E) \log V)$ | $\mathcal{O}(V + E)$ | • Tìm đường đi ngắn nhất từ **1 đỉnh nguồn** khi **mọi trọng số cạnh không âm ($\ge 0$)**.<br>• Dạng bài: Tìm chi phí/thời gian ít nhất trên bản đồ giao thông. |
| [`Bellman_Ford.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/Bellman_Ford.cpp) | Bellman-Ford | $\mathcal{O}(V \cdot E)$ | $\mathcal{O}(V + E)$ | • Đồ thị có **cạnh trọng số âm**.<br>• Cần **phát hiện chu trình âm** có thể tới được từ đỉnh xuất phát. |
| [`SPFA.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/SPFA.cpp) | Shortest Path Faster Algorithm | Trung bình $\mathcal{O}(kE)$ ($k \approx 2-3$)<br>Xấu nhất $\mathcal{O}(VE)$ | $\mathcal{O}(V + E)$ | • Bản cải tiến cực mạnh bằng Queue của Bellman-Ford.<br>• Xử lý trọng số âm và chu trình âm trên đồ thị thực tế chạy cực nhanh.<br>• Dùng làm hàm tìm đường tăng luồng trong Min Cost Max Flow. |
| [`Floyd_Warshall.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/Floyd_Warshall.cpp) | Floyd-Warshall | $\mathcal{O}(V^3)$ | $\mathcal{O}(V^2)$ | • Tìm đường đi ngắn nhất giữa **mọi cặp đỉnh $(u, v)$** khi $V \le 400 - 500$.<br>• Cực kỳ ngắn gọn (3 vòng `for`), tìm bao đóng bắc cầu (Transitive Closure). |
| [`Euler_Hierholzer.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/Euler_Hierholzer.cpp) | Hierholzer's Algorithm | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | • Bài toán người đưa thư, vẽ hình một nét.<br>• Tìm chu trình/đường đi đi qua **mỗi cạnh đúng 1 lần**. |
| [`topo.cpp`](./Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/topo.cpp) | Sắp xếp Tô-pô | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | • Tìm thứ tự thực hiện các công việc có điều kiện tiên quyết trên đồ thị có hướng không chu trình (DAG). |

---

## 2. Cây & Cây Khung Nhỏ Nhất (MST)

📂 **Thư mục:** [`./Cay_va_Cay_Khung`](./Cay_va_Cay_Khung/README.md)

| File mã nguồn | Thuật toán / Cấu trúc | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`DSU.cpp`](./Cay_va_Cay_Khung/DSU.cpp) | Disjoint Set Union | $\mathcal{O}(\alpha(N)) \approx \mathcal{O}(1)$ | $\mathcal{O}(N)$ | • Quản lý các tập hợp rời nhau, kiểm tra liên thông động khi liên tục nối cạnh.<br>• Dùng trong Kruskal, thuật toán tìm chu trình đồ thị vô hướng. |
| [`Kruskal.cpp`](./Cay_va_Cay_Khung/Kruskal.cpp) | Cây khung nhỏ nhất Kruskal | $\mathcal{O}(E \log E)$ | $\mathcal{O}(V + E)$ | • Tìm tập $N-1$ cạnh nối toàn bộ đồ thị với tổng trọng số nhỏ nhất.<br>• Tối ưu khi **đồ thị thưa** ($E \approx V$). Rất dễ cài đặt cùng DSU. |
| [`Prim.cpp`](./Cay_va_Cay_Khung/Prim.cpp) | Cây khung nhỏ nhất Prim | $\mathcal{O}(E \log V)$ | $\mathcal{O}(V + E)$ | • Tìm MST bằng Priority Queue phát triển dần từ 1 đỉnh.<br>• Tối ưu hơn khi **đồ thị dày** ($E \approx V^2$). |
| [`LCA_O(log(n)).cpp`](./Cay_va_Cay_Khung/LCA_O(log(n)).cpp) | LCA (Binary Lifting) | Tiền xử lý $\mathcal{O}(N \log N)$<br>Mỗi truy vấn $\mathcal{O}(\log N)$ | $\mathcal{O}(N \log N)$ | • Tìm tổ tiên chung gần nhất của 2 đỉnh trên cây.<br>• Tính khoảng cách giữa 2 đỉnh trên cây: $dist(u, v) = h(u) + h(v) - 2 \cdot h(LCA(u, v))$.<br>• Tìm cạnh có trọng số lớn nhất/nhỏ nhất trên đường đi từ $u$ đến $v$. |
| [`HLD.cpp`](./Cay_va_Cay_Khung/HLD.cpp) | Heavy-Light Decomposition | Phân rã $\mathcal{O}(N)$<br>Truy vấn $\mathcal{O}(\log^2 N)$ | $\mathcal{O}(N)$ | • Cập nhật giá trị đỉnh/cạnh trên đường đi giữa $(u, v)$ trên cây.<br>• Truy vấn tổng/max/min trên đường đi $(u, v)$ kết hợp Segment Tree. |

---

## 3. Tính Liên Thông Đồ Thị

📂 **Thư mục:** [`./Tinh_Lien_Thong_Do_Thi`](./Tinh_Lien_Thong_Do_Thi/README.md)

| File mã nguồn | Thuật toán | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`Tarjan.cpp`](./Tinh_Lien_Thong_Do_Thi/Tarjan.cpp) | Thuật toán Tarjan (1 lần DFS) | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | • **Khuyên dùng số 1**: Chỉ đúng **1 lần DFS** là tìm được toàn bộ:<br>  1. Thành phần liên thông mạnh (SCC) $\rightarrow$ Nén đồ thị có hướng thành DAG (Condensation Graph).<br>  2. Điểm khớp (Cut Vertices) và Cạnh cầu (Bridges) trên đồ thị vô hướng (xác định các vị trí huyết mạch). |
| [`Kosaraju.cpp`](./Tinh_Lien_Thong_Do_Thi/Kosaraju.cpp) | Thuật toán Kosaraju (2 lần DFS) | $\mathcal{O}(V + E)$ | $\mathcal{O}(V + E)$ | • Tìm SCC bằng 2 lần duyệt DFS với đồ thị đảo chiều $G^T$. Dễ nhớ về mặt lý thuyết. |

---

## 4. Luồng Trên Đồ Thị & Cặp Ghép

📂 **Thư mục:** [`./Luong_va_Cap_Ghep`](./Luong_va_Cap_Ghep/README.md)

| File mã nguồn | Thuật toán | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`Dinic.cpp`](./Luong_va_Cap_Ghep/Dinic.cpp) | Thuật toán Dinic (Max Flow) | $\mathcal{O}(V^2 E)$<br>Mạng đơn vị: $\mathcal{O}(E \sqrt{V})$ | $\mathcal{O}(V + E)$ | • **Thuật toán chuẩn mực tìm Luồng cực đại trong CP**.<br>• Bài toán chia cắt nhỏ nhất (Min-Cut = Max-Flow).<br>• Phân chia tài nguyên, bài toán gán việc, che phủ đỉnh/tập độc lập. |
| [`MaxFlow_Edmonds_Karp.cpp`](./Luong_va_Cap_Ghep/MaxFlow_Edmonds_Karp.cpp) | Edmonds-Karp | $\mathcal{O}(V E^2)$ | $\mathcal{O}(V^2)$ | • Tìm luồng cực đại bằng BFS đường tăng luồng khi $V, E$ nhỏ ($V \le 200$). |
| [`MinCostMaxFlow.cpp`](./Luong_va_Cap_Ghep/MinCostMaxFlow.cpp) | Min Cost Max Flow (MCMF) | $\mathcal{O}(F \cdot E \cdot V)$ | $\mathcal{O}(V + E)$ | • Tìm luồng cực đại đồng thời **tối thiểu hóa tổng chi phí**.<br>• Bài toán vận tải hàng hóa tối ưu, gán $N$ thợ cho $M$ việc với chi phí nhỏ nhất. |
| [`BipartiteMatching.cpp`](./Luong_va_Cap_Ghep/BipartiteMatching.cpp) | Cặp ghép cực đại đồ thị 2 phía | **Hopcroft-Karp**: $\mathcal{O}(E \sqrt{V})$<br>**Kuhn (DFS)**: $\mathcal{O}(VE)$ | $\mathcal{O}(V + E)$ | • Ghép đôi tối đa giữa 2 tập đối tượng (Nam - Nữ, Công nhân - Máy móc).<br>• Dùng Hopcroft-Karp khi $N, M \le 10^5$; dùng Kuhn khi $N, M \le 2000$. |

---

## 5. Cấu Trúc Dữ Liệu & Truy Vấn Đoạn

📂 **Thư mục:** [`./Cau_Truc_Du_Lieu`](./Cau_Truc_Du_Lieu/README.md)

| File mã nguồn | Cấu trúc dữ liệu | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`Fenwick_BIT.cpp`](./Cau_Truc_Du_Lieu/Fenwick_BIT.cpp) | Fenwick Tree (BIT) cơ bản | Cập nhật điểm: $\mathcal{O}(\log N)$<br>Truy vấn tổng: $\mathcal{O}(\log N)$ | $\mathcal{O}(N)$ | • Tính tổng tiền tố, đếm số nghịch thế (Inversions) trong mảng.<br>• Tiết kiệm bộ nhớ gấp 4 lần và cài đặt nhanh gấp 3 lần Segment Tree. |
| [`BITLazy.cpp`](./Cau_Truc_Du_Lieu/BITLazy.cpp) | Fenwick Range Update Range Query | $\mathcal{O}(\log N)$ cho cả update & query | $\mathcal{O}(N)$ | • Cộng giá trị vào đoạn $[L, R]$ và tính tổng đoạn $[L, R]$ với bộ nhớ cực nhẹ. |
| [`SegmentTree.cpp`](./Cau_Truc_Du_Lieu/SegmentTree.cpp) | Segment Tree cơ bản | $\mathcal{O}(\log N)$ cho update/query | $\mathcal{O}(4N)$ | • Cập nhật giá trị 1 phần tử và truy vấn Max/Min/Sum/GCD trên đoạn $[L, R]$. |
| [`SegmentTreelazy.cpp`](./Cau_Truc_Du_Lieu/SegmentTreelazy.cpp) | Segment Tree Lazy (Tổng) | $\mathcal{O}(\log N)$ cho Range Update/Query | $\mathcal{O}(4N)$ | • Cộng giá trị vào đoạn $[L, R]$ và tính tổng đoạn $[L, R]$. |
| [`STLazyMax.cpp`](./Cau_Truc_Du_Lieu/STLazyMax.cpp) | Segment Tree Lazy (Max) | $\mathcal{O}(\log N)$ cho Range Update/Query | $\mathcal{O}(4N)$ | • Cộng giá trị vào đoạn $[L, R]$ và tìm giá trị lớn nhất trên đoạn $[L, R]$. |
| [`SparseTable.cpp`](./Cau_Truc_Du_Lieu/SparseTable.cpp) | Bảng thưa (Sparse Table) | Tiền xử lý $\mathcal{O}(N \log N)$<br>Truy vấn $\mathcal{O}(1)$ | $\mathcal{O}(N \log N)$ | • Mảng tĩnh (không cập nhật). Cần truy vấn Min/Max/GCD đoạn với thời gian siêu tốc $\mathcal{O}(1)$. |
| [`PST.cpp`](./Cau_Truc_Du_Lieu/PST.cpp) | Persistent Segment Tree | Mỗi update: $\mathcal{O}(\log N)$<br>Truy vấn lịch sử: $\mathcal{O}(\log N)$ | $\mathcal{O}(N \log N)$ | • Tìm **phần tử nhỏ thứ $k$ (K-th smallest)** trên đoạn $[L, R]$.<br>• Đếm số phần tử trong khoảng $[x, y]$ nằm trên đoạn $[L, R]$.<br>• Truy vấn trên các phiên bản lịch sử. |
| [`Mo_algorithm.cpp`](./Cau_Truc_Du_Lieu/Mo_algorithm.cpp) | Thuật toán Mo (Mo with Updates) | $\mathcal{O}(N^{5/3})$ hoặc $\mathcal{O}(Q \sqrt{N})$ | $\mathcal{O}(N + Q)$ | • Xử lý offline $Q$ truy vấn đoạn đếm số phần tử phân biệt, tần số xuất hiện khi không thể dùng Segment Tree. |
| [`MonoStack.cpp`](./Cau_Truc_Du_Lieu/MonoStack.cpp) | Monotonic Stack | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ | • Tìm phần tử gần nhất lớn hơn/nhỏ hơn bên trái/phải.<br>• Tìm hình chữ nhật lớn nhất trong biểu đồ cột (Histogram). |

---

## 6. Thuật Toán Xử Lý Chuỗi

📂 **Thư mục:** [`./Xu_Ly_Chuoi`](./Xu_Ly_Chuoi/README.md)

| File mã nguồn | Thuật toán | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`KMP.cpp`](./Xu_Ly_Chuoi/KMP.cpp) | Knuth-Morris-Pratt | $\mathcal{O}(N + M)$ | $\mathcal{O}(M)$ | • Tìm tất cả các vị trí xuất hiện của chuỗi mẫu $P$ trong văn bản $T$ bằng mảng tiền tố $\pi$ (LPS). Không bao giờ quay lui con trỏ. |
| [`Z_Algorithm.cpp`](./Xu_Ly_Chuoi/Z_Algorithm.cpp) | Thuật toán Z | $\mathcal{O}(N + M)$ | $\mathcal{O}(N + M)$ | • Tính độ dài tiền tố chung dài nhất giữa chuỗi và các hậu tố của nó.<br>• So khớp xâu, tìm chu kỳ xâu, nén xâu. |
| [`Trie.cpp`](./Xu_Ly_Chuoi/Trie.cpp) | Cây tiền tố (String & XOR Trie) | $\mathcal{O}(\text{length})$ hoặc $\mathcal{O}(31)$ | $\mathcal{O}(\Sigma \cdot N)$ | • Tra cứu từ điển, đếm số từ có tiền tố chung.<br>• **Bitwise Trie**: Tìm cặp $(a_i, a_j)$ có $a_i \oplus a_j$ lớn nhất trong mảng trong thời gian $\mathcal{O}(31 \cdot N)$. |
| [`HashString.cpp`](./Xu_Ly_Chuoi/HashString.cpp) | Rolling Hash kép (Double Hash) | Tiền xử lý $\mathcal{O}(N)$<br>So sánh xâu con $\mathcal{O}(1)$ | $\mathcal{O}(N)$ | • So sánh 2 xâu con bất kỳ trong $\mathcal{O}(1)$.<br>• Dùng 2 modulo lớn ($10^9+7, 10^9+9$) để chống tràn và triệt tiêu hoàn toàn va chạm Hash. |

---

## 7. Quy Hoạch Động

📂 **Thư mục:** [`./Quy_Hoach_Dong`](./Quy_Hoach_Dong/README.md)

| File mã nguồn | Bài toán | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`Vidu-DPBitmask.cpp`](./Quy_Hoach_Dong/Vidu-DPBitmask.cpp) | DP Bitmask (QBSELECT) | $\mathcal{O}(N \cdot 4^K)$ với $K=4$ | $\mathcal{O}(N \cdot 2^K)$ | • Quy hoạch động trên lưới có 1 chiều rất nhỏ ($K \le 4-15$), nén trạng thái các ô được chọn thành mặt nạ nhị phân (Bitmask). |
| [`Vidu-TSP.cpp`](./Quy_Hoach_Dong/Vidu-TSP.cpp) | Người du lịch (TSP) | $\mathcal{O}(N^2 \cdot 2^N)$ | $\mathcal{O}(N \cdot 2^N)$ | • Tìm hành trình đi qua tất cả các thành phố đúng 1 lần với chi phí nhỏ nhất khi $N \le 20$. |

---

## 8. Hình Học Tính Toán

📂 **Thư mục:** [`./Hinh_Hoc_Tinh_Toan`](./Hinh_Hoc_Tinh_Toan/README.md)

| File mã nguồn | Thuật toán | Độ phức tạp thời gian | Bộ nhớ | Khi nào nên dùng & Dấu hiệu bài toán |
| :--- | :--- | :--- | :--- | :--- |
| [`ConvexHull.cpp`](./Hinh_Hoc_Tinh_Toan/ConvexHull.cpp) | Bao lồi (Monotone Chain) | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ | • Tìm đa giác lồi nhỏ nhất bao phủ tập $N$ điểm 2D.<br>• Tính chu vi bao lồi, diện tích bao lồi (Shoelace Formula).<br>• Tìm cặp điểm xa nhất trên mặt phẳng 2D. |
