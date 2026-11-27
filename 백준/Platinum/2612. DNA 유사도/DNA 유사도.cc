#include <bits/stdc++.h>
using namespace std;

int n, m;
string A[2];

int dp[1010][1010];
int from[1010][1010];

// 3 1
// 2 0
int dx[] = { 0, -1, 0, -1 };
int dy[] = { 0, 0, -1, -1 };

int solve(int l, int r) {

    if (l < 0 || r < 0) return 0;
    if (dp[l][r] != -5000) return dp[l][r];

    vector<pair<int, int>> res;
    res.push_back({ solve(l - 1, r - 1) + ((A[0][l] == A[1][r]) ? 3 : -2), 3 });
    res.push_back({solve(l - 1, r) - 2, 1});
    res.push_back({solve(l, r - 1) - 2, 2});
    res.push_back({ 0, 0 });
    sort(res.rbegin(), res.rend());

    from[l][r] = res[0].second;
    return dp[l][r] = res[0].first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> A[0];
    cin >> m >> A[1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -5000;
        }
    }

    int mx = -1;
    int mi = -1, mj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (solve(i, j) > mx) {
                mx = solve(i, j);
                mi = i, mj = j;
            }
        }
    }

    cout << mx << '\n';
    string ans1, ans2;
    ans1 += A[0][mi];
    ans2 += A[1][mj];
    while (1) {
        
        if (mi < 0 || mj < 0) break;
       // cout << mi << ' ' << mj << '\n';
        int nx = from[mi][mj];
        mi += dx[nx];
        mj += dy[nx];


        if (mi < 0 || mj < 0 || nx == 0 || dp[mi][mj] == 0) break;
        if (dx[nx]) ans1 += A[0][mi];
        if (dy[nx]) ans2 += A[1][mj];
    }

    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());

    cout << ans1 << '\n' << ans2;
}