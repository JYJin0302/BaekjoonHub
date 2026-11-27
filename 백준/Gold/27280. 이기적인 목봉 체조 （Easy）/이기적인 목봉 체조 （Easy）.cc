#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

ll dp[11][1010];
const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> A(n+ 1);
    for (int i = 1; i <= n; i++) cin >> A[i].x >> A[i].y;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = -INF;
    }
    dp[0][0] = 0;


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            
            ll mx = A[j].x;
            ll mv = 0;
            for (int k = j; k >= 1; k--) {
                if (A[k].x == mx) mv += A[k].y;
                else if (A[k].x > mx) {
                    mx = A[k].x;
                    mv = A[k].y;
                }

                dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + mv);
            }
        }
    }

    cout << dp[m][n];


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}