#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int path[501];

int main() {

    int t, n, m, w, n1, n2, n3;

    cin >> t;
    while (t--) {


        cin >> n >> m >> w;

        path[1] = 0;
        for (int i = 2; i <= n; i++) {
            path[i] = INF;
        }

        vector<vector<pair<int, int>>> base(n + 1);

        for (int i = 0; i < m; i++) {
            cin >> n1 >> n2 >> n3;
            base[n1].push_back({ n2, n3 });
            base[n2].push_back({ n1, n3 });
        }

        for (int i = 0; i < w; i++) {
            cin >> n1 >> n2 >> n3;
            base[n1].push_back({ n2, -n3 });
        }

        for (int cnt = 0; cnt < n; cnt++) {
            for (int i = 1; i <= n; i++) for (auto j : base[i]) {
                tie(n1, n2) = j;
                path[n1] = min(path[n1], path[i] + n2);
            }
        }

        bool ok = false;
        for (int i = 1; i <= n; i++) for (auto j : base[i]) {
            tie(n1, n2) = j;
            if (path[n1] > path[i] + n2) { ok = true; break; }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}