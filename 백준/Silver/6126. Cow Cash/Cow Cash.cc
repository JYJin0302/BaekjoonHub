#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll dp[10101];

void solve() {

    dp[0] = 1;
    int v, n;
    cin >> v >> n;

    for (int i = 0; i < v; i++) {
        int x;
        cin >> x;

        for (int j = x; j <= n; j++) dp[j] += dp[j - x];
    }
    cout << dp[n];


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}