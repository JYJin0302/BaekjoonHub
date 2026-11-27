#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 1e9;
bool isEqual(char c1, char c2) {
    if (c1 == c2)return 1;
    if (c1 == 'i') {
        return c2 == 'j' || c2 == 'l';
    }
    if (c1 == 'v') return c2 == 'w';
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int j = 1; j <= m; j++) dp[0][j] = j;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (isEqual(s1[i-1], s2[j-1])) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
            }
        }
    }

    cout << dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}