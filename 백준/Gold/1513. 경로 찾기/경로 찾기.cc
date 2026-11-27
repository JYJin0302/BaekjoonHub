#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[51][51];
ll dp[51][51][51][51];
// dp[i][j][a][b] : (i, j) 방문 시 오락실 최고 번호 : a, 방문 개수 : b

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;

    const int mod = 1000007;

    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        A[a][b] = i + 1;
    }

    dp[1][1][A[1][1]][A[1][1] != 0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + j == 2) continue;

            int v = A[i][j];

            if (v == 0) {

                for (int k = 0; k <= c; k++) {
                    for (int w = 0; w <= c; w++) {
                        dp[i][j][k][w] = dp[i - 1][j][k][w] + dp[i][j - 1][k][w];
                        dp[i][j][k][w] %= mod;
                    }
                }
            }
            else {

                for (int k = 0; k < v; k++) {
                    for (int w = 1; w <= c; w++) {
                        dp[i][j][v][w] += dp[i - 1][j][k][w-1] + dp[i][j-1][k][w-1];
                        dp[i][j][v][w] %= mod;
                    }
                    
                }

            }
        }
    }

    for (int i = 0; i <= c; i++) {
        int ans = 0;
        for (int j = 0; j <= c; j++) {
            ans += dp[n][m][j][i];
            ans %= mod;
        }
        cout << ans << ' ';
    }
}