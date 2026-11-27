#include <bits/stdc++.h>
using namespace std;
using ld = long double;

bool dp[66][10010]; // 개수, 길이

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int j = i; j >= 0; j--) {
            for (int k = 10000-x; k>= 0; k--) {
                if (dp[j][k]) dp[j + 1][k + x] = 1;
            }
        }
    }

    ld ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = m-10; j <= 10000; j++) {
            if (dp[i][j]) {

                ld tans = j - (m - 10);
                tans /= i + 1;

                if (tans <= 5) ans = max(ans, tans);

            }
        }
    }
    if (ans == -1) cout << "impossible";
    else cout << ans;

}