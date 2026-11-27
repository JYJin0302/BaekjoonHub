#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r, a, b, c;
    cin >> n >> m >> r;

    vector<int> items(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    vector<vector<int>> path(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) path[i][i] = 0;

    vector<vector<pair<int, int>>> base(n + 1);
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> c;
        path[a][b] = min(path[a][b] ,c);
        path[b][a] = min(path[b][a], c);
        base[a].push_back({ b, c });
        base[b].push_back({ a, c });
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            if (path[i][j] <= m) temp += items[j];
        }
        ans = max(ans, temp);
    }
    cout << ans;

}