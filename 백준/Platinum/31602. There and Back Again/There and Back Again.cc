#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[101010];
int distS[101010];
int distE[101010];

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edg;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
        edg.push_back(mp(mp(a, b), c));
    }

    memset(distS, -1, sizeof(distS));
    memset(distE, -1, sizeof(distE));

    priority_queue<pair<int, int>> pq;
    pq.push(mp(0, 1));

    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (distS[b] != -1) continue;
        distS[b] = -a;
        for (auto& [x, y] : adj[b]) {
            if (distS[x] == -1) {
                pq.push(mp(a - y, x));
            }
        }
    }

    pq.push(mp(0, n));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (distE[b] != -1) continue;
        distE[b] = -a;
        for (auto& [x, y] : adj[b]) {
            if (distE[x] == -1) {
                pq.push(mp(a - y, x));
            }
        }
    }

    ll ans = distS[n];
    if (ans == -1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> from(n + 1);
    int pos = n;
    while (pos != 1) {
        for (auto& [a, b] : adj[pos]) {
            if (distS[a] + b == distS[pos]) {
                from[pos] = a;
                pos = a;
                break;
            }
        }
    }

    ll mn = 1e18;
    for (auto f : edg) {
        auto& [a, b] = f.first;
        if (from[a] != b && from[b] != a && distS[a] != -1) {
            mn = min({ mn, (ll)distS[a] + distE[b] + f.second , (ll)distE[a] + distS[b] + f.second });
        }
    }
    if (mn == 1e18) cout << -1;
    else cout << ans + mn << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}