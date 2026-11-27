#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

struct P {
    ll x, y;
    ll vx, vy;

    P() : x(0), y(0), vx(0), vy(0) {}
    P(ll _x, ll _y, ll _vx, ll _vy) : x(_x), y(_y), vx(_vx), vy(_vy) {}

    bool operator==(P& o) {
        return x == o.x && y == o.y;
    }
};

ll ccw(const P& a, const P& b, const P& c) {
    ll val = a.x * b.y + b.x * c.y + c.x * a.y;
    val -= a.y * b.x + b.y * c.x + c.y * a.x;

    if (val != 0) val /= abs(val);
    return val;
}

ll ccw(P& a, P& b) {
    ll val = a.vx * b.vy - b.vx * a.vy;
    return val;
}


bool cmp(P& a, P& b) {
    if (a.vx == 0 && b.vx == 0) {
        return a.vy < b.vy;
    }

    if (a.vx * b.vx <= 0) {
        return a.vx < b.vx;
    }

    return ccw(a, b) > 0;
}

ld getVal(P& a, P& b, P& c) {
    if (b == c) {
        return 3e9;
    }
    ld S = abs(ccw(b, c));

    ld d1 = sqrtl(b.vx * b.vx + b.vy * b.vy);
    ld d2 = sqrtl(c.vx * c.vx + c.vy * c.vy);

    return S / max(d1, d2);
}

void solve() {

    int n;
    cin >> n;

    vector<P> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    ld ans = 3e9;
    for (int i = 0; i < n; i++) {
        vector<P> B;
        for (int j = 0; j < n; j++) {
            if (A[j] == A[i]) continue;
            B.push_back(P(A[j].x, A[j].y, A[j].x - A[i].x, A[j].y - A[i].y));
        }

        sort(all(B), cmp);

        /*for (int j = 0; j < n-1; j++)  cout << "{ " << B[j].vx << ' ' << B[j].vy << " | " << B[j].x << ' ' << B[j].y << " } ";
        cout << '\n';*/

        int ix0 = 0, ix1 = 1;

        for (; ix0 < n - 1; ix0++) {

            while (ccw(B[ix0], A[i], B[ix1]) < 0) ix1 = (ix1 + 1) % (n-1);
            // ix0 
            ans = min(ans, getVal(A[i], B[ix0], B[(ix0 + n) % (n - 1)]));
            ans = min(ans, getVal(A[i], B[ix0], B[(ix0 + 1) % (n - 1)]));
            ans = min(ans, getVal(A[i], B[ix0], B[ix1]));
            ans = min(ans, getVal(A[i], B[ix0], B[(ix1 + 1) % (n - 1)]));
        }

    }

    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}