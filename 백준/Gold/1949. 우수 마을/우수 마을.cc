#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> w;
vector<vector<int>> base;

// first: not using, second: using
vector<pair<int, int>> dp;

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



int main() {

    cin >> n;
    w = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];

    base = vector<vector<int>>(n+1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        base[a].push_back(b);
        base[b].push_back(a);
    }
    dp = vector<pair<int, int>>(n + 1);

    dfs();
    cout << max(dp[1].first, dp[1].second);
}