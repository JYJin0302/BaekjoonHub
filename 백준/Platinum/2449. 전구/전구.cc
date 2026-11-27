#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int n, k;
vector<int> A;
int dp[201][201][25];

int solve(int l, int r, int c) {

    if (dp[l][r][c] != 2000) return dp[l][r][c];
    if (l == r) {
        return dp[l][r][c] = 1 - (A[l] == c);
    }

    int res = 2000;
    for (int i = l; i < r; i++) {
        res = min(res, solve(l, i, c) + solve(i+1, r, c));
    }

    return dp[l][r][c] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> k;

    A = vector<int> (n);
    for (auto& i : A) cin >> i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int c = 1; c <= k; c++) {
                dp[i][j][c] = 2000;
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + i > n - 1) continue;
            int minv = 2000;
            for (int c = 1; c <= k; c++) {
                minv = min(minv, solve(j, j+i, c));
            }

            for (int c = 1; c <= k; c++) {
                dp[j][j+i][c] = min(dp[j][j+i][c], minv + 1);
            }
        }
    }
    

    int ans = 2000;
    for (int i = 1; i <= k; i++) ans = min(ans, dp[0][n-1][i]);
    cout << ans;
}