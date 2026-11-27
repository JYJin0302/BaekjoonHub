#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

char card[1010];
vector<pair<int, char>> adj[505];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> card[i];

    int m, k;
    cin >> m >> k;
    while (k--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    vector<int> dist(m + 1, -1), tmp(m+1, -1);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {

        tmp = vector<int>(m + 1, -1);
        for (int j = 1; j <= m; j++) {
            if (dist[j] == -1) continue;

            for (auto& f : adj[j]) {
                tmp[f.first] = max(tmp[f.first], dist[j] + (f.second == card[i] ? 10 : 0));
            }
        }
        swap(dist, tmp);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) ans = max(ans, dist[i]);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}