#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, ll>> adj[1010];

multiset<ll> dList[1010];
int topo[1010];

void solve() {

    int n, m, k;
    cin >> n >> m >> k;


    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        topo[b]++;
    }

    queue<int> q;

    for (int i = 1; i < n; i++) {
        if (topo[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto [u, v] : adj[a]) {
            topo[u]--;
            if (topo[u] == 0) q.push(u);
        }
    }

    q.push(n);
    dList[n].insert(0);
    while (!q.empty()) {
        int a = q.front(); q.pop();

        for (auto [u, v] : adj[a]) {
            for (auto f : dList[a]) {
                if (dList[u].size() == k && *dList[u].rbegin() <= f + v) break;
                dList[u].insert(f + v);
                while (dList[u].size() > k) dList[u].erase(--dList[u].end());
            }

            topo[u]--;
            if (topo[u] == 0) q.push(u);
        }
    }

    vector<int> ans;
    for (auto f : dList[1]) ans.push_back(f);
    while (ans.size() < k) ans.push_back(-1);
    for (auto f : ans) cout << f << '\n';

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}