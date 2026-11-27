#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
void solve() {

    int n;
    cin >> n;

    vector<ll> dp(5);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<ll> tmp(5);
        tmp[0] = dp[0] * 25 % mod;
        tmp[1] = (dp[0] + dp[1] * 25 % mod) % mod;
        tmp[2] = (dp[1] + dp[2] * 25 % mod) % mod;
        tmp[3] = (dp[2] + dp[3] * 25 % mod) % mod;
        tmp[4] = (dp[3] + dp[4] * 26 % mod) % mod;
        swap(dp, tmp);
    }

    cout << dp[4];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}