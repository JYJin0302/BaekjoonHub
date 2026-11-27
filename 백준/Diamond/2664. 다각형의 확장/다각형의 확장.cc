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

vector<P> segInter(P a, P b, P c, P d) {
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
    int d, n;
    cin >> d >> n;
    vector<P> A(n);
    for (auto& i : A) {
        cin >> i.x >> i.y;
    }

    //cout << "Expand: \n";
    vector<P> B;
    for (int i = 0; i < n; i++) {
        int pi = (i + n - 1) % n;
        int ni = (i + 1) % n;

        auto [a, b] = A[i];

        if (A[pi].cross(A[i], A[ni]) > 0) {
            // convex
            if (A[pi].x < A[i].x || A[ni].x < A[i].x) a += d;
            else a -= d;
            if (A[pi].y < A[i].y || A[ni].y < A[i].y) b += d;
            else b -= d;
        }
        else {
            // concave
            if (A[pi].x < A[i].x || A[ni].x < A[i].x) a -= d;
            else a += d;
            if (A[pi].y < A[i].y || A[ni].y < A[i].y) b -= d;
            else b += d;
        }
        B.push_back(P(a, b));
    }

    swap(A, B);
    int ix = min_element(all(A)) - A.begin();

    for (int i = 0; i < ix; i++) {
        for (int j = 1; j < n; j++) {
            swap(A[j], A[j - 1]);
        }
    }

    A.push_back(A[0]);
    vector<P> ans;
    ans.push_back(A[0]);
    for (int i = 1; i <= n; ) {

        P pos;
        int idx = -1;
        if (i == n) {
            pos = A[0];
            idx = n;
        }
        if (i == n - 1) {
            pos = A[i];
            idx = n-1;
        }
        else {
            for (int j = i; j < n - 1; j++) {
                int nj = (j + 1) % n;
                vector<P> tmp = segInter(A[i], A[i - 1], A[j], A[nj]);
                if (!tmp.empty()) {
                    idx = j;
                    pos = tmp[0];
                }
            }
        }

        while (ans.size() >= 2) {
            int sz = ans.size();
            if (ans[sz - 2].cross(ans[sz - 1], pos) == 0) ans.pop_back();
            else break;
        }
        ans.push_back(pos);
        i = idx + 1;
    }
    ans.pop_back();
    cout << ans.size() << '\n';
    for (auto f : ans) cout << f.x << ' '<< f.y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}