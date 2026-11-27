#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[101010];
vector<tuple<int, int, int>> ans;
bool vs[101010];
map<pair<int, int>, bool> used;

int dfs(int v, int p = -1) {

    if (vs[v]) return v;
    vs[v] = 1;

    int pv = 0;
    for (auto i : adj[v]) if (!used[{v, i}]) {
        used[{v, i}] = 1;
        used[{i, v}] = 1;
       // cout << "Go: " << v << " -> " << i << '\n';
        int res = dfs(i, v);

        if (res != i) {
            ans.push_back({ v, i, res });
        }
        else if (pv == 0) pv = res;
        else {
            ans.push_back({ pv, v, res });
            pv = 0;
        }
    }
    if (pv == 0) pv = v;
    return pv;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++ ) {
        if (!vs[i]) dfs(i);
    }

    cout << ans.size() << '\n';
    for (auto& [a, b, c] : ans) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}