#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s2[j-1] == s1[i-1]) dp[i][j] = max({ dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1] });
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    
    cout << dp[n][m];

}