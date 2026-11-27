#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()

string grid[55];

int n, m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0 ,-1, 0, 1 };
int dWx[] = { -1, -1, 1, 1 };
int dWy[] = { 1, -1, -1, 1 };

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T> struct P {
    T x, y;
    P() : x(0), y(0) {}
    P(T _x, T _y) : x(_x), y(_y) {}
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
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};
P<ld> s;
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


template<class P> pair<P, int> segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
        oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non-endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return mp((a * ob - b * oa) / (ob - oa), 3);

    if (onSegment(a, b, c)) {
        if (a.cross(b, d) < 0) {
            return mp(c, 2);
        }
        return mp(c, 1);
    }
    if (onSegment(a, b, d)) {
        if (a.cross(b, c) < 0) return mp(d, 2);
        return mp(d, 1);
    }
    return mp(P(), 0);
}

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}


bool cmp(P<ld>& p1, P<ld>& p2) {
    P<ld> t1 = p1 - s;
    P<ld> t2 = p2 - s;

    if ((t1.x >= 0) ^ (t2.x >= 0)) {
        return t1.x < t2.x;
    }
    ld val = s.cross(p1, p2);
    if (val == 0) return (p1 - s).dist2() < (p2 - s).dist2();
    return val < 0;
}

bool cmp2(pair<P<ld>, int>& v1, pair<P<ld>, int>& v2) {
    return (v1.first - s).dist2() < (v2.first - s).dist2();
}


void solve() {
    cin >> n >> m;

    vector<P<ld>> wall, points;
    wall.push_back(P<ld>(0, 0)); wall.push_back(P<ld>(0, m * 2.0));
    wall.push_back(P<ld>(0, 0)); wall.push_back(P<ld>(n * 2.0, 0));
    wall.push_back(P<ld>(n * 2.0, 0)); wall.push_back(P<ld>(n * 2.0, m * 2.0));
    wall.push_back(P<ld>(0, m * 2.0)); wall.push_back(P<ld>(n * 2.0, m * 2.0));


    ld ans = 4.0 * n * m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                sx = i * 2 + 1;
                sy = j * 2 + 1;
            }
            else if (grid[i][j] == '#') {
                ans -= 4;
                int ti = i * 2 + 1;
                int tj = j * 2 + 1;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (inGrid(ni, nj) && grid[ni][nj] != '#') {
                        int nk = (k + 1) % 4;
                        wall.push_back(P<ld>(ti + dWx[k], tj + dWy[k]));
                        wall.push_back(P<ld>(ti + dWx[nk], tj + dWy[nk]));
                    }
                }
            }
        }
    }
    s = P<ld>(sx, sy);

    /*for (int i = 0; i < wall.size(); i += 2) {
        cout << wall[i] << " | " << wall[i + 1] << '\n';
    }*/

    points = wall;
    sort(all(points));
    points.erase(unique(all(points)), points.end());

    // cout << "S : " << s << '\n';
    sort(all(points), cmp);
    //for (auto f : points) cout << f << '\n';

    pair<ld, int> mn = mp(1e8, -1);
    int sz = points.size();

    for (int i = 0; i < sz; i++) {
        mn = min(mn, mp((points[i] - s).dist2(), i));
    }

    int ix = mn.second;
    P<ld> pre = points[ix];
    ix = (ix - 1 + sz) % sz;
    for (int i = 0; i <= sz; i++) {
        ix = (ix + 1) % sz;

        // s - pre 반직선과 s - nx 반직선 (이 벽과 만나는 곳) 까지의 넓이
        // 교점 구하기
        //cout << "Go line: " << s << " | " << points[ix] << '\n';

        P<ld> ts = (points[ix] - s) * 1000.0 + s;

        vector<pair<P<ld>, int>> v;

        for (int j = 0; j < wall.size(); j += 2) {
            pair<P<ld>, int> res = segInter(s, ts, wall[j], wall[j + 1]);
            if (res.second != 0) v.push_back(res);
        }
        sort(all(v), cmp2);

        ld txx = v[0].first.x;
        ld tyy = v[0].first.y;
        if (abs(txx - (int)txx) > 1e-9) continue;
        if (abs(tyy - (int)tyy) > 1e-9) continue;

        /*cout << "intersections: ";
        for (auto f : v) cout << f.first << ' ';
        cout << '\n';*/

        int cur = 0;
        P<ld> pL, pR;
        for (int j = 0; j < v.size(); j++) {
            int x = v[j].second;
            if ((x & 1) && !(cur & 1)) {
                cur++;
                pL = v[j].first;
            }
            if ((x & 2) && !(cur & 2)) {
                cur += 2;
                pR = v[j].first;
            }
            if (cur == 3) break;
        }

        //cout << pL << ' ' << pR << '\n';

        // get area pre - s - pL

        //cout << "Get area: " << s << ' ' << pre << ' ' << pL << " => ";
        ld tans = abs(s.cross(pre, pL)) / 2;
       // cout << tans << '\n';
        ans -= tans;

        pre = pR;
    }
    cout << ans / 4 << '\n';
}

int main() {
    cout << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}