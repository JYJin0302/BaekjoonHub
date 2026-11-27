#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int sgn(int x) { return (x > 0) - (x < 0); }

struct P {
    ll x, y;
    P(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(ll d) const { return P(x * d, y * d); }
    P operator/(ll d) const { return P(x / d, y / d); }
    __int128 dot(P p) const { return x * p.x + y * p.y; }
    __int128 cross(P p) const { return x * p.y - y * p.x; }
    __int128 cross(P a, P b) const { return (a - *this).cross(b - *this); }
    __int128 dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }

};

ll n, k, r;
bool segDist(P& s, P& e, P& p) {

    __int128 d = (e - s).dist2(), t = min(d, max((__int128)0, (p - s).dot(e - s)));
    __int128 p0 = (p-s).x, p1 = (e-s).x;
    __int128 t0 = p0 * d - p1 * t;
    p0 = (p-s).y, p1 = (e-s).y;
    __int128 t1 = p0*d - p1*t;
    __int128 t2 = d;
    t2 *= r;
    t2 *= t2;
    return t1*t1 + t0*t0 > t2;
}

bool conn[155][155];
int dp[155][155];
int getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;

    int nl = (l + 1) % n;    
    int res = 0;
    while (nl != r) {
        res = max(res, getDp(l, nl) + getDp(nl, r));
        nl = (nl + 1) % n;
    }
    if (conn[l][r]) res++;
    return dp[l][r] = res;
}

void solve() {

    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> r;
    
    vector<P> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    vector<P> cir(k);
    for (auto& i : cir) cin >> i.x >> i.y;

    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            if (i == 0 && j == n - 1) continue;

            bool ok = 1;
            for (int f = 0; f < k; f++) {
                if (segDist(A[i], A[j], cir[f])) {}
                else ok = 0;
            }

            if (ok) {
                conn[i][j] = conn[j][i] = 1;
                //cout << i << ' ' << j << '\n';
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (conn[i][j]) {
                ans = max(ans, getDp(i, j) + getDp(j, i) - 1);
            }
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}