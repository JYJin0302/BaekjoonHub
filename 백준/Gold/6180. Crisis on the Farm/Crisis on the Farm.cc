#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int cnt[100][100];
int dp[33][100][100];
int from[33][100][100];

int dx[] = { 1, 0, 0, -1};
int dy[] = { 0, 1, -1, 0};
bool inGrid(int x, int y) {
    return x >= 0 && x < 100 && y >= 0 && y < 100;
}
string ans[33][101][101];

void solve() {
    string ss = "ENSW";

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> A(n), B(m);
    for (auto& i : A) cin >> i.x >> i.y;
    for (auto& i : B) cin >> i.x >> i.y;

    for (auto& [a, b] : A) {
        for (auto& [c, d] : B) {
            if (abs(c-a) + abs(d-b) <= 33) cnt[c - a + 50][d - b + 50]++;
        }
    }

    memset(dp, -1, sizeof dp);
    dp[0][50][50] = 0;

    for (int t = 0; t < k; t++) {
        for (int a = 0; a < 100; a++) {
            for (int b = 0; b < 100; b++) {
                if (dp[t][a][b] == -1) continue;
                for (int i = 0; i < 4; i++) {
                    int na = a + dx[i];
                    int nb = b + dy[i];

                    if (dp[t + 1][na][nb] == dp[t][a][b] + cnt[na][nb]) {
                        string tt = ans[t][a][b] + ss[i];
                        if (ans[t + 1][na][nb].empty() || ans[t + 1][na][nb] > tt) ans[t + 1][na][nb] = tt;
                    }
                    else if (dp[t + 1][na][nb] < dp[t][a][b] + cnt[na][nb]) {
                        string tt = ans[t][a][b] + ss[i];
                        ans[t + 1][na][nb] = tt;
                    }
                    dp[t + 1][na][nb] = max(dp[t + 1][na][nb], dp[t][a][b] + cnt[na][nb]);
                }
            }
        }
    }

    int mx = 0;
    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            mx = max(mx, dp[k][a][b]);
        }
    }
    //cout << mx << '\n';
    vector<string> ansL;
    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            if (dp[k][a][b] == mx) ansL.push_back(ans[k][a][b]);
        }
    }

    sort(all(ansL));

    cout << mx << '\n' << ansL[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}