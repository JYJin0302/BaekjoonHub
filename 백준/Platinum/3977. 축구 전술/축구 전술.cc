#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MAX_N = 200010;

vector<int> adj[MAX_N];
vector<int> rev[MAX_N];
bool visited[MAX_N];
int rep[MAX_N];
int topo[MAX_N];
stack<int> st;

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (!visited[i]) {
        visited[i] = 1;
        dfs(i, v);
    }
    st.push(v);
}

void dfs2(int v, int val) {
    for (auto i : rev[v]) if (rep[i] == -1) {
        rep[i] = val;
        dfs2(i, val);
    }
}


void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n*2; i++) {
        adj[i].clear();
        rev[i].clear();
        visited[i] = 0;
        rep[i] = -1;
        topo[i] = 0;
    }

    vector<pair<int, int>> A;
    while (m--) {
        int a, b;
        cin >> a >> b;

        A.push_back({ a, b });
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 0; i < n*2; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
    while (!st.empty()) {

        int a = st.top();
        st.pop();

        if (rep[a] != -1) continue;

        rep[a] = a;
        dfs2(a, a);
    }

    for (auto i : A) {
        int a, b;
        tie(a, b) = i;

        a = rep[a], b = rep[b];
        if (a != b) {
            topo[b]++;
        }
    }


    bool ok = 1;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (rep[i] == i && topo[i] == 0) {
            if (ans != -1) ok = 0;
            else ans = i;
        }
    }

    if (!ok) cout << "Confused\n";
    else {
        for (int i = 0; i < n; i++) {
            if (rep[i] == ans) cout << i << '\n';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}