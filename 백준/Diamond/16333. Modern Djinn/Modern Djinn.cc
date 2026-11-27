#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define mp make_pair

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edge(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[i] = mp(a, b);
    }

    vector<bool> color(n+1);
    while (1) {

        for (int i = 1; i <= n; i++) {
            color[i] = rng() % 2;
        }

        int cnt01 = 0, cnt10 = 0;
        for (auto f : edge) {
            int u, v;
            tie(u, v) = f;
            if (color[u] && !color[v]) cnt10++;
            else if (!color[u] && color[v]) cnt01++;
        }

        int target = m / 4 + 1;

        bool flip = 0;
        if (cnt10 >= target) {
            cout << cnt10 << '\n';
        }
        else if (cnt01 >= target) {
            cout << cnt01 << '\n';
            flip = 1;
        }
        else continue;

        for (int i = 0; i < m; i++) {
            int u, v;
            tie(u, v) = edge[i];
            if (color[u] && !color[v] && !flip) cout << i + 1 << ' ';
            else if (!color[u] && color[v] && flip) cout << i + 1 << ' ';
        }
        cout << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
