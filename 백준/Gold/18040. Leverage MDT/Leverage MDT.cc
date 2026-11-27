#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    vector<vector<int>> dp(2, vector<int>(m)), tmp(2, vector<int>(m));

    int ans = 1;
    for (int i = 0; i < m; i++) {
        if (A[0][i] == 'G') {
            dp[0][i] = 1;
            dp[1][i] = 0;
        }
        else {
            dp[1][i] = 1;
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {

        if (A[i][0] == 'G') {
            tmp[0][0] = 1;
            tmp[1][0] = 0;
        }
        else {
            tmp[1][0] = 1;
            tmp[0][0] = 0;
        }

        for (int j = 1; j < m; j++) {
            if (A[i][j] == 'G') {
                tmp[1][j] = 0;
                int tm = max(min(dp[0][j - 1], dp[0][j]), min(dp[1][j - 1], dp[1][j]));
                tmp[0][j] = min(tm, tmp[0][j - 1]) + 1;
            }
            else {
                tmp[0][j] = 0;
                int tm = max(min(dp[0][j - 1], dp[0][j]), min(dp[1][j - 1], dp[1][j]));
                tmp[1][j] = min(tm, tmp[1][j - 1]) + 1;
            }

            ans = max({ ans, tmp[1][j], tmp[0][j] });
        }

        swap(tmp, dp);
    }

    cout << ans*ans;
}