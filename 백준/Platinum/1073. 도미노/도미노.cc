#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int deg[10];
ll dp[10];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;

        int na, nb;
        na = a - '0';
        nb = b - '0';

        deg[na]++;
        deg[nb]++;
    }

    dp[0] = 1;
    dp[2] = 1;
    for (int i = 4; i < 10; i += 2) dp[i] = (i - 1) * dp[i - 2];

    ll ans = 1;
    for (int i = 0; i < 10; i++) ans *= dp[deg[i]];
    cout << ans;
}