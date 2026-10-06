# BẢNG RÀ SOÁT HIỆN TRẠNG VÀ KẾ HOẠCH BỔ SUNG THUẬT TOÁN (TIẾNG VIỆT KHÔNG DẤU)

Tài liệu này ghi lại chi tiết:
1. **Rà soát từng file trong 4 folder gốc**:
   - Folder `Tìm đường đi`
   - Folder `Caykhung LCA DSU`
   - Folder `SpareTable SegmentTree FenWick`
   - Folder `DPBITMask`
2. **Phân loại lại vào 8 thư mục mới (Tên tiếng Việt không dấu, dễ hiểu, chuẩn thi đấu CP)**.
3. **Danh sách các file giữ nguyên, file di chuyển và file viết mới**.

---

## 1. BẢNG PHÂN BỔ VÀ BỔ SUNG CHI TIẾT THEO 8 FOLDER MỚI

| STT | Tên Folder Mới | Các file chuyển từ folder cũ sang | Các file THIẾU CẦN VIẾT MỚI | Tác dụng tổng quan |
| :---: | :--- | :--- | :--- | :--- |
| **1** | `Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat` | • `BFS.cpp`<br>• `DFSdequy.cpp`<br>• `DFSStack.cpp`<br>• `Dijkstra.cpp`<br>• `topo.cpp` (từ Caykhung) | • `Bellman_Ford.cpp` (cũ bị rỗng 0 byte, viết lại chuẩn)<br>• ➕ `SPFA.cpp`<br>• ➕ `Floyd_Warshall.cpp`<br>• ➕ `Euler_Hierholzer.cpp`<br>• ➕ `README.md` | Duyệt BFS/DFS, Topo, các thuật toán đường đi ngắn nhất (Dijkstra, Bellman-Ford, SPFA, Floyd-Warshall) và chu trình/đường đi Euler. |
| **2** | `Cay_va_Cay_Khung` | • `DSU.cpp`<br>• `Prim.cpp`<br>• `LCA_O(log(n)).cpp`<br>• `HLD.cpp` (từ SegmentTree sang) | • ➕ `Kruskal.cpp` (Cây khung MST dùng DSU)<br>• ➕ `README.md` | Quản lý tập hợp DSU, Cây khung nhỏ nhất (Prim, Kruskal), Tổ tiên chung gần nhất (LCA), Phân rã cây (HLD). |
| **3** | `Tinh_Lien_Thong_Do_Thi` | • `Kosaraju.cpp` (hoàn thiện lại chuẩn SCC) | • ➕ `Tarjan.cpp` (Gộp 1 lần DFS tìm SCC + Khớp + Cầu)<br>• ➕ `README.md` | Tìm thành phần liên thông mạnh (SCC), điểm khớp và cạnh cầu trên đồ thị. |
| **4** | `Luong_va_Cap_Ghep` | *(Chưa có)* | • ➕ `Dinic.cpp`<br>• ➕ `MaxFlow_Edmonds_Karp.cpp`<br>• ➕ `MinCostMaxFlow.cpp`<br>• ➕ `BipartiteMatching.cpp`<br>• ➕ `README.md` | Luồng cực đại (Dinic, Edmonds-Karp), Luồng chi phí cực tiểu (MCMF), Cặp ghép cực đại đồ thị 2 phía (Hopcroft-Karp & Kuhn). |
| **5** | `Cau_Truc_Du_Lieu` | • `SegmentTree.cpp`<br>• `SegmentTreelazy.cpp`<br>• `STLazyMax.cpp`<br>• `SparseTable.cpp`<br>• `BITLazy.cpp`<br>• `PST.cpp`<br>• `Mo's algorithm.cpp`<br>• `MonoStack.cpp` (từ Tìm đường đi sang) | • ➕ `Fenwick_BIT.cpp` (BIT cơ bản Point Update Range Query)<br>• ➕ `README.md` | Các cấu trúc dữ liệu kinh điển: Segment Tree, Fenwick (BIT), Sparse Table, Persistent Tree, Mo's Algorithm, Monotonic Stack. |
| **6** | `Xu_Ly_Chuoi` | *(Chưa có)* | • ➕ `KMP.cpp`<br>• ➕ `Z_Algorithm.cpp`<br>• ➕ `Trie.cpp`<br>• ➕ `HashString.cpp`<br>• ➕ `README.md` | Các thuật toán so khớp xâu mẫu (KMP, Z-algo), Cây tiền tố (Trie), Mã băm xâu (Rolling Hash). |
| **7** | `Quy_Hoach_Dong` | • `Vidu-DPBitmask.cpp`<br>• `Vidu-TSP.cpp` | • ➕ `README.md` | Các bài toán Quy hoạch động trạng thái Bitmask kinh điển. |
| **8** | `Hinh_Hoc_Tinh_Toan` | *(Chưa có)* | • ➕ `ConvexHull.cpp`<br>• ➕ `README.md` | Thuật toán tìm Bao lồi (Monotone Chain / Graham Scan) và các ứng dụng hình học 2D. |

---

## 2. CẤU TRÚC THƯ MỤC CHI TIẾT (CHUẨN ĐƯỜNG DẪN TƯƠNG ĐỐI CHO GIT)

```
Algorithm/
├── AUDIT_AND_PLAN.md
├── README.md
│
├── Duyet_Do_Thi_va_Duong_Di_Ngan_Nhat/
│   ├── BFS.cpp
│   ├── DFSdequy.cpp
│   ├── DFSStack.cpp
│   ├── Dijkstra.cpp
│   ├── Bellman_Ford.cpp
│   ├── SPFA.cpp
│   ├── Floyd_Warshall.cpp
│   ├── Euler_Hierholzer.cpp
│   ├── topo.cpp
│   └── README.md
│
├── Cay_va_Cay_Khung/
│   ├── DSU.cpp
│   ├── Kruskal.cpp
│   ├── Prim.cpp
│   ├── LCA_O(log(n)).cpp
│   ├── HLD.cpp
│   └── README.md
│
├── Tinh_Lien_Thong_Do_Thi/
│   ├── Tarjan.cpp
│   ├── Kosaraju.cpp
│   └── README.md
│
├── Luong_va_Cap_Ghep/
│   ├── Dinic.cpp
│   ├── MaxFlow_Edmonds_Karp.cpp
│   ├── MinCostMaxFlow.cpp
│   ├── BipartiteMatching.cpp
│   └── README.md
│
├── Cau_Truc_Du_Lieu/
│   ├── Fenwick_BIT.cpp
│   ├── BITLazy.cpp
│   ├── SegmentTree.cpp
│   ├── SegmentTreelazy.cpp
│   ├── STLazyMax.cpp
│   ├── SparseTable.cpp
│   ├── PST.cpp
│   ├── Mo_algorithm.cpp
│   ├── MonoStack.cpp
│   └── README.md
│
├── Xu_Ly_Chuoi/
│   ├── KMP.cpp
│   ├── Z_Algorithm.cpp
│   ├── Trie.cpp
│   ├── HashString.cpp
│   └── README.md
│
├── Quy_Hoach_Dong/
│   ├── Vidu-DPBitmask.cpp
│   ├── Vidu-TSP.cpp
│   └── README.md
│
└── Hinh_Hoc_Tinh_Toan/
    ├── ConvexHull.cpp
    └── README.md
```
