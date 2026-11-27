#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double dp[11][11], dp2[4][4];

long double getP(long double p1, long double p2) {
    long double res = 0;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < 20; i++) {

        long double win1, win2;
        if (i % 4 < 2) {
            win1 = p1;
            win2 = 1 - p1;
        }
        else {
            win1 = 1 - p2;
            win2 = p2;
        }

        for (int j = 0; j <= i; j++) {
            // current score : j, i-j
            if (i - j > 10 || j > 10) continue;

            if (j + 1 == 11) {
                res += dp[j][i - j] * win1;
            }

            if (j + 1 < 11) {
                dp[j + 1][i - j] += dp[j][i - j] * win1;
            }
            if (i - j + 1 < 11) {
                dp[j][i - j + 1] += dp[j][i - j] * win2;
            }
        }
    }

    //cout << ans << ' ' << dp[10][10] << '\n';

    long double pa = p1 * p2 + (1 - p1) * (1 - p2);
    long double pw = p1 * (1 - p2), pl = (1 - p1) * p2;

    if (pa != 1) {
        res += dp[10][10] * pw / (1 - pa);
    }
    return res;
}

void solve() {

    long double p1, p2;
    cin >> p1 >> p2;

    long double p1Win = getP(p1, p2);
    long double p2Win = getP(p2, p1);


    // player1이 처음 서브한 게임에서 pWin : 이길 확률, pLose: 질 확률
    // 7전 4선승제
    long double ans = 0;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            dp2[i][j] = 0;
        }
    }
    
    dp2[0][0] = 1;
    for (int i = 0; i < 7; i++) {

        long double win1, win2;
        if (i & 1) {
            win1 = 1 - p2Win;
            win2 = p2Win;
        }
        else {
            win1 = p1Win;
            win2 = 1 - p1Win;
        }

        for (int j = 0; j <= i; j++) {
            // set score : j, i-j
            if (j > 3 || i - j > 3) continue;

            if (j + 1 == 4) ans += dp2[j][i - j] * win1;

            if (j + 1 < 4) dp2[j + 1][i - j] += dp2[j][i - j] * win1;
            if (i - j + 1 < 4) dp2[j][i - j + 1] += dp2[j][i - j] * win2;
        }
    }

    cout << ans << '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}