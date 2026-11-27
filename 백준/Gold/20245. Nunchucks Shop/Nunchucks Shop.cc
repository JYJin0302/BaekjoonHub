#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll comb[55][55];

ll solve(ll n, ll a) {
    ll ans = comb[n][a];
    ll rm = 0;
    if (a & 1) {
        if (n & 1) rm = comb[(n - 1) / 2][(a - 1) / 2];
        else rm = 0;
    }
    else {
        rm = comb[n / 2][a / 2];
    }
    ans = (ans - rm) / 2 + rm;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    comb[0][0] = 1;
    comb[1][0] = 1;
    comb[1][1] = 1;
    for (int i = 2; i <= 50; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }

    ll res = 0;
    for (int i = 0; i <= k; i++) {

        int a = i, b = k - i;
        if (a > b) break;
        if (b > n) continue;

        res += solve(n, a);
        res += solve(n, b);
    }
    cout << res;
}
