#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll cnt[2020][2020];
int dp[2020][2020];

string s;
int isOk(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] == s[r] || s[l] == '<') return dp[l][r] = 0;
    if (r - l == 1 || isOk(l+1, r-1)) return dp[l][r] = 1;
    return dp[l][r] = 0;
}

void solve() {

    int n;
    cin >> n; 
    cin >> s;

    cnt[0][n - 1] = 1;
    for (int d = n - 1; d >= 0; d--) {
        for (int i = 0; i + d < n; i++) {
            int l = i, r = i + d;
            if (l < r) {
                (cnt[l + 1][r] += cnt[l][r]) %= mod;
                (cnt[l][r - 1] += cnt[l][r]) %= mod;
            }
        }
    }

    memset(dp, -1, sizeof dp);

    ll ans = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            if (isOk(a, b)) ans = (ans + cnt[a][b]) % mod;
        }
    }
    cout << ans << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}