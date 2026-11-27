#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()


struct P {
    ll x, y;
    ll vx, vy;
    int idx;
};

bool cmp(P& a, P& b) {
    return mp(a.x, a.y) < mp(b.x, b.y);
}

bool cmp2(P& a, P& b) {
    ll val = a.vx * b.vy - a.vy * b.vx;

    if (val == 0) {
        return a.vx * a.vx + a.vy * a.vy < b.vx* b.vx + b.vy * b.vy;
    }
    return val > 0;
}

ll ccw(P& p1, P& p2, P& p3) {
    ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p2.x * p1.y + p2.y * p3.x + p3.y * p1.x;
    return res;
}
void solve() {

    int n;
    cin >> n;
    vector<P> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
        A[i].idx = i;
    }
    sort(all(A), cmp);

    for (int i = 0; i < n; i++) {
        A[i].vx = A[i].x - A[0].x;
        A[i].vy = A[i].y - A[0].y;
    }

    sort(all(A), cmp2);

    vector<P> res;
    res.push_back(A[0]);

    vector<bool> used(n);
    for (int i = 1; i <= n; i++) {
        while (res.size() >= 2) {
            P p1 = res.back(); res.pop_back();
            P p2 = res.back();
            if (ccw(p2, p1, A[i % n]) >= 0) {
                res.push_back(p1);
                break;
            }
            else {}
        }
        res.push_back(A[i % n]);
    }

    for (auto f : res) used[f.idx] = 1;

    int ix = n - 1;
    while (ix >= 0 && ccw(A[0], A[n - 1], A[ix]) == 0) {
        used[A[ix].idx] = 1;
        ix--;
    }

    for (int i = 0; i < n; i++) if (used[i]) cout << i + 1 << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}