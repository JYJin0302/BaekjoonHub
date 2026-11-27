#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        bool ok1 = 0, ok2 = 1;

        if (s[i - 1] != '0') ok1 = 1;
        if (s[i - 2] > '3' || s[i - 2] == '0' || (s[i - 2] == '3' && s[i - 1] > '4')) ok2 = 0;

        if (ok1) dp[i] += dp[i - 1];
        if (ok2) dp[i] += dp[i - 2];
    }

    cout << dp[n];

}