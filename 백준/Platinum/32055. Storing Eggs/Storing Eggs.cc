#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, k;
    cin >> n >> k;

    vector<string> A(3);
    for (auto& i : A) cin >> i;

    int cnt = 0;
    for (auto f : A) {
        for (auto v : f) {
            if (v == '.') cnt++;
        }
    }
    if (cnt < k) {
        cout << -1 << '\n';
        return;
    }

    int l = 6, r = 4 + (n - 1) * (n - 1), ans = 0;
    while (l <= r) {
        int md = (l + r) >> 1;
        //cout << "Go: " << md << '\n';
        vector<vector<int>> dp(3, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {

                if (A[j][i] == '.') {
                    dp[j][i] = 1;

                    for (int tj = 0; tj < 3; tj++) {
                        int rem = md - (j - tj) * (j - tj);

                        int di = sqrt(rem);
                        if (di * di < rem) di++;

                        if (i - di >= 0) dp[j][i] = max(dp[j][i], dp[tj][i - di] + 1);
                    }
                }

                if (i) dp[j][i] = max(dp[j][i], dp[j][i-1]);
            }
        }

        if (max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] }) >= k) {
            ans = md;
            l = md + 1;
        }
        else r = md - 1;
    }

    cout << fixed << setprecision(10);
    if (ans != 0) {
        cout << sqrtl(ans) << '\n';
        return;
    }

    // try 5

    vector<vector<int>> ttdp(5, vector<int>(n));
    for (int i = 0; i < n; i++) {

        vector<int> cnt(3);
        for (int j = 0; j < 3; j++) {
            if (A[j][i] == '.') cnt[j]++;
        }

        for (int j = 0; j < 3; j++) {
            ttdp[j][i] = cnt[j];
        }
        ttdp[3][i] = cnt[0];
        ttdp[4][i] = cnt[2];

        if (i) {
            for (int j = 0; j < 5; j++) ttdp[j][i] = max(ttdp[j][i], ttdp[j][i - 1]);
            ttdp[3][i] = max(ttdp[3][i], cnt[0] + ttdp[2][i - 1]);
            ttdp[4][i] = max(ttdp[4][i], cnt[2] + ttdp[0][i - 1]);
        }

        if (i >= 2) {
            for (int j = 0; j < 3; j++) {
                for (int tj = 0; tj < 5; tj++) {
                    if (j != tj || (j == 0 && tj != 3) || (j == 2 && tj != 4)) {
                        ttdp[j][i] = max(ttdp[j][i], ttdp[tj][i - 2] + cnt[j]);
                    }
                }
            }
        }

        //for (int j = 0; j < 5; j++) cout << ttdp[j][i] << ' ';
           // cout << '\n';
    }
    int tmx = max({ ttdp[0][n - 1], ttdp[1][n - 1], ttdp[2][n - 1], ttdp[3][n - 1], ttdp[4][n - 1] });
    if (tmx >= k) {
        cout << sqrtl(5) << '\n';
        return;
    }



    // try 4

    vector<vector<int>> tdp(4, vector<int>(n));
    for (int i = 0; i < n; i++) {

        vector<int> cnt(4);
        for (int j = 0; j < 3; j++) {
            if (A[j][i] == '.') cnt[j]++;
        }
        cnt[3] = cnt[0] + cnt[2];
        for (int j = 0; j < 4; j++) {
            tdp[j][i] = cnt[j];
        }

        if (i) {
            tdp[0][i] = max({ tdp[0][i], tdp[0][i - 1], tdp[2][i - 1] + cnt[0] });
            tdp[2][i] = max({ tdp[2][i], tdp[2][i - 1], tdp[0][i - 1] + cnt[2] });
            tdp[1][i] = max({ tdp[1][i], tdp[1][i - 1] });
            tdp[3][i] = max({ tdp[3][i], tdp[3][i - 1] });
        }
        if (i >= 2) {
            int mx = max({ tdp[0][i - 2], tdp[1][i - 2], tdp[2][i - 2], tdp[3][i - 2] });
            for (int j = 0; j < 4; j++) {
                tdp[j][i] = max({ tdp[j][i], mx + cnt[j] });
            }
        }
    }
    int mx = max({ tdp[0][n - 1], tdp[1][n - 1], tdp[2][n - 1], tdp[3][n - 1] });
    if (mx >= k) {
        cout << 2.0000 << '\n';
        return;
    }

    // try 2

    vector<vector<int>> dp(2, vector<int>(n));
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 3; j++) {
            if (A[j][i] == '.') dp[j % 2][i]++;
        }

        if (i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + dp[0][i]);
            dp[1][i] = max(dp[0][i - 1] + dp[1][i], dp[1][i - 1]);
        }
    }

    if (dp[0][n - 1] >= k || dp[1][n - 1] >= k) {
        cout << sqrtl(2) << '\n';
    }
    else cout << 1.0000 << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}