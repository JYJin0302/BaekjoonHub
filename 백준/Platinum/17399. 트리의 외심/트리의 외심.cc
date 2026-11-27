#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using ll = long long;

vector<int> adj[101010];

int dep[101010];
int spt[18][101010];

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i != pv) {
        dep[i] = dep[v] + 1;
        spt[0][i] = v;
        dfs(i, v);
    }
}

int getLca(int u, int v) {

    if (dep[u] > dep[v]) swap(u, v);

    int diff = dep[v] - dep[u];
    for (int i = 0; i < 18; i++) {
        if (diff & (1 << i)) v = spt[i][v];
    }

    for (int i = 17; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) u = spt[0][u];
    return u;
}

int getMid(int u, int v) {

    if (dep[u] > dep[v]) swap(u, v);
    int tv = v;

    int df = dep[v] - dep[u];
    for (int i = 0; i < 18; i++) {
        if (df & (1 << i)) v = spt[i][v];
    }

    if (df & 1) return -1;

    df >>= 1;
    for (int i = 0; i < 18; i++) {
        if (df & (1 << i)) tv = spt[i][tv];
    }

    for (int i = 17; i >= 0; i--){
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
            tv = spt[i][tv];
        }
    }

    if (u != v) {
        tv = spt[0][tv];
    }
    return tv;
}

int getDist(int u, int v) {
    int lca = getLca(u, v);
    return dep[u] + dep[v] - 2 * dep[lca];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;


    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    int q;
    cin >> q;
    while (q--) {

        int a, b, c;
        cin >> a >> b >> c;

        vector<int> tmp;

        tmp.push_back(getMid(a, b));
        tmp.push_back(getMid(b, c));
        tmp.push_back(getMid(c, a));
        
        bool ok = 1;
        for (auto i : tmp) {
            if (i == -1) ok = 0;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }
        
        int val = -1;
        if (tmp[0] == tmp[1]) val = tmp[0];
        if (tmp[0] == tmp[2]) val = tmp[0];
        if (tmp[1] == tmp[2]) val = tmp[1];

        if (val != -1) {
            vector<int> res;
            res.push_back(getDist(val, a));
            res.push_back(getDist(val, b));
            res.push_back(getDist(val, c));

            if (res[0] == res[1] && res[1] == res[2]) {}
            else val = -1;
        }

        cout << val << '\n';
    }
}
