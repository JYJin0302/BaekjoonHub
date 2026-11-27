#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    vector<ll> dp(4);

    for (int i = 1; i < n; i++) A[i] += A[i - 1];

    ll tot = A[n - 1];
    if (tot % 4 != 0) {
        cout << 0;
        return 0;
    }
    tot /= 4;

    for (int i = 0; i < n-1; i++) {

        if (A[i] == tot * 3) dp[2] += dp[1];
        if (A[i] == tot * 2) dp[1] += dp[0];
        if (A[i] == tot) dp[0]++;
    }
    cout << dp[2];
}