#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1999;
ll cnt[101];
ll dp[1010100];

void solve() {

    int n, m;
    cin >> n >> m;

    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cnt[i] += cnt[j];
            cnt[i] %= mod;
        }
    }
    for (int i = 1; i < n; i++) cnt[i] = 1;

    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; i - j >= 0 && j <= n; j++) {
            dp[i] += dp[i - j] * cnt[j] % mod;
            dp[i] %= mod;
        }
    }
    cout << dp[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}