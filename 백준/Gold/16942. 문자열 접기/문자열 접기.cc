#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i; j += 2) {
            if (s[i] == s[i - j]) dp[i] = max(dp[i], dp[i - j] + 1);
        }
    }
    cout << *max_element(all(dp));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}