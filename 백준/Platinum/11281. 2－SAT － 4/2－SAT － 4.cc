#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> adj[20001];
vector<int> rev[20001];
vector<int> rst[20001];
bool visited[20001];
int rep[20001];
int topo[20001];
stack<int> st;

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (!visited[i]) {
        visited[i] = 1;
        dfs(i, v);
    }
    st.push(v);
}

void dfs2(int v, int val) {
    rst[val].push_back(v);
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

        if (a < 0) a = n - a;
        if (b < 0) b = n - b;

        int ta, tb;
        if (a > n) ta = a - n;
        else ta = a + n;

        if (b > n) tb = b - n;
        else tb = b + n;

        adj[ta].push_back(b);
        adj[tb].push_back(a);
        inp.push_back({ ta, b });
        inp.push_back({ tb, a });

        rev[a].push_back(tb);
        rev[b].push_back(ta);
    }

    for (int i = 1; i <= n * 2; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
    int cnt = 0;
    while (!st.empty()) {

        int a = st.top();
        st.pop();

        if (rep[a] != 0) continue;
        rep[a] = ++cnt;
        dfs2(a, rep[a]);
    }

    bool valid = 1;
    for (int i = 1; i <= n; i++) {
        if (rep[i] == rep[i + n]) valid = 0;
    }

    if (!valid) {
        cout << 0;
        return 0;
    }

    cout << "1\n";
    for (int i = 1; i <= n; i++) {
        if (rep[i] > rep[i + n]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

}