#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[16][16];

void move(int fx, int fy, int tx, int ty) {
    for (int i = fx; i <= tx; i++) {
        for (int j = fy; j <= ty; j++) {
            if (i == fx || j == fy) dp[i][j] = dp[fx][fy];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}


int main() {
    int n, m, k, kx, ky;
    cin >> n >> m >> k;

    dp[1][1] = 1;
    if (k == 0) {
        move(1, 1, n, m);
        cout << dp[n][m];
        return 0;
    }

    kx = k / m + 1;
    ky = k % m;
    if (ky == 0) { ky += m; kx--; }

    move(1, 1, kx, ky);
    move(kx, ky, n, m);
    
    cout << dp[n][m];

}