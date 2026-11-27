#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int sgn(int x) {
    return (x > 0) - (x < 0);
}
struct P {
    int x, y;
    P(int x = 0, int y = 0) : x(x), y(y) {}

    void conv() {
        if (x == 1) {
            x = y;
            y = 51;
        }
        else if (x == 2) {
            x = y;
            y = 0;
        }
        else if (x == 3) {
            x = 0;
            y = 51 - y;
        }
        else {
            x = 51;
            y = 51 - y;
        }
    }
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(int d) const { return P(x * d, y * d); }
    P operator/(int d) const { return P(x / d, y / d); }
    int dot(P p) const { return x * p.x + y * p.y; }
    int cross(P p) const { return x * p.y - y * p.x; }
    int cross(P a, P b) const { return (a - *this).cross(b - *this); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

bool onSegment(P a, P b, P c) {
    if (a.cross(b, c) != 0) return 0;
    if (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) {}
    else return 0;
    return min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int segInter(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
        oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non-endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return 1;
    bool va = 0, vb = 0, vc = 0, vd = 0;
    va = onSegment(c, d, a);
    vb = onSegment(c, d, b);
    vc = onSegment(a, b, c);
    vd = onSegment(a, b, d);
    if (va ^ vb || vc ^ vd) return 1;
    return 0;
}


void solve() {

    int n;
    cin >> n;
    n /= 2;

    vector<pair<P, P>> A;
    for (int i = 0; i < n; i++) {
        P p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        p1.conv();
        p2.conv();
        A.push_back(mp(p1, p2));
    }

    int ans = 0;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int res = segInter(A[i].first, A[i].second, A[j].first, A[j].second);
            ans += res;
            cnt[i] += res;
            cnt[j] += res;
        }
    }

    cout << ans << '\n' << *max_element(all(cnt)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}