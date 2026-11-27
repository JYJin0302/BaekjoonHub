#include <bits/stdc++.h>
using namespace std;

int dist[1010][1010];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dist[i][j] = 1e8;
        }
        dist[i][i] = 0;
        if (i < n) dist[i][i + 1] = 1;
    }

    while (m--) {
        int a, b, r;
        cin >> a >> b >> r;
        a--;
        dist[a][b] = min(dist[a][b], r);
        dist[b][a] = min(dist[b][a], -r);

        for (int i = a; i <= b; i++) {
            for (int j = i + 1; j <= b; j++) {
                dist[i][j] = min(dist[i][j], r);
            }
        }
    }

    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool neg = 0;
    for (int i = 0; i <= n; i++) {
        if (dist[i][i] < 0) {
            neg = 1;
        }
    }

    if (neg) {
        cout << "NONE\n";
        return 0;
    }
    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dist[i][j] >= 0) cout << " ";
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    for (int i = 1; i <= n; i++) {
        if (dist[0][i] == dist[0][i - 1] + 1) cout << '#';
        else cout << '-';
    }
}