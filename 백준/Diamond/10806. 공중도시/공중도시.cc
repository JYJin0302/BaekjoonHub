#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[101010];
int minV[101010];
int visOrd[101010];
int ord = 0;

map<pair<int, int>, bool> cEdg;
vector<pair<int, int>> cList;

int dfs(int v, int pv = -1) {
    minV[v] = ++ord;
    visOrd[ord] = v;
    int ret = ord;

    int cnt = 0;
    for (auto f : adj[v]) {
        if (f == pv && cnt == 0) {
            cnt++;
            continue;
        }
        if (!minV[f]) {
            int ta = dfs(f, v);
            if (ta > minV[v]) {
                cEdg[mp(v, f)] = 1;
                cList.push_back(mp(v, f));
            }
            ret = min(ret, ta);
        }
        else ret = min(ret, minV[f]);
    }
    return ret;
}

int root[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

vector<int> ans;
void dfs2(int v, int pv = -1) {
    if (adj[v].size() == 1) ans.push_back(v);
    for (auto f : adj[v]) if (f != pv) {
        dfs2(f, v);
    }
}
void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg.push_back(mp(a, b));
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        root[i] = i;
    }

    for (auto& [a, b] : edg) {
        if (cEdg[mp(a, b)] || cEdg[mp(b, a)]) continue;
        int na = find(a);
        int nb = find(b);
        if (na != nb) {
            root[na] = nb;
        }
    }

    int r = 0;
    for (auto& [a, b] : cList) {
        int na = find(a);
        int nb = find(b);
        adj[na].push_back(nb);
        adj[nb].push_back(na);
        r = na;
    }
    dfs2(r);

    int k = ans.size() / 2;
    int res = (ans.size() + 1) / 2;
    cout << res << '\n';
    for (int i = 0; i < res; i++) {
        cout << ans[i] << ' ' << ans[i + k] << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}