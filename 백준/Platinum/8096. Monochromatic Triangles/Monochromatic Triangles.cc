#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt[1001][1001];
bool conn[1001][1001];
vector<int> adj[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll ans = 0;
    while (m--) {

        int a, b;
        cin >> a >> b;
        conn[a][b] = 1;

        ans += cnt[a][b];
        for (int i : adj[a]) cnt[i][b]++, cnt[b][i]++;
        for (int i : adj[b]) cnt[a][i]++, cnt[i][a]++;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        for (int j = i + 1; j <= n; j++) {
            cnt[i][j] = 0;
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = a+1; b <= n;b++) {
            if (!conn[a][b]) {

                ans += cnt[a][b];
                for (int i : adj[a]) cnt[i][b]++, cnt[b][i]++;
                for (int i : adj[b]) cnt[a][i]++, cnt[i][a]++;

                adj[a].push_back(b);
                adj[b].push_back(a);

            }
        }
    }

    cout << ans;
}