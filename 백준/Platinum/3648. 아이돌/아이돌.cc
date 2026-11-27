#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> adj[2001];
vector<int> rev[2001];
bool visited[2001];
int rep[2001];
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {

        // init
        for (int i = 1; i <= 2 * n; i++) {
            adj[i].clear();
            rev[i].clear();
            rep[i] = 0;
            visited[i] = 0;
        }

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

            rev[a].push_back(tb);
            rev[b].push_back(ta);
        }

        bool ok = 1;
        for (int i = 1; i <= 2 * n; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                dfs(i);

                if (i == 1 && visited[i + n]) ok = 0;
            }
        }

        while (!st.empty()) {

            int a = st.top();
            st.pop();

            if (rep[a] != 0) continue;
            rep[a] = a;
            dfs2(a, a);
        }


        for (int i = 1; i <= n; i++) {
            if (rep[i] == rep[i + n]) ok = 0;
        }



        if (ok) cout << "yes\n";
        else cout << "no\n";
    }
}