#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int dp[1010][2], tmp[1010][2];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) dp[i][0] = dp[i][1] = -1e9;

    for (int i = 0; i < n; i++) {

        vector<int> A(m);
        for (int j = 0; j < m; j++) {
            cin >> A[j];
        }

        tmp[0][0] = max(dp[0][0], dp[0][1]) + A[0];
        if (i == 0) tmp[0][0] = A[0];

        for (int j = 1; j < m; j++) {
            tmp[j][0] = max({ dp[j][0], dp[j][1], tmp[j - 1][0] }) + A[j];
        }

        if (i) {
            tmp[m - 1][1] = max(dp[m - 1][0], dp[m - 1][1]) + A[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                tmp[j][1] = max({ dp[j][1], dp[j][0], tmp[j + 1][1] }) + A[j];
            }
        }
        else {
            for (int j = 0; j < m; j++) tmp[j][1] = tmp[j][0];
        }

        swap(dp, tmp);

        /*cout << "RES: \n";
        for (int j = 0; j < m; j++) cout << dp[j][0] << ' ';
        cout << '\n';
        for (int j = 0; j < m; j++) cout << dp[j][1] << ' ';
        cout << '\n';*/

    }

    cout << max(dp[m - 1][0], dp[m - 1][1]);

}