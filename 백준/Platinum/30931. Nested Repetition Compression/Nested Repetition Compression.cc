#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
string s;
int dp[222][222];
string ans[222][222];

int getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) {
        ans[l][r] = s[l];
        return dp[l][r] = 1;
    }

    int res = r - l + 1;
    string tans = s.substr(l, r-l+1);
    for (int i = l; i < r; i++) {
        int v1 = getDp(l, i);
        int v2 = getDp(i + 1, r);
        res = min(res, v1 + v2);
        if (res == v1 + v2) {
            tans = ans[l][i] + ans[i + 1][r];
        }
    }

    int len = r - l + 1;
    for (int i = 2; i <= 9; i++) {
        if (len % i == 0) {

            // check multiply

            string ts = s.substr(l, len / i);

            bool ok = 1;
            for (int j = l + len / i; j <= r; j++) {
                if (ts[(j - l) % (len/i)] != s[j]) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                int v = getDp(l, l + len / i - 1);
                if (v + 3 < res) {
                    res = v + 3;
                    tans = char('0' + i);
                    tans += '(';
                    tans += ans[l][l + len / i - 1];
                    tans += ')';
                }
            }
        }
    }

    ans[l][r] = tans;
    return dp[l][r] = res;

}
void solve() {

    cin >> s;

    n = s.size();

    memset(dp, -1, sizeof(dp));

    getDp(0, n - 1);
    cout << ans[0][n-1];
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}