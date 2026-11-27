#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> A, sA;
int dp[3001][3001];
int dp2[3001];
int c1, c2;

const int INF = 1e9+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    A = vector<int>(n + 1);
    sA = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    cin >> c1 >> c2;

    sort(A.begin(), A.end());
    for (int i = 1; i <= n; i++) {
        sA[i] = sA[i - 1] + A[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
        dp2[i] = INF;
    }


    dp[1][0] = c1 * A[1];
    dp[1][1] = c2;
    dp2[0] = 0;
    dp2[1] = min(dp[1][0], dp[1][1]);

    for (int i = 2; i <= n; i++) {

        for (int j = 0; j < i; j++) {
            dp[i][j] = dp[i - 1][j] + c1 * (A[i] - A[j]);
            dp2[i] = min(dp2[i], dp[i][j]);

            dp[i][i] = min(dp[i][i], c2 + dp2[j] + c1*(A[i] * (i - j) - (sA[i] - sA[j])));
            dp2[i] = min(dp2[i], dp[i][i]);
        }
    }

    cout << dp2[n];

}