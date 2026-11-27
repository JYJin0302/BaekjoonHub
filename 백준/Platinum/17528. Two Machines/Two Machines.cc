#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dp[63000], dp2[63000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int tot = 0;
    vector<pair<int, int>> A(n);
    for (auto& i : A) {
        cin >> i.first >> i.second;
        tot += i.second;
    }

    for (auto i : A) {
        int a, b;
        tie(a, b) = i;

        for (int j = 1; j <= 62500; j++) {
            dp2[j] = max(dp[j], dp[j-1]);
            if (j >= a) dp2[j] = max(dp2[j], dp[j - a] + b);
        }

        swap(dp, dp2);
    }

    int ans = 62500;
    for (int i = 0; i <= 62500; i++) {
        ans = min(ans, max(i, tot - dp[i]));
    }
    cout << ans;

}