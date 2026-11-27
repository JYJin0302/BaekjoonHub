#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>

bool t[2010][2010];
int dp[2010][2010];

void solve() {

    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        t[a][b] = 1;
    }

    dp[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(mp(0, 0));

    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front(); q.pop();
        dp[a][b] = max(dp[a][b], b);

        if (a == n * 2) break;

        if (dp[a + 1][b + 1] == -1 && !t[a+1][b+1]) q.push(mp(a + 1, b + 1));
        dp[a + 1][b + 1] = max(dp[a + 1][b + 1], dp[a][b]);
        if (b > 0) {
            if (dp[a + 1][b - 1] == -1 && !t[a + 1][b - 1]) q.push(mp(a + 1, b - 1));
            dp[a + 1][b - 1] = max(dp[a + 1][b - 1], dp[a][b]);
        }
    }

    int res = dp[n * 2][0];
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}