#include <bits/stdc++.h>
using namespace std;


vector<int> adj[200001];
int ans[200001], sz[200001];
map<int, bool> tmp[200001];

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i != pv){
        dfs(i, v);

        if (sz[i] > sz[v]) {
            swap(sz[i], sz[v]);
            swap(tmp[i], tmp[v]);
        }
        // i -> v
        int tans = max(ans[i], ans[v]);

        for (auto k = tmp[i].begin(); k != tmp[i].end(); k++) {
            tmp[v][k->first] |= k->second;
        }

        while (tmp[v][tans]) tans++;
        ans[v] = tans;
        sz[v] += sz[i];
    }
    /*
    cout << "CURR: " << v << ' ' << ans[v] << '\n';
    for (auto k = tmp[v].begin(); k != tmp[v].end(); k++) {
        cout << k->first << ' ';
        if (!k->second) cout << "??";
    }
    cout << '\n';
    */
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int r = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1) {
            adj[x].push_back(i);
        }
        else r = i;
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tmp[i][x] = 1;
        ans[i] = 0;
        sz[i] = 1;
        if (x == 0) ans[i] = 1;
    }
    dfs(r);

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}