#include <bits/stdc++.h>
using namespace std;

vector<int> depth;
vector<vector<int>> adj, parent;

void dfs(int v = 1, int pv = 0, int dep = 1) {
    depth[v] = dep;
    for (int i : adj[v]) if (i != pv) {
        dfs(i, v, dep+1);
        parent[0][i] = v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int size = log2(n);
    parent = vector<vector<int>> (size+1, vector<int>(n+1));

    adj = vector<vector<int>>(n + 1);
    depth = vector<int>(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;

        if (depth[a] > depth[b]) swap(a, b);

        int diff = depth[b] - depth[a];
        for (int i = 0; diff; i++) {
            if (diff & 1) b = parent[i][b];
            diff /= 2;
        }

        int d = depth[b];
        for (int i = size; i >= 0; i--) {
            if (parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
            d /= 2;
        }

        if (a == b) cout << a << '\n'; 
        else cout << parent[0][a] << '\n';
    }

}