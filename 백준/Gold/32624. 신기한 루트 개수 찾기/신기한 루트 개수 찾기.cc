#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[303030];
int cnt[303030];

void dfs(int v, int pv = -1) {
    cnt[v] = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        cnt[v] += cnt[f];
    }
}

void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    dfs(a); ans += cnt[b];
    dfs(b); ans += cnt[a];
    cout << n - ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
