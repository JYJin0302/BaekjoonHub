#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len, n;
    cin >> len >> n;

    vector<int> A(n + 2);
    for (int i = 1; i <= n + 1; i++) cin >> A[i];
    for (int i = 1; i <= n+1; i++) A[i] += A[i - 1];

    vector<int> cost(n+2);
    for (int i = 1; i <= n; i++) cin >> cost[i];

    vector<int> dp(n + 2);
    vector<int> from(n + 2);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = -1;
        for (int j = 0; j < i; j++) {
            if (A[i] - A[j] <= len) {
                if (dp[i] == -1 || dp[i] > dp[j] + cost[i]) {
                    dp[i] = dp[j] + cost[i];
                    from[i] = j;
                }
            }
        }
    }

    
    vector<int> ans;
    int ix = from[n + 1];
    while (ix > 0) {
        ans.push_back(ix);
        ix = from[ix];
    }
    reverse(ans.begin(), ans.end());

    cout << dp[n + 1] << '\n';
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';

}