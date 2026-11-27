#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> adj[500001];
int dist[500001];
bool isD[500001];

int md = 0, mi = -1;
int cnt1, cnt2, cnt = 0;

vector<int> ans;
void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i != pv) {
        dist[i] = dist[v] + 1;
        dfs(i, v);
    }
    md = max(md, dist[v]);
    if (dist[v] == md) mi = v;
}

void dfs2(int v, int pv = -1) {
    cnt++;
    ans.push_back(v);

    int nx = 0;
    for (auto i : adj[v]) if (i != pv) {
        if (isD[i]) nx = i;
        else if (cnt2 >= 2) {
            cnt2 -= 2;
            dfs2(i, v);
            ans.push_back(v);
        }
    }

    if (cnt1 == 0 || nx == 0) return;
    cnt1--;
    dfs2(nx, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    dist[mi] = 0;
    md = 0;
    dfs(mi);

    int ix = mi;
    while (1) {
        isD[ix] = 1;

        int nx = -1;
        for (auto i : adj[ix]) {
            if (dist[i] == dist[ix] - 1) {
                nx = i;
            }
        }

        if (nx == -1) break;
        ix = nx;
    }

    cnt1 = min(k, dist[mi]);
    cnt2 = max(0, k-dist[mi]);

    dfs2(mi);

    cout << cnt << '\n';
    cout << ans.size()-1 << '\n';
    for (auto i : ans) cout << i << '\n';
}