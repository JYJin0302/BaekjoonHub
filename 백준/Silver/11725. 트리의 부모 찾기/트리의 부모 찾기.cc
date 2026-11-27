#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> base;

void dfs(int v, int p = 0) {
    for (int i : base[v]) if (i != p) {
        ans[i] = v;
        dfs(i, v);
    }
}

int main() {
    int n, a, b;
    cin >> n;

    base = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        base[a].push_back(b);
        base[b].push_back(a);
    }
    ans = vector<int>(n + 1);
    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}