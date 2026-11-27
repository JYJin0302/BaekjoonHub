#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, int>> adj[1010];
int val[1010];
void solve() {

    memset(val, -1, sizeof val);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    queue<int> q;
    q.push(1);
    val[1] = 0;

    while (!q.empty()) {
        int a = q.front(); q.pop();

        for (auto [u, v] : adj[a]) if(val[u] == -1) {
            val[u] = val[a] ^ v;
            q.push(u);
        }
    }

    cout << val[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}