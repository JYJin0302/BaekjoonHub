#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dp[5050][5050];
void solve() {
    ll n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (A[i] >= A[i - j]) dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) dp[i][j] += dp[i - 1][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += dp[i][j];
        }
    }

    reverse(all(A));
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (A[i] >= A[i - j]) dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) dp[i][j] += dp[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans - n * (n+1)/2;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    // cin >> t;
    while (t--) solve();
}