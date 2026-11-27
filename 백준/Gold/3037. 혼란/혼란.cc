#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll mod = 1e9 + 7;

void solve() {

    int n, c;
    cin >> n >> c;

    vector<ll> dp(c + 1);
    dp[0] = 1;

    for (int i = 2; i <= n; i++) {
        vector<ll> tmp(c + 1);
        ll val = 0;
        for (int j = 0; j <= c; j++) {
            val += dp[j];
            if (j >= i) val -= dp[j - i];
            val = ((val % mod) + mod) % mod;
            tmp[j] = val;
        }

        swap(dp, tmp);
    }
    cout << dp[c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}