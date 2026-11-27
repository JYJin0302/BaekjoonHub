#include <bits/stdc++.h>
using namespace std;
using ll = double;

ll n, m;
vector<ll> cntt;
vector<vector<ll>> mulmat(vector<vector<ll>> a, vector<vector<ll>> b) {

    vector<vector<ll>> res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cout << fixed << setprecision(6);

    cntt = vector<ll>(n);
    vector<vector<ll>> dp(n, vector<ll>(n)), A(n, vector<ll>(n));

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);

        dp[a][b] = 1;
        cntt[a]++;
        if (b != n - 1) dp[b][a] = 1, cntt[b]++;
    }
    cntt[n - 1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] /= cntt[i];
            A[i][j] = dp[i][j];
        }
    }

    ll cnt = 1;
    ll ans = 0;

    while (cnt < 10000) {
        
        ans += cnt * dp[0][n - 1];
        dp = mulmat(dp, A); 
        cnt++;
    }

    cout << ans;
}