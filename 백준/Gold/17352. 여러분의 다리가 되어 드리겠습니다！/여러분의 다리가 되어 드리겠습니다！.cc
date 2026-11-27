#include <bits/stdc++.h>
using namespace std;

vector<bool> check;
vector<vector<int>> base;

void dfs(int i) {
    if (check[i]) return;
    check[i] = true;
    for (auto k : base[i]) {
        dfs(k);
    }
}


int main() {
    int n, n1, n2;
    cin >> n;
    check = vector<bool>(n + 1);
    base = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 2; i++) {
        cin >> n1 >> n2;
        base[n1].push_back(n2);
        base[n2].push_back(n1);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        cout << 1 << ' ' << i;
        return 0;
    }
}