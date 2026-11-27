#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


ll n, k;
string ans;

ll dp[55][55];
ll getDp(int x, int len) {
    if (x < 0) return 0;
    if (dp[x][len] != -1) return dp[x][len];
    if (len == 0) {
        if (x == 0) return dp[x][len] = 1;
        return dp[x][len] = 0;
    }

    ll res = getDp(x + 1, len - 1) + getDp(x - 1, len-1);
    return dp[x][len] = res;
}


void goSolve(int pos, ll k, int cnt = 0, bool neg = 0) {
    // try '('
    if (cnt < 0) neg = 1;
    if (pos == n) {
        if (k == 0) cout << ans;
        else cout << -1;
        return;
    }

    ll tot = (1ll << n - pos - 1);
    ll able = 0;
    if (!neg) able = getDp(cnt + 1, n - pos - 1);

    if (tot - able > k) {
        ans[pos] = '(';
        goSolve(pos + 1, k, cnt + 1, neg);
        return;
    }
    // try ')'
    ans[pos] = ')';
    k -= tot - able;
    goSolve(pos + 1, k, cnt - 1, neg);
}

void solve() {
    cin >> n >> k;
    ans = string(n, '_');
    goSolve(0, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int t = 1;
    //cin >> t;
    while (t--) solve();
}