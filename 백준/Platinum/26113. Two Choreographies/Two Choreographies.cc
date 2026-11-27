#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[100001];
bool vs[100001];
int dep[100001];
int spt[100001][20];
map<pair<int, int>, bool> used;

vector<pair<int, int>> ans[100001];

void dfs(int v) {
    for (auto i : adj[v]) {
        if (!vs[i]) {
            vs[i] = 1;
            dep[i] = dep[v] + 1;
            spt[i][0] = v;
            used[{v, i}] = 1;
            used[{i, v}] = 1;
            dfs(i);
        }
    }
}


int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);

    int df = dep[b] - dep[a];
    for (int j = 0; j < 20; j++) {
        if (df & (1 << j)) b = spt[b][j];
    }

    for (int j = 19; j >= 0; j--) {
        if (spt[a][j] != spt[b][j]) {
            a = spt[a][j], b = spt[b][j];
        }
    }

    if (a == b) return a;
    return spt[a][0];
}
void pf(int a, int b) {

    int l = lca(a, b);

    while (a != l) {
        cout << a << ' ';
        a = spt[a][0];
    }
    vector<int> tmp;
    while (b != l) {
        tmp.push_back(b);
        b = spt[b][0];
    }
    tmp.push_back(l);
    reverse(tmp.begin(), tmp.end());

    for (auto i : tmp) cout << i << ' ';
    cout << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> edge;
    for (int i = 0; i < n * 2 - 3; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge.push_back({ a, b });
    }

    vs[4] = 1;
    dfs(4);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            spt[j][i] = spt[spt[j][i - 1]][i - 1];
        }
    }

    for (auto i : edge) {
        if (used[i]) continue;

        int a, b;
        tie(a, b) = i;

        int l = lca(a, b);

        int sz = dep[a] - dep[l] + dep[b] - dep[l] + 1;

        if (sz < 3 || sz > n || ans[sz].empty()) ans[sz].push_back(i);
        else {

            // ans print
            cout << sz << '\n';
            pf(a, b);
            pf(ans[sz][0].first, ans[sz][0].second);
            return 0;
        }
    }


}