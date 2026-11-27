#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> adj[4001];
vector<int> rev[4001];
bool visited[4001];
int rep[4001];
stack<int> st;

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


void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= (n + m) * 2; i++) {
        adj[i].clear();
        rev[i].clear();
        visited[i] = 0;
        rep[i] = 0;
    }

    // 1-n 가로 (upward), n+1 - n+m 세로(rightward), n+m+1 - 2*n+m -가로(downward), 2*n+m+1 - 2*n+2*m -세로(leftward)

    // true : right, up; false : down, left
    while (k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == c && b == d) continue;
        // a,b -> c,d

        int x1, x2, y1, y2;
        int rx1, rx2, ry1, ry2;
        if (a < c) {
            y1 = n+b;
            ry1 = b + 2*n + m;
            y2 = n+d;
            ry2 = d + 2*n + m;
        }
        else {
            y1 = b + 2*n + m;
            ry1 =n+ b;
            y2 = d + 2*n + m;
            ry2 = n+d;
        }

        if (b < d) {
            x1 = a;
            rx1 = a + n + m;
            x2 = c;
            rx2 = c + n + m;
        }
        else {
            x1 = a + n + m;
            rx1 = a;
            x2 = c + n + m;
            rx2 = c;
        }

        adj[rx1].push_back(x2);
        adj[rx1].push_back(y1);
        adj[ry1].push_back(x1);
        adj[ry1].push_back(y2);

        adj[rx2].push_back(x1);
        adj[rx2].push_back(y2);
        adj[ry2].push_back(x2);
        adj[ry2].push_back(y1);

        rev[x2].push_back(rx1);
        rev[y1].push_back(rx1);
        rev[x1].push_back(ry1);
        rev[y2].push_back(ry1);
        
        rev[x1].push_back(rx2);
        rev[y2].push_back(rx2);
        rev[x2].push_back(ry2);
        rev[y1].push_back(ry2);
    }

    for (int i = 1; i <= (n + m) * 2; i++) {
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

    bool ok = 1;
    for (int i = 1; i <= n + m; i++) {
        if (rep[i] == rep[i + n + m]) ok = 0;
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
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