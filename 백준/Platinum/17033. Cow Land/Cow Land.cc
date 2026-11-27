#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using ll = long long;

int o = 1;
int n, q;
int s[101010], e[101010];
vector<int> adj[101010];

int dep[101010];
int spt[18][101010];

int seg[404040];

void dfs(int v, int pv = -1) {
    s[v] = o++;
    for (auto i : adj[v]) if (i != pv) {
        dep[i] = dep[v] + 1;
        spt[0][i] = v;
        dfs(i, v);
    }
    e[v] = o++;
}

int getLca(int u, int v) {

    if (dep[u] > dep[v]) swap(u, v);

    int diff = dep[v] - dep[u];
    for (int i = 0; i < 18; i++) {
        if (diff & (1 << i)) v = spt[i][v];
    }

    for (int i = 17; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) u = spt[0][u];
    return u;
}

void update(int ix, int val) {
    for (int i = ix + n*2; i > 0; i >>= 1) {
        seg[i] ^= val;
    }
}

int getSum(int l, int r) {
    int res = 0;
    for (l += n * 2, r += n * 2; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res ^= seg[l++];
        if (r & 1) res ^= seg[--r];
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    for (int i = 0; i < n; i++) {
        update(s[i + 1], A[i]);
        update(e[i + 1], A[i]);
    }

    while (q--) {
       /* cout << "Curr: ";
        for (int i = 1; i <= n; i++) cout << A[i - 1] << ' ';
        cout << '\n';*/

        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1){
            int upd = A[b - 1] ^ c;
            A[b - 1] = c;

            update(s[b], upd);
            update(e[b], upd);
        }
        else {

            int lca = getLca(b, c);

            int res = 0;
            res ^= getSum(s[lca], s[c] + 1);
            res ^= getSum(s[lca], s[b] + 1);
            res ^= A[lca-1];

            cout <<  res << '\n';
        }

    }
}
