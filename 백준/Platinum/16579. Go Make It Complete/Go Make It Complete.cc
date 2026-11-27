#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool adj[505][505];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edge(m);
    for(auto& i : edge) cin >> i.first >> i.second;

    int l = 0, r = 2 * n - 2, ans = 0;
    while (l <= r) {

        int md = (l + r) >> 1;
        memset(adj, 0, sizeof(adj));

        queue<pair<int, int>> q;

        vector<int> deg(n+1);
        for (auto& [a, b] : edge) {
            adj[a][b] = adj[b][a] = 1;
            q.push({ a, b });
        }


        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            deg[a]++, deg[b]++;

            for (int i = 1; i <= n; i++) {
                if (a != i && !adj[a][i] && deg[a] + deg[i] >= md) {
                    adj[a][i] = adj[i][a] = 1;
                    q.push({ a, i });
                }
                if (b != i && !adj[b][i] && deg[b] + deg[i] >= md) {
                    adj[b][i] = adj[i][b] = 1;
                    q.push({ b, i });
                }

            }
        }

        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] != n - 1) ok = 0;
        }

        if (!ok) {
            r = md - 1;
        }
        else {
            ans = md;
            l = md + 1;
        }
    }
    cout << ans;

}