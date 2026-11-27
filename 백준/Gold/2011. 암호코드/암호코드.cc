#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    if (s[0] == '0') {
        cout << 0;
        return 0;
    }

    vector<int> dp(s.size()+1);

    bool ok = true;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++){
        if (s[i - 1] == '0') {
            if (s[i - 2] == '0' || s[i-2] >= '3') {
                ok = false;
                break;
            }
            dp[i] = dp[i - 2];
        }
        else if (s[i - 2] == '0') {
            dp[i] = dp[i - 1];
        }
        else {
            if (s[i - 2] >= '3' || (s[i - 2] == '2' && s[i - 1] >= '7')) {
                dp[i] = dp[i - 1];
            }
            else dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[i] %= 1000000;
    }
    if (ok) cout << dp[s.size()];
    else cout << 0;

}