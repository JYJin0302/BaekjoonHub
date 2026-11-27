#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, a, b, c, t;
vector<ll> inp;
vector<vector<ll>> mulmat(vector<vector<ll>>& a, vector<vector<ll>>& b) {

    vector<vector<ll>> res(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= m;
            }
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b >> c >> t;
    while (!(!n && !m && !a && !b && !c && !t)) {
        inp = vector<ll>(n);
        for (auto& i : inp) cin >> i;

        if (t == 0) {
            for (auto i : inp) cout << i << ' ';
            cout << '\n';
        }
        else {
            ll logt = log2(t);
            vector<vector<ll>> A(n, vector<ll>(n));
            vector<vector<vector<ll>>> dp(logt + 1);

            for (int i = 0; i < n; i++) {
                if (i - 1 >= 0) A[i - 1][i] = a;
                A[i][i] = b;
                if (i + 1 < n) A[i + 1][i] = c;
            }

            t--;

            dp[0] = A;
            for (int i = 1; i <= logt; i++) {
                dp[i] = mulmat(dp[i - 1], dp[i - 1]);
            }

            for (int i = 0; i <= logt; i++) {
                if (t % 2) A = mulmat(A, dp[i]);
                t /= 2;
            }

            vector<ll> ans(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans[i] += A[j][i] * inp[j];
                    ans[i] %= m;
                }
            }

            for (auto i : ans) cout << i << ' ';
            cout << '\n';
        }


        cin >> n >> m >> a >> b >> c >> t;
    }
}