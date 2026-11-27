#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ld P[22][22];
ld dp[1 << 20];

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> P[i][j];
            P[i][j] /= 100;
        }
    }
    for (int i = 0; i < (1 << n); i++) dp[i] = -1;

    queue<int> q, tq;
    for (int i = 0; i < n; i++) {
        dp[1 << i] = 1.0 * P[0][i];
        q.push(1 << i);
    }

    for (int i = 1; i < n; i++) {
        while (!q.empty()) {
            int v = q.front(); q.pop();

            for (int j = 0; j < n; j++) {
                if (v & (1 << j)) continue;
                int nv = v ^ (1 << j);
                if (dp[nv] < -0.5) {
                    dp[nv] = dp[v] * P[i][j];
                    tq.push(nv);
                }
                else dp[nv] = max(dp[nv], dp[v] * P[i][j]);
            }

        }
        swap(q, tq);
    }
    
    
    cout << fixed << setprecision(10);
    cout << dp[(1 << n) - 1] * 100 << '\n';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}