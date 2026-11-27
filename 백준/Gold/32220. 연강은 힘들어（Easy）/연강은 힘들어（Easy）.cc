#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


const int mod = 1e9 + 7;

ll dp[2][3030];
ll tdp[2][3030];

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        memset(tdp, 0, sizeof tdp);

        for (int j = 1; j <= k; j++) {
            (tdp[0][j] += dp[0][j - 1]) %= mod;
            (tdp[0][0] += dp[0][j - 1]) %= mod;


            (tdp[1][j] += dp[1][j - 1]) %= mod;
            (tdp[1][0] += dp[1][j - 1]) %= mod;
        }

        (tdp[1][0] += dp[0][k]) %= mod;
        (tdp[1][0] += dp[1][k]) %= mod;

        swap(dp, tdp);

        /*cout << "cur: " << i << '\n';
        for (int j = 0; j <= k; j++) cout << dp[0][j] << ' ';
        cout << '\n';
        for (int j = 0; j <= k; j++) cout << dp[1][j] << ' ';
        cout << '\n';*/
    }

    cout << dp[1][0];



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}