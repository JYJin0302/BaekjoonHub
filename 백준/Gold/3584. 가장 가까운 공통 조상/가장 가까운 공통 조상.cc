#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;
vector<int> depth, parent;

void dfs(int v, int pv = 0, int dep = 1) {
    depth[v] = dep;

    for (int i : adj[v]) {
        dfs(i, v, dep + 1);
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        adj = vector<vector<int>>(n + 1);
        depth = vector<int>(n + 1);
        parent = vector<int>(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
            adj[a].push_back(b);
        }
        int root = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == 0) root = i;
        }

        dfs(root);

        int a, b;
        cin >> a >> b;

        while (a != b) {
            if (depth[a] > depth[b]) a = parent[a];
            else if (depth[a] < depth[b]) b = parent[b];
            else {
                a = parent[a];
                b = parent[b];
            }
        }

        cout << a << '\n';
    }
}