#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int C[303];
int W[303][303];

int root[303];
bool chk[303];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void solve() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> C[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> W[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }

    set<pair<int, pair<int, int>>> st;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j) st.insert(mp(C[i], mp(i, i)));
            else st.insert(mp(W[i][j], mp(i, j)));
        }
    }

    ll ans = 0;
    for (auto f : st) {
        auto[ u, v] = f.y;
        int cost = f.x;

        if (u == v) {
            u = find(u);
            if (chk[u]) continue;
            chk[u] = 1;
            ans += cost;
        }
        else {
            u = find(u);
            v = find(v);
            if (u == v) continue;
            if (chk[u] && chk[v]) continue;
            ans += cost;
            root[v] = u;
            chk[u] = chk[u] || chk[v];
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