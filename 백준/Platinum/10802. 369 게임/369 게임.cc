#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 20150523;
int dp[3][101010];
int dp2[3][101010];

int getVal(string s) {
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));

    int sn = s.size();
    dp[0][0] = 1;
    for (int i = 0; i < sn; i++) {
        int val = s[i] - '0';
        for (int j = 0; j <= val; j++) {
            if (j % 3 == 0 && j) continue;
            if (j < val) {
                for (int k = 0; k < 3; k++) {
                    int nk = (k + j) % 3;
                    dp2[nk][i + 1] += dp[k][i];
                    dp2[nk][i + 1] %= mod;
                }
            }
            else {
                for (int k = 0; k < 3; k++) {
                    int nk = (k + j) % 3;
                    dp[nk][i + 1] += dp[k][i];
                    dp[nk][i + 1] %= mod;
                }
            }
        }

        for (int j = 0; j <= 9; j++) {
            if (j % 3 == 0 && j) continue;
            for (int k = 0; k < 3; k++) {
                int nk = (k + j) % 3;
                dp2[nk][i + 1] += dp2[k][i];
                dp2[nk][i + 1] %= mod;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= 2; i++) {
        res += dp[i][sn] + dp2[i][sn];
        res %= mod;
    }
    return res;
}

void solve() {

    string a, b;
    cin >> a >> b;

    int ans = (getVal(b) - getVal(a) + mod) % mod;

    bool ok = 1;
    int vv = 0;
    for (auto f : a) {
        int tv = f - '0';
        if (tv && tv % 3 == 0) ok = 0;
        vv = (vv + tv) % 3;
    }
    if (vv == 0) ok = 0;

    int valB = 0, valA = 0;
    for (auto f : a) {
        valA = valA * 10 + f - '0';
        valA %= mod;
    }
    for (auto f : b) {
        valB = valB * 10 + f - '0';
        valB %= mod;
    }

    int res = (valB - valA + mod) % mod;
    ans = (res - ans + mod) % mod;
    if (!ok) ans = (ans + 1) % mod;
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}