#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll f[100010], rev[100010];
ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}
ll dp[5005], tmp[5005];
ll C(int n, int r) {
    if (r > n) return 0;
    ll res = f[n];
    res = res * rev[r] % mod;
    res = res * rev[n-r] % mod;
    return res;
}

void solve() {

    f[0] = 1;
    for (ll i = 1; i <= 100000; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    for (int i = 0; i <= 100000; i++) {
        rev[i] = fastPow(f[i], mod - 2, mod);
    }

    int n, m;
    cin >> n >> m;
    vector<int> A(n), sA(n);
    for (auto& i : A) cin >> i;
    sort(all(A));
    sA[0] = A[0];
    for (int i = 1; i < n; i++) sA[i] = sA[i - 1] + A[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++) {

        if (A[i] == m) break;
        memset(tmp, 0, sizeof(tmp));

        for (int d2 = 0; d2 <= A[i]; d2++) {
            if (dp[d2] == 0) continue;
            int d1 = i * m - 2 * d2 - (i ? sA[i-1] : 0);
            int rem = A[i] - d2;
            for (int j = A[i] + d1 - m; j <= min(d1, rem); j++) {
                int nd2 = d2 + d1 - j;
                int nd1 = j;
                ll tval = dp[d2];
                tval = tval * C(d1, j) % mod;
                tval = tval * C(m - d1 - d2, A[i] - d2 - j) % mod;
                tmp[nd2] = (tmp[nd2] + tval) % mod;
            }
        }
        swap(tmp, dp);

        /*for (int j = 0; j <= m; j++) cout << dp[j] << ' ';
        cout << '\n';*/
    }

    ll res = 0;
    for (int i = 0; i <= m; i++) res = (res + dp[i]) % mod;
    cout << res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}