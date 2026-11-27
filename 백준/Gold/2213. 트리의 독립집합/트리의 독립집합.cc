#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> w;
vector<vector<int>> base;

// first: not using, second: using
vector<pair<int, int>> dp;

vector<int> ans;

void dfs(int v = 1, int p = 0) {
    int n1 = 0, n2 = 0;
    for (auto i : base[v]) {
        if (i != p) {
            dfs(i, v);
            n1 += max(dp[i].first, dp[i].second);
            n2 += dp[i].first;
        }
        else if (base[v].size() == 1) {
            dp[v].first = 0;
            dp[v].second = w[v];
            return;
        }
    }
    dp[v].first = n1;
    dp[v].second = n2 + w[v];
}

void track(int v = 1, int p = 0, int s = 0) {
    // s = 1: 부모 노드가 ans에 들어감
    if (dp[v].first >= dp[v].second || s == 1) {
        for (int u : base[v]) if (u != p) {
            track(u, v, 0);
        }
    }
    else {
        ans.push_back(v);
        for (int u : base[v]) if (u != p) {
            track(u, v, 1);
        }
    }
}

int main() {

    cin >> n;
    w = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];

    base = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        base[a].push_back(b);
        base[b].push_back(a);
    }
    dp = vector<pair<int, int>>(n + 1);

    dfs();
    cout << max(dp[1].first, dp[1].second) << '\n';
    track();
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
}