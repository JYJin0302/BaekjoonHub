#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dp[5050];
int f(int n) {
    if (n < 0) return 10000;
    if (n == 0) return dp[0] = 0;
    if (dp[n] != -1) return dp[n];
    return dp[n] = min(f(n - 3), f(n - 5)) + 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) dp[i] = -1;
    int res = f(n);
    if (res > n) cout << -1 << '\n';
    else cout << res << '\n';
}