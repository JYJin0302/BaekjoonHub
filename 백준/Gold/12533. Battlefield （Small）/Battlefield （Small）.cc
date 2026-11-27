#include <bits/stdc++.h>
using namespace std;


vector<int> adj[1010];
bool vs[1010];
int cnt = 0;

void dfs(int v, int pv = -1) {
    if (adj[v].size() & 1) cnt++;
    for (auto i : adj[v]) if (!vs[i]) {
        vs[i] = 1;
        dfs(i, v);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            adj[i].clear();
            vs[i] = 0;
        }

        while (m--) {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> lst;
        for (int i = 0; i < n; i++) {
            if (vs[i] || adj[i].empty()) continue;
            vs[i] = 1;
            cnt = 0;
            dfs(i);
            lst.push_back(cnt);
        }

        sort(lst.rbegin(), lst.rend());

        int ans = lst.size() - 1;
        int curr = lst[0];
        for (int i = 1; i < lst.size(); i++) {
            if (curr && lst[i]) {
                curr += lst[i] - 2;
            }
            else if (curr || lst[i]) {

            }
            else {
                curr = 2;
            }
        }
        ans += curr / 2;
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}