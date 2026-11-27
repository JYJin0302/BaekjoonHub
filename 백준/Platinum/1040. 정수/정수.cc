#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using ll = unsigned long long;

int cntb(int i) {
    i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
    i = (i & 0x00ff00ff) + ((i >> 8) & 0x00ff00ff);
    i = (i & 0x0000ffff) + ((i >> 16) & 0x0000ffff);
    return i;
}

void pf(int x) {
    for (int i = 0; i < 10; i++) {
        if (x & (1 << i)) cout << i;
    }
}

ll dp[2][20][1 << 10];
// dp[t][x][bit] : x 번째까지 채웠을 때 bit개를 사용 : t : prefix와 같은지 여부

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, LLONG_MAX, sizeof(dp));

    string s;
    cin >> s;

    while (s.size() < 19) {
        s = '0' + s;
    }

    int k;
    cin >> k;
    int n = 19;

    dp[1][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int currx = s[i - 1] - '0';
        for (int j = 0; j < (1 << 10); j++) {
            if (dp[1][i - 1][j] != LLONG_MAX) {
                int tj = j | (1 << currx);

                if (currx == 0 && dp[1][i - 1][j] == 0) tj = 0;
                ll nv = dp[1][i - 1][j] * 10 + currx;
                if (nv >= 0) dp[1][i][tj] = min(dp[1][i][tj], nv);

                
                for(int k = currx+1; k <= 9; k++){
                    tj = j | (1 << k);

                    nv = dp[1][i - 1][j] * 10 + k;
                    if (nv > 0) dp[0][i][tj] = min(dp[0][i][tj], nv);
                }
            }

            if (dp[0][i - 1][j] != LLONG_MAX) {

                for (int k = 0; k < 10; k++) {
                    ll nv = dp[0][i - 1][j] * 10 + k;
                    int tj = j | (1 << k);
                    if (nv >= 0) dp[0][i][tj] = min(dp[0][i][tj], nv);
                }
            }
        }
    }

    ll ans = LLONG_MAX;

    //for (int k = 0; k <= n; k++) {

    //    cout << "Go dp :" << k << '\n';
    //    for (int j = 0; j < (1 << 10); j++) {
    //        cout << "RES: ";
    //        pf(j);
    //        cout << '\n';

    //        for (auto i : { dp[0][k][j], dp[1][k][j] }) {
    //            if (i != INF) cout << i << ' ';
    //            else cout << "X ";
    //        }
    //        cout << '\n';
    //    }
    //}

    for (int j = 0; j < (1 << 10); j++) {
        if (cntb(j) == k) {
             ans = min(ans, dp[0][n][j]);
        }
        if (cntb(j) == k) {
            ans = min(ans, dp[1][n][j]);
        }
    }
    cout << ans;
}
