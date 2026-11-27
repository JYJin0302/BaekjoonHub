#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll dp[5001][5001];

ll solve(int s, int b) {

    if (s == 0) return dp[s][b] = 0;
    if (s == 1) return dp[s][b] = 1;
    if (b == 0) return dp[s][b] = 1;
    if (dp[s][b] != -1) return dp[s][b];

    ll res = 0;
    res += 2*solve(s - 1, b);
    if (b >= s) res += solve(s, b-s);
    res -= solve(s - 2, b);

    res = (res + mod) % mod;
    return dp[s][b] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int s, b;
    cin >> s >> b;

    cout << solve(s, b-s);
}