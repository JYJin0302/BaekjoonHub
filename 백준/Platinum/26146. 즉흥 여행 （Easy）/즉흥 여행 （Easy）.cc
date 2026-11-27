#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> adj[200001], rev[200001];
vector<bool> visited;
stack<int> st;
int rep[200001];

void dfs(int v) {
    visited[v] = 1;
    for (auto i : adj[v]) if (!visited[i]) {
        dfs(i);
    }
    st.push(v);
}

void dfs2(int v, int rp) {
    visited[v] = 1;
    rep[v] = rp;

    for (auto i : rev[v]) if (!visited[i]) {
        dfs2(i, rp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    visited = vector<bool>(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    visited = vector<bool>(n+1);

    int cnt = 0;
    while (!st.empty()) {
        
        int a = st.top();
        st.pop();

        if (!visited[a]) {
            cnt++;
            dfs2(a, a);
        }
    }

    if (cnt > 1) cout << "No";
    else cout << "Yes";
}