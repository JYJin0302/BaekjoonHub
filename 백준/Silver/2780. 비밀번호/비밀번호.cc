#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1234567;
int dp[11][1010];

vector<int> adj[11];

void solve() {

    adj[0].push_back(7);
    adj[7].push_back(0);

    for (int i = 0; i < 9; i++){
        int x1 = i / 3, y1 = i % 3;
        for (int j = i + 1; j < 9; j++) {
            int x2 = j / 3, y2 = j % 3;

            if (abs(x2 - x1) + abs(y2 - y1) == 1) {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }

    int n = 1000;

    for (int i = 0; i <= 9; i++) dp[i][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (auto f : adj[j]) {
                (dp[j][i] += dp[f][i - 1]) %= mod;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int ans = 0;
        for (int i = 0; i <= 9; i++) (ans += dp[i][x]) %= mod;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}