#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair


void solve() {

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    vector<ll> B(m);
    for (auto& i : B) {
        cin >> i;
        i *= 2;
    }

    sort(B.begin(), B.end());

    vector<ll> sA(n);
    sA[0] = A[0];
    for (int i = 1; i < n; i++) sA[i] = sA[i - 1] + A[i];

    ll ans = 0;

    int ix = 0;
    while (ix < n && ix * 200 < B[0]) ix++;

    if (ix > 0)ans = sA[ix-1];

    for (int i = 1; i < m; i++) {
        if (ix == n) break;

        if (ix * 200 == B[i - 1]) ix++;

        int l = ix;

        while (ix < n && ix * 200 < B[i]) ix++;

        int r = ix - 1;

        if (l > r) continue;

        ll tans = 0;
        int tl = l, tr = l;

        for (int f = l; f <= r; f++) {

            int npos = f * 400 - B[i - 1];

            while (tr < ix && tr * 200 < min(B[i], (npos + B[i])/ 2)) {
                tans += A[tr++];
            }

            while (tl < f) {
                tans -= A[tl++];
            }

            //cout << tl << ' ' << tr << '\n';
            ans = max(ans, tans);
        }

    }
    if (ix * 200 == B[m - 1]) ix++;

    ll tans = 0;
    while (ix < n) tans += A[ix++];

    ans = max(ans, tans);


    cout << ans << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}