#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> path1(n + 1, vector<int>(n + 1, INF)), path2(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path1[a][b] = 1;
        path2[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (k == i || k == j) continue;

                path1[i][j] = min(path1[i][j], path1[i][k] + path1[k][j]);
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (k == i || k == j) continue;

                path2[i][j] = min(path2[i][j], path2[i][k] + path2[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j != i && path1[i][j] == INF && path2[i][j] == INF) cnt++;
        }

        cout << cnt << '\n';
    }

}