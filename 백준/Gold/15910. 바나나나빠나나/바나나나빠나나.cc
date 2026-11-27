#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 0x3f3f3f3f;
int dp[6][101010];

void solve() {

    string s;
    cin >> s;
    memset(dp, INF, sizeof dp);

    vector<pair<pair<int, int>, char>> trans;
    trans.push_back(mp(mp(0, 0), 'B'));
    trans.push_back(mp(mp(0, 1), 'A'));
    trans.push_back(mp(mp(1, 2), 'N'));
    trans.push_back(mp(mp(2, 3), 'A'));
    trans.push_back(mp(mp(3, 4), 'N'));
    trans.push_back(mp(mp(4, 5), 'A'));
    trans.push_back(mp(mp(5, 4), 'N'));
    trans.push_back(mp(mp(5, 0), 'B'));

    if (s[0] == 'B') {
        dp[0][0] = 0;
    }
    else dp[0][0] = 1;

    int n = s.size();
    for (int i = 1; i < n; i++) {
        for (auto& f : trans) {
            auto [u, v] = f.x;
            char c = f.y;

            dp[v][i] = min(dp[v][i], dp[u][i - 1] + (s[i] != c));
        }
    }

    cout << dp[5][n - 1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}