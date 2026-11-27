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
    int n;
    cin >> n;

    vector<pair<Point<double>, Point<double>>> A, border;
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2), swap(y1, y2);

        if (min(x1, x2) >= 10 || max(x1, x2) <= -10) continue;
        if (min(y1, y2) >= 10 || max(y1, y2) <= -10) continue;
        Point p1(x1, y1), p2(x2, y2);
        A.push_back(mp(p1, p2));
    }

    border.push_back(mp(Point(-10.0, 10.0), Point(10.0, 10.0)));
    border.push_back(mp(Point(-10.0, 10.0), Point(-10.0, -10.0)));
    border.push_back(mp(Point(10.0, -10.0), Point(10.0, 10.0)));
    border.push_back(mp(Point(-10.0, -10.0), Point(10.0, -10.0)));

    int ans = 1;
    for (int i = 0; i < A.size(); i++) {
        set<Point<double>> st;
        for (int k = 0; k < 4; k++) {
            vector<Point<double>> res = segInter<Point<double>>(A[i].first, A[i].second, border[k].first, border[k].second);
            for (auto f : res) st.insert(f);
        }
        /*for (auto f : st) cout << f << ' ';
        cout << '\n';*/

        if (st.size() < 2) continue;

        int val = 1;
        for (int j = 0; j < i; j++) {
            vector<Point<double>> res = segInter<Point<double>>(A[i].first, A[i].second, A[j].first, A[j].second);
            if (res.size() != 1) continue;
            if (res[0].x > -10 && res[0].x < 10 && res[0].y > -10 && res[0].y < 10) {
                val++;
            }
        }
        ans += val;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}