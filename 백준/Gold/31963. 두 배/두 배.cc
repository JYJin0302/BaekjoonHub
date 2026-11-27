#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;
    vector<pair<ll, ll>> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int cnt = 0;
        while ((x & 1) == 0) {
            cnt++;
            x >>= 1;
        }

        A.push_back(mp(x, cnt));
    }
    
    ll ans = 0;
    for (int i = 1; i < n; i++) {

        auto [a, b] = A[i - 1];
        auto [c, d] = A[i];

        if (a >= c) {
            int tmp = (a + c - 1) / c;
            ll v = ceil(log2(tmp));

            if (b + v <= d) {
                // ok
                continue;
            }
            ans += b + v - d;
            A[i].y += b + v - d;
        }
        else {

            int tmp = (c + a - 1) / a;
            ll v = ceil(log2(tmp));

            if (b - v < d) {
                // ok
                continue;
            }
            A[i].y += b - v + 1 - d;
            ans += b - v + 1 - d;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}