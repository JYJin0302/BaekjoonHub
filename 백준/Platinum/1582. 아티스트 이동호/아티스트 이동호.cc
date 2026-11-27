#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m, k;
char G[55][55];
int C[55][55];

int dp[55][55][55];
int getDp(int l, int r, int c, int ix) {
    if (c == 0) return 0;
    if (dp[l][r][c] != -1) return dp[l][r][c];

    if (c >= r - l + 1) {
        return dp[l][r][c] = r - l + 1;
    }
    if (c == 1) {
        int val = C[ix][r] - C[ix][l - 1];
        val = max(val, r - l + 1 - val);
        return dp[l][r][c] = val;
    }

    int ret = 0;
    for (int i = l; i < r; i++) {
        ret = max(ret, getDp(l, i, 1, ix) + getDp(i + 1, r, c - 1, ix));
    }
    return dp[l][r][c] = ret;
}

vector<int> res[55];

void solve() {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
            C[i][j] = (G[i][j] == 'W');
            C[i][j] += C[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(dp, -1, sizeof dp);
        for (int j = 0; j <= min(m, k); j++) {
            res[i].push_back(getDp(1, m, j, i));            
        }
    }


    vector<int> ndp(k + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> tmp(k + 1);
        for (int j = 0; j < res[i].size(); j++) {
            for (int f = 0; f + j <= k; f++) {
                tmp[f + j] = max(tmp[f + j], ndp[f] + res[i][j]);
            }
        }

        ndp = tmp;
    }

    cout << n*m - ndp[k] << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}