#include<bits/stdc++.h>
using namespace std;

vector<bool> check;
vector<vector<int>> base;
void dfs(int k) {
    if (check[k]) return;
    check[k] = true;
    for (auto i : base[k]) {
        dfs(i);
    }
}


int main() {
    int n, m, t;
    cin >> n >> m;

    base = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            if (t) base[i].push_back(j);
        }
    }

    vector<int> visit(m);
    for (auto& i : visit) cin >> i;

    check = vector<bool>(n + 1);
    dfs(visit[0]);

    bool ok = true;
    for (int i = 1; i < m; i++) {
        if (!check[visit[i]]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO");
}