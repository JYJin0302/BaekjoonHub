#include <bits/stdc++.h>
using namespace std;


vector<bool> check;
vector<int> base;
vector<int> ans;

void dfs(int i, int s) {
    if (i == s) {
        ans.push_back(s);
        return;
    }
    if (check[i]) return;
    check[i] = 1;
    dfs(base[i], s);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    base = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> base[i];
    }

    check = vector<bool>(n + 1);
    for (int i = 1; i <= n; i++) {
        dfs(base[i], i);
        check = vector<bool>(n + 1);
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << '\n';
}