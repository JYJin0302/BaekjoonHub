#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct Point {
    ll x, y;
    Point(ll _x = 0, ll _y = 0) {
        x = _x, y = _y;
    }
    bool operator<(const Point& p) { return mp(x, y) < mp(p.x, p.y); }
    bool operator==(const Point& o) { return x == o.x && y == o.y; }
};

ll ccw(Point& p1, Point& p2, Point& p3) {
    ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return res;
}

vector<Point> convexHull(vector<Point> pts) {
    int sn = pts.size();
    sort(all(pts));
    vector<Point> h(sn + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (Point p : pts) {
            while (t >= s + 2 && ccw(h[t-2], h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    return { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
}

ld getDist(Point p, Point l1, Point l2) {
    ld A = l2.y - l1.y;
    ld B = -(l2.x - l1.x);
    ld C = -l1.x * A + -l1.y * B;

    ld num = abs(A * p.x + B * p.y + C);
    ld den = A * A + B * B;

    ld res = sqrtl(den);
    res = num / res;
    return res;
}

const ld eps = 1e-8;
void solve() {

    ll n, r;
    cin >> n >> r;

    vector<Point> A(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        A[i] = Point(a, b);
    }

    vector<Point> ch = convexHull(A);

    int sn = ch.size();
    if (sn <= 2) {
        cout << 0 << '\n';
        return;
    }

    ld ans = r * 2;
    int tar = 2;
    for (int i = 0; i < sn; i++) {
        ld res = getDist(ch[tar], ch[i], ch[(i + 1) % sn]);
        while (1) {
            int newt = (tar + 1) % sn;
            ld tres = getDist(ch[newt], ch[i], ch[(i + 1) % sn]);
            if (tres >= res - eps) {
                res = tres;
                tar = newt;
            }
            else break;
        }

        ans = min(ans, res);

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