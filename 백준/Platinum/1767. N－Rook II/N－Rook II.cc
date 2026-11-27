#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1000001;
ll dp[101][101][101];

ll getDp(ll n, ll m, ll k) {
    if (n > m) swap(n, m);
    if (n < 0 || k < 0) return 0;
    if (dp[n][m][k] != -1) return dp[n][m][k];
    if (k == 0) return dp[n][m][k] = 1;
    if (n == 0) return dp[n][m][k] = 0;

    int res = (getDp(n - 1, m - 1, k) + getDp(n - 1, m - 1, k - 1)) % mod;
    (res += (m - 1) * getDp(n - 1, m - 2, k - 1) % mod) %= mod;
    (res += (n - 1) * getDp(n - 2, m - 1, k - 1) % mod) %= mod;
  //  if (n + m + k == 8) cout << "GEt 11: " << n << ' ' << m << ' ' << k << " | " << res << '\n';
    (res += (m - 1) * (n - 1) * getDp(n - 2, m - 2, k - 2) % mod) %= mod;
    (res += (n - 1) * getDp(n - 2, m - 1, k - 2) % mod) %= mod;
    (res += (m - 1) * getDp(n - 1, m - 2, k - 2) % mod) %= mod;
    (res += (n - 1) * (n - 2) / 2 * getDp(n - 3, m - 1, k - 2) % mod) %= mod;
    (res += (m - 1) * (m - 2) / 2 * getDp(n - 1, m - 3, k - 2) % mod) %= mod;
   // if (n + m + k == 8) cout << "GEt 12: " << n << ' ' << m << ' ' << k << " | " << res << '\n';
    (res += (n - 2) * (n - 1) / 2 * (m - 1) * getDp(n - 3, m - 2, k - 3) % mod) %= mod;
    (res += (m - 2) * (m - 1) / 2 * (n - 1) * getDp(n - 2, m - 3, k - 3) % mod) %= mod;
    //if (n + m + k == 8) cout << "GEt 13: " << n << ' ' << m << ' ' << k << " | " << res << '\n';
    (res += (m - 2) * (m - 1) / 2 * (n - 2) * (n - 1) / 2  % mod * getDp(n - 3, m - 3, k - 4) % mod) %= mod;
   // if (n + m + k == 8) cout << "GEt 1: " << n << ' ' << m << ' ' << k << " | " << res << '\n';

    (res += 2 * (n - 1) * (m - 1) * getDp(n - 2, m - 2, k - 2) % mod) %= mod;
    (res += (n - 1) * (m - 1) % mod * (n - 2) % mod * getDp(n - 3, m - 2, k - 3) % mod) %= mod;
    (res += (n - 1) * (m - 1) % mod * (n - 2) * (n - 3) / 2 % mod * getDp(n - 4, m - 2, k - 4) % mod) %= mod;
   // if (n + m + k == 8) cout << "GEt 2: " << n << ' ' << m << ' ' << k << " | " << res << '\n';

    (res += (m - 1) * (n - 1) % mod * (m - 2) % mod * getDp(n - 2, m - 3, k - 3) % mod) %= mod;
    (res += (m - 1) * (n - 1) % mod * (m - 2) * (m - 3) / 2 % mod * getDp(n - 2, m - 4, k - 4) % mod) %= mod;
  //  if (n + m + k == 8) cout << "GEt 3: " << n << ' ' << m << ' ' << k << " | " << res << '\n';

    (res += (m - 2) * (m - 1) * (n - 1) * (n-2) % mod * getDp(n - 3, m - 3, k - 4) % mod) %= mod;
   // cout << "GEt: " << n << ' ' << m << ' ' << k << " | " << res << '\n';
    return dp[n][m][k] = res;
}


void solve() {
    memset(dp, -1, sizeof(dp));
    int n, m, k;
    cin >> n >> m >> k;
    cout << getDp(n, m, k);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
