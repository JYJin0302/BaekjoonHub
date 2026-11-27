#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ld eps = 1e-8;
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
};

template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
        oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non-endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return { (a * ob - b * oa) / (ob - oa) };
    return {};
}

template<class P> bool onSegment(P a, P b, P c) {
    if (abs(a.cross(b, c)) > eps) return 0;
    return min(b.x, c.x) <= a.x && a.x <= max(b.x, c.x);
}

bool adj[505][505];


void solve() {

    int n;
    cin >> n;

    vector<Point<ld>> A;
    vector<pair<Point<ld>, Point<ld>>> B;
    for (int i = 0; i < n; i++) {
        ld a, b, c, d;
        cin >> a >> b >> c >> d;

        Point<ld> p1(a, b);
        Point<ld> p2(c, d);
        if (p2 < p1) swap(p1, p2);

        A.push_back(p1);
        A.push_back(p2);
        B.push_back(mp(p1, p2));
    }
    sort(all(B));


    while (1) {
        bool diff = 0;
        n = B.size();

        vector<pair<Point<ld>, Point<ld>>> tmp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (onSegment(B[j].x, B[i].x, B[i].y) && onSegment(B[i].y, B[j].x, B[j].y)\
                    && abs(B[i].x.cross(B[j].x, B[j].y)) < eps && abs(B[j].y.cross(B[i].x, B[i].y)) < eps) {
                    B[i].x = min(B[i].x, B[j].x);
                    B[i].y = max(B[i].y, B[j].y);
                    diff = 1;
                    for (int f = 0; f < n; f++) {
                        if (f != j) tmp.push_back(B[f]);
                    }
                    break;
                }


            }
            if (diff) break;
        }

        if (!diff) break;

        B = tmp;
        sort(all(B));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            auto res = segInter(B[i].x, B[i].y, B[j].x, B[j].y);
            if (!res.empty()) A.push_back(res[0]);
        }
    }
    sort(all(A));
    A.erase(unique(all(A)), A.end());

    //cout << "RES:\n";
    //for (auto f : A) cout << f.x << ' ' << f.y << '\n';

    int tn = A.size();

    for (int i = 0; i < tn; i++) {
        for (int j = i + 1; j < tn; j++) {

            bool ok = 0;
            for (auto f : B) {
                if (onSegment(A[i], f.x, f.y) && onSegment(A[j], f.x, f.y)) {
                    ok = 1;
                    break;
                }
            }

            if (ok) {
                //cout << "found: " << A[i].x << ' ' << A[i].y << " | " << A[j].x << ' ' << A[j].y << '\n';
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < tn; i++) {
        for (int j = i + 1; j < tn; j++) {
            for (int k = j + 1; k < tn; k++) {
                if (abs(A[k].cross(A[i], A[j])) < eps) continue;

                if (adj[i][j] && adj[j][k] && adj[k][i]) ans++;

            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}