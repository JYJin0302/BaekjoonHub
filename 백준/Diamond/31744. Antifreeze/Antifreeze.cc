#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool isW[101010];
vector<pair<int, int>> adj[101010];

int n, t;
int root[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void merge(int u, int v) {
   // cout << "Merge: " << u << ' ' << v << '\n';
    u = find(u), v = find(v);
    if (u != v) root[u] = v;
}

int dist[101010];
set<pair<int, int>> st[101010];

void dfs(int v, int pv = -1) {

    if (isW[v]) {
        st[v].insert(mp(dist[v], v));
    }

    for (auto& [u, w] : adj[v]) if (u != pv) {
        dist[u] = dist[v] + w;
        dfs(u, v);

        pair<int, int> mn1 = mp(1e9 + 10, -1), mn2 = mp(1e9+10, -1);

        if (!st[v].empty()) mn1 = *st[v].begin();
        if (!st[u].empty()) mn2 = *st[u].begin();

        if (!st[v].empty()) {
            auto iter = st[v].begin();
            auto [val, ix] = mn2;

            while (iter != st[v].end()) {
                if ((*iter).first - 2 * dist[v] + val <= t) {
                    merge((*iter).second, ix);
                    iter = st[v].erase(iter);
                }
                else break;
            }
        }
        swap(st[u], st[v]);
        if (!st[v].empty()) {
            auto iter = st[v].begin();
            auto [val, ix] = mn1;

            while (iter != st[v].end()) {
                if ((*iter).first - 2 * dist[v] + val <= t) {
                    merge((*iter).second, ix);
                    iter = st[v].erase(iter);
                }
                else break;
            }
        }

        if (st[v].size() < st[u].size()) swap(st[v], st[u]);
        for (auto& f : st[u]) st[v].insert(f);
        mn1 = min(mn1, mn2);
        if (mn1.second != -1) st[v].insert(mn1);
    }

    /*cout << "SET: " << v << " | ";
    for (auto f : st[v]) cout << "(" << f.first << ' ' << f.second << ") ";
    cout << '\n';*/

}

void solve() {

    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> isW[i];
        root[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back(mp(b, w));
        adj[b].push_back(mp(a, w));
    }

    dfs(1);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b)) cout << "1\n";
        else cout << "0\n";
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}