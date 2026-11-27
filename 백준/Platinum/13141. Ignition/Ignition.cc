#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000000


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << setprecision(1) << fixed;
    vector<vector<ll>> path(n + 1, vector<ll>(n + 1, INF));
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ a, b, c });
        path[a][b] = min(path[a][b], c);
        path[b][a] = path[a][b];
    }
    for (int i = 1; i <= n; i++) path[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }

    double ans = INF;
    for (int i = 1; i <= n; i++) {

        double res = 0;
        for (auto k : edges) {
            int a, b, c;
            tie(a, b, c) = k;

            double nd;
            if (path[i][a] > path[i][b])  swap(a, b);

            nd = path[i][b] + (double)(c - path[i][b] + path[i][a]) / 2;
            res = max(res, nd);
        }

        ans = min(ans, res);

    }
    cout << ans;

}