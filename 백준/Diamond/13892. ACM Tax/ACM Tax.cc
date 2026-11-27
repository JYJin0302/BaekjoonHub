#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second

vector<pair<int, int>> adj[51010];
int spt[17][50101];
int dep[50101];

struct Node {

    int val;
    Node* L, *R;
    Node() : L(NULL), R(NULL), val(0) {}


}* root[51000];

void init(Node* curr, int l, int r) {
    if (l == r) {
        curr->val = 0;
        return;
    }

    int mid = (l + r) >> 1;
    curr->L = new Node();
    curr->R = new Node();
    init(curr->L, l, mid);
    init(curr->R, mid + 1, r);
}

void insert(Node* curr, Node* prev, int l, int r, int u) {

    if (l == u && r == u) {
        curr->val = prev->val + 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= u) {
        curr->L = new Node();
        curr->R = prev->R;
        insert(curr->L, prev->L, l, mid, u);
        curr->val = curr->L->val + curr->R->val;
    }
    else {
        curr->L = prev->L;
        curr->R = new Node();
        insert(curr->R, prev->R, mid+1, r, u);
        curr->val = curr->L->val + curr->R->val;
    }
}

int getSum(Node* n, int l, int r, int sl, int sr) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return n->val;

    int mid = (l + r) >> 1;
    return getSum(n->L, l, mid, sl, sr) + getSum(n->R, mid + 1, r, sl, sr);
}

void dfs(int v, int pv = -1) {
    for (auto f : adj[v]) if (f.x != pv) {
        //cout << "Go: " << v << ' ' << f.x << '\n';
        insert(root[f.x], root[v], 1, 100000, f.y);
        dep[f.x] = dep[v] + 1;
        dfs(f.x, v);
        spt[0][f.x] = v;
    }
}

int getLCA(int u, int v) {

    if (dep[u] > dep[v]) swap(u, v);
    int dif = dep[v] - dep[u];
    for (int i = 16; i >= 0; i--) {
        if (dif & (1 << i)) {
            v = spt[i][v];
        }
    }

    for (int i = 16; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) u = spt[0][u];
    return u;
}

void solve() {

    int n;
    cin >> n;

    memset(dep, 0, sizeof(dep));
    memset(spt, 0, sizeof(spt));
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        root[i] = new Node();
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    init(root[1], 1, 100000);

    dfs(1);

    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    int q; cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca = getLCA(u, v);

        int d = dep[u] + dep[v] - 2 * dep[lca];

        int d1, d2;
        if (d & 1) d1 = d2 = d / 2 + 1;
        else {
            d1 = d / 2;
            d2 = d / 2 + 1;
        }
        int l = 1, r = 100000;

        int ans = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;

            int res = 0;
            res += getSum(root[u], 1, 100000, 1, mid);
            res += getSum(root[v], 1, 100000, 1, mid);
            res -= 2*getSum(root[lca], 1, 100000, 1, mid);

            if (res >= d1) r = mid - 1;
            else l = mid + 1;
        }
        ans += l;

        l = 1, r = 100000;
        while (l <= r) {
            int mid = (l + r) >> 1;

            int res = 0;
            res += getSum(root[u], 1, 100000, 1, mid);
            res += getSum(root[v], 1, 100000, 1, mid);
            res -= 2 * getSum(root[lca], 1, 100000, 1, mid);

            if (res >= d2) r = mid - 1;
            else l = mid + 1;
        }
        ans += l;

        if (ans & 1) cout << ans / 2 << ".5\n";
        else cout << ans / 2 << ".0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
