#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, q;
string s;
int dp[5050][5050];
int dp2[5050][5050];
int getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l >= r) return dp[l][r] = 0;
    int len = r - l + 1;
    if (len & 1) return dp[l][r] = 0;
    return dp[l][r] = getDp(l + 1, r - 1) + (s[l] == s[r]);
}

int getDp2(int l, int r) {
    if (dp2[l][r] != -1) return dp2[l][r];
    if (l >= r) return dp2[l][r] = 0;
    int res = dp[l][r];
    return dp2[l][r] = max({ res, getDp2(l + 1, r), getDp2(l, r - 1) });
}

void solve() {

    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    cin >> n;
    cin >> s;

    s = '?' + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) getDp(i, j);
    }


    cin >> q;
    while (q--) {
        int l, r; 
        cin >> l >> r;

        cout << getDp2(l, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}