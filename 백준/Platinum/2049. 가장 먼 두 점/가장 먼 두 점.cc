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
            while (t >= s + 2 && ccw(h[t - 2], h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }
    return { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
}

ll getDist(Point l1, Point l2) {
    return (l1.x - l2.x) * (l1.x - l2.x) + (l1.y - l2.y) * (l1.y - l2.y);
}

const ld eps = 1e-8;
void solve() {

    int n;
    cin >> n;

    vector<Point> A(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        A[i] = Point(a, b);
    }

    vector<Point> ch = convexHull(A);

    int sn = ch.size();
    if (sn == 1) {
        cout << 0 << '\n';
        return;
    }

    ll ans = getDist(ch[0], ch[1]);
    int tar = 1;
    for (int i = 0; i < sn; i++) {
        while (abs(ccw(ch[i], ch[(i+1)%sn], ch[tar])) < abs(ccw(ch[i], ch[(i + 1) % sn], ch[(tar + 1) % sn]))) {
            tar = (tar + 1) % sn;
        }

        ans = max(ans, getDist(ch[i], ch[tar]));
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