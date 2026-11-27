#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct D {
    ll v, c;

    bool operator<(D& o) {
        if (v == o.v) return c > o.c;
        return v < o.v;
    }
};

ll dp[150101][10];

void solve() {

    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) dp[i][j] = 0;
    }

    vector<D> A(n);
    for (auto& i : A) cin >> i.v >> i.c;

    sort(A.begin(), A.end());

    dp[n - 1][0] = max(0ll, A[n - 1].v - A[n - 1].c);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = k; j >= 0; j--) {
            ll val = 0;
            if (j > 0) val = min(dp[i + 1][j - 1] - A[i].c, A[i].v - A[i].c);
            else val = A[i].v - A[i].c;

            val = max(val, dp[i + 1][j]);
            val = max(val, 0ll);
            dp[i][j] = val;
        }
    }

    cout << dp[0][k] << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}