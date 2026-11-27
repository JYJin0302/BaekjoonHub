#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int MAXN = 200000;
int nxt[202020];

void solve() {

    int n;
    cin >> n;

    for (int j = 0; j <= MAXN; j++) {
        nxt[j] = MAXN + 10;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        nxt[a] = min(nxt[a], a + b);
    }

    int ans = 0;
    vector<int> dp(MAXN + 100);
    for (int i = 1; i <= MAXN; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        dp[nxt[i]] = max(dp[nxt[i]], dp[i] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}