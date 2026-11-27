#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second

vector<int> adj[101010];
int spt[17][100101];
int dep[100101];
int val[101010];
vector<int> num;
int getIdx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}


int gdx = 0;
struct Node {

    int val;
    int L, R;
    Node() : L(-1), R(-1), val(0) {}


} root[2001000];

int rootIdx[101010];

void init(Node& curr, int l, int r) {
    if (l == r) {
        curr.val = 0;
        return;
    }

    int mid = (l + r) >> 1;
    curr.L = ++gdx;
    curr.R = ++gdx;
    init(root[curr.L], l, mid);
    init(root[curr.R], mid + 1, r);
}

void insert(Node& curr, Node& prev, int l, int r, int u) {

    if (l == u && r == u) {
        curr.val = prev.val + 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= u) {
        curr.L = ++gdx;
        curr.R = prev.R;
        insert(root[curr.L], root[prev.L], l, mid, u);
        curr.val = root[curr.L].val + root[curr.R].val;
    }
    else {
        curr.L = prev.L;
        curr.R = ++gdx;
        insert(root[curr.R], root[prev.R], mid + 1, r, u);
        curr.val = root[curr.L].val + root[curr.R].val;
    }
}

int getSum(Node& n, int l, int r, int sl, int sr) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return n.val;

    int mid = (l + r) >> 1;
    return getSum(root[n.L], l, mid, sl, sr) + getSum(root[n.R], mid + 1, r, sl, sr);
}

void dfs(int v, int pv) {
    rootIdx[v] = ++gdx;
    insert(root[rootIdx[v]], root[rootIdx[pv]], 1, 100000, getIdx(val[v]) + 1);
    for (auto f : adj[v]) if (f != pv) {
        //cout << "Go: " << v << ' ' << f.x << '\n';
        dep[f] = dep[v] + 1;
        dfs(f, v);
        spt[0][f] = v;
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

    int n, q;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        num.push_back(val[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());


    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(root[0], 1, 100000);

    dfs(1, 0);

    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    cin >> q;
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        int lca = getLCA(u, v);


        int l = 1, r = 100000;

        while (l <= r) {
            int mid = (l + r) >> 1;

            int res = 0;
            res += getSum(root[rootIdx[u]], 1, 100000, 1, mid);
            res += getSum(root[rootIdx[v]], 1, 100000, 1, mid);
            res -= getSum(root[rootIdx[lca]], 1, 100000, 1, mid);
            if (spt[0][lca] != 0) {
                int tl = spt[0][lca];
                res -= getSum(root[rootIdx[tl]], 1, 100000, 1, mid);
            }

            if (res >= k) r = mid - 1;
            else l = mid + 1;
        }

        cout << num[l - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
