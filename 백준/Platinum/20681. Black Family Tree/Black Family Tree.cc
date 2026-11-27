#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
vector<int> adj[101010];
ll seg[202020];
ll A[101010];
void dfs(int v, int pv = -1) {
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        A[v] += A[f];
    }
}

void update(int ix, ll val) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

ll getV(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}


void solve() {

    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    vector<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back(mp(mp(a, b), i));
    }
    dfs(1);

    sort(all(q));
    vector<ll> ans(m);


    update(1, A[1]);
    int cur = 1;
    for (auto f : q) {
        auto [a, b] = f.x;
        int ix = f.y;

        while (cur < a) {
            for (auto f : adj[cur]) {
                update(f, A[f]);
            }
            update(cur, -A[cur]);
            cur++;
        }

        ans[ix] = getV(a, b + 1);;
    }

    for (auto f : ans) cout << f << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
