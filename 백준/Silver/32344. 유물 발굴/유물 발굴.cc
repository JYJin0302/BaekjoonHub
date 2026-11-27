#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<ll, ll>> A[101010];

void solve() {

    ll w, h;
    cin >> w >> h;

    

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, a, b;
        cin >> n >> a >> b;

        A[n].push_back(mp(a, b));
    }

    int ans = -1;
    ll ansv = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i].empty()) continue;

        ll xl, xr, yl, yr;
        xl = xr = A[i][0].x;
        yl = yr = A[i][0].y;

        for (auto [a, b] : A[i]) {
            xl = min(xl, a);
            xr = max(xr, a);

            yl = min(yl, b);
            yr = max(yr, b);
        }

        ll aval = (xr - xl + 1) * (yr - yl + 1);

        if (aval > ansv) {
            ansv = aval;
            ans = i;
        }
    }

    cout << ans << ' ' << ansv << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}