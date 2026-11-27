#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> dist;
vector<vector<int>> adj;

void dfs(int v, int pv = -1) {
    for (int i : adj[v]) if (i != pv) {
        dist[i] = dist[v] + 1;
        dfs(i, v);
    }
    if (adj[v].size() == 1) {
        ans += dist[v];
    }
}

int main() {

    int n;
    cin >> n;

    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist = vector<int>(n + 1);
    dfs(1);

    if (ans % 2) cout << "Yes";
    else cout << "No";
}