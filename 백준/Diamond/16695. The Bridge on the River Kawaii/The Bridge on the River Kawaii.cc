#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

struct Edge {
    int u, v, d;
    int l, r;
};

int root[101010], sz[101010];
int find(int n) {
    int res = n;
    while (root[res] != res) res = root[res];
    return res;
}

stack<pair<int, int>> rec;
void merge(int u, int v) {
    int nu = find(u);
    int nv = find(v);

    if (sz[nu] > sz[nv]) swap(nu, nv);
    rec.push(mp(nu, nv));
    root[nu] = nv;
    sz[nv] += sz[nu];
}

void rollback() {
    if (rec.empty()) return;
    int u, v;
    tie(u, v) = rec.top();
    rec.pop();

    sz[v] -= sz[u];
    root[u] = u;
}

pair<int, int> Query[101010];
int ans[101010];
vector<Edge> edgSeg[501010];

void insert(int l, int r, int n, const Edge& curr) {
    if (curr.l <= l && r <= curr.r) {
        edgSeg[n].push_back(curr);
        return;
    }
    if (curr.l > r || curr.r < l) return;
    int mid = (l + r) >> 1;
    insert(l, mid, n * 2, curr);
    insert(mid + 1, r, n * 2 + 1, curr);
}

void solve(int l, int r, int n, int d) {
    int cnt = 0;
    for (auto& i : edgSeg[n]) if (i.d <= d) {
        int tu = find(i.u);
        int tv = find(i.v);

        if (tu != tv) {
            merge(tu, tv);
            cnt++;
        }
    }

    if (l == r) {
        // go query
        if (Query[l].first != -1 && ans[l] == -1) {
            int u, v;
            tie(u, v) = Query[l];
            if (find(u) == find(v)) ans[l] = d;
        }
    }
    else {
        int mid = (l + r) >> 1;
        solve(l, mid, n * 2, d);
        solve(mid + 1, r, n * 2 + 1, d);
    }
    while (cnt--) rollback();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    map<pair<int, int>, int> edg;
    for (int i = 1; i <= q; i++) {
        sz[i] = 1;
        root[i] = i;
        ans[i] = -1;
        Query[i] = mp(-1, -1);
    }

    vector<Edge> edgList;

    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;

        if (t == 0) {
            int u, v, d;
            cin >> u >> v >> d;
            if (u > v) swap(u, v);

            edgList.push_back({ u, v, d, i, q + 1 });
            edg[mp(u, v)] = edgList.size();
        }
        else if (t == 1) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);

            int tx = edg[mp(u, v)] - 1;
            edgList[tx].r = i;
        }
        else {
            // query
            int u, v;
            cin >> u >> v;
            Query[i] = mp(u, v);
        }
    }

    for (const auto& f : edgList) {
        insert(1, q, 1, f);
    }
    
    for (int i = 0; i <= 9; i++) {
        solve(1, q, 1, i);
    }

    for (int i = 1; i <= q; i++) {
        if (Query[i].first != -1) {
            cout << ans[i] << '\n';
        }
    }

}