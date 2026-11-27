#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[22][22], sA[22][22];
bool dp[22][22][42222];
int from[22][22][42222];

void solve() {

    int n; cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            tot += A[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sA[i][j] = A[i][j] + sA[i-1][j];
        }
    }

    for (int i = 0; i <= n; i++) dp[i][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int pv = 0; pv <= n; pv++) {
            for (int k = 0; k <= pv; k++) {
                int val = sA[k][i+1];
                for (int c = 0; c + val <= tot; c++) {
                    if (dp[pv][i][c]) {
                        dp[k][i + 1][c + val] = 1;
                        from[k][i + 1][c + val] = pv;
                    }
                }
            }
        }

       /* cout << "RES: " << i << '\n';
        for (int j = 0; j <= n; j++) {
            for (int c = 0; c <= tot; c++) {
                cout << dp[j][i+1][c];
            }
            cout << '\n';
        }
        cout << '\n';*/
    }

    vector<int> ans(n);
    int val = -1, ix = -1;
    for (int j = 0; j <= n; j++) {
        for (int c = 0; c <= tot; c++) {
            if (dp[j][n][c]) {
                if (abs(val - (tot - val)) > abs(c - (tot - c))) {
                    val = c;
                    ix = j;
                }
            }
        }
    }

    cout << abs(val - (tot - val)) << '\n';
    for (int i = n; i >= 1; i--) {
        ans[i - 1] = ix;
        int nv = val - sA[ix][i];
        ix = from[ix][i][val];
        val = nv;
    }

    for (auto f : ans) cout << n - f << ' ';
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}