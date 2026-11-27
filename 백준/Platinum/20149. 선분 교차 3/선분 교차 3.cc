#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

template<class P> bool onSegment(P a, P b, P c) {
    bool ok = 1;
    if ((c.x - a.x) * (b.y - c.y) == (b.x - c.x) * (c.y - a.y)) ok = 1;
    else return 0;

    if (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x)) {}
    else return 0;

    if (c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) {}
    else return 0;

    return 1;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
        oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non-endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return { (a * ob - b * oa) / (ob - oa) };
    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return { all(s) };
}

void solve() {
    int n = 2;

    vector<pair<Point<double>, Point<double>>> A;
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1), p2(x2, y2);
        A.push_back(mp(p1, p2));
    }

    vector<Point<double>> res = segInter(A[0].first, A[0].second, A[1].first, A[1].second);
    if (res.empty()) cout << 0 << '\n';
    else if (res.size() > 1) cout << 1 << '\n';
    else {
        cout << 1 << '\n';
        cout << res[0].x << ' ' << res[0].y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}