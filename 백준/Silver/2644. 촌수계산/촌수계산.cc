#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int ans = -1;
void dfs(int v, int pv, int t, int cnt = 0) {
    if (v == t) {
        ans = cnt;
        return;
    }

    for (int i : adj[v]) if (i != pv) {
        dfs(i, v, t, cnt + 1);
    }
}

int main() {

    int n;
    cin >> n;
    int s, t;
    cin >> s >> t;

    adj = vector < vector<int>>(n + 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(s, 0, t);

    cout << ans;
}