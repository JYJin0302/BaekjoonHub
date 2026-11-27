#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[100001];
int p[100001];
int dep[100001];

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i != pv) {
        dep[i] = dep[v] + 1;
        p[i] = v;
        dfs(i, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    p[1] = 0;
    dep[1] = 0;
    dfs(1);

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> visited(n+1);
    visited[1] = 0;

    bool valid = 1;
    if (A[0] != 1) valid = 0;
    for (int i = 1; i < n; i++) {

        if (dep[A[i]] < dep[A[i - 1]]) valid = 0;
        if (dep[A[i]] == dep[A[i - 1]] && visited[p[A[i]]] < visited[p[A[i - 1]]]) valid = 0;

        visited[A[i]] = i;
    }

    cout << valid;
}