#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
ll val[101010];

void dfs(int v) {
    for (auto f : adj[v]) {
        dfs(f);
        if (val[f] > 0) val[v] += val[f];
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        cnt[b]++;
    }

    for (int i = 0; i < n; i++) cin >> val[i];

    int r = 0;
    for (int i = 0; i < n; i++) if (cnt[i] == 0) r = i;

    dfs(r);
    cout << val[r] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}