#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> adj[500001];
vector<int> rev[500001];
bool visited[500001];
int rep[500001];
int dp[500001];
int topo[500001];
stack<int> st;
vector<int> A;
vector<bool> valid;

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (!visited[i]) {
        visited[i] = 1;
        dfs(i, v);
    }
    st.push(v);
}

void dfs2(int v, int val) {
    for (auto i : rev[v]) if (rep[i] == 0) {
        rep[i] = val;
        dfs2(i, val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> inp;
    while (m--) {
        int a, b;
        cin >> a >> b;
        inp.push_back({ a, b });
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    A= vector<int> (n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    int s, k;
    cin >> s >> k;
    vector<int> isR(k);
    for (auto& i : isR) cin >> i;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }

    while (!st.empty()) {

        int a = st.top();
        st.pop();

        if (rep[a] != 0) continue;
        rep[a] = a;
        dfs2(a, a);
    }


    valid= vector<bool> (n + 1);
    for (auto i : isR) {
        valid[rep[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        if (rep[i] != i) {
            A[rep[i]] += A[i];
        }
    }

    for (auto i : inp) {
        int a, b;
        tie(a, b) = i;
        a = rep[a], b = rep[b];
        if (a != b) {
            topo[b]++;
            adj[a].push_back(b);
        }
    }

    s = rep[s];
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (i == rep[i] && i != rep[s] && topo[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        if (a == s) continue;

        for (auto i : adj[a]) {
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
    }
    int ans = 0;
    q.push(s);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        dp[a] += A[a];

        for (auto i : adj[a]) {
            dp[i] = max(dp[i], dp[a]);
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }

    }

    for (int i = 1; i <= n; i++) {
        if (i == rep[i] && valid[i]) ans = max(ans, dp[i]);
    }

    cout << ans;

}