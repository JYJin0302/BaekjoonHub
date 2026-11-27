#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[i] = c;
    }

    vector<int> dp(n);
    dp[0] = A[0];
    for (int i = 1; i < n; i++) {
        if (i >= 2) dp[i] = dp[i - 2];
        dp[i] += A[i];
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1] << '\n';
}