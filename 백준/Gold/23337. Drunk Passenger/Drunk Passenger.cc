#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ld dp[303];
ld getDp(int n, bool st = 0) {
    if (dp[n] > -0.5) return dp[n];
    if (n == 1) {
        return dp[n] = 1;
    }
    if (st) {
        ld res = 0;
        for (int i = 1; i <= n - 1; i++) {
            res += 1.0 / (n - 1) * getDp(i);
        }
        return dp[n] = res;
    }

    ld res = 0;
    for (int i = 1; i <= n - 1; i++) {
        res += 1.0 / n * getDp(i);
    }
    return dp[n] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) dp[i] = -1;
    ld res = getDp(n, 1);
    cout << setprecision(15);
    cout << res << '\n';
}