#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, int>> adj[25252];
int root[25252];
vector<int> st[25252];
int find(int n) {
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}

int cur[25252];
bool merge(int u, int v, int b) {
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) {
        return (cur[u] ^ cur[v]) == b;
    }

    if (st[fu].size() > st[fv].size()) {
        swap(u, v);
        swap(fu, fv);
    }
    root[fu] = fv;

    int nd = 0;
    if ((cur[u] ^ cur[v]) != b) nd = 1;

    for (auto f : st[fu]) {
        st[fv].push_back(f);
        cur[f] ^= nd;
    }
    return 1;
}
void solve() {

    int n, m;
    cin >> n >> m;
    while (m--) {
        int v1, v2;
        char c1, c2;
        cin >> v1 >> c1 >> v2 >> c2;
        if (v1 > v2) swap(v1, v2);
        if (c1 == c2) {
            adj[v2].push_back(mp(v1, 1));
        }
        else {
            adj[v2].push_back(mp(v1, 0));
        }
    }

    for (int i = 1; i <= n; i++) {
        root[i] = i;
        st[i].push_back(i);
    }
    int ans = 1;
    int pv = 0;
    for (int i = 1; i <= n; i++) {
        bool ok = 1;
        for (auto [a, b] : adj[i]) {
            if (a <= pv) continue;
            if (!merge(a, i, b)) {
                ok = 0;
                break;
            }
        }

        if (!ok) {
            ans++;
            pv = i - 1;
            root[i] = i;
            st[i].clear();
            st[i].push_back(i);
            cur[i] = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}