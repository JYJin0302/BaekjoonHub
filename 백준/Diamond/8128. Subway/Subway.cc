#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[1000001];
int dist[1000001];
int dp[1000001];
int cnt[1000001];

void dfs(int v, int pv = -1) {

    for (auto i : adj[v]) if (i != pv) {
        dist[i] = dist[v] + 1;
        dfs(i, v);
    }

}

int dfs2(int v, int pv = -1) {

    int rs = 1;
    int mx = 0;
    for (auto i : adj[v]) if (i != pv) {

        int tv = dfs2(i, v);
        mx = max(mx, tv);
        cnt[tv]++;
    }

    if (mx) {
        cnt[mx]--;
        rs += mx;
    }
    return rs;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    int mi = 0, md = 0;
    for (int i = 1; i <= n; i++) {
        if (md < dist[i]) {
            md = dist[i];
            mi = i;
        }
    }

    if (k == 0) {
        cout << 0;
        return 0;
    }

    int ans = dfs2(mi);
    int tc = 2 * k - 2;
    for (int i = n; i >= 1; i--) {
        if (tc == 0) break;

        int tx = min(cnt[i], tc);
        ans += tx * i;
        tc -= tx;
    }

    cout << ans;
}