#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

map<int, int> st[201010];

void solve() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> color(n-1);
    vector<pair< int, int>> edge(n-1);

    for (int i = 0; i < n - 1; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = mp(a, b);
        st[a][0] ++;
        st[b][0]++;
        color[i] = c;
    }

    int ans = 1;

    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        tie(a, b) = edge[i];
        c = color[i];

        st[a][0]--;
        st[b][0]--;
        if (st[a][0]) ans++;
        if (st[b][0]) ans++;
        if (st[a][c]) ans--;
        if (st[b][c]) ans--;
        st[a][c]++;
        st[b][c]++;
    }

    while (q--) {

        int x, y;
        cin >> x >> y;
        x--;

        int a, b;
        tie(a, b) = edge[x];
        st[a][color[x]]--;
        st[b][color[x]]--;
        if (st[a][color[x]]) ans++;
        if (st[b][color[x]]) ans++;
        
        if (st[a][y]) ans--;
        if (st[b][y]) ans--;
        st[a][y]++;
        st[b][y]++;

        color[x] = y;
        cout << ans << '\n';
    }

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