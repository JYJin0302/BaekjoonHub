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

};

ld dist(P& a, P& b) {
    ld ans = sqrtl((a.x-b.x)*(a.x - b.x) + (a.y-b.y) * (a.y-b.y));
    return ans;
}


void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<P> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    vector<P> B, C;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') B.push_back(A[i]);
        else C.push_back(A[i]);
    }

    int sz = B.size();

    ld ans = 0;
    for (int i = 0; i < sz / 2; i++) {
        ans += dist(B[i], B[i + sz / 2]);
    }

    sz = C.size();
    for (int i = 0; i < sz / 2; i++) {
        ans += dist(C[i], C[i + sz / 2]);
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