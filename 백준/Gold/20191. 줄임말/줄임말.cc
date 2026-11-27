#include <bits/stdc++.h>
using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    // dp[i][j] : [i, s2.size() - 1] 에서 s2[x] == 'a' + j 인 가장 작은 x
    vector<vector<int>> dp(s2.size() + 1, vector<int>(26, -1));

    for (int i = s2.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (s2[i] == 'a' + j) dp[i][j] = i;
            else dp[i][j] = dp[i + 1][j];
        }
    }

    int L = 0, R = 0, ans = 1;
    while (L < s1.size()) {

        int t = dp[R][s1[L] - 'a'];
        if (t == -1) {
            if (R == 0) {
                ans = -1;
                break;
            }
            ans++;
            R = 0;
        }
        else {
            L++;
            R = t + 1;
        }
    }

    cout << ans;
}