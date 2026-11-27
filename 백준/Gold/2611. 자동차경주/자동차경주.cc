#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[1010];
int topo[1010];
int from[1010];

void solve() {

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == 1) b += n;
        adj[a].push_back(mp(b, c));
        topo[b]++;
    }

    vector<int> ans(n + 2);

    queue<int> q;
    q.push(1);
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (auto &[x, y] : adj[a]) {
            ans[x] = max(ans[x], ans[a] + y);
            if (ans[x] == ans[a] + y) from[x] = a;
            topo[x]--;
            if (topo[x] == 0) q.push(x);
        }
    }
    vector<int> route = { 1 };
    int cur = n + 1;
    while (cur != 1) {
        cur = from[cur];
        route.push_back(cur);
    }
    reverse(all(route));
    cout << ans[n + 1] << '\n';
    for (auto f : route) cout << f << ' ';
    cout << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}