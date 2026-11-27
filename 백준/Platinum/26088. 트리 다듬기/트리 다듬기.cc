#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int dist[100001];
int dp[100001];

vector<int> ans;

void dfs(int v, int pv = -1) {
    dp[v] = 1;
    vector<int> tmp;
    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);
        tmp.push_back(dp[i]);
    }

    if (tmp.size() == 1) {
        dp[v] = tmp[0] + 1;
    }
    else if (tmp.size() > 1) {

        sort(tmp.rbegin(), tmp.rend());
        dp[v] = tmp[0] + 1;
        for (int i = 1; i < tmp.size(); i++) ans.push_back(tmp[i]);

    }
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

    // bfs 1
    queue<int> q;
    dist[1] = 1;
    q.push(1);
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (auto i : adj[a]) if (dist[i] == 0){
            dist[i] = dist[a] + 1;
            q.push(i);
        }
    }

    int md = 0, mi = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > md) {
            md = dist[i];
            mi = i;
        }
    }

    // dfs mi
    dfs(mi);
    
    sort(ans.rbegin(), ans.rend());

    int tz = ans.size();
    int res = dp[mi];
    for (int i = 0; i < min(tz, k); i++) res += ans[i];
    cout << res - 1;
}