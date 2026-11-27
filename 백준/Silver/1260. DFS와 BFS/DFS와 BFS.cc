#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(1010);
vector<int> check(1010);

void dfs(int v) {
    if (check[v]) return;

    cout << v << ' ';
    check[v] = 1;
    for (int i : g[v]) {
        dfs(i);
    }
}

void bfs(int v) {
    queue<int> q;

    q.push(v);
    while (!q.empty()) {
        check[q.front()] = 1;
        for (int i : g[q.front()])if (!check[i]) {
            q.push(i); check[i] = 1;
        }
        cout << q.front() << ' ';
        q.pop();
    }
}


int main() {
    int n, m, v, t1, t2;
    cin >> n >> m >> v;
    while (m--) {
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for (int i = 0; i < n + 1; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(v);
    check = vector<int>(1010);
    cout << '\n';
    bfs(v);
}