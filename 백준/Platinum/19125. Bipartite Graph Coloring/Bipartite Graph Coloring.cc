#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
vector<pair<int, vector<int>>> adj[44];
int col[44];
void dfs(int v) {
    for (auto &[f, u] : adj[v]) {
        if (col[f] != -1) continue;
        col[f] = 1 - col[v];
        dfs(f);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        vector<int> tmp(4);
        cin >> a >> b;
        for (auto& i : tmp) cin >> i;

        adj[a].push_back(mp(b, tmp));
        swap(tmp[1], tmp[2]);
        adj[b].push_back(mp(a, tmp));
    }

    memset(col, -1, sizeof col);
    col[1] = 0;
    dfs(1);

    vector<int> c0, c1;
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) c0.push_back(i);
        else c1.push_back(i);
    }
    if (c0.size() > c1.size()) swap(c0, c1);
    int tn = c0.size();

    ll ans = 0;
    vector<bool> tcol(n+1);
    for (int i = 0; i < (1 << tn); i++) {
        // 0 : white, 1 : black
        for (int j = 0; j < tn; j++) {
            if (i & (1 << j)) tcol[c0[j]] = 1;
        }
        ll mult = 1;
        for (auto f : c1) {
            ll white = 1, black = 1;
            
            for (auto [u, v] : adj[f]) {
                (white *= v[tcol[u]]) %= mod;
                (black *= v[2 + tcol[u]]) %= mod;
            }
            (mult *= (white + black) % mod) %= mod;
        }
        (ans += mult) %= mod;


        for (int j = 0; j < tn; j++) {
            if (i & (1 << j)) tcol[c0[j]] = 0;
        }
    }
    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}