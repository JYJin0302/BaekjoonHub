#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[505050];
bool vis[505050];

void solve() {

    int n, m, r;
    cin >> n >> m >> r;

    vector<ll> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    set<pair<ll, ll>> st;
    st.insert(mp(A[r], r));
    vis[r] = 1;

    ll cur = 0;
    while (!st.empty()) {
        auto [a, b] = *st.begin();
        st.erase(st.begin());
        if (a > cur) break;
        cur += B[b];
        for (auto f : adj[b]) if (!vis[f]) {
            vis[f] = 1;
            st.insert(mp(A[f], f));
        }
    }
    cout << cur << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}