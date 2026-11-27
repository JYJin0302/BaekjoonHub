#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, int>> adj[1010];

void solve() {


    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        vector<int> dist(n + 1, -1);
        set<pair<int, int>> st;
        st.insert(mp(0, a));
        while (!st.empty()) {
            auto [u, v] = *st.begin();
            st.erase(st.begin());

            if (dist[v] != -1) continue;
            dist[v] = u;

            for (auto [w, z] : adj[v]) {
                if (dist[w] == -1) {
                    st.insert(mp(dist[v] + z, w));
                }
            }
        }

        cout << dist[b] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}