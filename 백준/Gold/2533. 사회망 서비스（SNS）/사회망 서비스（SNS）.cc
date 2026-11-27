#include <bits/stdc++.h>
using namespace std;

int n, a, b, cnt, ans;
vector<vector<int>> base;
vector<int> state; // 0: not defined, 1: early, 2: not-early

void dfs(int v = 1, int p = 0) {

    bool need = false;
    for (int i : base[v]) {
        if (i != p) {
           dfs(i, v);
           if (state[i] == 2) need = true;
        }
        else if (base[v].size() == 1) {
            state[v] = 2;
            return;
        }
    }
    if (need) state[v] = 1;
    else state[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    base = vector<vector<int>>(n + 1);
    state = vector<int>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        base[a].push_back(b);
        base[b].push_back(a);
    }
    dfs();

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (state[i] == 1) cnt++;
    }
    cout << cnt;
}