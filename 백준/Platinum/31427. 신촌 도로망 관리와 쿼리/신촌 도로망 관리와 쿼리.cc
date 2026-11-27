#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


vector<int> ord(5);

struct Edge {
    int u, v;
    int idx;
} edgList[101010];

int val[5050][5];

int root[50505];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

bool cmp(Edge& a, Edge& b) {
    return find(all(ord), a.idx) < find(all(ord), b.idx);
}

void solve() {

    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;

    for (int i = 0; i < 5; i++) {
        ord[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        char c;
        cin >> c;
        
        edgList[i] = { a, b, c - 'A' };
    }

    do {

        sort(edgList, edgList + m, cmp);

        int state = 0;
        for (int i = 0; i < 5; i++) state = state * 5 + ord[i];

        for (int i = 1; i <= n; i++) root[i] = i;

        vector<int> ans(5);
        for (auto& i : edgList) {
            int u = find(i.u);
            int v = find(i.v);
            if (u != v) {
                root[u] = v;
                ans[i.idx]++;
            }
        }

        for (int i = 0; i < 5; i++) val[state][i] = ans[i];

    } while (next_permutation(all(ord)));

    while (q--) {

        vector<pair<ll, ll>> inp;
        for (int i = 0; i < 5; i++) {
            ll x;
            cin >> x;
            inp.push_back(mp(x, i));
        }

        sort(all(inp));

        int state = 0;
        for (int i = 0; i < 5; i++) {
            state = state * 5 + inp[i].second;
        }

        ll ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += inp[i].first * val[state][inp[i].second];
        }
        cout << ans << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}