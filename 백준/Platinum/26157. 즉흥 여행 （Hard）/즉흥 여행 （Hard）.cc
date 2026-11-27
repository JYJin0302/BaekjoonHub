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
    vector<pair<int, int>> edge;
    while (m--) {
        int a, b;
        cin >> a >> b;

        edge.push_back({ a, b });
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    visited = vector<bool>(n+1);

    while (!st.empty()) {
        
        int a = st.top();
        st.pop();

        if (!visited[a]) {
            dfs2(a, a);
        }
    }

    vector<vector<int>> conn(n + 1);
    vector<int> topo(n + 1);
    for (auto i : edge) {
        int a, b;
        tie(a, b) = i;

        a = rep[a], b = rep[b];
        if (a == b) continue;

        conn[a].push_back(b);
        topo[b]++;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i == rep[i] && topo[i] == 0) ans.push_back(i);
    }

    if (ans.size() > 1) cout << 0;
    else {

        bool valid = 1;

        int v = ans[0];

        queue<int> q;
        q.push(v);
        while (!q.empty()) {

            if (q.size() != 1) valid = 0;

            int a = q.front();
            q.pop();

            for (auto i : conn[a]) {
                topo[i]--;
                if (topo[i] == 0) q.push(i);
            }
        }

        if (!valid) cout << 0;
        else {
            ans.clear();

            for (int i = 1; i <= n; i++) if (rep[i] == v) ans.push_back(i);

            cout << ans.size() << '\n';
            for (auto i : ans) cout << i << ' ';
        }
    }

}