#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int C[101];
vector<int> adj[101];

void solve() {

    int n;
    cin >> n;

    n++;
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        int x;
        cin >> x;
        while (x--) {
            int f;
            cin >> f;
            adj[i].push_back(f);
        }
    }

    vector<int> dist(n + 1, -1);
    
    set<pair<int, int>> st;
    st.insert(mp(0, 0));
    while (!st.empty()) {
        auto [a, b] = *st.begin();
        st.erase(st.begin());
        if (dist[b] != -1) continue;

        dist[b] = a;
      //  cout << b << " | " << a << '\n';

        for (auto f : adj[b]) {
            if (dist[f] == -1) {
                st.insert(mp(dist[b] + 20 + C[b] + C[f], f));
            }
        }
    }

    cout << *max_element(all(dist));


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}