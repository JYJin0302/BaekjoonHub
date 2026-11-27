#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, lim;
int dp[5][2525];
int getDp(int cnt, int len) {
    if (dp[cnt][len] != -1) return dp[cnt][len];
    if (cnt > len) return dp[cnt][len] = 0;
    if (cnt == 1) {
        if (len >= lim) return dp[cnt][len] = 0;
        return dp[cnt][len] = 1;
    }
    int res = 0;
    for (int i = 1; i < lim; i++) {
        res += getDp(cnt - 1, len - i);
    }
    return dp[cnt][len] = res;

}
void solve() {

    memset(dp, -1, sizeof dp);
    cin >> n;
    lim = (n + 1) / 2;
    cout << getDp(4, n);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}