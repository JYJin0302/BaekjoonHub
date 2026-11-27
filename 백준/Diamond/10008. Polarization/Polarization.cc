#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n;
int sz[250101], tsz[250101];
vector<int> adj[250101];

vector<int> ansList;
void dfs(int v, int pv = -1) {

    int mx = 0;
    sz[v] = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        sz[v] += sz[f];

        mx = max(mx, sz[f]);
    }
    mx = max(mx, n - sz[v]);

    if (mx * 2 <= n) {
        ansList.push_back(v);
    }
}

void dfs2(int v, int pv = -1) {

    tsz[v] = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs2(f, v);
        tsz[v] += tsz[f];
    }
}

ll getVal(int ix) {

    map<int, int> cnt;
    cnt.clear();
    for (auto f : adj[ix]) {
        if (sz[f] < sz[ix]) cnt[sz[f]]++;
    }
    cnt[n - sz[ix]]++;

    vector<int> v;
    for (auto f : cnt) {
        int x = f.second;

        int tv = 1;
        while (x >= tv) {
            v.push_back(f.first * tv);
            x -= tv;
            tv *= 2;
        }
        if (x) v.push_back(f.first * x);
    }

    bitset<1000000> bt;
    bt[0] = 1;
    for (auto f : v) {
        bt |= bt << f;
    }

    ll res = 0;
    for (ll i = 0; i <= n; i++) {
        if (bt[i]) res = max(res, (n - i) * (i + 1));
    }
   // cout << "RES1: " << res << '\n';

    dfs2(ix);
    for (int i = 1; i <= n; i++) if (i != ix) res += tsz[i];

   // cout << "GET ans: " << ix << ' ' << res << '\n';
    return res - n;

}

void solve() {

    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    ll ans = 0;

    for (auto f : ansList) {
        ans = max(ans, getVal(f));
    }
    cout << n-1 << ' '  << ans;
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