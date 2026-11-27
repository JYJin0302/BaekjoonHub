#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string A[1010];

vector<int> adj[1010101];
int spt[1010101][22];
int dep[1010101];

void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i != pv) {
        spt[i][0] = v;
        dep[i] = dep[v] + 1;
        dfs(i, v);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cin.ignore();

    string s;
    for (int i = 0; i < n + 1; i++) {
        getline(cin, s);
        A[i] = s;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 2 * m; j+= 2) {

            int ix = (i-1) * m + (j + 1) / 2;

            if (A[i][j + 1] != '|') adj[ix].push_back(ix + 1);

            if (A[i][j - 1] != '|') adj[ix].push_back(ix - 1);

            if (A[i][j] != '_') adj[ix].push_back(ix + m);

            if (A[i - 1][j] != '_') adj[ix].push_back(ix - m);
        }
    }

    dfs(1);
    for (int i = 1; i < 22; i++) {
        for (int j = 1; j <= n * m; j++) {
            spt[j][i] = spt[spt[j][i - 1]][i - 1];
        }
    }

    int q, pv = -1;
    ll ans = 0;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        int ix = (a - 1) * m + b;
        int tx = ix;
        if (pv != -1) {

            int tans = dep[ix] + dep[pv];

            if (dep[ix] > dep[pv]) swap(ix, pv);
            int diff = dep[pv] - dep[ix];
            for (int i = 0; i < 22; i++) {
                if (diff & (1 << i)) {
                    pv = spt[pv][i];
                }
            }

            for (int i = 21; i >= 0; i--) {
                if (spt[ix][i] != spt[pv][i]) {
                    ix = spt[ix][i];
                    pv = spt[pv][i];
                }
            }

            if (pv != ix) pv = spt[pv][0];

            tans -= 2 * dep[pv];

            ans += tans;
        }
        pv = tx;
    }
    cout << ans;
}