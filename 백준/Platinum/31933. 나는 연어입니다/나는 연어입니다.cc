#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

struct E {
    int u, v;
    int l, r;
};
vector<E> adj[5050];

vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}
int n, m;

bool chk(int l, int r) {

    vector<bool> vis(n + 1);
    vis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int a = q.front(); q.pop();
        
        if (a == n) return 1;
        for (auto f : adj[a]) {
            int v = f.u + f.v - a;

            if (f.l <= l && f.r >= r && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return 0;
}


void solve() {
    
    cin >> n >> m;

    while (m--) {
        int u, v;
        int d, t;
        cin >> u >> v >> d >> t;
        adj[u].push_back({ u, v, d, t });
        adj[v].push_back({ u, v, d, t });
        num.push_back(d);
        num.push_back(t + 1);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int k;
    cin >> k;
    vector<int> salmon(k);
    for (auto& i : salmon) cin >> i;

    vector<pair<int, int>> able;
    for (int i = 1; i < num.size(); i++) {
        if (chk(num[i - 1], num[i] - 1)) {
            able.push_back(mp(num[i - 1], num[i] - 1));
        }
    }

    int ans = 0;
    for (auto f : salmon) {
        int ix = lower_bound(all(able), mp(f + 1, -1)) - able.begin() - 1;
        if (ix < 0 || ix >= able.size()) {}
        else {
            auto [a, b] = able[ix];
            if (a <= f && f <= b) ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}