#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int col[101010];
ll cnt[2][101010];
vector<int> adj[101010];
ll ans[101010];

void dfs(int v, int pv = -1) {
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        ll a = cnt[0][f];
        ll b = cnt[1][f];
        ans[v] += cnt[0][v] * b + cnt[1][v] * a;
        cnt[0][v] += a;
        cnt[1][v] += b;
    }
    cnt[col[v]][v]++;
}


void solve() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        ll ta = cnt[0][1] - cnt[0][i];
        ll tb = cnt[1][1] - cnt[1][i];
        cnt[col[i]][i]--;
        ans[i] += ta * cnt[1][i] + tb * cnt[0][i];
        cnt[col[i]][i]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}