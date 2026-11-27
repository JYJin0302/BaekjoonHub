#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(101010);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        dp[x] = 1;
    }

    int m;
    cin >> m;
    vector<int> B(m);
    for (auto& i : B) cin >> i;

    for (int i = 2; i <= 100000; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                dp[i] += dp[j];
                if (j != i/j && j != 1) dp[i] += dp[i / j];
            }
        }
    }
    for (auto i : B) cout << dp[i] << ' ';
}