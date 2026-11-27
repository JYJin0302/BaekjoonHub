#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 2000000001


ll path[801][801];

int main() {

    ll n, m, n1, n2, n3, t1, t2;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) path[i][j] = 0;
            else path[i][j] = INF;
        }
    }


    while (m--) {
        cin >> n1 >> n2 >> n3;
        path[n1][n2] = min(path[n1][n2], n3);
        path[n2][n1] = min(path[n2][n1], n3);
    }
    for (int i = 1; i <= m; i++) {
        cin >> n1 >> n2 >> n3;
        path[n1][n2] = min(path[n1][n2], -n3);
    }


    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) {
        path[j][k] = min(path[j][k], path[j][i] + path[i][k]);
    }

    cin >> t1 >> t2;
    ll ans1 = (ll)path[1][t1] + (ll)path[t1][t2] + (ll)path[t2][n];
    ll ans2 = (ll)path[1][t2] + (ll)path[t1][t2] + (ll)path[t1][n];

    ll ans = min(ans1, ans2);
    if (ans >= INF) cout << -1;
    else cout << ans;
}