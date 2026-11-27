#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1e9 + 7;
vector<vector<ll>> dp[101];

vector<vector<ll>> mult(vector<vector<ll>>& A, vector<vector<ll>>& B) {

    int n = A.size();
    vector<vector<ll>> res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += A[i][k] * B[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, n, d;
    cin >> t >> n >> d;

    vector<vector<ll>> A(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        A[i][i] = 1;
    }
    dp[0] = A;

    for (int k = 1; k <= t; k++) {
        int tt;
        cin >> tt;
        A = vector<vector<ll>> (n, vector<ll>(n));
        for (int i = 0; i < tt; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            a--, b--;
            A[a][b] = c;
        }

        dp[k] = mult(dp[k - 1], A);
    }
    vector<vector<ll>> ans = dp[0];
    vector<vector<ll>> base = dp[t];



    ll tmp = d / t;
    while (tmp) {
        if (tmp % 2) ans = mult(ans, base);
        base = mult(base, base);
        tmp /= 2;
    }

    ans = mult(ans, dp[d % t]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] <<' ';
        }
        cout << '\n';
    }

}