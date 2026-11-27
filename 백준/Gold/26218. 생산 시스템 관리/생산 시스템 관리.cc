#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

struct O {
    ll b, a, c;
    // base, add, cost
};

ll dp[11][30001];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<O> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].b >> A[i].a >> A[i].c;
    }
    dp[0][0] = 1;


    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] * A[i].b;

        for (int j = 1; j <= b; j++) {
            dp[i][j] =  max(dp[i][j-1], dp[i - 1][j]);

            for (int k = 0; A[i].b + k * A[i].a <= 100 + A[i].a-1; k++) {
                ll ncost = A[i].c * k;
                ll nv = min(100LL, A[i].b + k * A[i].a);
                if (ncost > b) break;
                if (j < ncost) break;

                dp[i][j] = max(dp[i][j], dp[i - 1][j - ncost] * nv);
            }
        }

    }

    cout << dp[n][b] << '\n';
    ll val = dp[n][b], cb = b;

    vector<ll> ans(n + 1);
    int ix = n;
    while (ix >= 1) {
        while (cb > 0 && dp[ix][cb] == dp[ix][cb - 1]) cb--;

        for (int k = 0; A[ix].b + A[ix].a * k <= 100 + A[ix].a - 1; k++) {
            ll ncost = A[ix].c * k;
            ll nv = min(100LL, A[ix].b + k * A[ix].a);

            if (dp[ix - 1][cb - ncost] * nv == val) {
                ans[ix] = k;
                val = dp[ix - 1][cb - ncost];
                ix--, cb -= ncost;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';


}