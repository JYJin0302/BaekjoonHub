#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
//#define x first
//#define y second

const ld eps = 1e-9, inf = 1e9;
template<class T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) {
        x = _x, y = _y;
    }
    Point operator+(Point o) const { return Point(x + o.x, y + o.y); }
    Point operator-(Point o) const { return Point(x - o.x, y - o.y); }
    Point operator* (T d)const { return Point(x * d, y * d); }
    T dot(Point p) const { return x* p.x + y * p.y; }
    bool operator<(Point p) const { return mp(x, y) < mp(p.x, p.y); }
    bool operator==(Point o) const { return x == o.x && y == o.y; }
    T cross(Point p) const { return x * p.y - y * p.x; }
    T cross(Point a, Point b)const { return(a - *this).cross(b - *this); }
    T dist2()const { return x * x + y * y; }
    ld dist() const { return sqrtl((ld)dist2()); }
    Point rotate(double a)const {
        return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, Point p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<long double> P;

vector<P> convexHull(vector<P> pts) {
    int sn = pts.size();
    if (sn <= 1) return pts;
    sort(all(pts));
    //pts.erase(unique(all(pts)), pts.end());

    vector<P> h(sn + 1);
    int s = 0, t = 0;

    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= eps) {
                t--;
            }
            h[t++] = p;
        }
    return { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
}

struct Halfplane {
    // 'p' is a passing P of the line and 'pq' is the
    // direction vector of the line.
    P p, pq;
    long double angle;
    Halfplane() {}
    Halfplane(const P& a, const P& b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);
    }
    // Check if P 'r' is outside this half-plane.
    // Every half-plane allows the region to the LEFT of its line.
    bool out(const P& r) {
        return P().cross(pq, r - p) < -eps;
    }
    // Comparator for sorting.
    bool operator < (const Halfplane& e) const {
        return angle < e.angle;
    }
    // Intersection P of the lines of two half-planes. It
   // is assumed they're never parallel.
    friend P inter(const Halfplane & s, const Halfplane & t) {
    long double alpha = P().cross((t.p - s.p), t.pq) /
        P().cross(s.pq, t.pq);
    return s.p + (s.pq * alpha);
    }
};
// Actual algorithm
vector<P> hp_intersect(vector<Halfplane>& H) {
    P box[4] = { // Bounding box in CCW order
    P(inf, inf),
    P(-inf, inf),
    P(-inf,-inf),
    P(inf,-inf)
    };
   // cout << "checK Plane : ";
   // for (auto f : H) cout << f.p << ' ' << f.pq << " | ";
   // cout << '\n';
    for (int i = 0; i < 4; i++) { // Add bounding box
       //  half - planes.
            Halfplane aux(box[i], box[(i + 1) % 4]);
        H.push_back(aux);
    }
    // Sort by angle and start algorithm
    sort(H.begin(), H.end());
    deque<Halfplane> dq;

    int len = 0;
    for (int i = 0; i < int(H.size()); i++) {
        /*cout << "GO: " << H[i].p << ' ' << H[i].pq << '\n';
        for (auto f : dq) cout << f.p << ' ' << f.pq << " | ";
        cout << '\n';*/

        // Remove from the back of the deque while last
       //  half - plane is redundant
            while (len > 1 && H[i].out(inter(dq[len - 1], dq[len - 2]))) {
                dq.pop_back(); --len;
            }
        // Remove from the front of the deque while first
        // half - plane is redundant
            while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
                dq.pop_front(); --len;
            }
        // Special case check: Parallel half-planes
        if (len > 0 && fabsl(P().cross(H[i].pq, dq[len - 1].pq)) < eps) {
            // Opposite parallel half-planes that ended up
            // checked against each other.
            if (H[i].pq.dot(dq[len - 1].pq) < 0.0)
                return vector<P>();
            // Same direction half-plane: keep only the
            //  half - plane.
            if (H[i].out(dq[len - 1].p)) {
                dq.pop_back(); --len;
            }
            else continue;
        }
        // Add new half-plane
        dq.push_back(H[i]);
        ++len;
    }
    // Final cleanup: Check half-planes at the front against
    // the backand vice - versa
    while (len > 2 && dq[0].out(inter(dq[len - 1], dq[len - 2]))) {
        dq.pop_back(); --len;
    }
    while (len > 2 && dq[len - 1].out(inter(dq[0], dq[1]))) {
        dq.pop_front(); --len;
    }
    // Report empty intersection if necessary
    if (len < 3) return vector<P>();

    vector<P> ret(len);
    for (int i = 0; i + 1 < len; i++) {
        ret[i] = inter(dq[i], dq[i + 1]);
    }
    ret.back() = inter(dq[len - 1], dq[0]);
    return ret;
}

ld getVal(vector<P>& A) {
    vector<P> ch = convexHull(A);
    int sn = ch.size();
    if (sn <= 1) {
        return 0;
    }

   // cout << "Go convex : ";
   // for (auto f : ch) cout << f << ' ';
  //  cout << '\n';
    ld ans = (ch[0] - ch[1]).dist2();
    int tar = 1;
    for (int i = 0; i < sn; i++) {
        while (abs(ch[i].cross(ch[(i + 1) % sn], ch[tar])) < abs(ch[i].cross(ch[(i + 1) % sn], ch[(tar + 1) % sn])) - eps) {
            tar = (tar + 1) % sn;
        }
        ans = max(ans, (ch[i] - ch[tar]).dist2());
      //  cout << "checking : " << i << ' ' << tar << '\n';
    }
    return sqrtl(ans);

}

const ld PI = acos(-1);
int n;
ld tarD;
vector<Point<long double>> A;
bool F(ld D) {
    
   // cout << "GO D: " << D << '\n';
    vector<Halfplane> B;
    for (int i = 0; i < n; i++) {
        Halfplane cur(A[i], A[(i + 1) % n]);
        P tP = cur.pq;
        ld tD = tP.dist();
        tP.x /= tD, tP.y /= tD;
        P newP = cur.p + (tP * D).rotate(PI / 2);
        cur.p = newP;
        B.push_back(cur);
    }

    vector<P> res = hp_intersect(B);
   // cout << "intersect found : ";
   // for (auto f : res) cout << f << ' ';
   // cout << '\n';
    ld maxD = getVal(res);
    
   // cout << "Foudn res: " << D << " => " << maxD << '\n';
    return maxD >= tarD;
}

void solve() {
    cin >> n >> tarD;

    A = vector<Point<long double>>(n);
    for (auto& f : A) cin >> f.x >> f.y;
    reverse(all(A));

    ld L = 0, R = 1e7;
    ld ans = 0;
    while (R - L >= eps) {
        ld m = (L + R) / 2;
        if (F(m)) {
            ans = m;
            L = m;
        }
        else R = m;
    }

    cout << fixed << setprecision(10);
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}