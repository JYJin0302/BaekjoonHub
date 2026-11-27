#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair

vector<int> adj[303030];
int p[303030];

int cntT = 0;
int cnt0 = 0;
void dfs(int v, int pv = -1) {
    cntT++;
    if (p[v] == 0) cnt0++;
    for (auto f : adj[v]) if (f != pv){
        if (p[f] == -1) {
            p[f] = 1 - p[v];
            dfs(f, v);
        }
        else if (p[f] != 1 - p[v]) {
            cout << -1 << '\n';
            exit(0);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(p, -1, sizeof p);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == -1) {
            cntT = 0, cnt0 = 0;
            p[i] = 0;
            dfs(i);

            ans += min(cnt0, cntT - cnt0);
        }
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}