#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int topo[1010];
bool ck[1010];
int dp[1010];
int ans[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edge;
    while (m--) {
        int a, b;
        cin >> a >> b;
        edge.push_back({ a, b });
        adj[a].push_back(b);
        topo[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (topo[i] == 0) {
        q.push(i);
    }

    int s, e;
    cin >> s >> e;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        ck[x] = 1;
    }

    while (!q.empty()) {

        int a = q.front();
        q.pop();

        if (a == s) continue;

        for (auto i : adj[a]) {
           // if (ph) dp[i] = max(dp[i], dp[a]);
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
    }

    vector<int> tmp(n + 1);
    for (int i = 1; i <= n; i++) tmp[i] = topo[i];

    q.push(s);
    while (!q.empty()) {

        int a = q.front();
        q.pop();
        if (ck[a]) dp[a]++;

        for (auto i : adj[a]) {
            dp[i] = max(dp[i], dp[a]);
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
    }

    if (dp[e] != k) {
        cout << 0;
        return 0;
    }

    q.push(s);
    for (int i = 1; i <= n; i++) topo[i] = tmp[i];

    ans[s] = 1;
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        //cout << a << ' ' << ans[a] << '\n';
        for (auto i : adj[a]) {
            if (dp[i] == dp[a] && !ck[i]) ans[i] += ans[a];
            if (dp[i] == dp[a] + 1 && ck[i]) ans[i] += ans[a];

            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
    }
    cout << ans[e];

}