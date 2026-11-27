#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
int p[101010];
int h[101010];
int val[101010];

void dfs(int v, int pv = -1) {
    p[v] = pv;
    h[v] = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        h[v] = max(h[v], h[f] + 1);
    }
}

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a, b;
    cin >> a >> b;
    dfs(a);

    vector<int> route;
    int tv = 1;
    int tb = b;
    while (tb != -1) {
        route.push_back(tb);
        val[tb] = tv;
        tb = p[tb];
        tv++;
    }

    int ans = 0;
    int len = route.size() / 2;
    for (int i = 0; i < len; i++) {
        int tans = len;
        int v = route[i];
        for (auto f : adj[v]) if (f != p[v]) {
            //cout << v << " => " << f << " : " << len + h[f] - val[f] << '\n';
            tans = max(tans, len + h[f] - val[f]);
        }
        ans = max(ans, tans);
    }
    cout << ans;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}