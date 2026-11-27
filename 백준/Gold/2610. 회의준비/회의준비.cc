#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) path[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        path[a][b] = 1;
        path[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }

    int cnt = 0;
    vector<int> ans;

    vector<bool> check(n+1);
    for (int i = 1; i <= n; i++) {
        if (check[i])continue;
        cnt++;
        vector<int> t;

        for (int k = 1; k <= n; k++) {
            if (path[i][k] != INF) {
                check[k] = 1;
                t.push_back(k);
            }
        }

        int tcnt = 101, tans = i;
        for (int a : t) {
            int tt = 0;
            for (int b : t) {
                tt = max(tt, path[a][b]);
            }
            if (tcnt > tt) {
                tcnt = tt;
                tans = a;
            }
        }

        ans.push_back(tans);
    }
    
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (int i : ans) cout << i << '\n';
}