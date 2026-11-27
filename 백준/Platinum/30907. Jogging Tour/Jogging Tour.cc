#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

struct P {
    ld x, y;
    P(ld x = 0, ld y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(ld d) const { return P(x * d, y * d); }
    P operator/(ld d) const { return P(x / d, y / d); }
    ld dist2() const { return x * x + y * y; }
    ld dist() const { return sqrt((double)dist2()); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

int n;
ld dp[13][1 << 12];
ld getAns(vector<P>& A) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) dp[i][j] = 1e18;
    }

    for (int msk = 1; msk < (1 << n); msk++) {
        for (int i = 0; i < n; i++) {
            if (msk == (1 << i)) {
                dp[i][msk] = 0;
                continue;
            }

            if (msk & (1 << i)) {}
            else continue;

            int nmsk = msk ^ (1 << i);
            ld res = 1e18;
            for (int j = 0; j < n; j++) {
                if (i == j || !(msk & (1 << j))) continue;
                res = min(res, dp[j][nmsk] + abs((A[i] - A[j]).x) + abs((A[i]-A[j]).y));
            }
            dp[i][msk] = res;
        }
    }
    ld res = 1e18;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[i][(1 << n) - 1]);
    }
    return res;
}

void solve() {

    cin >> n;

    vector<P> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    ld ans = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld ang = 0;
            P tmp = A[i] - A[j];
            if (tmp.x * tmp.y == 0) {}
            else {
                ang = asin(abs(tmp.x) / tmp.dist());
                if (tmp.x * tmp.y < 0) ang = acos(-1)/2 - ang;
            }

            vector<P> tA;
            for (int f = 0; f < n; f++) {
                tA.push_back(A[f].rotate(ang));
            }
            ld res = getAns(tA);
            ans = min(ans, res);
        }
    }
    cout << fixed << setprecision(10);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}