#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


ll n, k;
int ans = 1;
vector<pair<ll, ll>> adj[101010];

multiset<ll> dList[101010];
ll dist[101010];

void dfs(int v, int pv = -1) {
    dList[v].insert(dist[v]);
    ll diff = 0;
    for (auto f : adj[v]) if (f.first != pv) {
        dist[f.first] = dist[v] + f.second;
        dfs(f.first, v);

        int a = f.first;
        int b = v;

        if (dList[a].size() > dList[b].size()) {
            for (auto i : dList[b]) {
                dList[a].insert(i);
            }
            swap(dList[a], dList[b]);
        }
        else {
            for (auto i : dList[a]) {
                dList[b].insert(i);
            }
        }
    }
    while (*dList[v].rbegin() > dist[v] + k) dList[v].erase(*dList[v].rbegin());

    int res = dList[v].size();
    ans = max(ans, res);

    /*cout << "Res: " << v << " " << res << ' ';
    for (auto f : dList[v]) cout << f << ' ';
    cout << '\n';*/
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    dfs(1);
    cout << ans;
}
