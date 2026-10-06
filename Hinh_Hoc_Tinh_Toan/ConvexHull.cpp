#include <bits/stdc++.h>
using namespace std;

/**
 * Thuật toán Tìm Bao Lồi 2D (Convex Hull)
 * Phương pháp: Thuật toán Monotone Chain (Chuỗi đơn điệu của Andrew)
 * Độ phức tạp: O(N log N) do bước sắp xếp tọa độ điểm.
 * Ứng dụng:
 *  - Tìm tập đa giác lồi nhỏ nhất bao quanh N điểm trên mặt phẳng 2D.
 *  - Tính chu vi bao lồi, diện tích bao lồi (Shoelace Formula).
 *  - Tìm cặp điểm xa nhất trên mặt phẳng (Rotating Calipers).
 */

struct Point {
    long long x, y;

    bool operator<(const Point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

// Tích có hướng (Cross Product) của 2 vector AB và AC
// > 0: Rẽ trái (Counter-clockwise)
// < 0: Rẽ phải (Clockwise)
// = 0: Thẳng hàng (Collinear)
long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Khoảng cách Euclid giữa 2 điểm
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Tìm bao lồi theo chiều ngược chiều kim đồng hồ
vector<Point> convex_hull(vector<Point> &pts) {
    int n = pts.size();
    if (n <= 2) return pts;

    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    n = pts.size();
    if (n <= 2) return pts;

    vector<Point> hull;

    // 1. Xây dựng bao dưới (Lower Hull)
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    // 2. Xây dựng bao trên (Upper Hull)
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while ((int)hull.size() > lower_size && cross_product(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    hull.pop_back(); // Xóa điểm lặp lại ở cuối
    return hull;
}

// Tính diện tích đa giác lồi
double polygon_area(const vector<Point> &hull) {
    double area = 0;
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += hull[i].x * hull[j].y - hull[j].x * hull[i].y;
    }
    return abs(area) / 2.0;
}

// Tính chu vi đa giác lồi
double polygon_perimeter(const vector<Point> &hull) {
    double perimeter = 0;
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        perimeter += dist(hull[i], hull[j]);
    }
    return perimeter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    vector<Point> hull = convex_hull(pts);

    cout << "So dinh cua bao loi: " << hull.size() << "\n";
    cout << "Cac dinh theo thu tu nguoc chieu kim dong ho:\n";
    for (const auto &p : hull) {
        cout << "  (" << p.x << ", " << p.y << ")\n";
    }

    cout << fixed << setprecision(3);
    cout << "Chu vi bao loi: " << polygon_perimeter(hull) << "\n";
    cout << "Dien tich bao loi: " << polygon_area(hull) << "\n";

    return 0;
}
