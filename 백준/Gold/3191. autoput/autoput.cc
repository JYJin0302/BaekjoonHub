#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dp[30303][1010];

void solve() {

    int a, b, c;
    cin >> a >> b >> c;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int mn = 0;
    vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            h[i + 1] = h[i];
        }
        else if (s[i] == 'G') {
            h[i + 1] = h[i] + 1;
        }
        else {
            h[i + 1] = h[i] - 1;
            mn = min(mn, h[i + 1]);
        }
    }

    for (auto& f : h) f -= mn;

    vector<int> pos(n + 1, -1);
    pos[h[0]] = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[h[i]] == i - 1) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j] + a;
            }
            pos[h[i]] = i;
            continue;
        }


        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] + b;
        }

        if (pos[h[i]] == -1) {
            pos[h[i]] = i;
            continue;
        }

        int pi = pos[h[i]];

        for (int j = 1; j <= k; j++) {
            dp[i][j] = min(dp[i][j], dp[pi][j - 1] + (i - pi) * c);
        }
        pos[h[i]] = i;
    }

    cout << dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}