#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[1 << 16];

ll dfs(int v, int d = 0) {

    cout << v << ' ';

    if (adj[v].empty()) return v;

    ll v1 = dfs(adj[v][0], d + 1);
    ll v2 = dfs(adj[v][1], d + 1);
    assert(abs(v1 - v2) == (1 << d));
    return v + v1 + v2;
}


void solve() {

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    int l = 1, r = 1;
    int d = 1;
    int tl = 2;

    for (int i = 0; i < n - 2; i++) {
        
        for (int f = l; f <= r; f++) {
            adj[f].push_back(tl);
            adj[f].push_back(tl + d);
        }

        l <<= 1;
        r <<= 1;
        d <<= 1;
        r++;
        tl <<= 1;
    }

    for (int i = r; i >= l; i--) {
        adj[i].push_back(tl);
        adj[i].push_back(tl + d);
        tl++;
    }

    dfs(1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}