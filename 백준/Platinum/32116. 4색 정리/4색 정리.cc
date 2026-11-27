#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[202020];

bool C[5][5];

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edg;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        adj[a].push_back(b);
        edg.push_back(mp(a, b));
    }

    for (int i = 1; i <= n; i++) {
        sort(all(adj[i]));
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        C[a][b] = C[b][a] = 1;
    }

    vector<int> col;
    for (int i = 1; i <= 4; i++) {
        bool ok = 1;
        for (int a = 1; a <= 4; a++) {
            for (int b = a + 1; b <= 4; b++) {
                if (a == i || b == i) continue;
                if (C[a][b]) ok = 0;
            }
        }

        if (ok) {
            for (int a = 1; a <= 4; a++) {
                if (a != i) col.push_back(a);
            }
            break;
        }
    }

    if (!col.empty()) {

        // 3 coloring
        vector<int> C(n + 1, -1);

        C[1] = 0;
        queue<pair<int, int>> q;
        q.push(mp(1, 1));
        while (!q.empty()) {

            auto [a, b] = q.front(); q.pop();
            //cout << "Go: " << a << ' ' << b << '\n';
            if (a == b) {
                int cur = C[a];
                int cc = 0;
                for (int i = a + 1; i <= n;) {
                    if (cc) C[i] = (cur + 1) % 3;
                    else C[i] = (cur + 2) % 3;
                    cc ^= 1;

                    if (!adj[i].empty()) {
                        q.push(mp(i, adj[i].back()));
                        i = adj[i].back();
                    }
                    else i++;
                }
            }
            else {
                int cc = 0;
                vector<int> lst;
                int c1 = C[b];
                int c2 = 3 - C[a] - C[b];
                for (int i = a + 1; i < b;) {
                    lst.push_back(i);
                    if (!adj[i].empty()) {
                        q.push(mp(i, adj[i].back()));
                        i = adj[i].back();
                    }
                    else i++;
                }

                for (int i = lst.size() - 1; i >= 0; i--) {
                    C[lst[i]] = c2;
                    swap(c1, c2);
                }

            }

            //  for (auto f : C) cout << f << ' ';
            //  cout << '\n';
        }

        for (auto [a, b] : edg) {
            assert(C[a] != C[b]);
        }
        for (int i = 1; i <= n; i++) {
            cout << col[C[i]] << ' ';
        }
        return;
    }



    for (int a = 1; a <= 4; a++) {
        for (int b = a + 1; b <= 4; b++) {
            if (!C[a][b]) {
                col.push_back(a);
                col.push_back(b);
                break;
            }
        }
        if (!col.empty()) break;
    }


    if (col.empty()) {
        cout << -1;
        return;
    }

    // 2 coloring

    for (auto [a, b] : edg)  adj[b].push_back(a);
    vector<int> C(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (C[i] != -1) continue;

        C[i] = 1;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto f : adj[a]) {
                if (C[f] == -1) {
                    C[f] = 1 - C[a];
                    q.push(f);
                }
                else if (C[f] != 1 - C[a]) {
                    cout << -1;
                    return;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << col[C[i]] << ' ';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}