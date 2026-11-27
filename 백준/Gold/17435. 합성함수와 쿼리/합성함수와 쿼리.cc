#include <bits/stdc++.h>
using namespace std;

int n;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int cnt = log2(500000) + 1;

    vector<vector<int>> dp(cnt, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) cin >> dp[0][i];

    for (int i = 1; i < cnt; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    // 쿼리 수행
    int q;
    cin >> q;

    while (q--) {

        int a, b;
        cin >> a >> b;
        a--;

        b = dp[0][b];

        // 값 구하기
        int ind = 0;
        while (a > 0) {
            if (a % 2 == 1) b = dp[ind][b];

            a /= 2;
            ind++;
        }

        cout << b << '\n';
    }

}