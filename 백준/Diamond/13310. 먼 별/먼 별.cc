#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct Point {
    ll x, y, vx, vy;
    Point(ll _x = 0, ll _y = 0, ll _vx = 0, ll _vy = 0) {
        x = _x, y = _y;
        vx = _vx, vy = _vy;
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

ll getVal(vector<Point>& A) {

    vector<Point> ch = convexHull(A);

    int sn = ch.size();
    if (sn == 1) {
        return 0;
    }

    ll ans = getDist(ch[0], ch[1]);
    int tar = 1;
    for (int i = 0; i < sn; i++) {
        while (abs(ccw(ch[i], ch[(i + 1) % sn], ch[tar])) < abs(ccw(ch[i], ch[(i + 1) % sn], ch[(tar + 1) % sn]))) {
            tar = (tar + 1) % sn;
        }

        ans = max(ans, getDist(ch[i], ch[tar]));
    }
    return ans;

}

int n, t;
vector<Point> A;
ll F(ll t) {
    vector<Point> B;
    for (int i = 0; i < n; i++) {
        B.push_back(Point(A[i].x + t * A[i].vx, A[i].y + t * A[i].vy));
    }
    return getVal(B);
}

void solve() {

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        ll a, b, c,d ;
        cin >> a >> b >> c >> d;
        A.push_back(Point(a, b, c, d));
    }

    ll L = 0, R = t;
    pair<ll, ll> ans = mp(1e18, -1);
    while (L + 3 <= R) {
        ll md1 = (2 * L + R) / 3;
        ll md2 = (L + 2 * R) / 3;

        ll res1 = F(md1);
        ll res2 = F(md2);

        if (res1 <= res2) {
            R = md2;
            ans = min(ans, mp(res1, md1));
        }
        else {
            L = md1;
            ans = min(ans, mp(res2, md2));
        }

       // cout << md1 << ' ' << res1 << " | " << md2 << ' ' << res2 << '\n';
    }
    for (ll i = L; i <= R; i++) {
        ll res = F(i);
        ans = min(ans, mp(res, i));
    }

    cout << ans.y << '\n' << ans.x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}