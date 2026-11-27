#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[1010];

int val[1010], topo[1010];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    while (m--) {

        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b ,c });
        topo[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (topo[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (auto &[x, y] : adj[a]) {
            val[x] = max(val[x], val[a] + y);
            topo[x]--;
            if (topo[x] == 0) q.push(x);
        }

    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, val[i]);
    cout << ans;
}